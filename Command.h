#pragma once
#include <string>
#include <iostream>

const std::string main_commands[] = { "grayscale", "monochrome", "negative", "rotate", };
const std::string addons_to_main_command[] = { "left", "right"};
const int amount_of_commands = 4;
const int amount_of_addon_commands = 2;

class Command{

	std::string command;
	std::string additional_command;

public:

	Command();
	Command(std::string command);
	Command(std::string command, std::string addon_command);

	bool is_valid_command(std::string command);
	bool is_valid_command(std::string command, std::string addon_command);

};

