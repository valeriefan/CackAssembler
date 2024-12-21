//
// Created by Valerie Fan on 2024/12/21.
//

#include "SymbolTable.h"

SymbolTable::SymbolTable() {
    table.clear();

    table.insert(std::pair<std::string, uint16_t>("SP", 0));
    table.insert(std::pair<std::string, uint16_t>("LCL", 1));
    table.insert(std::pair<std::string, uint16_t>("ARG", 2));
    table.insert(std::pair<std::string, uint16_t>("THIS", 3));
    table.insert(std::pair<std::string, uint16_t>("THAT", 4));
    table.insert(std::pair<std::string, uint16_t>("R0", 0));
    table.insert(std::pair<std::string, uint16_t>("R1", 1));
    table.insert(std::pair<std::string, uint16_t>("R2", 2));
    table.insert(std::pair<std::string, uint16_t>("R3", 3));
    table.insert(std::pair<std::string, uint16_t>("R4", 4));
    table.insert(std::pair<std::string, uint16_t>("R5", 5));
    table.insert(std::pair<std::string, uint16_t>("R6", 6));
    table.insert(std::pair<std::string, uint16_t>("R7", 7));
    table.insert(std::pair<std::string, uint16_t>("R8", 8));
    table.insert(std::pair<std::string, uint16_t>("R9", 9));
    table.insert(std::pair<std::string, uint16_t>("R10", 10));
    table.insert(std::pair<std::string, uint16_t>("R11", 11));
    table.insert(std::pair<std::string, uint16_t>("R12", 12));
    table.insert(std::pair<std::string, uint16_t>("R13", 13));
    table.insert(std::pair<std::string, uint16_t>("R14", 14));
    table.insert(std::pair<std::string, uint16_t>("R15", 15));
    table.insert(std::pair<std::string, uint16_t>("SCREEN", 16384));
    table.insert(std::pair<std::string, uint16_t>("KBD", 24576));

    VariableCounter = 16;
}

SymbolTable::~SymbolTable() {
    table.clear();
}

int SymbolTable::incLabelCounter() {
    return ++LabelCounter;
}

void SymbolTable::addLabel(const std::string& label) {
    if (table.find(label) != table.end()) {
        throw std::runtime_error("This label has been defined.");
    } else {
        table.insert(std::pair<std::string, uint16_t>(label, LabelCounter));
    }
}

void SymbolTable::addVariable(const std::string& var) {
    if (table.find(var) == table.end()) {
        table.insert(std::pair<std::string, uint16_t>(var, VariableCounter));
        VariableCounter++;
    }
}

uint16_t SymbolTable::getAddress(const std::string& var) {
    addVariable(var);
    return table.find(var)->second;
}