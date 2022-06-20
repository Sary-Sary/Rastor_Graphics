#pragma once
#include <string>

const std::string main_commands[] = { "grayscale", "monochrome", "negative", "rotate", };
const std::string addons_to_main_command[] = { "left", "right"};

class Command{

	std::string valid_command;
	std::string additional_command;

public:

	Command();
	Command(std::string command);
	Command(std::string command, std::string addon_command);

};

