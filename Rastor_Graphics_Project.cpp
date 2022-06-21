// Rastor_Graphics_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "Command_Queue.h"
#include "File.h"
#include "PBM_File.h"
#include "PGM_File.h"
#include "PPM_File.h"
#include "Session.h"
//PPM

const std::string TEXT_PBM_NUMBER = "P1";
const std::string BINARY_PBM_NUMBER = "P4";
const std::string TEXT_PGM_NUMBER = "P2";
const std::string BINARY_PGM_NUMBER = "P5";
const std::string TEXT_PPM_NUMBER = "P3";
const std::string BINARY_PPM_NUMBER = "P6";
const char COMMENT_CHARACTER = '#';


const std::string OPEN_COMMAND = "open";
const std::string CLOSE_COMMAND = "close";
const std::string SAVE_COMMAND = "save";
const std::string SAVE_AS_COMMAND = "save as";
const std::string HELP_COMMAND = "help";
const std::string GRAYSCALE_COMMAND = "grayscale";
const std::string MONOCHROME_COMMAND = "monochrome";
const std::string NEGATIVE_COMMAND = "negative";
const std::string ROTATE_COMMAND = "rotate";
const std::string UNDO_COMMAND = "undo";
const std::string SWITCH_COMMAND = "switch";
const std::string COLLAGE_COMMAND = "collage";
const std::string all_commands[] = { OPEN_COMMAND, CLOSE_COMMAND, SAVE_COMMAND, SAVE_AS_COMMAND, HELP_COMMAND, GRAYSCALE_COMMAND, MONOCHROME_COMMAND, NEGATIVE_COMMAND,
                                     ROTATE_COMMAND, UNDO_COMMAND, SWITCH_COMMAND, COLLAGE_COMMAND};
const int amount_of_all_commands = 14;

File* read_text_pbm(std::fstream& file) {

    std::string line;
    std::vector<int> pbm_file;
    int width;
    int height;

    getline(file, line);
    std::stringstream stream(line);

    stream >> width >> height;

    while (getline(file, line)) {

        if (line[0] != COMMENT_CHARACTER) {

            int size = line.size();

            for (int i = 0; i < size; i++) {

                if (line[i] == '0') pbm_file.push_back(0);
                if (line[i] == '1') pbm_file.push_back(1);

            }

        }

    }

    return new PBM_File(width, height, pbm_file);

}

File* read_binary_pbm(std::fstream& file) {
    
    std::string line;
    std::vector<int> pbm_file;
    int width;
    int height;

    getline(file, line);
    std::stringstream stream(line);

    stream >> width >> height;

    char* buffer = new char[width * height];
    file.read(buffer, width * height);

    line = buffer;
    delete[] buffer;

    int size = line.size();

    for (int i = 0; i < size; i++) {

        if (line[i] == '0') pbm_file.push_back(0);
        else if (line[i] == '1') pbm_file.push_back(1);

    }

    return new PBM_File(width, height, pbm_file);
}

File* read_text_pgm(std::fstream& file) {
    
    std::string line;
    std::vector<Greyscale> pbm_file;
    int width;
    int height;

    getline(file, line);
    std::stringstream stream(line);

    stream >> width >> height;

    getline(file, line);
    int max_value = line[0] - '0';

    while (getline(file, line)) {

        if (line[0] != COMMENT_CHARACTER) {

            int size = line.size();

            for (int i = 0; i < size; i++) {

                pbm_file.push_back(Greyscale(line[i] - '0', max_value));

            }

        }

    }

    return new PGM_File(width,  height, pbm_file, max_value);

}

File* read_binary_pgm(std::fstream& file) {



}

File* read_text_ppm(std::fstream& file) {

    std::string line;
    std::vector<RGB> ppm_file;
    int width;
    int height;

    getline(file, line);
    std::stringstream stream(line);

    stream >> width >> height;

    getline(file, line);
    int max_value = line[0] - '0';

    while (getline(file, line)) {

        if (line[0] != COMMENT_CHARACTER) {

            int size = line.size();

            for (int i = 0; i < size; i++) {

                std::stringstream new_stream;
                    
                int red;
                int green;
                int blue;

                new_stream >> red >> green >> blue;

                ppm_file.push_back(RGB(red, green, blue, max_value));

            }

        }

    }

    return new PPM_File(width, height, ppm_file, max_value);

}

File* read_binary_ppm(std::fstream& file) {



}

File* read_file(std::string file_name) {

    std::fstream file;
    file.open(file_name, std::ios::out);

    if (!file.is_open()) {

        throw std::runtime_error("Could not open the file.");

    }

    std::string line;
    getline(file, line);

    File* read_file;

    if (line == TEXT_PBM_NUMBER)read_file = read_text_pbm(file);
    else if (line == BINARY_PBM_NUMBER) read_file = read_binary_pbm(file);
    else if (line == TEXT_PGM_NUMBER) read_file = read_text_pgm(file);
    else if (line == BINARY_PGM_NUMBER) read_file = read_binary_pgm(file);
    else if (line == TEXT_PPM_NUMBER) read_file = read_binary_ppm(file);
    else if (line == BINARY_PPM_NUMBER) read_file = read_binary_ppm(file);
    else std::cout << "File format is invalid\n"; return nullptr;

    file.close();
    return read_file;
}

bool valid_command(std::string command) {

    for (int i = 0; i < amount_of_all_commands; i++) {

        if (command == all_commands[i]) return true;

    }

    std::cout << "Invalid command\n";

    return false;

}

void save_file(Session session) {

    

}

void help() {

    std::cout << OPEN_COMMAND << " - opens a file\n";
    std::cout << CLOSE_COMMAND << " - closes a file\n";
    std::cout << SAVE_COMMAND << " - saves an open file\n";
    std::cout << SAVE_AS_COMMAND << " - save an open file as [new_name]\n";
    std::cout << HELP_COMMAND << " - gives list of all commands\n";
    std::cout << GRAYSCALE_COMMAND << " - sets immage to grayscale\n";
    std::cout << MONOCHROME_COMMAND << " - set image to monochrome\n";
    std::cout << NEGATIVE_COMMAND << " - makes image negative\n";
    std::cout << ROTATE_COMMAND << " - rotates image to the left or right\n";
    std::cout << UNDO_COMMAND << " - undos an action\n";
    std::cout << SWITCH_COMMAND << " - switches to another session\n";
    std::cout << COLLAGE_COMMAND << " - makes a collage out of two images and saves to another file\n";

}

Session switch_session(std::vector<Session> sessions, std::string number, Session session) {

    int session_number = std::stoi(number);
    int amount_of_sessions = sessions.size();

    for (int i = 0; i < amount_of_sessions; i++) {

        if (session_number == sessions[i].get_session_number()) return sessions[i];

    }
    
    std::cout << "Invalid session number.\n";
    return session;

}

void collage(Session session, std::vector<std::string> addon_commands) {

    File* file_one = read_file(addon_commands[0]);
    File* file_two = read_file(addon_commands[1]);

    if (file_one->get_file_extension() != file_two->get_file_extension()) {

        std::cout << "Cannot make a collage out of two different files.\n";

    }

    //width/height check

    //make collage

}

Session find_command(std::string main_command, std::vector<std::string> addon_commands, Session session, std::vector<Session> sessions) {

    if (main_command == OPEN_COMMAND) {

        File* file = read_file(addon_commands[0]);
        session.open_file(file, addon_commands[0]);
        delete[] file;
    }
    else if (main_command == CLOSE_COMMAND) session.close_file();
    else if (main_command == SAVE_COMMAND) { session.save(); save_file(session); }
    else if (main_command == SAVE_AS_COMMAND) { session.save_as(addon_commands[0]); save_file(session); }
    else if (main_command == HELP_COMMAND) help();
    else if (main_command == GRAYSCALE_COMMAND) session.grayscale();
    else if (main_command == MONOCHROME_COMMAND) session.monochrome();
    else if (main_command == NEGATIVE_COMMAND) session.negative();
    else if (main_command == ROTATE_COMMAND) session.rotate();
    else if (main_command == UNDO_COMMAND) session.undo();
    else if (main_command == SWITCH_COMMAND) return switch_session(sessions, addon_commands[0], session);
    else if (main_command == COLLAGE_COMMAND) collage(session, addon_commands);

    return session;

}

void make_new_command(Session session, std::vector<Session> sessions) {

    std::cout << "> ";

    std::string command;
    std::getline(std::cin, command);

    std::stringstream stream(command);

    std::string main_command;
    std::vector<std::string> addon_commands;
    std::string buffer;

    stream >> main_command;

    while (stream >> buffer) {

        addon_commands.push_back(buffer);

    }

    find_command(main_command, addon_commands, session, sessions);

}

int main()
{



}


