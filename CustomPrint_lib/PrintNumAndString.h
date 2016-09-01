#pragma once

#include<iostream>
#include<map>
#include <vector>
using namespace std;

class PrintNumAndString
{
public:
	PrintNumAndString();
	~PrintNumAndString();
	vector<string> ProcessMap(map<int, string> elemMap);
};

