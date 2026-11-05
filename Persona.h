#pragma once
#include <string>
#include <chrono>
#include <vector>

class Persona {
    private:
        std::string Name;
        int reputation = 100;
        std::string Picture;

    public: 
    Persona(std::string _name ){
        Name = _name;
    }

    int reputationAdjustment(int consequences = 0){
        reputation += consequences;

        return reputation;
    }
    
    std::string GetName(){
        return Name;
    }

    void Say (std::string replic)const{
        std::cout << "\n" << Name << ":  " << replic << std::endl;
    }

    void SayInline (std::string replic, bool name)const{
        if(name){
            std::cout << "\n" << Name << ":  ";
        }
        std::cout << replic;
        
    }   

};