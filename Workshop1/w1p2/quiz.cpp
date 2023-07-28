/*
*****************************************************************************
                        OOP244-Workshop-1, part-2
Full Name  : Travis Liu
e-mail     : tliu84@myseneca.ca
Student ID#: 156740201
Date       : 22 May, 2022
Section    : ZCC

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "quiz.h"
#include "question.h"

using namespace std;

namespace quizzer {

    const int TEXT_OF_QUESTION = 1024;
    const int TEXT_OF_ANSWER = 128;
    const int MAX_QUESTION = 60;
    const int MAX_ANSWERS = 10;

    struct answer {
        char textofans[TEXT_OF_ANSWER];
        char answer[2];
    };

    struct question {
        char typeofQ[4];
        char textofQ[TEXT_OF_QUESTION];
        struct answer answer[MAX_ANSWERS];
        int noofans = 0;
        char useranswer[MAX_ANSWERS];
    };
    struct question question[MAX_QUESTION];

    struct quiz {
        int quiztaken = 0;
        int questions = 0;
        int totalquestions = 0;
        int questionnumber = 0;
        int score = 0;
    };
    struct quiz quiz;

    FILE* sfptr = nullptr;
    
    /// Loads a quiz from a file.
    int LoadQuiz(const char* filename) {
        quiz.quiztaken = 0;
        quiz.score = 0;
        for (int i = 0; i < MAX_QUESTION; i++)
        {
            for (int j = 0; j < MAX_ANSWERS; j++)
            {
                question[i].useranswer[j] = '\0';
            }
        }
        sfptr = fopen(filename, "r");
        quiz.questions = 0;
        if (sfptr != NULL) {
            for (int i = 0; i < MAX_QUESTION && fgetc(sfptr) == '{'; i++)
            {
                question[i].noofans = 0;
                fscanf(sfptr, "%[^ ] %[^\n]", question[i].typeofQ,
                    question[i].textofQ);
                quiz.questions++;
                fgetc(sfptr);
                int j = 0;
                for (j =0; fgetc(sfptr) == '['; j++)
                {
                    for (int k = 0; question[i].answer[j].textofans[k] != '\0'; k++)
                    {
                        question[i].answer[j].textofans[k] = { '\0' };
                    }
                    fscanf(sfptr, "%[^]] %[^\n]", question[i].answer[j].answer,
                        question[i].answer[j].textofans);
                    fgetc(sfptr);
                    question[i].noofans++;
                }               
                fgetc(sfptr);                
            }
            return 0;
        }
        return 1;
    }

    /// Checks if a quiz is currently loaded and is valid.
    int IsQuizValid() {
        quiz.totalquestions = quiz.questions;
        if (sfptr != NULL && quiz.questions >= 5) {
            int validquiz = 1;
            for (int i = 0; i < quiz.questions; i++)
            {
                isquestionvalid(question, &validquiz, i);
            }
            if (validquiz)
            {
                fclose(sfptr);
                return 1;
            }
            fclose(sfptr);
            return 0;
        }
        fclose(sfptr);
        return 0;
    }

    /// Checks if there are still questions in the quiz that haven't been shown to the user.
    int HasMoreQuestions() {
        if (--quiz.questions)
        {
            return 1;
        }
        quiz.questionnumber = 0;
        return 0;
    }

    /// Prints to the screen the next question from the quiz and records
    ///   user's answer.
    void ShowNextQuestion() {
        cout << question[quiz.questionnumber].textofQ << endl;
        for (int i = 0; i < question[quiz.questionnumber].noofans; i++)
        {
            cout << i + 1 << '.';
            for (int j = 0; j < TEXT_OF_ANSWER; j++)
            {
                if (question[quiz.questionnumber].answer[i].textofans[j] != ']' && question[quiz.questionnumber].answer[i].textofans[j] != '\0')
                {
                    cout << question[quiz.questionnumber].answer[i].textofans[j];
                }
            }
            cout << endl;
        }
        int useranswer = 0;
        cout << "Your answer? ";
        cin >> useranswer;
        isanscorrect(question, quiz, &useranswer);
        for (int i = 0; i < question[quiz.questionnumber].noofans; i++)
        {
            if (question[quiz.questionnumber].useranswer[i] == question[quiz.questionnumber].answer[i].answer[0])
            {
                quiz.score++;
            }
        }
        if (quiz.questionnumber)
        {
            quiz.quiztaken = 1;
        }
        quiz.questionnumber++;
    }

    /// Prints to the screen the results in the format
    void ShowQuizResults() {
        if (quiz.quiztaken)
        {
            cout << endl << "QUIZ RESULTS: your score is " << quiz.score << "/" << quiz.totalquestions << '.' << endl;
        }
    }

}