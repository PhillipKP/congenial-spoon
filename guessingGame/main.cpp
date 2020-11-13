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

// Include the header file for the functions we use to the high score
#include "high_scores.hpp"


// Defines the struct called players_struct
struct players_struct
{
    int guesses;
    int timeSinceEpoch;
    std::string stringValue;

    // This is the constructor.
    // In C++ constructors have the same name as the struct or class
    // The : starts the member initialization list.
    // All things being equal, your code will run faster if you use initialization lists rather than assignment.
    
    players_struct(int k, int j, const std::string s) : guesses{k}, timeSinceEpoch{j}, stringValue{s}
    {
    }
    
};


// Defines the predicate function to for setting the rules of the sort
bool less_than_guesses(const players_struct& struct1, const players_struct& struct2)
{
    
    // Sorts based on the number of guesses if there isn't a tie in guesses
    // Lower number of guesses are sorted ahead of higher number of guesses
    if (struct1.guesses != struct2.guesses)
    {
        return struct1.guesses < struct2.guesses;
    }
    
    // If there is a tie in guesses then it sorts based on seconds since epoch
    return (struct1.timeSinceEpoch < struct2.timeSinceEpoch);
    
}



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
            
            print_number_of_guesses(number_of_guesses);
            //std::cout << "You have " << number_of_guesses << " guesses.\n";
        }
        if (guess > answer)
        {
            std::cout << "The number you entered is higher than the correct answer.\n";
            std::cout << "Try again!\n\n";
            answerFlag = true;
            std::cout << "You have " << number_of_guesses << " guesses.\n";
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
         
         
         // -- Opens the file and saves the seconds since epoch, player's initial, and the number of guesses in the file -- //
         std::ofstream myfile{ "example.csv" , std::ios::app };
         
         myfile << get_sec_since_epoch() << ", " << initials << ", " << number_of_guesses << "\n";
         
         myfile.close();
         
         
         // -- Opens the CSV file containing the scores and prints everything in the file -- //
         
         
         // ifstream is used for reading files
         // We'll read from a file called Sample.dat
         std::ifstream inf{ "example.csv" };
      
         // If we couldn't open the input file stream for reading
         if (!inf)
         {
             // Print an error and exit
             std::cerr << "Uh oh, example.csv could not be opened for reading!\n";
             return 1;
         }
         
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

         
        std::cout << "Here is a list of scores from least to most number of guesses:\n";
    
        
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
         
        //std::cout << time_since_epoch_stored << initials_stored << " " << num_of_guesses_stored << std::endl;
        players.push_back( players_struct( num_of_guesses_stored, time_since_epoch_stored, initials_stored ) );

    }

    // Actually does the sorting using iterators and the function less_than_guesses
    std::sort(players.begin(), players.end(), &less_than_guesses);
    
    // Uses vector iterator to make the code cleaner than using indices
    for (players_struct p: players)
    {
        //D-BUG std::cout << p.stringValue << '\t' << p.guesses << '\t' << p.timeSinceEpoch << '\n';
        std::cout << p.stringValue << '\t' << p.guesses << std::endl;
    }
         
    return 0;
    
}
