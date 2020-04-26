//Assignment written by Márton Zoltán for ELTE's Algoritmusok és Adatszerkezetek I.
#include <iostream>
#include <fstream>
#include <string>
#include "E2.h"

void printLists(E2* arglist1, E2* arglist2)
{
	E2* iterp;
	//PRINT THE 2 LISTS
	std::cout << "________Lists:________" << std::endl;
	iterp = arglist1->_next;
	while (iterp != arglist1)
	{
		std::cout << iterp->_key.code << "_" << iterp->_key.grade << std::endl;
		iterp = iterp->_next;
	}
	std::cout << "$$$$" << std::endl;
	iterp = arglist2->_next;
	while (iterp != arglist2)
	{
		std::cout << iterp->_key.code << "_" << iterp->_key.grade << std::endl;
		iterp = iterp->_next;
	}
	std::cout << "______________________" << std::endl;
}
void loadFromFile(std::string filename, E2* arglist1, E2* arglist2)
{
	std::ifstream iFile(filename);
	E2* iteri = arglist1;
	int list1size, list2size;
	iFile >> list1size;
	for (int i = 0; i < list1size; i++)
	{
		E2* Temp = new E2();
		iFile >> Temp->_key.code >> Temp->_key.grade;
		Temp->follow(iteri, Temp);
		iteri = iteri->_next;
	}
	//Initialize the FEJ2 list fron txt
	iteri = arglist2;
	iFile >> list2size;
	for (int i = 0; i < list2size; i++)
	{
		E2* Temp = new E2();
		iFile >> Temp->_key.code >> Temp->_key.grade;
		Temp->follow(iteri, Temp);
		iteri = iteri->_next;
	}
}
void applyAlgorithm(E2* arglist1, E2* arglist2)
{
	E2* iter2 = arglist2->_next;
	E2* iter1 = arglist1->_next;
	while (iter2 != arglist2)
	{
		if (iter1 == arglist1)
		{
			E2* p = iter2;
			iter2 = iter2->_next;
			iter2->out(iter2->_prev);
			p->precede(p, iter1);
		}
		bool bStop = false;
		while (iter1 != arglist1 && !bStop)
		{
			if (iter2->_key.code == iter1->_key.code) //If it needs to be updated
			{
				bStop = true;
				E2* p = iter2;
				iter2 = iter2->_next;
				iter2->out(iter2->_prev);
				p->follow(iter1, p);
				iter1 = iter1->_next;
				iter1->out(iter1->_prev);
			}
			else if ((iter2->_key.code > iter1->_key.code&& iter2->_key.code < iter1->_next->_key.code) || (iter2->_key.code > iter1->_key.code&& iter1->_next == arglist1)) //If it needs to be inserted
			{
				bStop = true;
				E2* p = iter2;
				iter2 = iter2->_next;
				iter2->out(iter2->_prev);
				p->follow(iter1, p);
				iter1 = p;
			}
			else if (iter2->_key.code < iter1->_key.code && iter1->_prev == arglist1)
			{
				bStop = true;
				E2* p = iter2;
				iter2 = iter2->_next;
				iter2->out(iter2->_prev);
				p->precede(p, iter1);
			}
			else
			{
				iter1 = iter1->_next;
			}
		}
		if (!bStop)
		{
			iter2 = iter2->_next;
		}
	}
}
int main()
{
	//Create Lists
	std::cout << "M : Manual input || F : File input" << std::endl;
	std::cout << "Choose input mode:" << std::endl;
	char userinput;
	std::cin >> userinput;
	switch (userinput)
	{
	case 'M':
	{
		E2* FEJ1 = new E2();
		E2* FEJ2 = new E2();
		userinput = ' ';
		while (userinput != 'q')
		{
			std::cout << "1 - Append to list1" << std::endl;
			std::cout << "2 - Append to list2" << std::endl;
			std::cout << "r - Run algorithm" << std::endl;
			std::cout << "p - Print lists" << std::endl;
			std::cout << "q - quit" << std::endl;
			std::cin >> userinput;
			switch (userinput)
			{
			case '1':
			{
				std::cout << "Code: " << std::endl;
				int code;
				std::cin >> code;
				std::cout << "Grade" << std::endl;
				int grade;
				std::cin >> grade;
				E2* Temp = new E2();
				Temp->_key.code = code;
				Temp->_key.grade = grade;
				Temp->precede(Temp, FEJ1);
				break;
			}
			case '2':
			{
				std::cout << "Code: " << std::endl;
				int code;
				std::cin >> code;
				std::cout << "Grade" << std::endl;
				int grade;
				std::cin >> grade;
				E2* Temp = new E2();
				Temp->_key.code = code;
				Temp->_key.grade = grade;
				Temp->precede(Temp, FEJ2);
				break;
			}
			case 'r':
			{
				applyAlgorithm(FEJ1, FEJ2);
				printLists(FEJ1, FEJ2);
				break;
			}
			case 'p':
				printLists(FEJ1, FEJ2);
				break;
			default:
				std::cout << "Undefined menu selection!" << std::endl;
				break;
			}
		}
		break;
	}
	case 'F':
	{
		//Input cases
		// Updates current elements
		E2* FEJ1 = new E2();
		E2* FEJ2 = new E2();
		std::cout << "input01 - update.txt" << std::endl;
		loadFromFile("Inputs/input01 - update.txt", FEJ1, FEJ2);
		printLists(FEJ1, FEJ2);
		applyAlgorithm(FEJ1, FEJ2);
		std::cout << "Algorithm ran..." << std::endl;
		printLists(FEJ1, FEJ2);
		// Inserts new elements without updating
		FEJ1 = new E2();
		FEJ2 = new E2();
		std::cout << "input02 - append.txt" << std::endl;
		loadFromFile("Inputs/input02 - insert.txt", FEJ1, FEJ2);
		printLists(FEJ1, FEJ2);
		applyAlgorithm(FEJ1, FEJ2);
		std::cout << "Algorithm ran..." << std::endl;
		printLists(FEJ1, FEJ2);
		// All kinds of inserts
		FEJ1 = new E2();
		FEJ2 = new E2();
		std::cout << "input03 - insertallcase.txt" << std::endl;
		loadFromFile("Inputs/input03 - insertallcase.txt", FEJ1, FEJ2);
		printLists(FEJ1, FEJ2);
		applyAlgorithm(FEJ1, FEJ2);
		std::cout << "Algorithm ran..." << std::endl;
		printLists(FEJ1, FEJ2);
		// Inserting and updating
		FEJ1 = new E2();
		FEJ2 = new E2();
		std::cout << "input04 - update and insert.txt" << std::endl;
		loadFromFile("Inputs/input04 - update and insert.txt", FEJ1, FEJ2);
		printLists(FEJ1, FEJ2);
		applyAlgorithm(FEJ1, FEJ2);
		std::cout << "Algorithm ran..." << std::endl;
		printLists(FEJ1, FEJ2);
		FEJ1 = new E2();
		FEJ2 = new E2();
		std::cout << "input05 - emptylist1.txt" << std::endl;
		loadFromFile("Inputs/input05 - emptylist1.txt", FEJ1, FEJ2);
		printLists(FEJ1, FEJ2);
		applyAlgorithm(FEJ1, FEJ2);
		std::cout << "Algorithm ran..." << std::endl;
		printLists(FEJ1, FEJ2);
		FEJ1 = new E2();
		FEJ2 = new E2();
		std::cout << "input06 - emptylist2.txt" << std::endl;
		loadFromFile("Inputs/input06 - emptylist2.txt", FEJ1, FEJ2);
		printLists(FEJ1, FEJ2);
		applyAlgorithm(FEJ1, FEJ2);
		std::cout << "Algorithm ran..." << std::endl;
		printLists(FEJ1, FEJ2);
		//BAD INPUTS
		std::cout << "|||||||||||||||BAD INPUTS|||||||||||||" << std::endl;
		FEJ1 = new E2();
		FEJ2 = new E2();
		std::cout << "badinput01 - wrongindex.txt" << std::endl;
		loadFromFile("Inputs/badinput01 - wrongindex.txt", FEJ1, FEJ2);
		printLists(FEJ1, FEJ2);
		applyAlgorithm(FEJ1, FEJ2);
		std::cout << "Algorithm ran..." << std::endl;
		printLists(FEJ1, FEJ2);
		FEJ1 = new E2();
		FEJ2 = new E2();
		std::cout << "badinput02 - notsorted.txt" << std::endl;
		loadFromFile("Inputs/badinput02 - notsorted.txt", FEJ1, FEJ2);
		printLists(FEJ1, FEJ2);
		applyAlgorithm(FEJ1, FEJ2);
		std::cout << "Algorithm ran..." << std::endl;
		printLists(FEJ1, FEJ2);
		break;
	}
	default:
		std::cout << "Undefined menu selection!" << std::endl;
		break;
	}
	//Input cases
	// Updates current elements
	/*
	loadFromFile("Inputs/input01 - update.txt", FEJ1, FEJ2);
	printLists(FEJ1, FEJ2);
	applyAlgorithm(FEJ1, FEJ2);
	std::cout << "Algorithm ran..." << std::endl;
	printLists(FEJ1, FEJ2);
	*/
	// Inserts new elements without updating
	/*
	loadFromFile("Inputs/input02 - insert.txt", FEJ1, FEJ2);
	printLists(FEJ1, FEJ2);
	applyAlgorithm(FEJ1, FEJ2);
	std::cout << "Algorithm ran..." << std::endl;
	printLists(FEJ1, FEJ2);
	*/
	// All kinds of inserts
	/*
	loadFromFile("Inputs/input03 - insertallcase.txt", FEJ1, FEJ2);
	printLists(FEJ1, FEJ2);
	applyAlgorithm(FEJ1, FEJ2);
	std::cout << "Algorithm ran..." << std::endl;
	printLists(FEJ1, FEJ2);
	*/
	// Inserting and updating
	/*
	loadFromFile("Inputs/input04 - update and insert.txt", FEJ1, FEJ2);
	printLists(FEJ1, FEJ2);
	applyAlgorithm(FEJ1, FEJ2);
	std::cout << "Algorithm ran..." << std::endl;
	printLists(FEJ1, FEJ2);
	*/
}