//
//  checkAndProcessInput.cpp
//  guessingGame
//
//  Created by Poon, Phillip (383H) on 8/23/20.
//  Copyright © 2020 Poon, Phillip (383H). All rights reserved.
//

#include "checkAndProcessInput.hpp"
#include "high_scores.hpp"
#include <iostream>
#include <cmath> // for the absolute value
#include <string>
#include <regex>
#include <sstream>
#include <random>

// Generates a random number between minNum and maxNum
int genRandInt(int minNum, int maxNum)
{
   
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<int> distribution(minNum, maxNum);
    return distribution(generator);
    
}


// Converts a string to an interger
int str2int(std::string myText)
{
    std::stringstream geek(myText);
    int guess{0};
    geek >> guess;
    return guess;
}



int askUserForInt()
{
    
    bool keepLoopingFlag {true};
    
   
    // Initialize the string variable that will store the guess
    std::string num1{""};
        
    // The regex we will try to match with.
    auto const regex = std::regex("^[0-9]$|^[0-9][0-9]$|^[0-9][0-9][0-9]$");
    
    // Initialize a variable that will store if the regex function has found a match.
    bool myTextContainsRegex{false};
    
    // Initialize the variable that will store the guess after it's converted to an integer. 
    int guess{0};
    
    std::string myText{""};
    while (keepLoopingFlag)
    {
        
        std::cout << "Type an integer from 0 to 100: ";
        
        
        // By using std::getline instead of just std::cin we can check if the user entered spaces into
        // their input.
        std::getline (std::cin, myText);
        
        myTextContainsRegex = std::regex_search(myText, regex); // Calls a regex function to search myText

// For debugging purposes
//std::cout << std::boolalpha << myTextContainsRegex << '\n';
                    
        
        if (myTextContainsRegex)
        {
            guess = str2int(myText) ;
            
            if (guess <= 100)
            {
                keepLoopingFlag = false;
            }
            else
            {
                std::cout << "Invalid Input!\n";
            }
        }
        else
        {
            std::cout << "Invalid Input!\n";
        }
    }
    
    guess =  str2int(myText);
    return guess;
    
}



bool checkInitials(std::string initials)
{
    // This function will check if initial are a valid 3 characters they cannot be numbers or special characters.
    // Only uppercase or lowercase letters are allow.
    // Only up to 3 characters are allowed.

    // The regex we will try to match with.
    //auto const regex = std::regex("^[a-z|A-Z]$|^[a-z|A-Z][a-z|A-Z]]$|^[a-z|A-Z][a-z|A-Z][a-z|A-Z]$");
   
    auto const regex = std::regex("^[a-z|A-Z]{1,3}$");
    
    
    // Initialize a variable that will store if the regex function has found a match.
    bool myTextContainsRegex{false};

    // Function actually performs the match
    myTextContainsRegex = std::regex_search(initials, regex); // Calls a regex function to search

    // Returns 0 if not a match, returns 1 if match
    return myTextContainsRegex;
}


// This function just gets the input
std::string askForInitials()
{
    std::cout << "Enter your initials (1 to 3 letters): ";
    std::string initials{};
    std::getline(std::cin, initials); // read a full line of text into name
    return initials;
}



// This functions calls askForInitials() and checkInitials()
std::string loopUntilValidInitials()
{

    // Initialize variables
    bool isValid{false};
    std::string initials{""};

    // Loops until we get a valid function
    while ( isValid == 0 )
    {
        
        // Calls function to ask for initials
        initials = askForInitials();
      
        // Calls function to check initials for validity
        isValid = checkInitials(initials);
            
        if (isValid == 0)
        {
            std::cout << "Please enter your initials (numbers and special characters are not allowed).\n\n";
        }
        
//std::cerr << isValid << '\n';
    }
    
    return initials;
}


// This function displays the congratulations message
void congrats(int guessNum)
{
    if (guessNum > 1)
    {
        std::cout << "Congratulations! It took you " << guessNum << " guesses to get it right!\n";
    }
    if (guessNum == 1)
    {
        std::cout << "Congratulations! It took you 1 guess to get it right!\n";
    }
}


// This function is self explanatory :)
void print_number_of_guesses(int number_of_guesses)
{
    std::cout << "You have " << number_of_guesses << " guesses.\n";
}



