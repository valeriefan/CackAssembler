//
// Created by Valerie Fan on 2024/12/21.
//

#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <bitset>

#include "Code.h"
#include "SymbolTable.h"

extern SymbolTable symbolTable;

class Parser {
    Code *code;
    std::string prefixA = "0";
    std::string prefixC = "111";

    [[nodiscard]] std::string parseAInst(const std::string& inst) const;
    [[nodiscard]] std::string parseCInst(const std::string& inst) const;

public:
    explicit Parser();
    ~Parser() = default;

    [[nodiscard]] std::string parseInst(const std::string& inst) const;
};



#endif //PARSER_H
