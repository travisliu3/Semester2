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
#ifndef SDDS_QUIZ_H__
#define SDDS_QUIZ_H__

namespace quizzer {
	int j;
	/// Loads a quiz from a file.
	int LoadQuiz(const char* filename);

	/// Checks if a quiz is currently loaded and is valid.
	int IsQuizValid();

	/// Checks if there are still questions in the quiz that haven't been shown to the user.
	int HasMoreQuestions();

	/// Prints to the screen the next question from the quiz and records
	///   user's answer.
	void ShowNextQuestion();

	/// Prints to the screen the results in the format
	void ShowQuizResults();

}

#endif