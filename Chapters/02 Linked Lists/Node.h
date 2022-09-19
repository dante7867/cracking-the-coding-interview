#include <stack>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>


struct Node
{
    Node(int num):val{num} {};
    Node* next = nullptr;
    int val;


    void appendToTail(int num)
    {
        Node* n = this;
        while(n->next != nullptr)
            n = n->next;
        n->next = new Node(num);
    }


    Node* deleteNode(Node* head, int num)
    {
        Node* n = head;
        if(head->val == num)
        {
            head = n->next;
            delete n;
            return head;
        }

        while(n->next != nullptr)
        {
            if(n->next->val == num)
            {
                auto nextNext = n->next->next;
                delete n->next;
                n->next = nextNext;
                return head;
            }
            n = n->next;
        }
        return head;
    }
    

    void print()
    {
        Node* n = this;
        while(n != nullptr)
        {
            std::cout << n->val << " ";
            n = n->next;
        }
        std::cout << "\n";
    }

    std::vector<int> toVector()
    {
	std::vector<int> ret;
	Node* n = this;

	while(n != nullptr)
	{
	    ret.push_back(n->val);
	    n = n->next;
	}
	return ret;
    }

    // Q 2.1. Remove Dups:
    // Remove Dups! Write code to remove duplicates from an unsorted linked list. 
    void removeDuplicates()
    {
        std::set<int> present {this->val};
        Node* n = this;

        while(n->next != nullptr)
        {
            if(present.find(n->next->val) == std::end(present))
            {
               present.insert(n->next->val);
               n = n->next;
            }
            else
            {
                auto nextNext = n->next->next;
                delete n->next;
                n->next = nextNext;
            }
        }
    }

    // Q 2.1. Remove Dups:
    // Remove Dups! Write code to remove duplicates from an unsorted linked list. 
    void removeDuplicatesNoBuffer()
    {
        Node* head = this;
        Node* n = head;
        bool removed = false;

        while(n->next != nullptr)
        {
            Node* runner = head;
            removed = false;
            
            while(runner != n->next)
            {
                if(runner->val == n->next->val)
                {
                    auto nextNext = n->next->next;
                    delete n->next;
                    n->next = nextNext;
                    removed = true;
                    break;
                }
                runner = runner->next;
            }
            if(!removed)
                n = n->next;
        }
    }

    // Q 2.2. Return Kth to last
    // Implement an algorithm to find the kth to last element of a singly linked list.
    Node* getKthToLast(int K)
    {
        if(K < 0)
            return nullptr;

        int linkedListLength = 1;
        Node* head = this;
        Node* n = this;
        
        while(n->next != nullptr)
        {
            ++linkedListLength;
            n = n->next;
        }

        if(linkedListLength <= K)
           return nullptr;
        
        n = head;
        while(--linkedListLength != K)
            n = n->next;

        return n;
    }
    

    // 2.3 Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., any node but
    // the first and last node, not necessarily the exact middle) of a singly linked list, given only access to
    // that node.
    // EXAMPLE
    // Input:the node c from the linked list a->b->c->d->e->f
    //Result: nothing is returned, but the new linked list looks like a->b->d->e->f
    void deleteMiddleNode(int valueToDelete)
    {
        Node* n = this;
        while(n->next != nullptr)
        {
            if(n->next->val == valueToDelete)
            {
                auto nextNext = n->next->next;
                if(nextNext == nullptr) // if n->next is last element
                    return;

                delete n->next;
                n->next = nextNext;
                return;
            }
            n = n->next; 
        }
    }


    /*
     * Partition: Write code to partition a linked list around a value x, such that all nodes less than x come
     * before all nodes greater than or equal to x. If x is contained within the list, the values of x only need
     * to be after the elements less than x (see below). The partition element x can appear anywhere in the
     * "right partition"; it does not need to appear between the left and right partitions.
     * EXAMPLE
     * Input:
     * Output:
     * 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition= 5]
     * 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8
     */
    void partition(int value)
    {
	Node* bigger = this;
	Node* smaller = this;
	
	while(true)
	{
		while(bigger->val < value)
		{
			bigger = bigger->next;
			if(nullptr == bigger)
				return;
		}
		smaller = bigger;
		while(smaller->val >= value)
		{
			smaller = smaller->next;
			if(nullptr == smaller)
				break;
		}
		if(nullptr == bigger || nullptr == smaller)
			return;
		std::swap(bigger->val, smaller->val);
	}
    }
};

/*
2.5 Sum Lists: You have two numbers represented by a linked list, where each node contains a single
digit. The digits are stored in reverse order, such that the 1 's digit is at the head of the list. Write a
function that adds the two numbers and returns the sum as a linked list.
EXAMPLE
Input: (7-> 1 -> 6) + (5 -> 9 -> 2).That is,617 + 295.
Output: 2 -> 1 -> 9. That is, 912.
FOLLOW UP
Suppose the digits are stored in forward order. Repeat the above problem.
EXAMPLE
lnput:(6 -> 1 -> 7) + (2 -> 9 -> 5).That is,617 + 295.
Output: 9 -> 1 -> 2. That is, 912.
*/

int toInt(Node* n)
{
    int sum = 0;

    int mul = 1;
    while(n)
    {
	sum += mul*(n->val);
	mul *= 10;
	n = n->next;
    }

    return sum;
}
int sumLists(Node* n1, Node* n2)
{
    return toInt(n1) + toInt(n2);
}

int toIntForwardOrder(Node* n)
{
    int sum = 0;	
    int mul = 1;

    Node* x1 = n;
    while(x1)
    {
	mul *= 10;
	x1 = x1->next;
    }

    while(n)
    {
	mul /= 10;
	sum += mul*(n->val);
	n = n->next;
    }
    return sum;
}


int sumListsForwardOrder(Node* n1, Node* n2)
{
    return toIntForwardOrder(n1) + toIntForwardOrder(n2);
}


/*
 * 2.6 Palindrome: Implement a function to check if a linked list is a palindrome.
 * Hints:#5, #13, #29, #61, #101
 */
bool isPalindrome(Node* n)
{
    if(!n->next)
	return true;

    std::stack<int> stack;
    Node* p1 = n;
    Node* p2 = n;
    
    // find node in the middle
    while(p2)
    {
	p2 = p2->next;
	if(p2)
	{
	   p2 = p2->next;
	   p1 = p1->next;
	}
    }
    // push values from middle to stack
    p2 = p1;
    while(p2)
    {
        stack.push(p2->val);
	p2 = p2->next;
    }
    // compare stack with beggining of the list
    while(n!=p1)
    {
	if(stack.top() != n->val)
	    return false;
	stack.pop();
	n = n->next;
    }
    return true;
}


bool isPalindromeWithVector(Node* n)
{
    auto vec = n->toVector();
    size_t i, j;
    for(i = 0, j = vec.size() - 1; i < j; ++i, --j)
    {
        if(vec[i] != vec[j])
	    return false;
    }
    return true;
}


/*
2.7 Intersection: Given two (singly) linked lists, determine if the two lists intersect. Return the intersecting node. Note that the intersection is defined based on reference, not value. That is, if the kth
node of the first linked list is the exact same node (by reference) as the jth node of the second
linked list, then they are intersecting.
Hints:#20, #45, #55, #65, #76, #93, #111, #120, #129
*/

Node* getIntersection(Node* n1, Node* n2)
{
    // easy in c++ since we can comepare addresses
    while(n1)
    {
	Node* m = n2;
	while(m)
	{
	     if(m == n1)
		return m;
	     m = m->next;
	}
	n1 = n1->next;
    }
    return nullptr;
}

/*
2.8 Loop Detection: Given a circular linked list, implement an algorithm that returns the node at the
beginning of the loop.
DEFINITION
Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node, so
as to make a loop in the linked list.
EXAMPLE
Input: A -> B -> C -> D -> E -> C [the same C as earlier]
Output: C
Hints: #50, #69, #83, #90
*/

Node* getLoopStart(Node* n)
{
    std::set<Node*> s;
    while(n)
    {
        if(s.contains(n))
	    return n;
	s.insert(n);
	n = n->next;
    }
    return nullptr;
}

