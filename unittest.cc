#include <gtest/gtest.h>
#include <cmath>

#include "01 IsUnique.h"
#include "02 CheckPermutation.h"
#include "03 Urlify.h"
#include "04 Palindrome permutation.h"
#include "05 One away.h"
#include "06 String compression.h"
#include "07 Rotate matrix.h"
#include "08 Zero matrix.h"
#include "09 Rotate string.h"

TEST(ch1ex1_isUnique, ZeroLengthStr)
{
    const std::string str{""};
    EXPECT_EQ(true, isUniqueWithArray(str));
    EXPECT_EQ(true, isUniqueWithSet(str));
    EXPECT_EQ(true, inUniqueNoDataStructuresBruteForce(str));
    EXPECT_EQ(true, isUniqueNoDataStructuresWithSort(str));
}


TEST(ch1ex1_isUnique, AllUnique)
{   
    const std::string str = "abcdefghijk";
    EXPECT_EQ(true, isUniqueWithArray(str));
    EXPECT_EQ(true, isUniqueWithSet(str));
    EXPECT_EQ(true, inUniqueNoDataStructuresBruteForce(str));
    EXPECT_EQ(true, isUniqueNoDataStructuresWithSort(str));
}


TEST(ch1ex1_isUnique, NotAllUnique)
{   
    const std::string str = "aab";
    EXPECT_EQ(false, isUniqueWithArray(str));
    EXPECT_EQ(false, isUniqueWithSet(str));
    EXPECT_EQ(false, inUniqueNoDataStructuresBruteForce(str));
    EXPECT_EQ(false, isUniqueNoDataStructuresWithSort(str));
}


TEST(ch1ex1_isUnique, NotAllUniqueApartFromEachOther)
{   
    const std::string str = "oabcdefghijklmno";
    EXPECT_EQ(false, isUniqueWithArray(str));
    EXPECT_EQ(false, isUniqueWithSet(str));
    EXPECT_EQ(false, inUniqueNoDataStructuresBruteForce(str));
    EXPECT_EQ(false, isUniqueNoDataStructuresWithSort(str));
}


TEST(ch1ex2_CheckPermutation, ZeroStrings)
{   
    const std::string str = "";
    EXPECT_TRUE(CheckPermutation(str, str));
    EXPECT_TRUE(CheckPermutationKnownCharacterSets(str, str));
}


TEST(ch1ex2_CheckPermutation, ArePermutationsSingleChar)
{
    const std::string str1 = "x";
    const std::string str2 = "x";
    EXPECT_TRUE(CheckPermutation(str1, str2));
    EXPECT_TRUE(CheckPermutationKnownCharacterSets(str1, str2));
}


TEST(ch1ex2_CheckPermutation, ArePermutations)
{
    const std::string str1 = "abcdefgh";
    const std::string str2 = "hgfedcab";
    EXPECT_TRUE(CheckPermutation(str1, str2));
    EXPECT_TRUE(CheckPermutationKnownCharacterSets(str1, str2));
}


TEST(ch1ex2_CheckPermutation, AreNotPermutations)
{
    const std::string str1 = "abcdefgh";
    const std::string str2 = "abcdefghi";
    EXPECT_FALSE(CheckPermutation(str1, str2));
    EXPECT_FALSE(CheckPermutationKnownCharacterSets(str1, str2));
}

TEST(ch1ex2_CheckPermutation, AreNotPermutationsFirstLonger)
{
    const std::string str1 = "abcdefghi";
    const std::string str2 = "abcdefgh";
    EXPECT_FALSE(CheckPermutation(str1, str2));
    EXPECT_FALSE(CheckPermutationKnownCharacterSets(str1, str2));
}


TEST(ch1ex3_Urlify, EmptyString)
{
    std::string emptyStr = "";
    EXPECT_EQ("", urlifyWithIterators(emptyStr, 0));
    EXPECT_EQ("", urlify(emptyStr, 0));
}


TEST(ch1ex3_Urlify, OnlySpace)
{
    std::string str = "   ";
    EXPECT_EQ("%20", urlifyWithIterators(str, 1));
    EXPECT_EQ("%20", urlify(str, 1));
}


TEST(ch1ex3_Urlify, NormalCases)
{
    std::string str = "abc def ghi    ";
    EXPECT_EQ("abc%20def%20ghi", urlifyWithIterators(str, 11));
    EXPECT_EQ("abc%20def%20ghi", urlify(str, 11));
    
    std::string sJohnSmith = "Mr John Smith    ";
    EXPECT_EQ("Mr%20John%20Smith", urlifyWithIterators(sJohnSmith, 13));
    EXPECT_EQ("Mr%20John%20Smith", urlify(sJohnSmith, 13));
}


TEST(ch1ex4_PalindromePermutations, ArePalindrom)
{
    const std::string abba = "abba";
    EXPECT_TRUE(isPalindrom(abba));

    const std::string ab_ba = "ab ba";
    EXPECT_TRUE(isPalindrom(ab_ba));

    const std::string taco_cat = "taco cat";
    EXPECT_TRUE(isPalindrom(taco_cat));
}


TEST(ch1ex4_PalindromePermutations, NotPalindrom)
{
    const std::string ab_b = "ab b";
    EXPECT_FALSE(isPalindrom(ab_b));
    
    const std::string b_ba = "b ba";
    EXPECT_FALSE(isPalindrom(b_ba));
}


TEST(ch1ex4_PalindromePermutations, ArePalindromWithTrailingOrStartingStrings)
{
    const std::string __ab_ba = "  ab ba";
    EXPECT_TRUE(isPalindrom(__ab_ba));

    const std::string ab_ba__ = "ab ba  ";
    EXPECT_TRUE(isPalindrom(ab_ba__));

    const std::string ___ab_ba__ = "   ab ba  ";
    EXPECT_TRUE(isPalindrom(___ab_ba__));
}


TEST(ch1ex4_toggleBit, BitFlipping)
{
    uint32_t num = 4;
    flipBit(num, 2);
    EXPECT_EQ(0, num); 

    num = 1;
    flipBit(num, 0);
    EXPECT_EQ(0, num); 

    for(int i = 0; i < 32; ++i)
    {
        num = 0;
        flipBit(num, i);
        EXPECT_EQ(pow(2, i), num); 
    }
    
    num = 3;
    flipBit(num, 0);
    EXPECT_EQ(2, num);
}


TEST(ch1ex4_PalindromePermutations, ArePalindromPermutation)
{
    const std::string taco_cat = "taco cat"; 
    EXPECT_TRUE(isPalindromPermutation(taco_cat));
    EXPECT_TRUE(isPalindromPermutationBitMasks(taco_cat));

    const std::string atco_cta = "atco cta";
    EXPECT_TRUE(isPalindromPermutation(atco_cta));
    EXPECT_TRUE(isPalindromPermutationBitMasks(atco_cta));
}


TEST(ch1ex4_PalindromePermutations, NotPalindromPermutation)
{
    const std::string atco_ctc = "atco ctc";
    EXPECT_FALSE(isPalindromPermutation(atco_ctc));
    EXPECT_FALSE(isPalindromPermutationBitMasks(atco_ctc));
}


TEST(ch1ex5_OneAway, EmptyString)
{
    std::cout << isOneAway("", "") << std::endl;
}

TEST(ch1ex5_OneAway, ValidInputs)
{
    EXPECT_TRUE(isOneAway("pale", "pale"));
    EXPECT_TRUE(isOneAway("pale", "ple"));
    EXPECT_TRUE(isOneAway("pales", "pale"));
    EXPECT_TRUE(isOneAway("pale", "bale"));

    EXPECT_FALSE(isOneAway("pale", "bake"));
    EXPECT_FALSE(isOneAway("pale", "pale12"));
    EXPECT_FALSE(isOneAway("pale", ""));
    EXPECT_FALSE(isOneAway("abcde", "bcda"));
}


TEST(ch1ex6_StringCompression, ValidInputs)
{
    const std::string emptyString = "";
    EXPECT_EQ("", compress(emptyString));

    const std::string compressable = "aabcccccaaa";
    EXPECT_EQ("a2b1c5a3", compress(compressable));

    const std::string notWorthCompressing = "aabbcc";
    EXPECT_EQ("aabbcc", compress(notWorthCompressing));

    const std::string xx = "abc";
    EXPECT_EQ("abc", compress(xx));
}


TEST(ch1ex7_RotateMatrix, nIsThree)
{
    std::vector<std::vector<int>> three = { { 1, 2, 3},
                                            { 4, 5, 6},
                                            { 7, 8, 9}}; 
    std::vector<std::vector<int>> rotated_three = {{7,4,1},
                                                   {8,5,2},
                                                   {9,6,3}};
    rotateMatrix(three);
    EXPECT_EQ(rotated_three, three);
}


TEST(ch1ex7_RotateMatrix, nIsFour)
{
    std::vector<std::vector<int>> four = { { 1, 2, 3, 4},
                                           { 5, 6, 7, 8},
                                           { 9,10,11,12},
                                           {13,14,15,16}};

    std::vector<std::vector<int>> rotated_four = {{13, 9, 5, 1},
                                                  {14,10, 6, 2},
                                                  {15,11, 7, 3},
                                                  {16,12, 8, 4} 
                                                 };
    rotateMatrix(four);
    EXPECT_EQ(rotated_four, four);
}


TEST(ch1ex7_RotateMatrix, nIsFive)
{
    std::vector<std::vector<int>> five = { { 1, 2, 3, 4, 5},
                                           { 6, 7, 8, 9,10},
                                           {11,12,13,14,15},
                                           {16,17,18,19,20},
                                           {21,22,23,24,25}};
    
    std::vector<std::vector<int>> rotated_five = {{21,16,11, 6, 1},
                                                  {22,17,12, 7, 2},
                                                  {23,18,13, 8, 3},
                                                  {24,19,14, 9, 4},
                                                  {25,20,15,10, 5}
                                                 };
    rotateMatrix(five);
    EXPECT_EQ(rotated_five, five);
}


TEST(ch1ex8_ZeroMatrix, nIsThree)
{
    std::vector<std::vector<int>> three = { { 1, 2, 3},
                                            { 4, 0, 6},
                                            { 7, 8, 9}};
    

    std::vector<std::vector<int>> zeroed_three = { { 1, 0, 3},
                                            { 0, 0, 0},
                                            { 7, 0, 9}};
    zeroMatrix(three);
    EXPECT_EQ(zeroed_three, three);
}

TEST(ch1ex8_ZeroMatrix, nIsFour)
{
    std::vector<std::vector<int>> four = { { 1, 0, 3, 4},
                                           { 5, 6, 7, 8},
                                           { 9,10,11,12},
                                           {13,14,15,16}};

    std::vector<std::vector<int>> zeroed_four = { { 0, 0, 0, 0},
                                           { 5, 0, 7, 8},
                                           { 9, 0,11,12},
                                           {13, 0,15,16}};

    zeroMatrix(four);
    EXPECT_EQ(zeroed_four, four);
}


TEST(ch1ex8_ZeroMatrix, nIsFive)
{
    std::vector<std::vector<int>> five = { { 1, 0, 3, 4, 5},
                                           { 6, 7, 8, 9,10},
                                           {11,12,13,14,15},
                                           {16,17,18,19,20},
                                           {21,22,23, 0,25}};
    
    std::vector<std::vector<int>> zeroedfive = { { 0, 0, 0, 0, 0},
                                                 { 6, 0, 8, 0,10},
                                                 {11, 0,13, 0,15},
                                                 {16, 0,18, 0,20},
                                                 { 0, 0, 0, 0, 0}};

    zeroMatrix(five);
    EXPECT_EQ(zeroedfive, five);
}


TEST(ch1ex9_RotateString, isRotated)
{
    EXPECT_TRUE(isRotation("waterbottle", "erbottlewat"));
}


TEST(ch1ex9_RotateString, IsNotRotated)
{
    EXPECT_FALSE(isRotation("waterbottlx", "erbottlewat"));
}
