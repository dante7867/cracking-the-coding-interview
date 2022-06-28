#include <gtest/gtest.h>

#include "./Chapters/01 Arrays and Strings/01 isUnique.h"

TEST(Chapter1, isUnique)
{   
    const std::string str1 = "abcdefghijk";
    const std::string str2 = "aab";

    EXPECT_EQ(true, isUniqueWithArray(str1));
    EXPECT_EQ(false, isUniqueWithArray(str2));

    EXPECT_EQ(true, isUniqueWithSet(str1));
    EXPECT_EQ(false, isUniqueWithSet(str2));

    EXPECT_EQ(true, inUniqueNoDataStructuresBruteForce(str1));
    EXPECT_EQ(false, inUniqueNoDataStructuresBruteForce(str2));

    EXPECT_EQ(true, isUniqueNoDataStructuresWithSort(str1));
    EXPECT_EQ(false, isUniqueNoDataStructuresWithSort(str2));
}
