//
// Created by Valerie Fan on 2024/12/21.
//

#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include <map>
#include <string>


class SymbolTable {
    std::map<std::string, uint16_t> table;
    int VariableCounter;
    int LabelCounter{};

public:
    SymbolTable();
    ~SymbolTable();
    int incLabelCounter();
    void addLabel(const std::string& label);
    void addVariable(const std::string& var);
    uint16_t getAddress(const std::string& var);
};



#endif //SYMBOLTABLE_H
