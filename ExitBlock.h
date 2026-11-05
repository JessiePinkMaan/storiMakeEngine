#pragma once
#include <string>
#include <chrono>
#include <vector>
 

enum class ExitBlock{

    ReturnToParent,
    GoToScene,      
    EndGame    

};

struct BlockResult
{
    ExitBlock exitType = ExitBlock::ReturnToParent;
    std::string targetScene;
};
