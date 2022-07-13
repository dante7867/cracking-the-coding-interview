#include <iostream>
#include <string>


// Time - O(A+B), where A and B are sizes of input strings
bool isSubstring(const std::string& sMain, const std::string& sSub)
{
    if(sMain.find(sSub) != std::string::npos)
        return true;
    return false;
}


// Time - O(N)
bool isRotation(const std::string& s1, const std::string& s2)
{
    if(s1.size() != s2.size() && s1.size() > 0)
        return false;
    return isSubstring(s1+s1, s2);
}

