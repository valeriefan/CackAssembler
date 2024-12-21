//
// Created by Valerie Fan on 2024/12/21.
//

#include <string>
#include <fstream>
#include <queue>

#include "Parser.h"
#include "SymbolTable.h"

SymbolTable symbolTable;
Parser parser;

int main(int argc, char* argv[]) {

    std::queue<std::string> instructions, clean; // temporarily store the source code and the labels

    // Input file
    std::ifstream fin;
    std::string finName = std::string(argv[1]);
    fin.open(finName);

    // Output file
    std::ofstream fout;
    std::string::size_type idx = finName.find_last_of('.');
    std::string foutname = finName.substr(0, idx) + ".hack";
    fout.open(foutname);

    // Read .asm file
    std::string line;

    while (getline(fin, line)) {
        // Remove comments and empty lines
        std::string::size_type comment = line.find("//");
        std::string removedComm = line.substr(0, comment);
        if (removedComm.empty()) continue;
        // Remove spaces
        auto iter = remove(removedComm.begin(), removedComm.end(), ' ');
        removedComm.erase(iter, removedComm.end());

        instructions.push(removedComm);
    }

    // Build symbol table
    while (!instructions.empty()) {
        line = instructions.front();
        instructions.pop();
        // If this line is a label, add an entry to the symbol table
        if (line.find('(') != std::string::npos && line.find(')') != std::string::npos) {
            std::string::size_type idx_L = line.find_last_of('(');
            std::string::size_type idx_R = line.find_first_of(')');
            line = line.substr(idx_L + 1, idx_R - 1);
            symbolTable.addLabel(line);
            continue;
        }
        symbolTable.incLabelCounter();
        clean.push(line);
    }

    // Translate instructions
    while (!clean.empty()) {
        line = clean.front();
        clean.pop();
        std::string machineCode = parser.parseInst(line);
        fout << machineCode << std::endl;
    }

    fin.close();
    fout.close();
    return 0;
}