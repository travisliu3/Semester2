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
#ifndef SDDS_QUESTION_H__
#define SDDS_QUESTION_H__

namespace quizzer {

	struct question;

	/// checks if question is valid.
	void isquestionvalid(struct question* question, int* validquiz, int i);

	/// Checks if the answer to the question is correct.
	void isanscorrect(struct question* question, struct quiz quiz, int* userans);

}

#endif