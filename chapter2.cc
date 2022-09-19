#include <gtest/gtest.h>
#include <cmath>
#include <set>

#include "Node.h"


bool areThereAnyDuplicates(Node* n)
{
    std::set<int> presentValues;

    while(nullptr != n)
    {
	std::cout << n->val << " ";
	if(presentValues.contains(n->val))
	    return true;
	presentValues.insert(n->val);
	n = n->next;
    }
    return false;
}


TEST(ch2_ex1_removeDuplicates, SomeDuplicates)
{
    Node* n = new Node{1};
    n->appendToTail(2);
    n->appendToTail(3);
    n->appendToTail(4);
    n->appendToTail(4);
    n->appendToTail(4);
    n->appendToTail(4);
    n->appendToTail(5);

    EXPECT_TRUE(areThereAnyDuplicates(n));
    
    n->removeDuplicates();
    EXPECT_FALSE(areThereAnyDuplicates(n));
}


TEST(ch2_ex1_removeDuplicates, ManyDuplicates)
{
    Node* n = new Node{1};
    n->appendToTail(2);
    n->appendToTail(3);
    n->appendToTail(3);
    n->appendToTail(4);
    n->appendToTail(4);
    n->appendToTail(5);

    EXPECT_TRUE(areThereAnyDuplicates(n));

    n->removeDuplicates();
    EXPECT_FALSE(areThereAnyDuplicates(n));
}


TEST(ch2_ex1_removeDuplicates, NoDuplicates)
{
    Node* n = new Node{1};
    n->appendToTail(2);
    n->appendToTail(3);
    n->appendToTail(4);
    n->appendToTail(5);

    EXPECT_FALSE(areThereAnyDuplicates(n));

    n->removeDuplicates();
    EXPECT_FALSE(areThereAnyDuplicates(n));
}

TEST(ch2_ex1_removeDuplicatesNoBuffer, SomeDuplicates)
{
    Node* n = new Node{1};
    n->appendToTail(2);
    n->appendToTail(3);
    n->appendToTail(4);
    n->appendToTail(4);
    n->appendToTail(4);
    n->appendToTail(4);
    n->appendToTail(5);

    EXPECT_TRUE(areThereAnyDuplicates(n));
    
    n->removeDuplicatesNoBuffer();
    EXPECT_FALSE(areThereAnyDuplicates(n));
}


TEST(ch2_ex1_removeDuplicatesNoBuffer, ManyDuplicates)
{
    Node* n = new Node{1};
    n->appendToTail(2);
    n->appendToTail(3);
    n->appendToTail(3);
    n->appendToTail(4);
    n->appendToTail(4);
    n->appendToTail(5);

    EXPECT_TRUE(areThereAnyDuplicates(n));

    n->removeDuplicatesNoBuffer();
    EXPECT_FALSE(areThereAnyDuplicates(n));
}


TEST(ch2_ex1_removeDuplicatesNoBuffer, NoDuplicates)
{
    Node* n = new Node{1};
    n->appendToTail(2);
    n->appendToTail(3);
    n->appendToTail(4);
    n->appendToTail(5);

    EXPECT_FALSE(areThereAnyDuplicates(n));

    n->removeDuplicates();
    EXPECT_FALSE(areThereAnyDuplicates(n));
}


TEST(ch2_ex2_return_kth_to_last, KlargerThenListLenght)
{
    Node* n = new Node{1};
    EXPECT_EQ(nullptr, n->getKthToLast(1000));
}


TEST(ch2_ex2_return_kth_to_last, negativeK)
{
    Node* n = new Node{1};
    
    EXPECT_EQ(nullptr, n->getKthToLast(-1));
}


TEST(ch2_ex2_return_kth_to_last, lastElement)
{
    Node* n = new Node{1};
    n->appendToTail(2);
    n->appendToTail(3);
    n->appendToTail(4);
    n->appendToTail(5);
    
    EXPECT_EQ(5, n->getKthToLast(0)->val);
}


TEST(ch2_ex2_return_kth_to_last, checkWholeList)
{
    Node* n = new Node{1};
    n->appendToTail(2);
    n->appendToTail(3);
    n->appendToTail(4);
    n->appendToTail(5);
    
    EXPECT_EQ(5, n->getKthToLast(0)->val);
    EXPECT_EQ(4, n->getKthToLast(1)->val);
    EXPECT_EQ(3, n->getKthToLast(2)->val);
    EXPECT_EQ(2, n->getKthToLast(3)->val);
    EXPECT_EQ(1, n->getKthToLast(4)->val);
}


TEST(ch2_ex3_deteleMiddleNode, RandomValues)
{
    Node* n = new Node{1};
    n->appendToTail(2);
    n->appendToTail(3);
    n->appendToTail(4);
    n->appendToTail(5);
    
    n->deleteMiddleNode(4);
    std::vector<int> expected = {1, 2, 3, 5};
    EXPECT_EQ(n->toVector(), expected);

    n->deleteMiddleNode(2);
    expected = {1, 3, 5};
    EXPECT_EQ(n->toVector(), expected);

    n->deleteMiddleNode(3);
    expected = {1, 5};
    EXPECT_EQ(n->toVector(), expected);
}


TEST(ch2_ex3_deteleMiddleNode, DoesntDeleteFirstElement)
{
    Node* n = new Node{1};
    n->appendToTail(2);
    n->appendToTail(3);
    n->appendToTail(4);
    n->appendToTail(5);
    
    n->deleteMiddleNode(1);
    std::vector<int> expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(n->toVector(), expected);
}


TEST(ch2_ex3_deteleMiddleNode, DoesntDeleteLastElement)
{
    Node* n = new Node{1};
    n->appendToTail(2);
    n->appendToTail(3);
    n->appendToTail(4);
    n->appendToTail(5);
    
    n->deleteMiddleNode(5);
    std::vector<int> expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(n->toVector(), expected);
}


TEST(ch2_ex4_partition, basicTest)
{
    Node* n = new Node(3);
    n->appendToTail(5);
    n->appendToTail(8);
    n->appendToTail(5);
    n->appendToTail(10);
    n->appendToTail(2);
    n->appendToTail(1);

    n->partition(5);
    auto is_smaller_than_five = [](int i){ return i < 5; };
    auto vec = n->toVector();
    EXPECT_TRUE(std::is_partitioned(vec.begin(), vec.end(), is_smaller_than_five));
}


TEST(ch2_ex4_partition, PartitionedFromStart)
{
    Node* n = new Node(1);
    n->appendToTail(2);
    n->appendToTail(3);
    n->appendToTail(4);
    n->appendToTail(5);
    n->appendToTail(6);

    n->partition(3);
    auto is_smaller_than_three = [](int i){ return i < 3; };
    auto vec = n->toVector();
    EXPECT_TRUE(std::is_partitioned(vec.begin(), vec.end(), is_smaller_than_three));
}


TEST(ch2_ex4_partition, ValueBiggerThanAnyListElement)
{
    Node* n = new Node(6);
    n->appendToTail(5);
    n->appendToTail(4);
    n->appendToTail(3);
    n->appendToTail(2);
    n->appendToTail(1);

    n->partition(100);
    auto is_smaller_than_100 = [](int i){ return i < 100; };
    auto vec = n->toVector();
    EXPECT_TRUE(std::is_partitioned(vec.begin(), vec.end(), is_smaller_than_100));
}


TEST(ch2_ex4_partition, ValueSmallerThanAnyListElement)
{
    Node* n = new Node(6);
    n->appendToTail(5);
    n->appendToTail(4);
    n->appendToTail(3);
    n->appendToTail(2);
    n->appendToTail(1);

    n->partition(0);
    auto is_smaller_than_0 = [](int i){ return i < 100; };
    auto vec = n->toVector();
    EXPECT_TRUE(std::is_partitioned(vec.begin(), vec.end(), is_smaller_than_0));
}


TEST(ch2_ex5_sumLists, differentLengths)
{

    Node* n1 = new Node(7);
    n1->appendToTail(1);
    n1->appendToTail(6);
    n1->appendToTail(1);

    Node* n2 = new Node(5);
    n2->appendToTail(9);
    n2->appendToTail(2);
    EXPECT_EQ(1617+295, sumLists(n1, n2));
}


TEST(ch2_ex5_sumLists, sameLengthLists)
{
    Node* n = new Node(1);
    n->appendToTail(2);
    n->appendToTail(3);
    EXPECT_EQ(321+321, sumLists(n, n));
}


TEST(ch2_ex5_sumLists, example)
{
    Node* n1 = new Node(7);
    n1->appendToTail(1);
    n1->appendToTail(6);

    Node* n2 = new Node(5);
    n2->appendToTail(9);
    n2->appendToTail(2);
    EXPECT_EQ(617+295, sumLists(n1, n2));
}


TEST(ch2_ex5_sumListsForwardOrder, differentLengths)
{

    Node* n1 = new Node(7);
    n1->appendToTail(1);
    n1->appendToTail(6);
    n1->appendToTail(1);

    Node* n2 = new Node(5);
    n2->appendToTail(9);
    n2->appendToTail(2);
    EXPECT_EQ(7161+592, sumListsForwardOrder(n1, n2));
}


TEST(ch2_ex5_sumListsForwardOrder, sameLengthLists)
{
    Node* n = new Node(1);
    n->appendToTail(2);
    n->appendToTail(3);
    EXPECT_EQ(123+123, sumListsForwardOrder(n, n));
}


TEST(ch2_ex5_sumListsForwardOrder, example)
{
    Node* n1 = new Node(7);
    n1->appendToTail(1);
    n1->appendToTail(6);

    Node* n2 = new Node(5);
    n2->appendToTail(9);
    n2->appendToTail(2);
    EXPECT_EQ(716+592, sumListsForwardOrder(n1, n2));
}


TEST(ch2_ex6_isPalindrome, retTrue)
{
    Node* n1 = new Node(7);
    n1->appendToTail(1);
    n1->appendToTail(7);
    EXPECT_TRUE(isPalindrome(n1));

}


TEST(ch2_ex6_isPalindrome, retFalse)
{
    Node* n1 = new Node(7);
    n1->appendToTail(1);
    n1->appendToTail(6);
    EXPECT_FALSE(isPalindrome(n1));
}


TEST(ch2_ex6_isPalindromeWithVector, oneItemList)
{
    Node* n1 = new Node(7);
    EXPECT_TRUE(isPalindrome(n1));
}


TEST(ch2_ex6_isPalindromeWithVector, retTrue)
{
    Node* n1 = new Node(7);
    n1->appendToTail(1);
    n1->appendToTail(7);
    EXPECT_TRUE(isPalindromeWithVector(n1));

}


TEST(ch2_ex6_isPalindromeWithVector, retFalse)
{
    Node* n1 = new Node(7);
    n1->appendToTail(1);
    n1->appendToTail(6);
    EXPECT_FALSE(isPalindromeWithVector(n1));
}

