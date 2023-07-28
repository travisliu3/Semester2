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
        int noofans;
        char useranswer[MAX_ANSWERS];
    };

    struct quiz {
        int quiztaken = 0;
        int questions = 0;
        int totalquestions = 0;
        int questionnumber = 0;
        int score = 0;
    };

    /// checks if question is valid.
    void isquestionvalid(struct question* question, int* validquiz, int i) {
        int noofans = 0;
        if (question[i].typeofQ[1] == 'c')
        {
            for (int j = 0; j < question[i].noofans; j++)
            {
                if (question[i].answer[j].answer[0] == 'X')
                {
                    noofans++;
                }
            }
            if (noofans != 1)
            {
                *validquiz = 0;
                cout << "Question " << i + 1 << " -> ERROR" << endl;
            }
            else
            {
                cout << "Question " << i + 1 << " -> OK" << endl;
            }
        }
        else
        {
            for (int j = 0; j < question[i].noofans; j++)
            {
                if (question[i].answer[j].answer[0] == 'X')
                {
                    noofans++;
                }
            }
            if (noofans == 0)
            {
                *validquiz = 0;
                cout << "Question " << i + 1 << " -> ERROR" << endl;
            }
            else
            {
                cout << "Question " << i + 1 << " -> OK" << endl;
            }
        }
    }

    /// Checks if the answer to the question is correct.
    void isanscorrect(struct question* question, struct quiz quiz, int* useranswer) {
        for (int i = 0; i < question[quiz.questionnumber].noofans; i++)
        {
            if (*useranswer == i + 1)
            {
                question[quiz.questionnumber].useranswer[i] = 'X';
            }
        }
    }

}