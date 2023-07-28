#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "Utils.h"

using namespace std;

namespace sdds {

    // default constructor
    MenuItem::MenuItem()
    {
        menuitem = nullptr;
    }

    // one argument constructor
    MenuItem::MenuItem(const char itemname[])
    {
        menuitem = new char[strlen(itemname) + 1];
        strcpy(menuitem, itemname);
    }

    // it returns true, if MenuItem is not empty
    MenuItem::operator bool()
    {
        if (menuitem)
        {
            return false;
        }
        return true;
    }

    //  it returns the address of the menuitem.
    MenuItem::operator const char* ()
    {
        return menuitem;
    }

    // display the content of the MenuItem on ostream.
    ostream& MenuItem::display(ostream& os)
    {
        os << menuitem;
        return os;
    }

    // default constructor
    Menu::Menu()
    {
        for (unsigned int i = 0; i < MAX_MENU_ITEMS; i++)
        {
            menuitems[i] = nullptr;
        }
        items = 0;
    }

    // one argument constructor
    Menu::Menu(const char title[])
    {
        menutitle.menuitem = new char[strlen(title) + 1];
        strcpy(menutitle.menuitem, title);
        for (unsigned int i = 0; i < MAX_MENU_ITEMS; i++)
        {
            menuitems[i] = nullptr;
        }
        items = 0;
    }

    // default destructor
    Menu::~Menu()
    {
        delete[] menutitle.menuitem;
        for (int i = 0; i < items; i++)
        {
            delete[] menuitems[i]->menuitem;
            delete menuitems[i];
        }

    }

    // display the title of the Menu on ostream if the title is not empty
    ostream& Menu::displaytitle(ostream& os) const
    {
        if (menutitle.menuitem != nullptr)
        {
            os << menutitle.menuitem << endl;
        }
        return os;
    }

    // display the entire Menu on ostream
    ostream& Menu::displaymenu(ostream& os) const
    {
        for (int i = 0; i < items; i++)
        {
            os << ' ' << i + 1 << "- " << menuitems[i]->menuitem << endl;
        }
        os << " 0- Exit" << endl;
        os << "> ";
        return os;
    }

    // This function displays the Menu and gets the user selection.
    unsigned int Menu::run() const
    {
        displaytitle(cout);
        displaymenu(cout);
        unsigned int order = 0;
        cin >> order;
        while (cin.fail() || order > (unsigned)items || order < 0)
        {
            cout << "Invalid Selection, try again: ";
            cin.clear();
            cin.ignore(2000, '\n');
            cin >> order;
        }
        return order;
    }

    // This function displays the Menu and gets the user selection.
    unsigned int Menu::operator~()
    {
        displaytitle(cout);
        displaymenu(cout);
        unsigned int order = 0;
        cin >> order;
        while (cin.fail() || order >= (unsigned)items || order < 0)
        {
            error(order);
        }
        return order;
    }

    // add a MenuItem to the Menu.
    Menu& Menu::operator<<(const char* menuitemConent)
    {
        if ((unsigned)items + 1 <= MAX_MENU_ITEMS)
        {
            menuitems[items] = new MenuItem;
            menuitems[items]->menuitem = new char[strlen(menuitemConent) + 1];
            strcpy(menuitems[items]->menuitem, menuitemConent);
            items++;
        }
        return *this;
    }

    // return the number of MenuItems on the Menu.
    Menu::operator int()
    {
        return items;
    }

    // return the number of MenuItems on the Menu.
    Menu::operator unsigned int()const
    {
        return items;
    }

    // return true if the Menu has one or more MenuItems
    Menu::operator bool()const
    {
        return (items > 0);
    }

    void Menu::title(ostream& os)const
    {
        if (menutitle.menuitem != nullptr)
        {
            os << menutitle.menuitem;
        }
    }

    // print the title of the Menu using cout.
    ostream& operator<<(ostream& os, Menu& main)
    {
        main.title(os);
        return os;
    }

    // return the const char* cast of the corresponding MenuItem in the array of MenuItem pointers.
    const char* Menu::operator[](int i) const
    {
        if (i < items)
        {
            return menuitems[i]->menuitem;
        }
        else
        {
            while (i >= items)
            {
                i -= items;
            }
        }
        return menuitems[i]->menuitem;
    }

}