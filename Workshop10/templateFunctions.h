/*
*****************************************************************************
							OOP244-Workshop-10
Full Name  : Travis Liu
e-mail     : tliu84@myseneca.ca
Student ID#: 156740201
Date       : 2 August, 2022
Section    : ZCC

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_TEMPLATEFUNCTIONS_H_
#define SDDS_TEMPLATEFUNCTIONS_H_
#include <iostream>
#include "Collection.h"
namespace sdds {
	//Find with 3 parameters
	//The following function template requires an array and an element to check
	//for its existence in the array. Both the type of array and the type of element
	//inside the array is unknown.
	template <typename T, typename I>
	bool find(T arr[], int i, I find) {
		return (arr[i] == find);
	}

	//Find with 4 parameters
	//The following function template requires an array and two element to check
	//for its existence in the array. Both the type of array and the type of elements
	//inside the array is unknown.
	template <typename T, typename I, typename C>
	int find(T arr[], int i, I find, C find2) {
		for (int j = 0; j < i; j++)
		{
			if (arr[j] == find && arr[j] == find2)
			{
				return j;
			}
		}
		return -1;
	}

	//Insertion operator
	//The following function template requires an Collection class template
	//to print its attributes to the screen.
	template <typename T>
	std::ostream& operator<<(std::ostream& os, Collection<T> collect) {
		for (int i = 0; i < collect.size(); i++)
		{
			os << collect[i] << std::endl;
		}
		return os;
	}

	//Load Collection
	//The following function template requires an Collection class template and
	//and element of same type as the attribute of Collection template to be added
	//in the Collection type.
	template <typename T>
	const Collection<T>& loadCollection(Collection<T>& collect, const T element) {
		return collect += element;
	}

}
#endif // !SDDS_SEARCH_H_
