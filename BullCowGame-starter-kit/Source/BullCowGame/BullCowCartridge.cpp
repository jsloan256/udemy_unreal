// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();

    // Debug: Show the answer
    PrintLine(TEXT("This hidden word is %s."), *HiddenWord);
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else // Check player guess
    {
        if (Input == HiddenWord)
        {
            PrintLine(TEXT("You Win!"));
            EndGame();
        }
        else if (Input.Len() != HiddenWord.Len())
        {
            PrintLine(TEXT("Your word is NOT %i letters long. \nyou have lost!"), HiddenWord.Len());
            EndGame();
        }
        else
        {
            --Lives;
            PrintLine(TEXT("You lost a life!"));
            PrintLine(TEXT("You have %i lives left"), Lives);
        }

        if (Lives <= 0)
            EndGame();
    }

    // Check if isogram
    // Prompt to guess again
    // Check if correct number of characters

    // Remove Life

    // Check if lives > 0
        // If Yes GuessAgain
            // Show lives left
        // If No GameOver and HiddenWord
        // Prompt to PlayAgain (or press enter to play again)
}

void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("cakes");
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Welcome to Bull Cow!"));
    PrintLine(TEXT("You have %i lives left"), Lives);
    PrintLine(TEXT("Guess the %d letter word:"), HiddenWord.Len());
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again."));
}