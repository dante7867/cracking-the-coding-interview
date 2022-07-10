/*
String Compression: Implement a method to perform basic string compression using the counts 
of repeated characters. For example, the string aabcccccaaa would become a2blc5a3. If the 
"compressed" string would not become smaller than the original string, your method should return 
the original string. You can assume the string has only uppercase and lowercase letters (a - z).
*/

#include <iostream>
#include <string>


// Time - O(S), space - O(S), where S - string size
std::string compress(const std::string& original)
{
    if(""==original)
        return original;

    std::string compressed;

    // worst case abc -> a1b1c1, so twice the size. Without code below algorithm would be O(s*(k**2)) 
    // s - original.size(), k - sequences ex: aabbcc -> 3 sequences 
    compressed.reserve(original.size() * 2); 
    
    int cnt = 1;
    char prevChar = original[0];
    for(size_t idx = 1; idx != original.size(); ++idx)
    {
        if(original[idx] == prevChar)
        {
            ++cnt;
        }
        else
        {
            compressed += prevChar + std::to_string(cnt);
            cnt = 1;
            prevChar = original[idx];
        }
    }
    // add trailing character
    compressed += prevChar + std::to_string(cnt);

    // early return to bypass shrink_to_fit() if not needed
    if (compressed.size() >= original.size())
        return original

    // I assumed capacity pessimistically. Reducing capacity to size. 
    // May cause rellocation and add O(n) to time complexity in favor for space complexity.
    compressed.shrink_to_fit(); 

    // if compressed is not smaller than original return original
    return compressed;
}

