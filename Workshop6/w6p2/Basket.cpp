/*
*****************************************************************************
						OOP244-Workshop-6, part-2
Full Name  : Travis Liu
e-mail     : tliu84@myseneca.ca
Student ID#: 156740201
Date       : 1 July, 2022
Section    : ZCC

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include "Basket.h"

using namespace std;

namespace sdds {

	Basket::Basket() {
		m_fruits = nullptr;
		m_cnt = 0;
		m_price = 0;
	}

	Basket::Basket(const Fruit fruit[], int cnt, double price) {
		if (fruit != nullptr && cnt > 0 && price > 0)
		{
			m_fruits = nullptr;
			m_fruits = new Fruit[cnt];
			for (int i = 0; i < cnt; i++)
			{
				strcpy(m_fruits[i].m_name, fruit[i].m_name);
				m_fruits[i].m_qty = fruit[i].m_qty;
			}
			m_cnt = cnt;
			m_price = price;
		}
		else
		{
			m_fruits = nullptr;
			m_cnt = 0;
			m_price = 0;
		}
	}

	Basket::Basket(const Basket& basket) {
		m_cnt = basket.m_cnt;
		m_price = basket.m_price;
		m_fruits = nullptr;
		m_fruits = new Fruit[m_cnt];
		for (int i = 0; i < m_cnt; i++)
		{
			strcpy(m_fruits[i].m_name, basket.m_fruits[i].m_name);
			m_fruits[i].m_qty = basket.m_fruits[i].m_qty;
		}
	}

	Basket& Basket::operator=(const Basket& basket) {
		m_cnt = basket.m_cnt;
		m_price = basket.m_price;
		delete[] m_fruits;
		m_fruits = nullptr;
		m_fruits = new Fruit[m_cnt];
		for (int i = 0; i < m_cnt; i++)
		{
			strcpy(m_fruits[i].m_name, basket.m_fruits[i].m_name);
			m_fruits[i].m_qty = basket.m_fruits[i].m_qty;
		}
		return *this;
	}

	Basket::~Basket() {
		delete[] m_fruits;
	}

	void Basket::setPrice(double price) {
		m_price = price;
	}

	Basket::operator bool() {
		if (m_cnt)
		{
			return true;
		}
		return false;
	}

	Basket& Basket::operator+=(Fruit fruit) {
		Fruit* fruits = nullptr;
		fruits = new Fruit[m_cnt + 1];
		for (int i = 0; i < m_cnt; i++)
		{
			strcpy(fruits[i].m_name, m_fruits[i].m_name);
			fruits[i].m_qty = m_fruits[i].m_qty;
		}
		m_cnt++;
		strcpy(fruits[m_cnt - 1].m_name, fruit.m_name);
		fruits[m_cnt - 1].m_qty = fruit.m_qty;
		delete[] m_fruits;
		m_fruits = nullptr;
		m_fruits = fruits;
		return *this;
	}

	int Basket::cnt() {
		return m_cnt;
	}

	Fruit* Basket::fruits() {
		return m_fruits;
	}
	
	double Basket::price() {
		return m_price;
	}

	void operator<<(std::ostream& os, Basket basket) {
		if (basket.cnt())
		{
			os << "Basket Content:" << endl;
			os.setf(ios::fixed);
			os.precision(2);
			for (int i = 0; i < basket.cnt(); i++)
			{
				os.width(10);
				os << basket.fruits()[i].m_name << ": " << basket.fruits()[i].m_qty << "kg" << endl;
			}
			os << "Price: " << basket.price() << endl;
			os.unsetf(ios::fixed);
		}
		else
		{
			os << "The basket is empty!" << endl;
		}
	}
	
}