//Aiden Tjahjono
//9/30/2023
#include "helpers.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
using namespace std;

void parseLine(string line);
void readFile(string filename);
bool isBlank(string line);

int main() {
    readFile("pp1_input.txt");
    return 0;
}


void parseLine(string line) {
    ofstream file("pp1_output.txt", ios::app);

    size_t start = 0;
    size_t end = line.find(" ");
    string opName = line.substr(start, end - start);

    if (opName != "ADD" && opName != "SUB" && opName != "AND" && opName != "OR" &&
        opName != "XOR" && opName != "NOT" && opName != "LSL" && opName != "LSR" &&
        opName != "EQ" && opName != "LT" && opName != "GT") {
        file << line << ": " << "Error: Invalid operation name." << endl;
        return;
    }

    uint32_t first, second;
    //cout << "Debug: Operation = " << opName << endl;
    start = end + 1;
    end = line.find(" ", start);
    first = static_cast<uint32_t>(stoul(line.substr(start, end - start), nullptr, 0));
    //cout << "Debug: First operand = " << first << endl;
    start = end + 1;
    end = line.find(" ", start);

    if (opName == "NOT" && line.substr(start, end - start) != opName) {
        file << line << ": " << "Error: NOT operation requires only one operand." << endl;
        return;
    } else if (opName == "NOT") {
        file << line << ": " << printOpResult(opName, first, 0) << endl;
        return;
    }

    if (opName != "NOT" && (line.substr(start, end - start) == opName || isBlank(line.substr(start, end - start)))) {
        file << line << ": " << "Error: " << opName << " operation requires two operands." << endl;
        return;
    } else if (opName != "NOT") {
        if (end != string::npos && !isBlank(line.substr(end))) {
            file << line << ": " << "Error: Too many operands." << endl;
            return;
        }

        if (line.substr(start, 1) == "-" && (opName == "LSL" || opName == "LSR")) {
            file << line << ": " << "Error: Shifts must be non-negative." << endl;
            return;
        } 
        //cout << "Debug: Second operand = " << line.substr(start, end - start) << endl;
        second = static_cast<uint32_t>(stoul(line.substr(start, end - start), nullptr, 0));
        if ((opName == "LSL" || opName == "LSR") && (second > 31)) {
            file << line << ": " << "Error: Shift amount must be between 0 and 31." << endl;
            return;
        }
        if (opName == "GT" || opName == "LT" || opName == "EQ") {
            file << line << ": " << printOpResult(opName, first, second) << endl;
        } else {
            try {
                stoi(printOpResult(opName, first, second));
            } catch (invalid_argument&) {
                file << line << ": " << printOpResult(opName, first, second) << endl;
                return;
            } catch (out_of_range&) {
                file << line << ": " << "Error: Result out of range." << endl;
                return;
            }
            file << line << ": " << hex << "0x" << stoi(printOpResult(opName, first, second)) << endl;
        }
    }
    //cout << stoi(printOpResult(opName, first, second)) << endl;
    file.close();
}

void readFile(string filename) {
    ofstream ofile("pp1_output.txt");
    ofile.close(); // Clear the file at the start

    ifstream file(filename);
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            //cout << "Processing line: " << line << endl; // Debugging output
            parseLine(line);
        }
        file.close();
    } else {
        cout << "Error: Could not open file." << endl;
    }
}

bool isBlank(string line) {
    for (char c : line) {
        if (!isspace(c)) {
            return false;
        }
    }
    return true;
}