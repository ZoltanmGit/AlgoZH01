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
	std::cout << "____" << std::endl;
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
	while (iter2 != arglist2)
	{
		bool bStop = false;
		E2* iter1 = arglist1->_next;
		while (iter1 != arglist1 && !bStop)
		{
			if (iter2->_key.code == iter1->_key.code) //If the exam was retaken
			{
				bStop = true;
				E2* p = iter2;
				iter2 = iter2->_next;
				iter2->out(iter2->_prev);
				p->follow(iter1, p);
				iter1->out(iter1);
			}
			else if ((iter2->_key.code > iter1->_key.code && iter2->_key.code < iter1->_next->_key.code) || (iter2->_key.code > iter1->_key.code&& iter1->_next == arglist1))
			{
				bStop = true;
				E2* p = iter2;
				iter2 = iter2->_next;
				iter2->out(iter2->_prev);
				p->follow(iter1, p);
			}
			iter1 = iter1->_next;
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
	E2* FEJ1 = new E2();
	E2* FEJ2 = new E2();
	loadFromFile("input01.txt", FEJ1, FEJ2);
	printLists(FEJ1, FEJ2);
	std::cout << "Applying algo....." << std::endl;
	applyAlgorithm(FEJ1, FEJ2);
	printLists(FEJ1, FEJ2);
}