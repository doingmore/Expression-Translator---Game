#include <iostream>
#include <string>
#include <algorithm>
#include <map>

#include "RepositoryForExpressions.h"

bool backInMenu = false;

int getExpressionBG(int &value) // bulgarian to english
{
	int counter{ 0 };
	std::string englishExpresion;
	std::map<std::string, std::string>::iterator it;
	for (it = myMap.begin(); it != myMap.end(); it++)
	{
		while (value == counter)
		{
			std::cout <<">> "<< it->first<<" <<" << " Enter on english: ";
			std::getline(std::cin, englishExpresion);
			if (englishExpresion=="exit")
			{
				backInMenu = true;
				return 1;
			}
			if (it->second == englishExpresion)
			{
				std::cout << "OK!!! Your answer is correct ^_^ ";
				return 1;
			}
			else
			{
				std::cout << "Your answer is incorrect! Tyr agine:" << '\n';
			}
		}
		counter++;
	}
	return 1;
}

int getExpressionENG(int& value)  // english to bulgarian
{
	int counter{ 0 };
	std::string englishExpresion;
	std::map<std::string, std::string>::iterator it;
	for (it = myMap.begin(); it != myMap.end(); it++)
	{
		while (value == counter)
		{
			std::cout << ">> " << it->second << " <<" << " Enter on bulgarian: ";
			std::getline(std::cin, englishExpresion);
			if (englishExpresion == "exit")
			{
				backInMenu = true;
				return 1;
			}
			if (it->first == englishExpresion)
			{
				std::cout << "OK!!! Your answer is correct ^_^ ";
				return 1;
			}
			else
			{
				std::cout << "Your answer is incorrect! Tyr agine:" << '\n';
			}
		}
		counter++;
	}
	return 1;
}


int play(int &mode)
{
	int rangeRandom = myMap.size();
	int value = rand() % rangeRandom;
	 
	while (1)
	{
		switch (mode)
		{
		case 1:
			backInMenu = false;
			system("cls");
			value = rand() % rangeRandom;
			getExpressionBG(value);
			break;
		case 2:
			backInMenu = false;
			system("cls");
			value = rand() % rangeRandom;
			getExpressionENG(value);
			break;
		}
		if (backInMenu)
		{
			break;
		}
	}
	return 0;
}