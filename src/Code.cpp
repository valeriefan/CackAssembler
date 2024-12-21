//
// Created by Valerie Fan on 2024/12/21.
//

#include "Code.h"
#include <string>

Code::Code() {
    compDict.clear();
    destDict.clear();
    jumpDict.clear();

    compDict.insert(std::pair<std::string, std::string>("0", "0101010"));
    compDict.insert(std::pair<std::string, std::string>("1", "0111111"));
    compDict.insert(std::pair<std::string, std::string>("-1", "0111010"));
    compDict.insert(std::pair<std::string, std::string>("D", "0001100"));
    compDict.insert(std::pair<std::string, std::string>("A", "0110000"));
    compDict.insert(std::pair<std::string, std::string>("!D", "0001101"));
    compDict.insert(std::pair<std::string, std::string>("!A", "0110001"));
    compDict.insert(std::pair<std::string, std::string>("-D", "0001111"));
    compDict.insert(std::pair<std::string, std::string>("-A", "0110011"));
    compDict.insert(std::pair<std::string, std::string>("D+1", "0011111"));
    compDict.insert(std::pair<std::string, std::string>("1+D", "0011111"));
    compDict.insert(std::pair<std::string, std::string>("A+1", "0110111"));
    compDict.insert(std::pair<std::string, std::string>("1+A", "0110111"));
    compDict.insert(std::pair<std::string, std::string>("D-1", "0001110"));
    compDict.insert(std::pair<std::string, std::string>("A-1", "0110010"));
    compDict.insert(std::pair<std::string, std::string>("D+A", "0000010"));
    compDict.insert(std::pair<std::string, std::string>("A+D", "0000010"));
    compDict.insert(std::pair<std::string, std::string>("D-A", "0010011"));
    compDict.insert(std::pair<std::string, std::string>("A-D", "0000111"));
    compDict.insert(std::pair<std::string, std::string>("D&A", "0000000"));
    compDict.insert(std::pair<std::string, std::string>("A&D", "0000000"));
    compDict.insert(std::pair<std::string, std::string>("D|A", "0010101"));
    compDict.insert(std::pair<std::string, std::string>("A|D", "0010101"));

    compDict.insert(std::pair<std::string, std::string>("M", "1110000"));
    compDict.insert(std::pair<std::string, std::string>("!M", "1110001"));
    compDict.insert(std::pair<std::string, std::string>("-M", "1110011"));
    compDict.insert(std::pair<std::string, std::string>("M+1", "1110111"));
    compDict.insert(std::pair<std::string, std::string>("1+M", "1110111"));
    compDict.insert(std::pair<std::string, std::string>("M-1", "1110010"));
    compDict.insert(std::pair<std::string, std::string>("D+M", "1000010"));
    compDict.insert(std::pair<std::string, std::string>("M+D", "1000010"));
    compDict.insert(std::pair<std::string, std::string>("D-M", "1010011"));
    compDict.insert(std::pair<std::string, std::string>("M-D", "1000111"));
    compDict.insert(std::pair<std::string, std::string>("D&M", "1000000"));
    compDict.insert(std::pair<std::string, std::string>("M&D", "1000000"));
    compDict.insert(std::pair<std::string, std::string>("D|M", "1010101"));
    compDict.insert(std::pair<std::string, std::string>("M|D", "1010101"));

    destDict.insert(std::pair<std::string, std::string>("null", "000"));
    destDict.insert(std::pair<std::string, std::string>("M", "001"));
    destDict.insert(std::pair<std::string, std::string>("D", "010"));
    destDict.insert(std::pair<std::string, std::string>("MD", "011"));
    destDict.insert(std::pair<std::string, std::string>("DM", "011"));
    destDict.insert(std::pair<std::string, std::string>("A", "100"));
    destDict.insert(std::pair<std::string, std::string>("AM", "101"));
    destDict.insert(std::pair<std::string, std::string>("MA", "101"));
    destDict.insert(std::pair<std::string, std::string>("AD", "110"));
    destDict.insert(std::pair<std::string, std::string>("DA", "110"));
    destDict.insert(std::pair<std::string, std::string>("AMD", "111"));
    destDict.insert(std::pair<std::string, std::string>("ADM", "111"));
    destDict.insert(std::pair<std::string, std::string>("MAD", "111"));
    destDict.insert(std::pair<std::string, std::string>("MDA", "111"));
    destDict.insert(std::pair<std::string, std::string>("DAM", "111"));
    destDict.insert(std::pair<std::string, std::string>("DMA", "111"));

    jumpDict.insert(std::pair<std::string, std::string>("null", "000"));
    jumpDict.insert(std::pair<std::string, std::string>("JGT", "001"));
    jumpDict.insert(std::pair<std::string, std::string>("JEQ", "010"));
    jumpDict.insert(std::pair<std::string, std::string>("JGE", "011"));
    jumpDict.insert(std::pair<std::string, std::string>("JLT", "100"));
    jumpDict.insert(std::pair<std::string, std::string>("JNE", "101"));
    jumpDict.insert(std::pair<std::string, std::string>("JLE", "110"));
    jumpDict.insert(std::pair<std::string, std::string>("JMP", "111"));
}

Code::~Code() {
    compDict.clear();
    destDict.clear();
    jumpDict.clear();
}

std::string Code::comp(const std::string& instComp) {
    return compDict.find(instComp)->second;
}

std::string Code::dest(const std::string& instDest) {
    return destDict.find(instDest)->second;
}

std::string Code::jump(const std::string& instJump) {
    return jumpDict.find(instJump)->second;
}


