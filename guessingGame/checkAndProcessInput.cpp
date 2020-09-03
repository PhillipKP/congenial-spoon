//
//  checkAndProcessInput.cpp
//  guessingGame
//
//  Created by Poon, Phillip (383H) on 8/23/20.
//  Copyright © 2020 Poon, Phillip (383H). All rights reserved.
//

#include "checkAndProcessInput.hpp"
#include <iostream>
#include <cmath> // for the absolute value
#include <string>
#include <regex>
#include <sstream>


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
