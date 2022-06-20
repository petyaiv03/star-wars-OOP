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
	
	if (strcmp(command, "help\0")==0)
	{
		help();
		std::cout << std::endl;
	}
	if (strcmp(command, "exit") == 0)
	{
		//TODO: Check if the file has been saved and then exit.
		programExit = true;
	}
	if (strcmp(command, "open") == 0)
	{
		open();
	}
	if (strcmp(command, "save") == 0)
	{
		save();
	}
	if (strcmp(command, "saveas") == 0)
	{
		saveas();
	}
	if (strcmp(command, "add_planet") == 0)
	{
		String name;
		
		std::cout << "Enter planet name:	";
		name.readFromConsole();
		std::cout << name << std::endl;
		int size = galaxy.getSize();
		std::cout << size;
	}
	if (strcmp(command, "create_jedi") == 0)
	{
		create_jedi();
	}
	if (strcmp(command, "remove_jedi") == 0)
	{
		remove_jedi();
	}
	if (strcmp(command, "promote_jedi") == 0)
	{
		promote_jedi();
	}
	if (strcmp(command, "demote_jedi") == 0)
	{
		demote_jedi();
	}
	if (strcmp(command, "get_strongest_jedi") == 0)
	{
		get_strongest_jedi();
	}
	if (strcmp(command, "get_youngest_jedi") == 0)
	{
		get_youngest_jedi();
	}
	if (strcmp(command, "get_most_used_saber_colour") == 0)
	{
		get_most_used_saber_colour();
	}
	if (strcmp(command, "get_most_used_saber_colour_p") == 0)
	{
		get_most_used_saber_colour_p();
	}
	if (strcmp(command, "print_planet") == 0)
	{
		print_planet();
	}
	if (strcmp(command, "print_jedi") == 0)
	{
		print_jedi();
	}
	if (strcmp(command, "+") == 0)
	{
		plus();
	}
	} while (programExit != true);
	return 0;
}