//
// Created by Valerie Fan on 2024/12/21.
//

#ifndef CODE_H
#define CODE_H
#include <map>


class Code {
    std::map<std::string, std::string> compDict{};
    std::map<std::string, std::string> destDict{};
    std::map<std::string, std::string> jumpDict{};

public:
    Code();
    ~Code();

    std::string comp(const std::string& instComp);
    std::string dest(const std::string& instDest);
    std::string jump(const std::string& instJump);
};



#endif //CODE_H
