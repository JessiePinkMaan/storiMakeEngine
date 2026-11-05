#pragma once
#include <string>
#include "Persona.h"

struct DialogLine {
    Persona Char;    
    std::string replic = " ";
    bool inlineMode = false;
    bool showNames = true;
};