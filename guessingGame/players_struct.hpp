//
//  players_struct.hpp
//  guessingGame
//
//  Created by Poon, Phillip (383H) on 11/26/20.
//  Copyright © 2020 Poon, Phillip (383H). All rights reserved.
//

#ifndef players_struct_hpp
#define players_struct_hpp

#include <stdio.h>
#include <iostream>

// Defines a struct called players_struct
struct players_struct
{
    int guesses;
    int timeSinceEpoch;
    std::string stringValue;

    // This is the constructor.
    // In C++ constructors have the same name as the struct or class (confusing isn't it?)
    // The : starts the member initialization list.
    // All things being equal, your code will run faster if you use initialization lists rather than assignment.
    
    
    players_struct(int k, int j, const std::string s) : guesses{k}, timeSinceEpoch{j}, stringValue{s}
    {
    }
    
    
};


bool less_than_guesses(const players_struct& struct1, const players_struct& struct2);


#endif /* players_struct_hpp */
