// Magic Ball Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Node.cpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//Node and switch structure for the first game layout.
struct gameLayout
{
	Node* output1 = new Node();
	Node* output2 = new Node();
	Switch* switch3 = new Switch(output1, output2);
	Switch* switch2 = new Switch(switch3, output2);
	Switch* switch1 = new Switch(output1, switch3);
	Node* inputL = new Node(switch1);
	Node* inputR = new Node(switch2);
}layout1; //End of gameLayout

//Node and switch structure for the second game layout.
struct gameLayout2
{
	Node* output0 = new Node();
	Node* output1 = new Node();
	Node* output2 = new Node();
	Node* output3 = new Node();
	Switch* switch6 = new Switch(output2, output1); //Left and Right pointer values swapped.
	Switch* switch5 = new Switch(output3, switch6); //Left and Right pointer values swapped.
	Switch* switch4 = new Switch(switch6, output0); //Left and Right pointer values swapped.
	Switch* switch3 = new Switch(switch4, switch5);
	Switch* switch2 = new Switch(output0, switch4);
	Switch* switch1 = new Switch(switch2, switch3);
	Node* input = new Node(switch1);

	//Attepted code for fliping switches.
		//Node* switch4 = switch4->goNext();
		//Node* switch5 = switch5->goNext();
		//Node* switch6 = switch6->goNext();
}layout2; //End of gameLayout2

//Node and switch structure for the mega game layout.
struct gameLayout3
{
	Node* output1 = new Node();
	Node* output2 = new Node();
	Node* output3 = new Node();
	Node* output4 = new Node();
	Node* output5 = new Node();
	Switch* switch23 = new Switch(output4, output5);
	Switch* switch22 = new Switch(output3, output4);
	Switch* switch21 = new Switch(switch22, output4);
	Switch* switch20 = new Switch(output1, switch22);
	Switch* switch19 = new Switch(output2, output3);
	Switch* switch18 = new Switch(output1, output2);
	Switch* switch17 = new Switch(switch21, switch23);
	Switch* switch16 = new Switch(output2, switch19);
	Switch* switch15 = new Switch(switch20, switch21);
	Switch* switch14 = new Switch(switch17, switch23);
	Switch* switch13 = new Switch(switch19, switch15);
	Switch* switch12 = new Switch(switch15, switch17);
	Switch* switch11 = new Switch(switch16, switch13);
	Switch* switch10 = new Switch(switch18, switch16);
	Switch* switch9 = new Switch(switch12, switch14);
	Switch* switch8 = new Switch(switch13, switch12);
	Switch* switch7 = new Switch(switch11, switch13);
	Switch* switch6 = new Switch(switch10, switch11);
	Switch* switch5 = new Switch(switch9, output5);
	Switch* switch4 = new Switch(switch8, switch9);
	Switch* switch3 = new Switch(switch7, switch8);
	Switch* switch2 = new Switch(switch6, switch7);
	Switch* switch1 = new Switch(output1, switch6);
	Node* input1 = new Node(switch1);
	Node* input2 = new Node(switch2);
	Node* input3 = new Node(switch3);
	Node* input4 = new Node(switch4);
	Node* input5 = new Node(switch5);
}layout3; //End of gameLayout3

//Node pointer declared as ptr.
Node* ptr = nullptr;

//Interactive game mode source code.
void interactive()
{
	char userinp;
	//User asked for input. 	
	cout << "Enter an input of 1 or 2, enter 0 to finish: ";
	cin >> userinp;
	//User input compared for marble input.
	while (userinp != '0') {
		if (userinp == '1') { ptr = layout1.inputL; }
		else if (userinp == '2') { ptr = layout1.inputR; }
		//Outpout checked and displayed.
		while (ptr != nullptr)
		{
			if (ptr == layout1.output1)
				cout << "output 1" << endl;
			if (ptr == layout1.output2)
				cout << "output 2" << endl;
			ptr = ptr->goNext();
		}
		//User askes for another input.
		cout << "Enter annother input of 1 or 2, enter 0 to finish: ";
		cin >> userinp;
	}
}//End of interactive()

//Buffered game mode source code.
void buffered()
{	//String declared as str.
	string str;	//User asked for input of string.
	cout << "Enter a string of inputs of 1 or 2: ";
	cin >> str;	//String size checked.
	int count = str.size();
	//Run while less than string size.
	for (int i = 0; i < count; i++)
	{	//String input compared for marble input.
		if (str[i] == '1') { ptr = layout1.inputL; }
		else if (str[i] == '2') { ptr = layout1.inputR; }
		//Outpout checked and displayed.
			while (ptr != nullptr)
			{
				if (ptr == layout1.output1)
					cout << "output 1" << endl;
				if (ptr == layout1.output2)
					cout << "output 2" << endl;
				ptr = ptr->goNext();
			}
	}
}//End of buffered()

//File based game mode source code.
void fileBased()
{	//String declared as str.
	string str; //File to be used set.
	ifstream myfile("inputs.txt");
	//Try to open file if possible.
	if (myfile.is_open())
	{	//Read first line of file and fill string with it.
		while (myfile){ getline(myfile, str); }
		//String size checked.
		int count = str.size();
		//Run while less than string size.
		for (int i = 0; i < count; i++)
		{	//String input compared for marble input.
			if (str[i] == '1') { ptr = layout1.inputL; }
			else if (str[i] == '2') { ptr = layout1.inputR; }
			//Outpout checked and displayed.
			while (ptr != nullptr)
			{
				if (ptr == layout1.output1)
					cout << "output 1" << endl;
				if (ptr == layout1.output2)
					cout << "output 2" << endl;
				ptr = ptr->goNext();
			}
		}
		//Close file at end.
		myfile.close();
	}
	//Error if file cannot be opened.
	else { cout << "Unable to open file" << endl; }
}//End of fileBased()

//Alternate game mode source code.
void altGame()
{	//Run through 5 times.
	for (int i = 0; i < 5; i++)
	{	//Pass marble through input each loop.
		ptr = layout2.input;
		//Outpout checked and displayed.
		while (ptr != nullptr)
		{
			if (ptr == layout2.output0)
				cout << "output 0" << endl;
			if (ptr == layout2.output1)
				cout << "output 1" << endl;
			if (ptr == layout2.output2)
				cout << "output 2" << endl;
			if (ptr == layout2.output3)
				cout << "output 3" << endl;
			ptr = ptr->goNext();
		}
	}
}//End of altGame()

//Mega game mode source code.
void megaGame()
{	//String declared as str and filled with "1234554321".
	string str = "1234554321";
	//String size checked.
	int count = str.size();
	//Run while less than string size.
	for (int i = 0; i < count; i++)
	{
		if (str[i] == '1') { ptr = layout3.input1; }
		else if (str[i] == '2') { ptr = layout3.input2; }
		else if (str[i] == '3') { ptr = layout3.input3; }
		else if (str[i] == '4') { ptr = layout3.input4; }
		else if (str[i] == '5') { ptr = layout3.input5; }
		//Outpout checked and displayed.
		while (ptr != nullptr)
		{	//String input compared for marble input.
			if (ptr == layout3.output1)
				cout << "output 1" << endl;
			if (ptr == layout3.output2)
				cout << "output 2" << endl;
			if (ptr == layout3.output3)
				cout << "output 3" << endl;
			if (ptr == layout3.output4)
				cout << "output 4" << endl;
			if (ptr == layout3.output5)
				cout << "output 5" << endl;
			ptr = ptr->goNext();
		}
	}
}//End of megaGame()

//Main source code.
int main()
{	//Reset variable and game mode varibles declared.
	char reset = 'R';
	int gameMode;
	//Run through at least once and ask the user for input to choose game mode.
	do{
		cout << "To run the interactive game and get an output after each input press 1" << endl;
		cout << "To run the buffered game and input a string to get a all of the outputs press 2" << endl;
		cout << "To run from the inputs text file press 3" << endl;
		cout << "To run alternate game layout press 4" << endl;
		cout << "To run the mega game layout press 5" << endl;
		cin >> gameMode;
		//Run game mode based on users input.
		if (gameMode == 1) { interactive(); }
		if (gameMode == 2) { buffered(); }
		if (gameMode == 3) { fileBased(); }
		if (gameMode == 4) { altGame(); }
		if (gameMode == 5) { megaGame(); }
		//Ask user if they wish to reset.
		cout << "Press R to reset or any key to finish: ";
		cin >> reset;
		//Reset the game if user presses 'r' or 'R'.
	} while (reset == 'r' || reset == 'R');
	//End program if user presse anything else.
	//Ask for input to prevent program from instantley closing.
	cin.get();
	return 0;
}//End of main()