#include "01 isUnique.h"

int main()
{
    const std::string str1 = "abcdefghijk";
    const std::string str2 = "aab";

    std::cout << isUniqueWithArray(str1) << '\n';
    std::cout << isUniqueWithArray(str2) << '\n';

    std::cout << isUniqueWithSet(str1) << '\n';
    std::cout << isUniqueWithSet(str2) << '\n';

    std::cout << inUniqueNoDataStructuresBruteForce(str1) << '\n';
    std::cout << inUniqueNoDataStructuresBruteForce(str2) << '\n';

    std::cout << isUniqueNoDataStructuresWithSort(str1) << '\n';
    std::cout << isUniqueNoDataStructuresWithSort(str2) << '\n';
}

