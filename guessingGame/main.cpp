#include <iostream>
#include <cmath> // for the absolute value
#include <string>
#include <regex>
#include <sstream>




float getFractPart(float x)
{
    float fracPart { x-static_cast<long>(x) };
       
    return fracPart;
}

// Checks to see if string only contains numbers.
bool isValidNum(std::string num1)
{

    if( num1.find_first_not_of("1234567890.- ") != std::string::npos )
    {
        std::cout << "Invalid number " << std::endl;
        return false;
    }
    else
    {
        return true;
    }

}

// Converts a string to a float
float str2float(std::string num1)
{
    float x = 0;
    x = atof( num1.c_str() );
    return x;
}

// Converts a string to an interger
int str2int(std::string myText)
{
    std::stringstream geek(myText);
    int guess{0};
    geek >> guess;
    return guess;
}


bool isInt(float x)
{
     bool isIntFlag {false};
    if ( std::abs( getFractPart(x) ) > 0 )
    {
        std::cout << "Input is not an integer\n";
        isIntFlag = false;
    }
    else
    {
        //std::cout << "\nInput is an integer\n";
        isIntFlag = true;
    }
    
    return isIntFlag;
}


int askUserForInt()
{
    
    bool keepLoopingFlag {true};
    
    // Initialize boolean which tells us if it's actually a float
    bool valNumFlag {false};
    
    
    // Initialize the string variable that will store the guess
    std::string num1{""};
        
    // The regex we will try to match with.
    auto const regex = std::regex("^[0-9]$|^[0-9][0-9]$|^[0-9][0-9][0-9]$");
    
    std::string myText{""};
    while (keepLoopingFlag)
    {
        
        std::cout << "Type an integer from 0 to 999: ";
        std::cin >> myText;
        bool myTextContainsRegex = std::regex_search(myText, regex);

// For debugging purposes
std::cout << std::boolalpha << myTextContainsRegex << '\n';
                    
        
        if (myTextContainsRegex)
        {
            break;
        }
        else
        {
            std::cout << "Invalid Input!\n";
        }
    }
    
    int guess { str2int(myText) };
    return guess;
    
}



int main() {
    
    // initialize random seed:
    srand (time(NULL));
    int answer { rand() % 100 + 1 };     // v2 in the range 1 to 100
    
    // Initialize the variable for storing the guess from the user.
    float guess{0};
    
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
        }
        
        if (guess > answer)
        {
            std::cout << "The number you entered is higher than the correct answer.\n";
            std::cout << "Try again!\n\n";
            answerFlag = true;
               
        }
    }
    return 0;
}
