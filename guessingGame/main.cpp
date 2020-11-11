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


std::vector<std::string> splitstring_comma(std::string my_str)
// This function splits strings at the commas
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

         
        std::cout << "Here is a list of scores:\n";
        for (std::string test_string: entire_output)
        {
            std::vector<std::string> result = splitstring_comma(test_string);
            std::cout << result[0] << result[1] << result[2] << '\n';
        }
         
     }

    return 0;
    
}
