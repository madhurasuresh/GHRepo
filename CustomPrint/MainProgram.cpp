#include<iostream>
#include <map>
#include <sstream>
#include "PrintNumandString.h"
using namespace std;

void main()
{
	int num1 = 3;
	int num2 = 5;
	int num3 = 7;
	int num4 = 11;

	string string1 = "Fizz";
	string string2 = "Buzz";
	string string3 = "Hello";
	string string4 = "Bye";

	std::map<int, string> map1;

	map1.insert(std::pair<int, string>(num1, string1));
	map1.insert(std::pair<int, string>(num2, string2));
	map1.insert(std::pair<int, string>(num3, string3));
	map1.insert(std::pair<int, string>(num4, string4));

	PrintNumAndString *ns = new PrintNumAndString;
	vector<string> elems = ns->ProcessMap(map1);
	
	if (elems.empty())
	{
		return;
	}
	for (std::vector<string>::iterator elems_it = elems.begin(); elems_it != elems.end(); ++elems_it)
	{
		cout << *elems_it << endl;
	}
}