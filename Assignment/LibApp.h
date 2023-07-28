#ifndef SDDS_LIBAPP_H__
#define SDDS_LIBAPP_H__
#include "Menu.h"
#include "Publication.h"

namespace sdds {

	class LibApp
	{
		bool m_changed;
		Menu m_mainMenu;
		Menu m_exitMenu;
		char filename[256 + 1];
		Publication* p[SDDS_LIBRARY_CAPACITY];
		int publicationloaded;
		int reference;
		Menu type;
		bool confirm(const char* message);
		void load();  // prints: "Loading Data"<NEWLINE>
		void save();  // prints: "Saving Data"<NEWLINE>
		int search(int pubtype, int check = 0);  // prints: "Searching for publication"<NEWLINE>
		void returnPub();  /*  Calls the search() method.
							 prints "Returning publication"<NEWLINE>
							 prints "Publication returned"<NEWLINE>
							 sets m_changed to true;
						 */
		void newPublication();  // add new publication
		void removePublication();  // remove publication
		void checkOutPub();  // checkout publication
	public:
		~LibApp();
		LibApp(const char*);
		void run();
		Publication* getPub(int libRef);
	};

}
#endif