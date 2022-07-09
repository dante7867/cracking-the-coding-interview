#include <iostream>
#include <cmath>

/*
One Away: There are three types of edits that can be performed on strings: insert a character, 
remove a character, or replace a character. Given two strings, write a function to check if they are 
one edit (or zero edits) away. 
EXAMPLE 
pale, ple -> true 
pales, pale -> true 
pale, bale -> true 
pale, bake -> false 
*/

/*
 * IMPORTANT DETAILS FOR INQUIRY
 * Is comparison case sensitive?
 * ASCII or UNICODE strings?
 */

bool isOneAway(const std::string& sLeft, const std::string& sRight)
{
    if(fabs(sLeft.size() - sRight.size()) > 1)
        return false;

    int missmatches = 0;
    size_t l = 0;
    size_t r = 0;

    while(r < sLeft.size()  && r < sRight.size())
    {
        if(sLeft[l] != sRight[r])
        {
            if(++missmatches > 1)
                return false;

            if(sLeft.size() > sRight.size())
                --r;
            else if(sLeft.size() < sRight.size())
                --l;
        }
        ++l;
        ++r;
    }
    
    return true;
}

