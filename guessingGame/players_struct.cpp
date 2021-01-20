//
//  players_struct.cpp
//  guessingGame
//
//  Created by Poon, Phillip (383H) on 11/26/20.
//  Copyright © 2020 Poon, Phillip (383H). All rights reserved.
//

#include "players_struct.hpp"

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
