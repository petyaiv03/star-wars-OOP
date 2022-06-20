#include <iostream>
#include "commandHelper.h"
#include "string.h"
#include "galaxy.h"

int main()
{
	char command[128];
	bool programExit = false;
	Galaxy galaxy;
	do {
	std::cout << "Please enter a command:\n";
	//std::cin.ignore(10000, '\n');
	std::cin >> command;//.getline(command,128);
	std::cin.ignore();
	
	if (strcmp(command, "help\0")==0)
	{
		help();
		std::cout << std::endl;
	}
	else if (strcmp(command, "exit") == 0)
	{
		//TODO: Check if the file has been saved and then exit.
		programExit = true;
	}
	else if (strcmp(command, "open") == 0)
	{
		open();
	}
	else if (strcmp(command, "save") == 0)
	{
		save();
	}
	else if (strcmp(command, "saveas") == 0)
	{
		saveas();
	}
	else if (strcmp(command, "add_planet") == 0)
	{
		add_planet_(galaxy);
	}
	else if (strcmp(command, "create_jedi") == 0)
	{
		//create_jedi();
		String planet_name;
		std::cout << "Enter the name of the planet:\n";
		planet_name.readFromConsole();

		String jedi_name;
		std::cout << "Enter the name of the Jedi:\n";
		jedi_name.readFromConsole();

		String rank;
		std::cout << "Enter the rank of the jedi:\n";
		rank.readFromConsole();
		JediRank rank_ = getRank_(rank);

		int age;
		do {
			std::cout << "Enter jedi age:\n";
			std::cin >> age;
		} while (age <= 0);

		String saber_color;
		std::cout << "Enter ligthsaber colour:\n";
		saber_color.readFromConsole();

		double strength;
		do {
			std::cout << "Enter jedi strength:\n";
			std::cin >> strength;
		} while (strength <= 0);

		galaxy.create_jedi(planet_name, jedi_name, rank_, age, saber_color, strength);
	}
	else if (strcmp(command, "remove_jedi") == 0)
	{
		//remove_jedi();
		String jedi_name;
		std::cout << "Enter the name of the Jedi:\n";
		jedi_name.readFromConsole();
		String planet_name;
		std::cout << "Enter the name of the planet:\n";
		planet_name.readFromConsole();
		galaxy.remove_jedi(jedi_name, planet_name);
	}
	else if (strcmp(command, "promote_jedi") == 0)
	{
		//promote_jedi();
		String jedi_name;
		std::cout << "Enter the name of the Jedi:\n";
		jedi_name.readFromConsole();
		double multiplier;
		std::cout << "Enter the multiplier:\n";
		do {
			std::cin >> multiplier;
		} while (multiplier <= 0);
		galaxy.promote_jedi(jedi_name, multiplier);
	}
	else if (strcmp(command, "demote_jedi") == 0)
	{
		//demote_jedi();
		String jedi_name;
		std::cout << "Enter the name of the Jedi:\n";
		jedi_name.readFromConsole();
		double multiplier;
		std::cout << "Enter the multiplier: \n";
		do {
			std::cin >> multiplier;
		} while (multiplier <= 0);
		galaxy.demote_jedi(jedi_name, multiplier);
	}
	else if (strcmp(command, "get_strongest_jedi") == 0)
	{
		//get_strongest_jedi();
		String jedi_name;
		std::cout << "Enter the name of the Jedi:\n";
		jedi_name.readFromConsole();
		galaxy.get_strongest_jedi(jedi_name);
	}
	else if (strcmp(command, "get_youngest_jedi") == 0)
	{
		//get_youngest_jedi();
		String planet_name;
		String rank;
		std::cout << "Enter the name of the planet:\n";
		planet_name.readFromConsole();
		std::cout << "Enter the rank of the jedi:\n";
		rank.readFromConsole();
		JediRank rank_ = getRank_(rank);
		galaxy.get_youngest_jedi(planet_name, rank_);
	}
	else if (strcmp(command, "get_most_used_saber_colour") == 0)
	{
		String planet_name;
		String rank;
		std::cout << "Enter the name of the planet:\n";
		planet_name.readFromConsole();
		std::cout << "Enter the rank of the jedi:\n";
		rank.readFromConsole();
		JediRank rank_ = getRank_(rank);
		galaxy.get_most_used_saber_colour(planet_name, rank_);
	}
	else if (strcmp(command, "get_most_used_saber_colour_p") == 0)
	{
		String planet_name;
		std::cout << "Enter the name of the planet:\n";
		planet_name.readFromConsole();
		galaxy.get_most_used_saber_colour_(planet_name);
	}
	else if (strcmp(command, "print_planet") == 0)
	{
		String planet_name;
		std::cout << "Enter the name of the planet:\n";
		planet_name.readFromConsole();
	}
	else if (strcmp(command, "print_jedi") == 0)
	{
		String jedi_name;
		std::cout << "Enter the name of the Jedi:\n";
		jedi_name.readFromConsole();
		galaxy.print_jedi(jedi_name);
	}
	else if (strcmp(command, "+") == 0)
	{
		String name1, name2;
		std::cout << "Enter the name of the first planet: \n";
		name1.readFromConsole();
		std::cout << "Enter the name of the second planet:\n";
		name2.readFromConsole();
		galaxy.plus(name1, name2);
		//plus();
	}
	} while (programExit != true);
	return 0;
}