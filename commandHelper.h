#include <iostream>
#include "galaxy.h"
#include "string.h"
#include "jedi.h"
#pragma once

void help()
{
	std::cout << "You have chosen the command <help>, here is a list of all the commands you can choose from: \n\n";
	std::cout << "<open> opens file\n<close> closes currently open file without saving the changes\n<save> saves the currently open file\n";
	std::cout << "<saveas> saves the currently open file in <file>\n<help> prints this information\n<exit> exits the program\n";
	std::cout << std::endl;
	std::cout << "<add_planet> adds new planet\n";
	std::cout << "<create_jedi> creates new jedi in chosen planet\n";
	std::cout << "<remove_jedi> removes a jedi from chosen planet\n";
	std::cout << "<promote_jedi> promotes jedi by rank and strength\n";
	std::cout << "<demote_jedi> demotes jedi by rank and strength\n";
	std::cout << "<get_strongest_jedi> prints the strongest jedi on chosen planet\n";
	std::cout << "<get_youngest_jedi> prints the youngest jedi living on chosen planet with chosen rank\n";
	std::cout << "<get_most_used_saber_colour> prints most used saber colour on chosen planet of chosen rank\n";
	std::cout << "<get_most_used_saber_colour_p> prints most used saber colour on a planet that is used by at least 1 GRAND_MASTER\n";
	std::cout << "<print_planet> prints planet name + jedi that live in it in order lowest to highest rank\n";
	std::cout << "<print_jedi> prints jedi info the planet he/she lives in\n";
	std::cout << "<+> prints all the jedi in alphabetical order that live on the 2 chosen planets\n";
}


void open(const Galaxy& galaxy)
{
	std::ofstream out;

	out.open("galaxy.bin", std::ios::binary);
	if (out)
	{
		galaxy.serializeGalaxy(out);
	}
	out.close();
}

void save(Galaxy& galaxy)
{
	std::ifstream in;

	in.open("galaxy.bin", std::ios::binary);
	if (in)
	{
		galaxy.deserializeGalaxy(in);
	}
	in.close();
}

void add_planet_(Galaxy& galaxy)
{
	String name;
	std::cout << "Enter planet name:";
	name.readFromConsole();
	std::cout << name<<std::endl;
	galaxy.add_planet(name);
	int size = galaxy.getSize();
	std::cout << std::endl << size;
}

JediRank getRank_(const String& rank)
{
	for (int i = 0; i <= (int) JediRank::GRAND_MASTER; i++)
	{
		if (strcmp(rank.str(), Jedi::JEDI_RANKS[i]) == 0)
		{
			return (JediRank) i;
		}
	}
	return JediRank::YOUNGLING;
}
void create_jedi_(Galaxy& galaxy)
{
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

	std::cin.ignore();//added after deadline
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
//
//void remove_jedi()
//{
//
//}
//
//void promote_jedi()
//{
//
//}
//
//void demote_jedi()
//{
//
//}
//
//void get_strongest_jedi()
//{
//
//}
//
//void get_youngest_jedi()
//{
//
//}
//
//void get_most_used_saber_colour()
//{
//
//}
//
//void get_most_used_saber_colour_p()
//{
//
//}
//
//void print_planet()
//{
//
//}
//
//void print_jedi()
//{
//
//}
//
//void plus()
//{
//
//}



void close(bool exit)
{
	exit = true;
}



void saveas()
{
	std::cout << "didn't have time for it sry";
}

void exit()
{
	/*if (strcmp(command.str(), "open") == 0)
	{
		open();
	}*/
}