#include<iostream>
#include<cstring>
using namespace std;
template <typename T>
T myMin(T val[], int j) {
	int x = 0;
	for (int i = 1; i < j; i++)
	{
		if (val[i] < val[x])
		{
			x = i;
		}
	}
	return val[x];
}

int main() {
	int intvalue[] = {1,3,5};
	double doublevalue[] = { 1.2,3.2,5.2 };
	cout << "Integer array: " << myMin(intvalue, 3);
	cout << "Integer array: " << myMin(doublevalue, 3);
	return 0;
}