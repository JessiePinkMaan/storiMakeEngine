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
#include <limits>
class Choice{
    private:
        std::vector<std::string> choiceSequence;
        std::string userChoice;
        int _indexOfChoice;

    public:
        Choice(  std::vector<std::string> _choiceSequence){
            choiceSequence = _choiceSequence;
        }

    void makeChoice(){
        int ibdexOfChoice = 0;
        bool WaitAnswer = true;
        
        std::cout << "Âûáîð: " ;
        
        while(WaitAnswer){
            for(int i = 0; i < choiceSequence.size(); i++){
                std::cout << "\n" << i + 1 << ": " << choiceSequence[i] << std::endl;
            }
            if(std::cin >> ibdexOfChoice){
                if(ibdexOfChoice >= 1 && ibdexOfChoice <= choiceSequence.size()){
                    
                    userChoice = choiceSequence[ibdexOfChoice - 1];
                    _indexOfChoice = ibdexOfChoice - 1;
                    WaitAnswer = false;
                    break;
                }
                else{
                    std::cout << "ÒÀÊÎÃÎ ÂÛÐÈÀÍÒÀ ÍÅÒÓ\n" << std::endl;
                }
            }
            else{
                if (std::cin.bad()) {
                std::cerr << "Îøèáêà ïîòîêà ââîäà\n";
                return;
                }

                if (std::cin.eof()) {
                    return; 
                }
            
                std::cout << "âû ââåëè íå êîððåêòíîå çíà÷åíèå\n" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
         }
    }

    std::string returnAnswer(){
        return userChoice;
    }
    
    int GetIdOfAnswer(){
        return _indexOfChoice;
    }
    
};