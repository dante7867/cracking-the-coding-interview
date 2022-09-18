#include <iostream>
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
    void partition()
    {
        
    }
};

