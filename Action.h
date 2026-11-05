#pragma once
#include <string>
#include <chrono>
#include <vector>
#include "ActionType.h"

class StoryBlock;

struct Action {
    ActionType type;
    int milliseconds = 0;
    std::vector<std::string> choiceSequence = {};
     std::vector<StoryBlock> block = {};
};