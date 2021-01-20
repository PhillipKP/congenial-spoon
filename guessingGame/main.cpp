//---- All the includes

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


// Include the header file for custom functions
#include "checkAndProcessInput.hpp"

// Include the header file for the functions we use to the high score
#include "high_scores.hpp"

#include "players_struct.hpp"

//---- Begin the main function

int main() {
    
    // Best Practice: Any variable that shouldn't be modified after initialization and
    // whose initializer is known at compile-time should be declared as constexpr.
    // REMEMBER: constexpr creates compile-time constant
    constexpr int answer_min = 0  ;
    constexpr int answer_max = 100;
    
    // REMEMBER: const just means it cannot be changed
    
    // This is the filename where the scores are stored
    const std::string high_scores_filename = "example.csv";
    
    // Generate random number and stores it in the variable answer
    const int answer{ genRandInt(answer_min, answer_max) };

    
// For debugging purposes
//std::cerr << answer << '\n';
    
    // Initialize the variable for storing the guess from the user.
    float guess{0};
    
    // Initialize the variable for storing the number of guess it took for the user to get it right
    int number_of_guesses{0};
    
    // As long as this is true the loop will continue to ask for guesses.
    bool answerFlag = true;
       
    // insert code here...
    std::cout << "Hello there! \nI have randomly selected a number between 0 and 100\n";
    
    
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
            
            // Calls a function to output how many guesses the user produced
            print_number_of_guesses(number_of_guesses);
            
        }
        
        if (guess > answer)
        {
            std::cout << "The number you entered is higher than the correct answer.\n";
            std::cout << "Try again!\n\n";
            
            
            // Calls a function to output how many guesses the user produced
            print_number_of_guesses(number_of_guesses);
        }
    }
    
    

         
         
         // Calls a function to congratulate the user based on the number of guesses.
         congrats(number_of_guesses);

                 
         // Initialize the initials variable
         std::string initials{""};
                 
         // Calls a function that asks the user for their initials and loops until the their input is valid
         initials = loopUntilValidInitials();
         
         // Outputs the initials
         std::cout << "Thank you for playing " << initials << '\n';
         
         
         // Opens file and saves seconds since epoch, player's initials, and the number of guesses in the file
         save_time_user_score_to_file(high_scores_filename, initials, number_of_guesses);

    
         
         // -- Opens the CSV file containing the scores and prints everything in the file -- //
         
         
         // Creates an ifstream object is used for reading files
         // We'll read from a file high_scores_filename
         std::ifstream inf{ high_scores_filename };
      
         // If we couldn't open the input file stream for reading
         if (!inf)
         {
             // Print an error and exit
             std::cerr << "Uh oh, example.csv could not be opened for reading!\n";
             return 1;
         }
         
         // Initializes a vector of strings called entire_output
         std::vector<std::string> entire_output;
         
         // While there's still stuff left to read it loops over each line in the file
         // Each line is added as an entry to the vector of strings called entire_output;
         while (inf)
         {
             // read stuff from the file into a string and print it
             std::string strInput;
             std::getline(inf, strInput);
             
             if (!strInput.empty())
             {
                 entire_output.push_back(strInput);
             }
         }

         
        std::cout << "Top ten scores:\n";
    
        
        for (std::string test_string: entire_output)
        {
            std::vector<std::string> result = splitstring_comma(test_string);
        }
         
         // initialize a vector of players_structs called players
         std::vector <players_struct> players;
         
         
    // loop over each index
    for (std::string test_string: entire_output)
    {
        std::vector<std::string> result = splitstring_comma(test_string);
         
        // Convert to integer and use that to initialize
        int time_since_epoch_stored { std::stoi( result[0] ) };
        int num_of_guesses_stored { std::stoi( result[2]) };
        std::string initials_stored { result[1] };
         
        //DEBUG: std::cout << time_since_epoch_stored << initials_stored << " " << num_of_guesses_stored << std::endl;
        players.push_back( players_struct( num_of_guesses_stored, time_since_epoch_stored, initials_stored ) );

    }

    // Actually does the sorting using iterators and the function less_than_guesses
    std::sort(players.begin(), players.end(), &less_than_guesses);
    
    // Used to keep track of how many scores to output
    int count_scores_printed{1};
    
    // Uses vector iterator to make the code cleaner than using indices
    for (players_struct p: players)
    {
        //D-BUG std::cout << p.stringValue << '\t' << p.guesses << '\t' << p.timeSinceEpoch << '\n';
        
        // function takes the string with initials in it and makes sure they are all the same length
    
        
        
        std::string hs_initials = p.stringValue;
        
        if (hs_initials.length() == 3)
        {
            hs_initials = hs_initials + " ";
        }
        else if (hs_initials.length() == 2)
        {
            hs_initials = hs_initials + "  ";
        }
        else if (hs_initials.length() == 1)
        {
            hs_initials = hs_initials + "   ";
        }
        
        
        // Only prints the first 10 scores
        if (count_scores_printed < 10)
        {
            std::cout << count_scores_printed << ",  " <<  hs_initials << '\t' << p.guesses << std::endl;
        }
        else if (count_scores_printed == 10)
        {
            std::cout << count_scores_printed << ", " <<  hs_initials << '\t' << p.guesses << std::endl;
        }
            
            
        count_scores_printed++;
        //std::cerr << count_scores_printed << '\n';
        
    }
         
    return 0;
    
}
