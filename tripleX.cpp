#include <iostream>
#include <ctime>

void Introduction(){
    std::cout << "\n\nWelcome to math challenge!\n";
    std::cout << "Guess the correct numbers that will fulfill the following rules:\n";
    std::cout << "Be careful you can only guess incorrectly 2 times...\n\n";
}

bool PlayGame(int Difficulty){
    int CodeA = (rand()% Difficulty) + Difficulty;
    int CodeB = (rand()% Difficulty) + Difficulty;
    int CodeC = (rand()% Difficulty) + Difficulty;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProd = CodeA * CodeB * CodeC;

    std::cout <<"++++++++++++ Level " << Difficulty <<" ++++++++++++\n\n";
    std::cout <<"+ There are 3 numbers in the code\n";
    std::cout <<"+ The numbers add up to: " << CodeSum;
    std::cout <<"\n+ The numbers multiply to give: " << CodeProd << "\n\n";

    //Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProd = GuessA * GuessB * GuessC;

    if(GuessSum == CodeSum && GuessProd == CodeProd){
        std::cout <<"\n+ You guessed correctly! Great Work! \n\n+++ Moving on to next Level +++\n\n";
        return true;
    }
    else{
        return false;
    }
}


int main(){
    srand(time(NULL));

    Introduction();

    int LevelDifficulty = 1;
    int const MaxLevel = 15;
    int Lives = 2;

    while (MaxLevel >= LevelDifficulty){
        bool bLevelComplete = PlayGame(LevelDifficulty);;
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete){
            ++LevelDifficulty;
            if(LevelDifficulty %5 == 0){
                ++Lives;
                std::cout << "\n\n+1UP\nGained a Life\n\n";
            }
        }
        else if(Lives > 0 && bLevelComplete == false){
            --Lives; 
            std::cout << "\nYou guessed incorrectly and lost one life: \n" << Lives << " Lives remaining\n\n";
        }
        else{
            std::cout <<"\nYou are out of lives...\n" << ".....Game Over!.....\n";
            return 0;
        }
        
    }
    
    std::cout <<"****Congratulations! You Win!****";

    return 0;
}
