#pragma once
#include <string>
#include "Persona.h"
#include <vector>
#include <iostream>
#include <functional>
#include "Action.h"
#include <thread> 
#include <chrono>  
#include <conio.h>
#include "Choice.h"
#include "DialogLine.h"
#include "ExitBlock.h"

class StoryBlock{
    private:
        std::vector<Persona> persona; 
        std::vector<DialogLine> selectPersona;
        std::vector<Action> actionSequence;
        std::string backgroundFoto;
        BlockResult blockResult;
  
    public:
        StoryBlock( std::vector<Persona> _persona){
            persona = _persona;
        }

        void setOfEnd(BlockResult result){
            blockResult = result;

        }
    
        const BlockResult& GetEndOfBlock() const{
            return blockResult;

        }


    const std::vector<DialogLine>& GetSelectPersona() const{
        return selectPersona;

    }

    const std::vector<Action>& GetActionSequence() const{
        return actionSequence;

    }
    
    void AddChoice(std::vector<std::string> choiceSequence, std::vector<StoryBlock> _block ){
          Action action;
          action.type = ActionType::WaitForChoice;
          action.choiceSequence = choiceSequence;
          action.block = _block;
          actionSequence.push_back(action);
    }

    void GetVariantBlock(){

    }

    void timeOut(int n){
        Action action;
        action.type = ActionType::Pause;
        action.milliseconds = n;
        actionSequence.push_back(action);
    }

    void waiteForPress(){
        Action action;
        action.type = ActionType::WaitForInput;
        actionSequence.push_back(action);
    }

    void AddLine(std::string name, std::string replic, bool inLine = false, bool showName = true){
        bool found = false;
        
        for (int i = 0; i < persona.size(); i++){
            if(persona[i].GetName() == name){
                DialogLine dialogLine{persona[i]};
                dialogLine.replic = replic;
                dialogLine.inlineMode = inLine;
                dialogLine.showNames = showName;
                selectPersona.push_back(dialogLine);

                found = true;
                Action action;
                action.type = ActionType::Say;
                actionSequence.push_back(action);
                break;
            }
        }
        if(!found){
             std::cerr << "Персонаж не найден: " << name << '\n';
             return;
        }
    }   
};


