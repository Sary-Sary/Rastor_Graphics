#include "Command.h"

Command::Command() {

	command = main_commands[0];

}

Command::Command(std::string command_) {

	bool valid_command = is_valid_command(command_);

	if (!valid_command) {
		std::cout << "Invalid command";
		command = "invalid";
	}

	else command = command_;
}

Command::Command(std::string command_, std::string addon_command) {

	bool valid_command = is_valid_command(command_, addon_command);

	if (!valid_command) {
		std::cout << "Invalid command";
		command = "invalid";
	}

	else command = command_; additional_command = addon_command;

}

bool Command::is_valid_command(std::string command) {

	for (int i = 0; i < amount_of_commands; i++) {

		if (main_commands[i] == command) return true;

	}

	return false;

}

bool Command::is_valid_command(std::string command, std::string addon_command) {

	if (command != main_commands[3]) return false;

	for (int i = 0; i < amount_of_addon_commands; i++) {

		if (addons_to_main_command[i] == addon_command) return true;

	}

	return false;

}