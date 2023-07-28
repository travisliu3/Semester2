#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

#include "LibApp.h"
#include "Menu.h"
#include "Book.h"
#include "PublicationSelector.h"

namespace sdds {

	bool LibApp::confirm(const char* message)
	{
		Menu confirm;
		confirm.menutitle.menuitem = new char[strlen(message) + 1];
		strcpy(confirm.menutitle.menuitem, message);
		confirm << "Yes";
		if (confirm.run())
		{
			return true;
		}
		return false;
	}

	// prints: "Loading Data"<NEWLINE>
	void LibApp::load()
	{
		char type;
		publicationloaded = 0;
		cout << "Loading Data" << endl;
		ifstream ifstr("LibRecs.txt");
		while (!ifstr.fail())
		{
			for (int i = 0; i < SDDS_LIBRARY_CAPACITY; i++)
			{
				ifstr >> type;
				if (!ifstr.fail())
				{
					if (type == 'P')
					{
						p[i] = new Publication;
						ifstr >> *p[i];
						publicationloaded++;
					}
					else
					{
						p[i] = new Book;
						ifstr >> *p[i];
						publicationloaded++;
					}
				}
			}
		}
		reference = p[publicationloaded - 1]->getRef();
	}

	// prints: "Saving Data"<NEWLINE>
	void LibApp::save()
	{
		cout << "Saving Data" << endl;
		ofstream ofstr("LibRecs.txt");
		for (int i = 0; i < publicationloaded; i++)
		{
			if (p[i]->getRef() != 0)
			{
				ofstr << *p[i] << endl;
			}
		}
	}

	// prints: "Searching for publication"<NEWLINE>
	int LibApp::search(int pubtype, int check)
	{
		PublicationSelector PS("Select one of the following found matches:");
		cout << "Publication Title: ";
		cin.ignore();
		char title[256 + 1];
		cin.get(title, '\n');
		bool found = false;
		if (check == 0)
		{
			if (pubtype == 2)
			{
				for (int i = 0; i < publicationloaded; i++)
				{
					if (p[i]->getRef() != 0 && p[i]->type() == 'P' && strstr((const char*)*p[i], title))
					{
						PS << p[i];
						found = true;
					}
				}
			}
			else
			{
				for (int i = 0; i < publicationloaded; i++)
				{
					if (p[i]->getRef() != 0 && p[i]->type() == 'B' && strstr((const char*)*p[i], title))
					{
						PS << p[i];
						found = true;
					}
				}
			}
		}
		else if (check == 1)
		{
			if (pubtype == 2)
			{
				for (int i = 0; i < publicationloaded; i++)
				{
					if (p[i]->getRef() != 0 && p[i]->getmember() == 0 && p[i]->type() == 'P' && strstr((const char*)*p[i], title))
					{
						PS << p[i];
						found = true;
					}
				}
			}
			else
			{
				for (int i = 0; i < publicationloaded; i++)
				{
					if (p[i]->getRef() != 0 && p[i]->getmember() == 0 && p[i]->type() == 'B' && strstr((const char*)*p[i], title))
					{
						PS << p[i];
						found = true;
					}
				}
			}
		}
		else if (check == 2)
		{
			if (pubtype == 2)
			{
				for (int i = 0; i < publicationloaded; i++)
				{
					if (p[i]->getRef() != 0 && p[i]->getmember() != 0 && p[i]->type() == 'P' && strstr((const char*)*p[i], title))
					{
						PS << p[i];
						found = true;
					}
				}
			}
			else
			{
				for (int i = 0; i < publicationloaded; i++)
				{
					if (p[i]->getRef() != 0 && p[i]->getmember() != 0 && p[i]->type() == 'B' && strstr((const char*)*p[i], title))
					{
						PS << p[i];
						found = true;
					}
				}
			}
		}
		if (found)
		{
			PS.sort();
			cin.clear();
			cin.ignore(1000, '\n');
			int ref = PS.run();
			for (int i = 0; i < publicationloaded; i++)
			{
				if (p[i]->getRef() == ref)
				{
					cout << *p[i];
					return p[i]->getRef();
				}
			}
		}
		else
		{
			cout << "No matches found!" << endl;
			return 0;
		}
		cout << "Aborted!" << endl;
		return 0;
	}

	/*  Calls the search() method.
							 prints "Returning publication"<NEWLINE>
							 prints "Publication returned"<NEWLINE>
							 sets m_changed to true;
						 */
	void LibApp::returnPub()
	{
		cout << "Return publication to the library" << endl;
		unsigned int pubtype;
		pubtype = type.run();
		if (pubtype)
		{
			int returnref = search(pubtype, 2);
			if (returnref)
			{
				cout << endl;
				if (confirm("Return Publication?"))
				{
					int late = 0;
					for (int i = 0; i < publicationloaded; i++)
					{
						if (p[i]->getRef() == returnref)
						{
							Date d;
							late = d - p[i]->checkoutDate();
							late -= 15;
							break;
						}
					}
					if (late)
					{
						double pay = late * 0.5;
						cout.setf(ios::fixed);
						cout.precision(2);
						cout << "Please pay $" << pay << " penalty for being " << late << " days late!" << endl;
						cout.unsetf(ios::fixed);
					}
					for (int i = 0; i < publicationloaded; i++)
					{
						if (p[i]->getRef() == returnref)
						{
							p[i]->set(0);
							break;
						}
					}
					cout << "Publication returned" << endl;
					m_changed = true;
				}
			}
		}
		else
		{
			cout << "Aborted!" << endl;
		}
	}


	LibApp::LibApp(const char* file)
	{
		m_changed = false;
		m_mainMenu.menutitle.menuitem = new char[strlen("Seneca Library Application") + 1];
		strcpy(m_mainMenu.menutitle.menuitem, "Seneca Library Application");
		m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
		m_exitMenu.menutitle.menuitem = new char[strlen("Changes have been made to the data, what would you like to do?") + 1];
		strcpy(m_exitMenu.menutitle.menuitem, "Changes have been made to the data, what would you like to do?");
		m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
		type.menutitle.menuitem = new char[strlen("Choose the type of publication:") + 1];
		strcpy(type.menutitle.menuitem, "Choose the type of publication:");
		type << "Book" << "Publication";
		strcpy(filename, file);
		load();
	}

	LibApp::~LibApp() {
		for (int i = 0; i < publicationloaded; i++)
		{
			delete p[i];
		}
	}

	// add new publication
	void LibApp::newPublication()
	{
		if (publicationloaded == SDDS_LIBRARY_CAPACITY)
		{
			cout << "Library is at its maximum capacity!" << endl;
		}
		else
		{
			unsigned int pubtype;
			cout << "Adding new publication to the library" << endl;
			pubtype = type.run();
			Publication* choice = nullptr;
			if (pubtype == 2)
			{
				choice = new Publication;
			}
			else if (pubtype == 1)
			{
				choice = new Book;
			}
			if (pubtype)
			{
				cin >> *choice;
				if (cin.fail())
				{
					cin.ignore(1000, '\n');
					cout << "Aborted!";
				}
				else
				{
					if (confirm("Add this publication to the library?"))
					{
						if (choice)
						{
							reference++;
							choice->setRef(reference);
							p[publicationloaded] = choice;
							publicationloaded++;
							m_changed = true;
							cout << "Publication added" << endl;
						}
						else
						{
							cout << "Failed to add publication!";
							delete choice;
						}
					}
				}
			}
			else
			{
				cout << "Aborted!" << endl;
			}
		}
	}

	// remove publication
	void LibApp::removePublication()
	{
		unsigned int pubtype;
		cout << "Removing publication from the library" << endl;
		pubtype = type.run();
		if (pubtype)
		{
			int removeref = search(pubtype);
			if (removeref)
			{
				cout << endl;
				if (confirm("Remove this publication from the library?"))
				{
					for (int i = 0; i < publicationloaded; i++)
					{
						if (p[i]->getRef() == removeref)
						{
							p[i]->setRef(0);
							break;
						}
					}
					m_changed = true;
					cout << "Publication removed" << endl;
				}
			}
		}
		else
		{
			cout << "Aborted!" << endl;
		}
	}

	// checkout publication
	void LibApp::checkOutPub()
	{
		unsigned int pubtype;
		cout << "Checkout publication from the library" << endl;
		pubtype = type.run();
		if (pubtype)
		{
			int checkref = search(pubtype, 1);
			if (checkref)
			{
				cout << endl;
				if (confirm("Check out publication?"))
				{
					int membernum;
					cout << "Enter Membership number: ";
					cin >> membernum;
					while (membernum > 99999 || membernum < 10000)
					{
						cout << "Invalid membership number, try again: ";
						cin >> membernum;
					}
					for (int i = 0; i < publicationloaded; i++)
					{
						if (p[i]->getRef() == checkref)
						{
							p[i]->set(membernum);
							break;
						}
					}
					m_changed = true;
					cout << "Publication checked out" << endl;
				}
			}
		}
		else
		{
			cout << "Aborted!" << endl;
		}
	}

	void LibApp::run()
	{
		int selection = 1;
		while (selection)
		{
			cout << m_mainMenu << endl;
			m_mainMenu.displaymenu(cout);
			cin >> selection;
			switch (selection)
			{
			case 1:
				newPublication();
				break;
			case 2:
				removePublication();
				break;
			case 3:
				checkOutPub();
				break;
			case 4:
				returnPub();
				break;
			case 0:
				if (m_changed)
				{
					switch (m_exitMenu.run())
					{
					case 1:
						save();
						break;
					case 2:
						selection = 1;
						break;
					default:
						confirm("This will discard all the changes are you sure?");
						break;
					}
				}
				break;
			default:
				break;
			}
			cout << endl;
		}
		cout << "-------------------------------------------" << endl;
		cout << "Thanks for using Seneca Library Application" << endl;
	}

	Publication* LibApp::getPub(int libRef) {
		int i = 0;
		for (i = 0; i < publicationloaded; i++)
		{
			if (libRef == p[i]->getRef())
			{
				break;
			}
		}
		return p[i];
	}

}