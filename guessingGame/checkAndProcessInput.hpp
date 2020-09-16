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

    int str2int(std::string myText);

    int askUserForInt();

    bool checkInitials(std::string initials);

    std::string askForInitials();
    std::string loopUntilValidInitials();


#endif /* checkAndProcessInput_hpp */
