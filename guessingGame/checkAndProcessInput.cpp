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
    
    // Initialize boolean which tells us if it's actually a float
    //bool valNumFlag {false};
    
    
    // Initialize the string variable that will store the guess
    std::string num1{""};
        
    // The regex we will try to match with.
    auto const regex = std::regex("^[0-9]$|^[0-9][0-9]$|^[0-9][0-9][0-9]$");
    
    std::string myText{""};
    while (keepLoopingFlag)
    {
        
        std::cout << "Type an integer from 0 to 100: ";
        std::cin >> myText;
        bool myTextContainsRegex = std::regex_search(myText, regex);

// For debugging purposes
std::cout << std::boolalpha << myTextContainsRegex << '\n';
                    
        
        if (myTextContainsRegex)
        {
            break;
        }
        else
        {
            std::cout << "Invalid Input!\n";
        }
    }
    
    int guess { str2int(myText) };
    return guess;
    
}
