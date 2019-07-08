// removeDuplicatesFromLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<forward_list>
using namespace std;

class LinkedListNode
{
public:
	LinkedListNode(int d);
	~LinkedListNode();
	bool operator ==( LinkedListNode second)
	{
		return this->data == second.getData();
	}
	int getData(void);
	void setData(int d);


private:
	int data;
	LinkedListNode * next;

};

LinkedListNode::LinkedListNode(int d):data(d),next(nullptr)
{

}

LinkedListNode::~LinkedListNode()
{
}

int LinkedListNode::getData(void)
{
	return this->data;
}

void LinkedListNode::setData(int d)
{
	this->data = d;
}

static void deleteDups2(LinkedListNode head) {
	 if (head == NULL) return;
	 LinkedListNode previous = head;
	 LinkedListNode current = previous.next;
	 while (current != null) {
		 LinkedListNode runner = head;
		 while (runner != current) { // Check for earlier dups
			 if (runner.data == current.data) {
				 LinkedListNode tmp = current.next; // remove current
				 previous.next = tmp;
				 current = tmp; // update current to next node
				 break; // all other dups have already been removed
				
			}
			 runner = runner.next;
			
		}
		 if (runner == current) { // current not updated - update now
			 previous = current;
			 current = current.next;
			
		}
		
	}
	
}

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
