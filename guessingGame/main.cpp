#include <iostream>
#include <cmath> // for the absolute value
#include <string>



float getFractPart(float x)
{
    float fracPart { x-static_cast<long>(x) };
       
    return fracPart;
}

// Checks to see if string only contains numbers.
bool isValidNum(std::string num1)
{

    if( num1.find_first_not_of("1234567890.-") != std::string::npos )
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
        

    while (keepLoopingFlag)
    {
        std::cout << "Enter a integer: ";
        std::cin >> num1;
        
        
        // Call function to check if the input is actually a float
        valNumFlag = isValidNum(num1);
        //std::cout << valNumFlag << '\n';
        
        // Converts to a number and sets the keepLoopFlag to false
        float newNum1{0};
        
        if (valNumFlag)
        {
            newNum1 = str2float(num1);
            //std::cout << newNum1 << '\n';
            bool isIntFlag{false};
            isIntFlag = isInt(newNum1);
            //std::cout << isIntFlag << '\n';
            
            if (isIntFlag)
            {
                // If it is an integer it will set keepLoopFlag to false
                keepLoopingFlag = false;
                return newNum1;
            }
        }
        else
        {
            keepLoopingFlag = true;
        }
        
    }
    return 0;
}



int main() {
    
    // initialize random seed:
    srand (time(NULL));
    
    // insert code here...
    std::cout << "Hello there! \nI have randomly selected a number between 1 and 100\n";
    
    int answer { rand() % 100 + 1 } ;     // v2 in the range 1 to 100
    
    // Initialize the variable for storing the guess
    float guess{0};
    
    bool answerFlag = true;
    
    while (answerFlag)
    {
        std::cout << "Please guess a number: ";
        
    

        // Calls a function that ask users for an integer and will loop until they finally enter an integer.
        guess = askUserForInt() ;
            
        
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
