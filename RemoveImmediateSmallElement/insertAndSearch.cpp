#include <iostream>
using namespace std;
struct Node
{
	int data;
	struct Node* next;
};
void append(struct Node** headRef, int newData)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	struct Node* last = *headRef;
	new_node->data = newData;
	new_node->next = NULL;
	if (*headRef == NULL)
	{
		*headRef = new_node;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}
void printList(struct Node* head) {
	while (head) {
		cout << head->data << " ";
		head = head->next;
	}
}
int countPairs(struct Node* head1, struct Node* head2, int x);
// Driver program to test above
int main()
{
	int T;
	cin >> T;
	while (T--) {
		struct Node* head1 = NULL;
		struct Node* head2 = NULL;
		int n1, n2, tmp, x;
		cin >> n1;
		while (n1--) {
			cin >> tmp;
			append(&head1, tmp);
		}
		cin >> n2;
		while (n2--) {
			cin >> tmp;
			append(&head2, tmp);
		}
		cin >> x;
		cout << countPairs(head1, head2, x) << "\n";
	}
	return 0;
}


/*This is a function problem.You only need to complete the function given below*/
/*
Structure of the node of the linked list is as
struct BSTNode
{
   int data;
   struct Node* next;
   struct Node* left;
   struct Node* right;
};
*/
// your task is to complete this function 
struct BSTNode
{
	int data;
	struct BSTNode* left;
	struct BSTNode* right;
};

void insertNode(struct BSTNode*, int);
int exists(struct BSTNode*, int);

int countPairs(struct Node* head1, struct Node* head2, int x)
{
	struct BSTNode newNode;
	struct BSTNode* rootTree2 = &newNode;
	int count = 0;
	rootTree2->data = head2->data;
	struct Node* listPointer2 = head2->next;
	//Code here
	while (listPointer2 != nullptr)
	{
		insertNode(rootTree2, listPointer2->data);
		listPointer2 = listPointer2->next;
	}
	struct Node* listPointer1 = head1;
	int value;
	while (listPointer1 != nullptr)
	{
		value = x - listPointer1->data;
		if (exists(rootTree2, value))
		{
			count++;
		}
	}
}

void insertNode(struct BSTNode* root, int data)
{
	if (root == nullptr)
	{
		struct BSTNode newNode;
		newNode.data = data;
		root = &newNode;
	}

	else if (root->data < data)
	{
		insertNode(root->right, data);

	}
	else if (root->data >= data)
	{
		insertNode(root->left, data);
	}
}

int exists(struct BSTNode* root, int data)
{
	if (root == nullptr)
		return 0;
	else if (root->data == data)
		return 1;
	else if (root->data < data)
		return exists(root->left, data);
	else if (root->data > data)
		return exists(root->right, data);
}

int countPairElements(Node * head1, Node * head2, int givenValue) {
	//base case
	while (head1 != nullptr)
	{
		if (head2 != nullptr && head1->data + head2->data == givenValue)
			return 1 + countPairElements(head1, head2->next, givenValue);
		else if (head2 != nullptr && head1->data + head2->data != givenValue)
			return  countPairElements(head1, head2->next, givenValue);
		else
			return 0;
		head1 = head1->next;

	}
}