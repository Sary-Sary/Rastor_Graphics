// Rastor_Graphics_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "Command_Queue.h"
#include "File.h"
#include "PBM_File.h"
#include "PGM_File.h"
//PPM

const std::string TEXT_PBM_NUMBER = "P1";
const std::string BINARY_PBM_NUMBER = "P4";
const std::string TEXT_PGM_NUMBER = "P2";
const std::string BINARY_PGM_NUMBER = "P5";
const std::string TEXT_PPM_NUMBER = "P3";
const std::string BINARY_PPM_NUMBER = "P6";
const char COMMENT_CHARACTER = '#';

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
        if (line[i] == '1') pbm_file.push_back(1);

    }

    return new PBM_File(width, height, pbm_file);
}

File* read_text_pgm(std::fstream& file) {
    


}

File* read_binary_pgm(std::fstream& file) {



}

File* read_text_ppm(std::fstream& file) {



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
    else std::cout << "File format is invalid";

    file.close();
    return read_file;
}

int main()
{
    std::cout << "Hello World!\n";
}


