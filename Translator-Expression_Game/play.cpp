#include <iostream>
#include <string>
#include <algorithm>
#include <map>

#include "storetail.h"
#include "RepositoryForExpressions.h"

bool backInMenu = false;

int score{ 0 };

int getExpressionBG(int &value) // bulgarian to english
{
	int counter{ 0 };
	std::string englishExpresion;
	std::map<std::string, std::string>::iterator it;
	std::cout << "Your score: " << score << '\n';
	for (it = myMap.begin(); it != myMap.end(); it++)
	{
		while (value == counter)
		{
			std::cout <<">> "<< it->first<<" <<" <<'\n'<< " Enter on english: ";
			std::getline(std::cin, englishExpresion);
			if (englishExpresion=="exit")
			{
				backInMenu = true;
				return 1;
			}
			if (it->second == englishExpresion)
			{
				std::cout << "OK!!! Your answer is correct ^_^ ";
				score += 1;
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
		std::cout << "Your score: " << score << '\n';
		while (value == counter)
		{
			std::cout << ">> " << it->second << " <<" <<'\n'<< " Enter on bulgarian: ";
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

int getRandomNumber(tail<int> &lastTen)
{
	int rangeRandom = myMap.size();
	int somethingValue = rand() % rangeRandom;
	while (true)
	{
		if (lastTen.find(somethingValue) )
		{
			
		}
		else
		{
			lastTen.push_front(somethingValue);
			break;
		}
		somethingValue = rand() % rangeRandom;
	}
	return somethingValue;
}

int play(int &mode)
{
	tail<int> lastTen; // store last 10 numbers from srand, in order not repeat expresions 
	int value{0};

	while (1)
	{
		switch (mode)
		{
		case 1:
			backInMenu = false;
			system("cls");
			value = getRandomNumber(lastTen);
			getExpressionBG(value);
			break;
		case 2:
			backInMenu = false;
			system("cls");
			value = getRandomNumber(lastTen);
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
