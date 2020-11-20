//
//  high_scores.hpp
//  guessingGame
//
//  Created by Poon, Phillip (383H) on 11/13/20.
//  Copyright © 2020 Poon, Phillip (383H). All rights reserved.
//

#ifndef high_scores_hpp
#define high_scores_hpp

#include <stdio.h>
#include "high_scores.hpp"
#include "checkAndProcessInput.hpp"
#include <iostream>
#include <cmath> // for the absolute value
#include <string>
#include <regex>
#include <sstream>
#include <random>


std::vector<std::string> splitstring_comma(std::string my_str);

int get_sec_since_epoch();

std::string pad_initials(std::string initials_in);

#endif /* high_scores_hpp */
