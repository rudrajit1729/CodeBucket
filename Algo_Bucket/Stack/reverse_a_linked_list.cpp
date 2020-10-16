// C/C++ program to print reverse of linked list
// using stack.

/*
Input : 1->2->3->4->5->NULL
Output :5->4->3->2->1->NULL
*/



#include<bits/stdc++.h>
using namespace std;
/* Link list node */
struct Node
{
int data;
struct Node* next;
};
/* Given a reference (pointer to pointer) to the head
of a list and an int, push a new node on the front
of the list. */
void push(struct Node** head_ref, int new_data)
{
struct Node* new_node =
(struct Node*) malloc(sizeof(struct Node));
new_node->data = new_data;
new_node->next = (*head_ref);
(*head_ref)
= new_node;
}
/* Counts no. of nodes in linked list */
int getCount(struct Node* head)
{
int count = 0; // Initialize count
struct Node* current = head; // Initialize current
while (current != NULL)
{
count++;
current = current->next;
}
return count;
}
/* Takes head pointer of the linked list and index
as arguments and return data at index*/
int getNth(struct Node* head, int n)
{
struct Node* curr = head;
for (int i=0; i<n-1 && curr != NULL; i++)
curr = curr->next;
return curr->data;
}
void printReverse(Node *head)
{
// store Node addresses in stack
stack<Node *> stk;
Node* ptr = head;
while (ptr != NULL)
{
stk.push(ptr);
ptr = ptr->next;
}
// print data from stack
while (!stk.empty())
{
cout << stk.top()->data << " ";
stk.pop(); // pop after print
}
cout << "\n";
}
/* Driver program to test count function*/
int main()
{
/* Start with the empty list */
struct Node* head = NULL;
/* Use push() to construct below list
1->2->3->4->5 */
push(&head, 5);
push(&head, 4);
push(&head, 3);
push(&head, 2);
push(&head, 1);
printReverse(head);
return 0;
}