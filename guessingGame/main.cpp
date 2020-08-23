#include <iostream>
#include <cmath> // for the absolute value
#include <string>
#include <regex>
#include <sstream>

// Include the header file for custom functions
#include "checkAndProcessInput.hpp"




int main() {
    
    // initialize random seed:
    srand (time(NULL));
    int answer { rand() % 100 + 1 };     // v2 in the range 1 to 100
    
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
    return 0;
}
