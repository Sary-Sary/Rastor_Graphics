#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "Command_Queue.h"
#include "File.h"
#include "PBM_File.h"
#include "PGM_File.h"
#include <string>

const std::string all_commands[] = {"open", "close", "save", "save as", "help", "grayscale", "monochrome", "negative", "rotate", "undo", "add", "session", "switch", "collage"};
const int amount_of_all_commands = 14;

class Session
{
	int session_number;
	File* files_in_session;
	Command_Queue photo_commands;

public:

	Command make_photo_command(std::string command) {

		std::stringstream stream(command);

		std::string main_command;
		std::string addon_command;

		stream >> main_command >> addon_command;

		if (addon_command.empty()) return Command(main_command);
		return Command(main_command, addon_command);

	}

	bool valid_command(std::string command) {

		for (int i = 0; i < amount_of_all_commands; i++) {

			if (command == all_commands[i]) return true;

		}
		
		std::cout << "Invalid command\n";

		return false;

	}

	void make_new_command() {

		std::string command;
		std::getline(std::cin, command);

		std::stringstream stream(command);

		std::string main_command;
		std::string addon_command;

		stream >> main_command >> addon_command;

	}

	void session() {



	}


};

