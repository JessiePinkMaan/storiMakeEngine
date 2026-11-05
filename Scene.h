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
#include "StoryBlock.h"
#include <cstddef>

class Scene{
    private:
        std::string backgroundFoto;
        std::string lastChoice;
        StoryBlock Block;
        

    public:
        Scene( StoryBlock _Block ): Block(_Block) {
         
        }

    BlockResult play(const StoryBlock* currentBlock = nullptr){
        int replicI = 0;
        const StoryBlock& nextBlock = currentBlock? *currentBlock : Block;
        
        for(std::size_t i = 0; i < nextBlock.GetActionSequence().size(); i++){
            if(nextBlock.GetActionSequence()[i].type == ActionType::Say ){
                if (nextBlock.GetSelectPersona()[replicI].inlineMode) {
                    nextBlock.GetSelectPersona()[replicI].Char.SayInline(nextBlock.GetSelectPersona()[replicI].replic, nextBlock.GetSelectPersona()[replicI].showNames);
                } else {
                    nextBlock.GetSelectPersona()[replicI].Char.Say(nextBlock.GetSelectPersona()[replicI].replic);
                }
               replicI++;
            }
            
            else if(nextBlock.GetActionSequence()[i].type == ActionType::Pause){
                std::this_thread::sleep_for(std::chrono::milliseconds(nextBlock.GetActionSequence()[i].milliseconds));
            }
            else if(nextBlock.GetActionSequence()[i].type == ActionType::WaitForInput){
                int key = getch();

                while(key != ' '){
                    key = _getch();
                }
            }
            else if(nextBlock.GetActionSequence()[i].type == ActionType::WaitForChoice){
                Choice f{nextBlock.GetActionSequence()[i].choiceSequence};
                f.makeChoice();
                StoryBlock ChoiceBlock = nextBlock.GetActionSequence()[i].block[f.GetIdOfAnswer()];
                play(&ChoiceBlock);
            }

            
        }
        const auto& huilo = nextBlock.GetEndOfBlock();
        if (huilo.exitType == ExitBlock::GoToScene){
            
        }
        return huilo;
    }
};


//бля полностью пеорелопатьтить эту хунйю вызов в плей сука
