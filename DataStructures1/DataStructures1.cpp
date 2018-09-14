#include<iostream>
#include<string>
#include "DataStructures1.h"

using namespace std;



void returnError() {

}

void getNextNum()
{
}

void getRest()
{
}

int main() {

	int index = 0;
	string textinput = "";
	//char textiterator = '?';
	bool quit = false;
	string choice = "";

	cin >> textinput;

	int i = 0;
	while (textinput.at(i) != ' ') {
		choice += textinput.at(i);
		i++;
	}
	if (choice == "insertEnd") {
		//get the whole text
	}
	else if(choice == "insert"){
		//store the next num and the rest of the text
	}
	else if (choice == "delete") {
		//store the next num and return error if there is anything else
	}
	else if (choice == "edit") {
		//store the next num and the rest of the text
	}
	else if (choice == "print") {
		//return error if there is anything else
	}
	else if (choice == "search") {
		//store the next num and return error if there is anything else
	}
	else if (choice == "quit") {
		//return error if there is anything else
	}
	else {
		//return error
	}

	system("pause");
	return 0;
}