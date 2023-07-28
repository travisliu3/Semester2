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
#ifndef _SDDS_BASKET_H__
#define _SDDS_BASKET_H__

namespace sdds {

	struct Fruit
	{
		char m_name[30 + 1]; // the name of the fruit
		double m_qty;        // quantity in kilograms
	};

	class Basket
	{
		Fruit* m_fruits; // a dynamically allocated array of objects of type Fruit.
		int m_cnt; // the size of the m_fruits array.
		double m_price; // the price of the basket.
	public:
		Basket();
		Basket(const Fruit fruit[], int cnt, double price);
		Basket(const Basket& basket);
		Basket& operator=(const Basket& basket);
		~Basket();
		void setPrice(double price);
		operator bool();
		Basket& operator+=(Fruit fruit);
		int cnt();
		Fruit* fruits();
		double price();
	};

	void operator<<(std::ostream& os, Basket basket);

}

#endif