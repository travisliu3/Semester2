#include "LibApp.h"
#include "Date.h"
int main() {
	sdds::sdds_day = 27;
	sdds::sdds_mon = 7;
	sdds::sdds_year = 2022;
	sdds::sdds_test = true;
	sdds::LibApp theApp("LibRecs.txt");
	theApp.run();
	return 0;
}