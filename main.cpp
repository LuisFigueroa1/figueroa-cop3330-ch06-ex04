#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include "Name_valueClass.h"

void fillList(std::vector<Name_value>&);
void printList(const std::vector<Name_value>&);
bool allDiff(const std::vector<Name_value>&);

//main function
int main(){
	// data structure holding names and scores
	std::vector<Name_value> NandS;

	// read input and store in vector
	fillList(NandS);
	 
	// check if all names unique and print
	if (allDiff(NandS))
	{
		 printList(NandS);
	}
	else  //name entered twice case
	{
		std::cout <<"Name entered twice, terminating program now.\n";
	}
	getchar();
}

//function for filling the vector lsit with names and scores
void fillList(std::vector<Name_value>& list)
{
	std::string endCmd = "NoName 0"; //command for ending the loop
	std::string newLn;

	//loop for prompting to input the names and score
	std::cout <<"Please input the name and the respective score separated by a space then\npress enter to save it to the list (input \"NoName 0\" to print the list):\n";
	//keeps asking and going as long is not the end command
	while (getline(std::cin, newLn) && newLn != endCmd) 
	{
		std::stringstream stringStreamObj(newLn);

		std::string name;
		int score = 0;

		// check input format
		if (stringStreamObj >> name >> score) //if to keep putting names
		{
			//pushes back the list element in the list
			list.push_back(Name_value(name, score)); 
		}
		else //error message
		{
			std::cout <<"Error: Please input in the format: \"Name Score\"\n";
		}
		std::cout <<"Please input the name and the respective score separated by a space then\npress enter to save it to the list (input \"NoName 0\" to print the list):\n";
	}
}

//check if all the names are different using boolean function
bool allDiff(const std::vector<Name_value>& list)
{
	//use temporal variable 
	std::vector<Name_value> t(list); 

	//we use sort 
	sort(t.begin(), t.end());

	//for loop to keep checking
	for (size_t i = 0; i < t.size() - 1; ++i)
	{
		//if it is equal retrun false for the boolean
		if (t[i].name == t[i+1].name)
		{
			return false;
		}
	}
	//if it not retrun true for the boolean
	return true;
}

//function to print the list filled
void printList(const std::vector<Name_value>& list)
{
	//for loop for printing
	for (unsigned int i = 0; i < list.size(); ++i)
	{
		//prints the name and score and \n
		std::cout << list[i].name <<" "<< list[i].score <<'\n';
	}
}