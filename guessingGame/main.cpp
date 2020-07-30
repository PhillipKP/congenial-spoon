//
//  main.cpp
//  guessingGame
//
//  Created by Poon, Phillip (383H) on 7/30/20.
//  Copyright © 2020 Poon, Phillip (383H). All rights reserved.
//

#include <iostream>

int main() {
    
    /* initialize random seed: */
    srand (time(NULL));
    
    // insert code here...
    std::cout << "Hello there! \nI have randomly selected a number between 1 and 100\n";
    
    int answer { rand() % 100 + 1 } ;     // v2 in the range 1 to 100
    // std::cout << answer << '\n';
    
    // Initialize the variable for storing the guess
    int guess{0};
    
    bool answerFlag = true;
    
    while (answerFlag)
    {
        std::cout << "Please guess a number: ";
        std::cin >> guess;
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
        }
        
        if (guess > answer)
        {
                std::cout << "The number you entered is higher than the correct answer.\n";
                std::cout << "Try again!\n\n";
               
        }
    }
    return 0;
}
