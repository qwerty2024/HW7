
#include "IntegerArray.h"

using namespace std;

int main()
{
	IntegerArray arr1(-1);
	cout << arr1[333] << endl;
	cout << arr1[-333] << endl << endl;

	IntegerArray arr2(10, 33);
	arr2.printer(); 
	cout << endl;

	arr1.printer();
	arr1 = arr2;
	arr1.printer();
	cout << endl;

	arr1.erase();
	arr1.printer();
	cout << endl;

	arr1.reallocate(5);
	arr1.printer();
	cout << endl;

	arr2.resize(5);
	arr2.printer();
	arr2.resize(15);
	arr2.printer();
	cout << endl;
	
	IntegerArray arr3(10, 33);
	arr3.insertBefore(44, 3);
	arr3.printer();
	arr3.remove(3);
	arr3.printer();
	arr3.push_front(11);
	arr3.printer();
	arr3.push_back(55);
	arr3.printer();
	cout << endl;

	int ind = 0;
	if (arr3.search(11, ind))
	{
		cout << "First index eqal element = " << ind << endl;
	}
	else
	{
		cout << "Not found!" << endl;
	}

	if (arr3.search(22, ind))
	{
		cout << "First index eqal element = " << ind << endl;
	}
	else
	{
		cout << "Not found!" << endl;
	}

	if (arr3.search(33, ind))
	{
		cout << "First index eqal element = " << ind << endl;
	}
	else
	{
		cout << "Not found!" << endl;
	}

	if (arr3.search(55, ind))
	{
		cout << "First index eqal element = " << ind << endl;
	}
	else
	{
		cout << "Not found!" << endl;
	}


	arr1.erase();
	arr2.erase();
	arr3.erase();
	return 0;
}