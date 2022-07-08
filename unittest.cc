#include <gtest/gtest.h>
#include <cmath>

#include "01 IsUnique.h"
#include "02 CheckPermutation.h"
#include "03 Urlify.h"
#include "04 Palindrome permutation.h"


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

