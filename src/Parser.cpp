//
// Created by Valerie Fan on 2024/12/21.
//

#include "Parser.h"

Parser::Parser() {
    this->code = new Code();
}


std::string Parser::parseInst(const std::string& inst) const {
    if (inst.find('@') != std::string::npos) {
        const std::string tempInst = inst.substr(1, inst.size() - 1);
        return parseAInst(tempInst);
    }
    return parseCInst(inst);
}

std::string Parser::parseAInst(const std::string& inst) const {
    if (inst.find_first_not_of("0123456789") == std::string::npos) {
        return prefixA + std::bitset<15>(stoi(inst)).to_string();
    }
    const uint16_t addr = symbolTable.getAddress(inst);
    return prefixA + std::bitset<15>(addr).to_string();
}

std::string Parser::parseCInst(const std::string& inst) const {
    std::string::size_type idxe = inst.find('=');
    std::string::size_type idxsc = inst.find(';');

    const std::string instDest = (idxe == std::string::npos) ? "null" : inst.substr(0, idxe);
    const std::string instComp = inst.substr(idxe + 1, idxsc - idxe - 1);
    const std::string instJump = (idxsc == std::string::npos) ? "null" : inst.substr(idxsc + 1, inst.size() - 1);

    return prefixC + code->comp(instComp) + code->dest(instDest) + code->jump(instJump);
}
