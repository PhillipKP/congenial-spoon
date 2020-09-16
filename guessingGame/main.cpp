#include <iostream>
#include <cmath> // for the absolute value
#include <string>
#include <regex>
#include <sstream>

//-- for Mersenne Twister random number generating algorithm
#include <random>
#include <ctime>
//--


// Include the header file for custom functions
#include "checkAndProcessInput.hpp"




int main() {
    
    
    
    // Initialize our mersenne twister with a random seed based on the clock
    std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    
    // Create a reusable random number generator that generates uniform numbers between 1 and 100
    std::uniform_int_distribution die{ 1, 100 };
    
    // Generate random number
    int answer{ die(mersenne) };
    
// For debugging purposes
//std::cerr << answer << '\n';
    
    
    
    // Initialize the variable for storing the guess from the user.
    float guess{0};
    
    // As long as this is true the loop will continue to ask for guesses.
    bool answerFlag = true;
       
    // insert code here...
    std::cout << "Hello there! \nI have randomly selected a number between 1 and 100\n";
    
    
    while (answerFlag)
    {
    
        //std::cout << "Please guess a number: ";
        
        // Calls a function that ask users for an integer and will loop until they finally enter an integer.
        guess = askUserForInt() ;
            
        // Tells the user what they guessed!
        std::cout << "You guessed " << guess << '\n';
        
        if (guess == answer)
        {
            std::cout << "CORRECT!!!\n\n";
            answerFlag = false;
        }
        
        if (guess < answer)
        {
            std::cout << "The number you entered is lower than the correct answer.\n";
            std::cout << "Try again!\n\n";
            answerFlag = true;
        }
        
        if (guess > answer)
        {
            std::cout << "The number you entered is higher than the correct answer.\n";
            std::cout << "Try again!\n\n";
            answerFlag = true;
               
        }
    }
    
    
     if (guess == answer)
     {
         // Initialize the initials variable
         std::string initials{""};
         
         // Calls a function that asks the user for their initials and loops until the their input is valid
         initials = loopUntilValidInitials();
         
         // Outputs the initials
         std::cout << initials << '\n';
     }
    
    return 0;
}
