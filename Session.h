#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "Command_Queue.h"
#include "File.h"
#include "PBM_File.h"
#include "PGM_File.h"
#include <string>

class Session
{
	int session_number;
	std::vector<File*> files_in_session;
	Command_Queue photo_commands;
	std::vector<std::string> file_name;
	bool has_saved_since_last_edit;

public:

	Command make_photo_command(std::string command) {

		has_saved_since_last_edit = false;

		photo_commands.enqueue(Command(command));

	}

	void add_file(File* file) {

		files_in_session.push_back(file);
		return;
	}

	void add_file_name(std::string file_name) {

		file_name = file_name;

	}

	void open_file(File* file, std::string file_name) {

		add_file(file);
		add_file_name(file_name);

	}

	void close_file() {

		session_number = 0;
		files_in_session.clear();
		photo_commands.clear();
		file_name.clear();
		has_saved_since_last_edit = true;

	}

	void save() {

		has_saved_since_last_edit = true;

	}

	void save_as(std::string new_file_name) {

		file_name.push_back(new_file_name);
		has_saved_since_last_edit = true;

	}

	void grayscale() {

		make_photo_command("greyscale");

	}

	void monochrome() {

		make_photo_command("monochrome");

	}

	void negative() {

		make_photo_command("negative");

	}

	void rotate() {

		make_photo_command("rotate");

	}

	void undo() {

		photo_commands.dequeue();

	}

	int get_session_number() { return session_number; }

	void save_files(Command command) {

		for (int i = 0; i < files_in_session.size(); i++) {

			if (Command(command) == Command("grayscale")) files_in_session[i]->grayscale();
			else if (Command(command) == Command("monochrome")) files_in_session[i]->monochrome();
			else if (Command(command) == Command("negative")) files_in_session[i]->negative();
			else if (Command(command) == Command("rotate")) files_in_session[i]->rotate(command.additional_command);

		}

	}

	void save_all() {

		while (!photo_commands.empty()) {

			save_files(photo_commands.front());
			photo_commands.dequeue();

		}

		return;

	}

};

