/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Luis Figueroa
 */

//could not use the std_lib_facilities.h" in this exercise because my clang compiler hated it
//so I had to take a different approach

#include <iostream>
#include <string>
#include <vector>

//class definition
class Name_value
{
public:

    int score;
	std::string name;

	Name_value(); //class declaration
	Name_value(std::string& nam, int sco)
		: name(nam), score(sco)
	{
	
	}

    //boolean so we can use sort
	bool operator< (const Name_value& right) const 
	{
		return name < right.name; 
	}
};