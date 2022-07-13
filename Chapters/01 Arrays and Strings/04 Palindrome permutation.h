/*
 * 1.4 Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palin
 * drome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation 
 * is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.
 * EXAMPLE 
 * Input: Tact Coa 
 * Output: True (permutations: "taco cat", "atco eta", etc.)
*/

/*
 * IMPORTANT DETAILS FOR INQUIRY
 * Is case sensitive?
 * Alphabet size?
 * ASCII or UNICODE strings?
 */
#include <string>
#include <map>
#include <iostream>
#include <cstdint>
#include <bitset>

#include "02 CheckPermutation.h"


// Time complexity - O(S), S - string length
bool isPalindrom(const std::string& str)
{
    if(str.size() < 2)
        return true;

    int leftIdx = 0;
    int rightIdx = static_cast<int>(str.size()-1);

    while(leftIdx < str.size() && rightIdx > -1)
    {
        // std::cout << "LEFT str[" << leftIdx << "]=" << str[leftIdx] <<
        //    ", RIGHT str[" << rightIdx << "]="<<str[rightIdx] << '\n';

        while(str[leftIdx] == ' ')
        {
            ++leftIdx;
            if(leftIdx == str.size()-1)
                break;
        }

        while(str[rightIdx] == ' ')
        {
            --rightIdx;
            if(rightIdx == 0)
                break;
        }
        
        if(str[leftIdx] == ' ' || str[rightIdx] == ' ')
           break;

        if(str[leftIdx] != str[rightIdx])
            return false;

        ++leftIdx;
        --rightIdx;
    }
    
    return true;
}


// Time complexity - O(S+U), S - string length, U - unique letters in str
bool isPalindromPermutation(const std::string& str)
{
    std::map<char, bool> letterOccurances;

    for(const char ch : str)
    {
        if(ch != ' ')
            letterOccurances[ch] = !letterOccurances[ch];
    }

    int without_pairs = 0;
    for(const auto& ch2o : letterOccurances)
    {
        if(ch2o.second) 
            ++without_pairs;
        if(without_pairs > 1)
            return false;
    } 

    return true;
}

// Time complexity - O(1) 
inline void flipBit(uint32_t& mask, int bitNumber)
{
    mask = mask ^ (1 << bitNumber);
}

// Time complexity - O(S), S - string length
bool isPalindromPermutationBitMasks(const std::string& str)
{
    //assuming english alphabet
    uint32_t characterBits = 0;
    
    for(const char ch : str)
        if(ch-'a' < 26 && ch-'a'>-1)
            flipBit(characterBits, ch-'a');

    return (characterBits & (characterBits - 1)) == 0;
}

