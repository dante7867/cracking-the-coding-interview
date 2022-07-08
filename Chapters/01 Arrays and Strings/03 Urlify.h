/* Chapter 1 ex. 3
URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string 
has sufficient space at the end to hold the additional characters, and that you are given the "true" 
length of the string. (Note: If implementing in Java, please use a character array so that you can 
perform this operation in place.) 
EXAMPLE 
Input: "Mr John Smith    ", 13 
Output: "Mr%20John%20Smith"
*/

#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>


std::string urlify(std::string str, const size_t trueLength)
{
    if(str.size() == 0)
       return "";
    
    if(trueLength > str.size() || trueLength < 1)
        throw std::invalid_argument("trueLength > str.size()!"); 

    size_t leftIdx = trueLength - 1;
    size_t rightIdx = str.size() - 1;
    
    while(leftIdx != rightIdx)
    {
        if(' ' != str[leftIdx])
        {
            str[rightIdx] = str[leftIdx];
            --rightIdx;
        }
        else
        {
            str[rightIdx] = '0';
            str[rightIdx-1] = '2';
            str[rightIdx-2] = '%';
            rightIdx -= 3;
        }
        --leftIdx;
    }

    // std::cout << __PRETTY_FUNCTION__ << " " << str << std::endl;
    return str;
}


std::string urlifyWithIterators(std::string str, const int trueLength)
{
    if(str.size() == 0)
       return "";

    if(trueLength > str.size() || trueLength < 1)
        throw std::invalid_argument("trueLength > str.size()!"); 

    auto spaces = std::count(std::begin(str), std::end(str), ' ');
    if(spaces == 0)
        return str;

    auto itOld = std::begin(str);
    std::advance(itOld, trueLength-1);
    auto itNew = std::end(str) - 1;

    while(itNew != itOld)
    {
        if(*itOld != ' ')
        {
            *itNew = *itOld;
            if(std::begin(str) != itNew)
                --itNew;
        } 
        else
        {
            *itNew = '0';
            --itNew; 
            *itNew = '2';
            --itNew;
            *itNew = '%';
            if(std::begin(str) != itNew)
                --itNew;
            
        }
        if(std::begin(str) != itOld)
            --itOld;
    }

    //std::cout << __PRETTY_FUNCTION__ << " " << str << std::endl;
    return str;
}

