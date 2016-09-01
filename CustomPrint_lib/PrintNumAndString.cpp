#include "stdafx.h"
#include "PrintNumAndString.h"
#include <string>

// Constructor
PrintNumAndString::PrintNumAndString()
{
}

// Destructor
PrintNumAndString::~PrintNumAndString()
{
}

// Checks if the numbers from 1 to 100 are divisible by the elements in map
// Returns a vector with the replaced string if divisble
vector<string> PrintNumAndString::ProcessMap(map<int, string> elemMap)
{
	vector<string> elemsVector;
	for (int i = 1; i <= 100; i++)
	{
		int fl = 0;
		string toPrint;
		for (std::map<int, string>::iterator elemMap_it = elemMap.begin(); elemMap_it != elemMap.end(); elemMap_it++)
		{
			if (elemMap_it->first == 0) //mod 0 is undefined
			{
				return {};
			}
			else if (i % elemMap_it->first == 0)
			{
				toPrint = toPrint + elemMap_it->second;
				fl = 1;
			}
		}
		if (fl == 1)
		{
			elemsVector.push_back(toPrint.c_str());
		}
		else if (fl == 0)
		{
			elemsVector.push_back(std::to_string(i));
		}
	}
	return elemsVector;
}