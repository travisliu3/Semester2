#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__

#include <iostream>

namespace sdds {

	const unsigned int MAX_MENU_ITEMS = 20;

	class Menu;
	class LibApp;

	class MenuItem
	{
		char* menuitem;
		friend class Menu;
		friend class LibApp;
		MenuItem();  // default constructor
		MenuItem(const char itemname[]);  // one argument constructor
		operator bool();  // it returns true, if MenuItem is not empty
		operator const char* ();  //  it returns the address of the menuitem.
		std::ostream& display(std::ostream& os = std::cout);  // display the content of the MenuItem on ostream.
	};

	class Menu
	{
		friend class LibApp;
		MenuItem menutitle;
		MenuItem* menuitems[MAX_MENU_ITEMS];
		int items;
	public:
		Menu();  // default constructor
		Menu(const char title[]);  // one argument constructor
		~Menu();  // default destructor
		std::ostream& displaytitle(std::ostream& os) const;  // display the title of the Menu on ostream if the title is not empty
		std::ostream& displaymenu(std::ostream& os) const;  // display the entire Menu on ostream
		unsigned int run() const;  // This function displays the Menu and gets the user selection.
		unsigned int operator~();  // This function displays the Menu and gets the user selection.
		Menu& operator<<(const char* menuitemConent);  // add a MenuItem to the Menu.
		operator int();  // return the number of MenuItems on the Menu.
		operator unsigned int() const;  // return the number of MenuItems on the Menu.
		operator bool() const;  // return true if the Menu has one or more MenuItems
		const char* operator[](int i)const;  // return the const char* cast of the corresponding MenuItem in the array of MenuItem pointers.
		void title(std::ostream& os)const;
	};
	std::ostream& operator<<(std::ostream& os, Menu& main);  // print the title of the Menu using cout.

}
#endif