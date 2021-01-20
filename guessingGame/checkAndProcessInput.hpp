//
//  checkAndProcessInput.hpp
//  guessingGame
//
//  Created by Poon, Phillip (383H) on 8/23/20.
//  Copyright © 2020 Poon, Phillip (383H). All rights reserved.
//

#ifndef checkAndProcessInput_hpp

    #define checkAndProcessInput_hpp

    #include "checkAndProcessInput.hpp"
    #include <iostream>
    #include <cmath> // for the absolute value
    #include <string>
    #include <regex>
    #include <sstream>
    #include <random> // used for random number generation
    
    // For handling files
    #include <fstream>

    int genRandInt(int minNum, int maxNum);

    int str2int(std::string myText);

    int askUserForInt();

    bool checkInitials(std::string initials);

    std::string askForInitials();
    std::string loopUntilValidInitials();

    

    void print_number_of_guesses(int number_of_guesses);
#endif /* checkAndProcessInput_hpp */
