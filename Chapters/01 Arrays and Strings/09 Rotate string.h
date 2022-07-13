#include <iostream>
#include <string>

bool isSubstring(const std::string& sMain, const std::string& sSub)
{
    if(sMain.find(sSub) != std::string::npos)
        return true;
    return false;
}


bool isRotation(const std::string& s1, const std::string& s2)
{
    if(s1.size() != s2.size() && s1.size() > 0)
        return false;
    return isSubstring(s1+s1, s2);
}

