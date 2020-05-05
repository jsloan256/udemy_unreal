#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    // Print welcome messages to the terminal
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room...\n";
    std::cout << "Enter the correct code to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    // Declare 3 number code
    const int CodeA = rand()%Difficulty + Difficulty;
    const int CodeB = rand()%Difficulty + Difficulty; 
    const int CodeC = rand()%Difficulty + Difficulty; 

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and CodeProduct to the terminal
    std::cout << std::endl;
    std::cout << "+ There are 3 numbers in the code\n";
    std::cout << "\nThe codes add-up to " << CodeSum;
    std::cout << "\nThe CodeProduct of the codes is " << CodeProduct;
    std::cout << "\n\n";

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the player's guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nYou win!";
        return true;
    }
    else
    {
        std::cout << "\nYou lose!";
        return false;
    }
}

int main()
{
    srand(time(NULL));

    const int MaxLevel = 5;
    int LevelDifficulty = 1;

    // Loop the game until all levels are complete
    while (LevelDifficulty <= MaxLevel)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);

        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            std::cout << "\nMoving to the next level...\n";
            ++LevelDifficulty;
        }
        else
        {
            std::cout << "\nRetrying level " << LevelDifficulty << std::endl;
        }
        
    }

    std::cout << "Congratuations! You won the game!\n";

    return 0;
}