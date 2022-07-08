// 1.1 Is Unique: Implement an algorithm to determine if a string has all unique characters. 
// What if you cannot use additional data structures?

/*
 * IMPORTANT DETAILS FOR INQUIRY
 * 1. Is string ASCII or UNICODE?
 * 2. What is alphabet size?
 */

#include <iostream>
#include <algorithm>
#include <set>
#include <array>


bool isUniqueWithArray(const std::string& str)
{
    // assuming 128-character alphabet. Coule be 256 or more for extended alphabet
    constexpr size_t ALPHABET_SIZE = 128;  
    std::array<bool, ALPHABET_SIZE> chars {false}; // bool chars[ALPHABET_SIZE] = {false};  

    for(const char& ch : str)
    {
        if(chars[ch])
            return false;
        chars[ch] = true;
    }
    return true;    
}


bool isUniqueWithSet(const std::string& str)
{
    std::set<char> chars;
    for(const auto& ch : str)
    {
        if(chars.find(ch) != std::end(chars))
            return false;
        chars.insert(ch);
    }   
    return true;
}


bool inUniqueNoDataStructuresBruteForce(const std::string& str)
{
    for(size_t i = 0; i != str.size();  ++i)
    {
        for(size_t j = 0; j != str.size();  ++j)
        {
            if(i!=j)
                if(str[i] == str[j])
                    return false;
        }
    }
    return true;
}


// str can be passed by ref or moved if it's no longer needed after call
bool isUniqueNoDataStructuresWithSort(std::string str)
{
    if(""==str)
        return true;

    std::sort(std::begin(str), std::end(str));
    for(size_t idx = 1; idx != str.length(); ++idx)
    {
        if(str[idx-1] == str[idx])
           return false; 
    } 
    return true;
}
