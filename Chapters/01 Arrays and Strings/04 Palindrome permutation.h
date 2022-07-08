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
#include <iostream>
#include "02 CheckPermutation.h"

bool isPalindrom(const std::string& str)
{
    std::cout << str << std::endl;
    if(str.size() < 2)
        return true;

    int leftIdx = 0;
    int rightIdx = str.size()-1;

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
        {
            return false;
        }

        ++leftIdx;
        --rightIdx;
        
    }
    
    return true;
}


bool isPalindromPermutation(const std::string& palindrome, const std::string& permutation)
{
    if(palindrome.size() != permutation.size())
        return false;

    return isPalindrom(palindrome) && CheckPermutation(palindrome, permutation);
}

