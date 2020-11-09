// For std::cout and std::cin
#include <iostream>

// For handling files
#include <fstream>

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
    
    
    // Generate random number
    int answer{ genRandInt(0, 100) };
    
// For debugging purposes
//std::cerr << answer << '\n';
    
    
    
    // Initialize the variable for storing the guess from the user.
    float guess{0};
    
    // Initialize the variable for storing the number of guess it took for the user to get it right
    int number_of_guesses{0};
    
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
        
        // Increments the number of guesses by one
        ++number_of_guesses; // Increment by 1
        
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
            std::cout << "You have " << number_of_guesses << " guesses.\n";
        }
        
        if (guess > answer)
        {
            std::cout << "The number you entered is higher than the correct answer.\n";
            std::cout << "Try again!\n\n";
            answerFlag = true;
            std::cout << "You have " << number_of_guesses << " guesses.\n";
               
        }
        
        
        
        
    }
    
    
     if (guess == answer)
     {
         
         
         // Calls a function to congratulate the user based on the number of guesses.
         congrats(number_of_guesses);

                 
         // Initialize the initials variable
         std::string initials{""};
                 
         // Calls a function that asks the user for their initials and loops until the their input is valid
         initials = loopUntilValidInitials();
         
         // Outputs the initials
         std::cout << "Thank you for playing " << initials << '\n';
         
         std::ofstream myfile{ "example.csv" , std::ios::app };
         
         myfile << get_sec_since_epoch() << " , " << initials << " , " << number_of_guesses << " , \n";
         
         myfile.close();
     }

    return 0;
    
}
