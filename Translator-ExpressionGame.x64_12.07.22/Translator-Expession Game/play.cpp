#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <chrono>
#include <random>


#include "storetail.h"
#include "RepositoryForExpressions.h"

bool backInMenu = false;


int score{ 0 };
int number_of_expresion{ 1 };

int getExpressionBG(int& value) // bulgarian to english
{
	int counter{ 0 };
	std::string englishExpresion;
	std::map<std::string, std::string>::iterator it;
	std::cout << "Number of expresions since begin: " << number_of_expresion << '\n';
	std::cout << '\n';
	for (it = myMap.begin(); it != myMap.end(); it++)
	{
		while (value == counter)
		{
			std::cout << "Your score: " << score << '\n';
			std::cout << ">> " << it->first << " <<" << '\n' << " Enter on english: ";
			std::getline(std::cin, englishExpresion);
			if (englishExpresion == "exit")
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
				system("cls");
				std::cout << "Number of expresions since begin: " << number_of_expresion << '\n';
				std::cout << '\n';
				std::cout << "Your answer is incorrect! Tyr agine:" << '\n';
				score = 0;
				std::cout << "The correct answer is: " << it->second << '\n';
				std::cout << '\n';
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
			std::cout << ">> " << it->second << " <<" << '\n' << " Enter on bulgarian: ";
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
				std::cout << "The correct answer is: " << it->first << '\n';
			}
		}
		counter++;
	}
	return 1;
}

int getRandomNumber(tail<int>& lastTen)
{
	int size_repository = myMap.size();
	// Seed our Mersenne Twister using the
	std::mt19937 mt{ static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count()) };
	// Create a reusable random number generator that generates uniform numbers between 0 and 3
	std::uniform_int_distribution<> die6{ 0, size_repository }; // for C++14, use std::uniform_int_distribution<> die6{ 0, 10 };
	int number{ static_cast<int>(die6(mt)) };
	while (true)
	{
		if (lastTen.find(number))
		{
			// do nothing
		}
		else
		{
			lastTen.push_front(number);
			break;
		}
		std::uniform_int_distribution<> die6{ 0, size_repository }; // for C++14, use std::uniform_int_distribution<> die6{ 0, 10 };
		number = static_cast<int>(die6(mt));
	}
	return number;
}

int play(int& mode)
{
	tail<int> lastTen;
	int value{ 0 };

	while (1)
	{
		switch (mode)
		{
		case 1:
			backInMenu = false;
			system("cls");
			value = getRandomNumber(lastTen);
			getExpressionBG(value);
			number_of_expresion++;
			break;
		case 2:
			backInMenu = false;
			system("cls");
			value = getRandomNumber(lastTen);
			getExpressionENG(value);
			number_of_expresion++;
			break;
		}
		if (backInMenu)
		{
			break;
		}
	}
	return 0;
}