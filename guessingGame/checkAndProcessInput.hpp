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
    
    int genRandInt(int minNum, int maxNum);

    int str2int(std::string myText);

    int askUserForInt();

    bool checkInitials(std::string initials);

    std::string askForInitials();
    std::string loopUntilValidInitials();

    void congrats(int guessNum);

    int get_sec_since_epoch();
#endif /* checkAndProcessInput_hpp */
