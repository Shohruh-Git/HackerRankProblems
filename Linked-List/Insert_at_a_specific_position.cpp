#include <iostream>
using namespace std;
//Node for linked list
struct SinglyLinkedListNode
{
    int data;
    SinglyLinkedListNode* next;
   
};
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position)
{
    SinglyLinkedListNode* iterator = head;

    SinglyLinkedListNode* new_node = new SinglyLinkedListNode(); // creating new node and passing its data by constructor
    new_node->data = data;
    new_node->next = NULL;
    SinglyLinkedListNode* temp; // temporary pointer

    int i = 0;

    if (position == 0)
    {
        new_node->next = iterator;
        return head;
    }
    else
    {
        while (i < position - 1)
        {
            iterator = iterator->next;
            i++;
        }
        temp = iterator->next;
        iterator->next = new_node;
        new_node->next = temp;

    }
    return head;

}
SinglyLinkedListNode* InsertIntoSinglyLinkedList(SinglyLinkedListNode* head, int data)
{
    SinglyLinkedListNode* new_node = new SinglyLinkedListNode();
    new_node->data = data;
    new_node->next = NULL;
    SinglyLinkedListNode* iterator = head;
    while (iterator->next)
    {
        iterator = iterator->next;
    }
    iterator->next = new_node;
    return head;
    
}
void PrintSinglyLinkedList(SinglyLinkedListNode* head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
    int position;
    int n; // n for iteration
    int data;
    cin >> n;
    SinglyLinkedListNode* head = new SinglyLinkedListNode(); // pointer to node
    cin >> data;
    head->data = data;
    head->next = NULL;
    for (int i = 1; i < n; i++)
    {
        cin >> data;
        head = InsertIntoSinglyLinkedList(head,data);
    }
    cin >> data;
    cin >> position;
    head = insertNodeAtPosition(head, data, position);
    PrintSinglyLinkedList(head);
    return 0;
}