//
//  hangman_game.cpp
//  CPlusPlus
//
//  Created by Pan Michael on 2024/7/6.
//

#include <iostream>
#include <sstream>
#include "hangman_game.hpp"
#include "random.hpp"


std::string to_lower_case(std::string word);
char to_lower_case(char character);
std::string to_hidden_characters(std::string word);


#define print(message) std::cout << message << "\n";




const char* WORDS[] = {
    "Blue", "Red", "Orange", "Yellow"
};
const int WORDS_LENGTH = sizeof(WORDS) / sizeof(char*);


void hangman_game()
{
    print("Start Hangman Game");

    // Won't work if "const" is not stated
    std::string chosen_word = to_lower_case(WORDS[random_int(0, WORDS_LENGTH)]);
    int chosen_word_length = (int)chosen_word.length();
    std::string known_words = to_hidden_characters(chosen_word);
    
    int guessCount = 0;
    
    while (true)
    {
        std::string input;
        std::cout << "\nKnown Words (" << guessCount << " times): " << known_words << "\n" << "Please input answer (one character only): ";
        std::cin >> input;
        
        if (input == "quit")
        {
            print("-------------------------------");
            print("Correct word: " << chosen_word);
            break;
        }
        else if (input.length() != 1)
        {
            print("Invalid input");
            continue;
        }

        guessCount++;
        char character = to_lower_case(input[0]);
        bool fullyReveal = true;
        
        for (int i = 0; i < chosen_word_length; i++)
        {
            if (chosen_word[i] == character)
                known_words[i] = chosen_word[i];
            else if (known_words[i] == '_')
                fullyReveal = false;
        }
        
        if (fullyReveal)
        {
            print("-------------------------------");
            print("You solved it: " << chosen_word << " (In " << guessCount << " Guesses)");
            break;
        }
    }
}


std::string to_lower_case(std::string word)
{
    int length = (int) word.length();
    for (int i = 0; i < length; i++)
    {
        int order = (int)word[i];
        
        if (order >= 65 and order <= 90)
        {
            order += 32;
            word[i] = (char)order;
        }
    }
    return word;
}
char to_lower_case(char character)
{
    int order = (int)character;
    
    if (order >= 65 and order <= 90)
    {
        order += 32;
        return (char)order;
    }

    return character;
}

std::string to_hidden_characters(std::string word)
{
    std::ostringstream oss;
    int length = (int)word.length();
    for (int i = 0; i < length; i++) oss << '_';
    return oss.str();
}


