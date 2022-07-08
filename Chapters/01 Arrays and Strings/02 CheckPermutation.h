#ifndef CHECK_PERMUTATION_H
#define CHECK_PERMUTATION_H

// 1.2 Check Permutation: Given two strings, write a method to decide if one is a permutation of the other.

/*
 * IMPORTANT DETAILS FOR INQUIRY
 * Permutation with or without repetitions? // Assuming permutation with repetitions
 * ASCII or UNICODE strings?
 * Alphabet size?
 * Is case sensitive? (god ? Dog)
 * What about whitespaces?
 */
#include <iostream>
#include <map>
#include <vector>


// Assuming permutation with repetitions
bool CheckPermutation(const std::string& lhs, const std::string& rhs)
{
    if(lhs.length() != rhs.length())
        return false;

    std::map<char, int> charCount; // could be std::set if there are no repetitions

    for(const char ch : lhs)
        charCount[ch] += 1;
    
    for(const char ch : rhs)
    {
        charCount[ch] -= 1;
        if(charCount[ch] < 0)
        {
            return false;
        }
    }
    return true;
}


bool CheckPermutationKnownCharacterSets(const std::string& lhs, const std::string& rhs)
{
    const int ALPHABET_SIZE = 128;
    if(lhs.length() != rhs.length())
        return false;

    std::array<int, ALPHABET_SIZE> charCount = {0}; // could be array<bool, SIZE> if no repetitions

    for(const char ch : lhs)
        charCount[ch-'0'] += 1;

    for(const char ch : rhs)
    {
        charCount[ch-'0'] -= 1;
        if(charCount[ch-'0'] < 0)
            return false;
    }

    return true;
}

#endif
