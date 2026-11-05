#include <iostream>
#include <string>
#include "Persona.h"
#include "Choice.h"
#include "Scene.h"
#include <thread>  // sleep_for
#include <chrono>  // секунды и миллисекунды
#include <vector>
#include "StoryBlock.h"


std::string UserName;

void timeOut(int n){
    std::this_thread::sleep_for(std::chrono::milliseconds(n));
}

void theBranchIsGone(StoryBlock &block){
    block.AddLine(UserName, "ебаный рот...", true);
    block.waiteForPress();

    block.AddLine(UserName, "не мое дело.", true, false);
    block.waiteForPress();

    block.AddLine("...", "на улице была обычная осень...", false, true);
    block.waiteForPress();
    
    block.AddLine(UserName, "что это было..", true);
    block.waiteForPress();

    block.AddLine(UserName, "может стоило проверить..", true, false);
    block.waiteForPress();

    block.AddLine(UserName, "НЕТ, не мое дело", false);
    block.waiteForPress();

    block.AddLine(UserName, "я почти забыл куда шел..", true);
    block.waiteForPress();

    block.AddLine(UserName, "мне надо в магазин...", true);
    block.waiteForPress();

    block.AddLine(UserName, "на улице сегодня особено жутко...", false);
    block.waiteForPress();

    block.AddLine("...", "магазин показался из за угла", false, true);
    block.waiteForPress();

    block.AddLine(UserName, "надо закупиться всем необходимым", true);
    block.waiteForPress();

    block.AddLine(UserName, "чтобы прожить еще неделю без вылазок на улицу", true);
    block.waiteForPress();

    block.AddLine("...", "дорога домой прошла обычно, без происшествий", true, true);
    block.waiteForPress();

    block.AddLine("...", " почти..", true, false);
    block.waiteForPress();
    
    block.AddLine("...", "мысли о происшедшем не выходили из головы..", false, true);
    block.waiteForPress();

    block.AddLine(UserName, "обратно я шел в своих мыслях, почти не обращая внимание на окружающий мир...", false, true);
    block.waiteForPress();

    block.AddLine(UserName, "но.....", true, true);
    block.waiteForPress();

    block.AddLine(UserName, "кое что вернуло меня в реальность...", true, false);
    block.waiteForPress();

    block.AddLine(UserName, "в том самом месте ничего уже небыло....", true, false);
    block.waiteForPress();

    block.AddLine(UserName, "только лужица крови...", true, false);
    block.waiteForPress();
}

void Game(){
    Persona Bebrina{"Liza"};
    Persona Narator{"..."};
    Persona GG{UserName};
    
    bool GameFlag = true;

    while(GameFlag){
        StoryBlock FirsBlock({Bebrina, Narator, GG});
      
        FirsBlock.AddLine("Liza", "ох привет");
        FirsBlock.AddLine("...", "лиза привстала и подошла к окну...");

        FirsBlock.AddLine("Liza", "я.. ", true, true);
        FirsBlock.timeOut(500);

        FirsBlock.AddLine("Liza", "я.. ", true, false);
        FirsBlock.timeOut(500);

        FirsBlock.AddLine("Liza", "уже и забыла ", true, false);
        FirsBlock.timeOut(500);

        FirsBlock.AddLine("Liza", "как это..", true, false);
        FirsBlock.timeOut(500);

        FirsBlock.AddLine("Liza", "о... ты тут?");
        FirsBlock.waiteForPress();

        FirsBlock.AddLine("...", "лиза открыла окно...");
        FirsBlock.waiteForPress();

        FirsBlock.AddLine("Liza", "что то душно", true);
        FirsBlock.waiteForPress();

        FirsBlock.AddLine("Liza", ")))", true, false);
        FirsBlock.waiteForPress();

        FirsBlock.AddLine("...", "лиза нырнула в открытый проем");
        FirsBlock.waiteForPress();

        FirsBlock.AddLine("Liza", "аааааааааааааааааа", false);
        FirsBlock.waiteForPress();

        FirsBlock.AddLine("...", "ее тело размазалось по асфальту...");
        FirsBlock.waiteForPress();
        
        FirsBlock.AddLine("...", "вы видете мертвое тело на дороге...");

        StoryBlock silent({Bebrina, Narator, GG});
            silent.AddLine("...", "ты не можешь пошевелиться...");
            silent.waiteForPress();

        StoryBlock go({Bebrina, Narator, GG});
            go.AddLine("...", "ты подошел к телу..");
            go.waiteForPress();

        StoryBlock leve({Bebrina, Narator, GG});
            leve.AddLine("...", "ты ушел");
            leve.waiteForPress();
            theBranchIsGone(leve);

        FirsBlock.AddChoice({"...", "подойти", "пройти дальше"}, {silent, go, leve});

        Scene First(FirsBlock);
        First.play();
    

        GameFlag = false;

    }
}

void mainMenu(){
    int ans = 0;
   
    std::cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  МЕНЮ - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;
    timeOut(1000);
    std::cout << "1 - новая игра " << std::endl;
    std::cout << "2 - загрузить игру " << std::endl;
    std::cout << "3 - выйти " << std::endl;
 
    std::cin >> ans;

    if(ans == 1){
        Game();
    }

    else if(ans == 2){
        std::cout << "нет" << std::endl;
    }

    else if(ans == 3){
        std::cout << "пока" << std::endl;
    }

}

int main(){

    mainMenu();

    return 0;
}