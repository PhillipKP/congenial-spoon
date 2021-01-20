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

// For handling files
#include <fstream>



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



// This function displays the congratulations message
void congrats(int guessNum)
{
    if (guessNum > 1)
    {
        std::cout << "Congratulations! It took you " << guessNum << " guesses to get it right!\n";
    }
    if (guessNum == 1)
    {
        std::cout << "Congratulations! It took you 1 guess to get it right!\n";
    }
}

// Opens file and saves seconds since epoch, player's initials, and the number of guesses in the file
void save_time_user_score_to_file(std::string high_scores_filename, std::string initials, int number_of_guesses)
{
    std::ofstream myfile{ high_scores_filename , std::ios::app };
    myfile << get_sec_since_epoch() << ", " << initials << ", " << number_of_guesses << "\n";
    myfile.close();
}
