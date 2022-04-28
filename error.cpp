//
// Created by valus on 27.04.2022.
//

#include "error.h"

invalidId::invalidId(const std::string &arg) : invalidStat{arg} {}

invalidStat::invalidStat(const std::string &arg) : runtime_error{arg} {}

invalidInput::invalidInput(const std::string &arg) : invalidStat{arg} {}
