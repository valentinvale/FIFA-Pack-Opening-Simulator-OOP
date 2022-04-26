//
// Created by valus on 27.04.2022.
//

#ifndef OOP_ERROR_H
#define OOP_ERROR_H


#include <stdexcept>

class invalidStat : public std::runtime_error{
public:
    explicit invalidStat(const std::string& arg);

};

class invalidId : public invalidStat{
public:
    explicit invalidId(const std::string& arg);
};

//class invalidAmount : public invalidStat{
//public:
//    explicit invalidAmount(const std::string& arg) : invalidStat{arg} {};
//};


#endif //OOP_ERROR_H
