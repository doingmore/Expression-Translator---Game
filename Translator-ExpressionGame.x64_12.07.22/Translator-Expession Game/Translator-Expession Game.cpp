#include <iostream>
#include <map>
#include <string>

extern int play(int& mode);

int main()
{
	std::string action = "something";
	int actionINT{ 0 };
	int mode{ 0 };
	while (action != "exit")
	{
		std::cout << "Please choice number what you wanna do?" << '\n'
			<< "================================" << '\n'
			<< "1. For start game. Mode 1 bulgarian to english. If you desire back in menu enter *exit* " << '\n'
			<< "2. For change the input language. First back in this menu, then press number *2* ." << '\n'
			<< "3. For EXIT." << '\n';
		std::getline(std::cin, action);
		if (action == "exit")
		{
			break;
		}
		actionINT = stoi(action);
		switch (actionINT)
		{
		case 1:
			mode = 1;
			play(mode);
			break;
		case 2:
			mode = 2;
			play(mode);
			break;
		case 3:
			std::cout << "Bye Bye! :)" << '\n';
			action = "exit";
			break;
		default:
			std::cout << " ERROR! Your choice is not correct, choice again.";
		}
	}
	return 0;
}