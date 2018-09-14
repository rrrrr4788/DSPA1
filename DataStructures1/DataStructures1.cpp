
#include "DataStructures1.h"

using namespace std;

int list::getSize() {
	int number = 0;
	node* temp = head;
	while (temp != NULL) {
		temp = temp->next;
		number++;
	}
	return number;
}

void list::firstNode(string textToInsert) {
	node *temp = new node;

	temp->name = textToInsert;

	temp->next = head;

	head = temp;
}

void list::insertEnd(string textToInsert) {//insert given text at the end of the document
	/*if (head!=NULL) {//list is not empty
		node *temp = head;
		node *tempInsert = new node;
		tempInsert->name = textToInsert;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = tempInsert;
		cout << temp->next->name << endl;
		node *temp = head;
		int pos = 1;
		while (temp->next != NULL) {
			temp = temp->next;
			pos++;
		}
		this->insert(textToInsert, pos);
	}
	else {//list is empty
		node *temp = new node;
		temp->name = textToInsert;
		temp->next = head;
		head = temp;*/
	if (head == NULL) {
		this->firstNode(textToInsert);
	}
	else{
		node *temp = head;
		node *prev = new node;
		prev->next = head;

		/*while (temp != NULL) {
			prev = temp;
			temp = temp->next;
			if (temp->next == NULL) {
				break;
			}
		}*/
		/*for (int i = 0; i < this->getSize(); i++) {
			prev = temp;
			if(temp->next!=nullptr)
			temp = temp->next;
		}*/
		while (temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp = temp->next;
		node *temp3 = new node;
		temp3 = temp;
		temp3->name = textToInsert;
	}
}
void list::insert(string textToInsert, int indexNum) {//insert given text at the line indicated by index given
	/*node *curr = head;
	node *prev = new node;
	node *tempInsert = new node;
	tempInsert->name = textToInsert;
	prev->next = curr;
	int counter = 0;
	while (counter < indexNum) {
		counter++;
		prev = curr;
		curr = curr->next;
	}
	prev->next = tempInsert;
	tempInsert->next = curr;*/
	node* temp = head;
	node* temp2 = head;
	temp2->name = textToInsert;
	int size = 0;

	while (temp != NULL) {
		temp = temp->next;
		size++;
	}
	temp = head;

	if (indexNum > size) {
		returnError();
	}
	else {
		if (indexNum == 0) {
			/*temp2->next = head;
			head = temp2;
			temp = head;
			return temp;*/
			this->insertEnd(textToInsert);
		}
		else {
			for (int i = 0; i < indexNum - 1; i++) {
				temp = temp->next;
			}
			temp2->next = temp->next;
			temp->next = temp2;
		}
	}
}
void list::deletion(int indexNum) {//delete line at index given
	node* curr = new node;
	node* prev = new node;
	curr = head;
	prev->next = head;
	int size = 0;

	while (curr != NULL) {
		curr = curr->next;
		size++;
	}
	curr = head;

	/*for (int i = 0; i < size; i++) {
		if ((curr->name == indexNum) && (curr != head)) {
			curr = curr->next;
			prev->next = curr;
		}
		else if ((curr->name == indexNum) && (curr == head)) {
			head = curr->next;
			curr = curr->next;
			prev->next = curr;
		}
		else {
			prev = curr;
			curr = curr->next;
		}
	}*/
	for (int i = 0; i < indexNum; i++) {
		prev = curr;
		curr = curr->next;
	}
	if (curr != head) {
		curr = curr->next;
		prev->next = curr;
	}
	else {
		head = curr->next;
		curr = curr->next;
		prev->next = curr;
	}
}
void list::edit(string textToEdit, int indexNum) {//replace the line at the index given with the given text
	int counter = 0;
	node *temp = head;
	while (counter < indexNum) {
		temp = temp->next;
		counter++;
	}
	temp->name = textToEdit;
}
void list::print() {//print the entire document, with line numbers
	node *temp = new node;
	temp = head;
	int counter = 1;
	int max = this->getSize();
	for (int i = 0; i< max;i++){
		cout << counter << ". " << temp->name << endl;
		temp = temp->next;
		counter++;
	}
}
void list::search(int indexNum) {//print the line number and line that contains the given text.  print "not found" if it is not found
	int counter = 0;//we get the size of linked list here first
	node* temp = head;
	while (temp != NULL) {
		counter++;
		temp = temp->next;
	}

	if (counter < indexNum) {//if the index exceeds then print "not found"
		cout << "Not found." << endl;
	}
	else {
		bool flag = true;
		counter = 1;
		while (temp != NULL) {
			if (indexNum == counter) {
				cout << counter << ". " << temp->name << endl;
				flag = false;
			}
			counter++;
			temp = temp->next;
		}
	}
}

void list::searchTerms(string textToSearch) {

}


void returnError() {
	cout << "Check your input." << endl;
}

int getNextNum(string input)
{
	int number = 0;

	istringstream iss(input);
	string word;
	while (iss >> word) {
		if (isNumber(word)) {
			number = stoi(word);
			return number;
		}
		else {
			return -1;
		}
	}

	return number;
}

string getRest(string input, int size)
{
	string rest = "";

	rest = input.substr(size + 1, input.length() - 1);

	return rest;
}

bool isNumber(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (!isdigit(str.at(i))) {
			return false;
		}
	}
	return true;
}

string truncateIt(string str, int choice) {
	string stuff = "";
	int i = 0;

	stuff = str.substr(choice, str.length()-choice);
	while ((!isalpha(stuff.at(i)))&&(i<stuff.length())) {
		i++;
	}
	cout << stuff << endl;
	system("pause");
	stuff = stuff.substr(i,str.length()-i-1);
	cout << stuff << endl;
	return stuff;
}

int main() {

	int index = 0;
	string textInput = "";
	bool quit = false;
	string text;
	list linkedlist;

	while (quit == false) {
		getline(cin, textInput);

		string choice = "";
		int i = 0;
		
		int lengthTextInput = textInput.length();
		while (/*(textInput.at(i) != ' ')&&*/(i!= lengthTextInput)) {
			if (textInput.at(i) == ' ') {
				break;
			}
			choice += textInput.at(i);
			i++;
		}
		int lengthChoice = choice.length();


		if (choice == "insertEnd") {

			text = getRest(textInput, lengthChoice);//get the text after the choice word
			linkedlist.insertEnd(text);
			//insert the whole text
		}
		else if (choice == "insert") {

			text = getRest(textInput, lengthChoice);//get the text after the choice word
			index = getNextNum(text);//get the index
			
			if (index != -1) {
				text = truncateIt(textInput,lengthChoice);
				linkedlist.insert(text, index);
			}
			else {
				returnError();
			}
			//store the next num and insert the rest of the text
		}
		else if (choice == "delete") {
			//store the next num and return error if there is anything else
			//then delete selected text
		}
		else if (choice == "edit") {
			//store the next num and the rest of the text
			//then replace the designated text with the rest of the text
			text = getRest(textInput, lengthChoice);//get the text after the choice word
		}
		else if (choice == "print") {
			//return error if there is anything else
			if (lengthChoice != lengthTextInput)
				returnError();
			else
				linkedlist.print();
		}
		else if (choice == "search") {
			//store the next num or any text and return error if there is anything else
			//FIXME: split the search function into 2 according to the next term (num or word). 
		}
		else if (choice == "quit") {
			if (lengthChoice!=lengthTextInput)
				returnError();
			else
				quit = true;
			//return error if there is anything else
		}
		else {
			returnError();
			//return error
		}
	}
	system("pause");
	return 0;
}