//
//  high_scores.cpp
//  guessingGame
//
//  Created by Poon, Phillip (383H) on 11/13/20.
//  Copyright © 2020 Poon, Phillip (383H). All rights reserved.
//

#include "high_scores.hpp"
#include "checkAndProcessInput.hpp"
#include <iostream>
#include <cmath> // for the absolute value
#include <string>
#include <regex>
#include <sstream>
#include <random>



// This function splits strings at the commas
std::vector<std::string> splitstring_comma(std::string my_str)
{
    std::vector<std::string> result;
   
    std::stringstream s_stream(my_str); //create string stream from the string
   
    while(s_stream.good()) {
        std::string substr;
        getline(s_stream, substr, ','); //get first string delimited by comma
        result.push_back(substr);
    }
    return result;
}

// Gets the time since epoch
int get_sec_since_epoch()
{
    std::time_t result = std::time(nullptr);
    int sec_since_epoch { static_cast<int>(result) };
    return sec_since_epoch;
}



// pad initials string
std::string pad_initials(std::string initials_in)
{
    std::string initials_out("");
    
    if (initials_in.length() == 3)
    {
        initials_out = initials_in + " ";
    }
    else if (initials_in.length() == 2)
    {
        initials_out = initials_in + "  ";
    }
    else if (initials_in.length() == 1)
    {
        initials_out = initials_in + "   ";
    }
    
    return initials_out;
}
