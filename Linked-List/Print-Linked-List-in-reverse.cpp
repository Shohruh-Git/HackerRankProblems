#include <iostream>
using namespace std;

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};
void PrintSinglyLinkedListReverse(SinglyLinkedListNode* head)
{
    if (head == NULL)
        return;
    if (head)
    {
        PrintSinglyLinkedListReverse(head->next);
        cout << head->data << endl;
    }
}


//Insert into Linked List
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

int main()
{

    SinglyLinkedListNode* head = new SinglyLinkedListNode;
    int OuterLoop, data,Innerloop;
    cin >> OuterLoop;

    head->next = NULL;
    for (int i = 0; i < OuterLoop; i++)
    {
        cin >> Innerloop;
        cin >> head->data;
        for (int j = 1; j < Innerloop; j++)
        {
            cin >> data;
            head = InsertIntoSinglyLinkedList(head, data);
        }
        PrintSinglyLinkedListReverse(head);
        
    }


    return 0;
}