#include <iostream>
using namespace std;

//Creating a node

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};
void PrintSinglyLinkedList(SinglyLinkedListNode* head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
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
SinglyLinkedListNode* DeleteNode(SinglyLinkedListNode* head, int position)
{
    SinglyLinkedListNode* iterator = head;
    SinglyLinkedListNode* t;
    int i = 0;
    if (position == 0)
    {
        t = head;
        head = head->next;
        free(t);
        return head;

    }
    while (i < position - 1)
    {
        iterator = iterator->next;
        i++;
    }
    t = iterator->next;
    iterator->next = iterator->next->next;
    free(t);
    return head;
}
int main()
{
    SinglyLinkedListNode* head = new SinglyLinkedListNode;
    int position;
    int data;
    int n;
    cin >> n;
    cin >> head->data;
    head->next = NULL;
    for (int i = 1; i < n; i++)
    {
        cin >> data;
        head = InsertIntoSinglyLinkedList(head, data);
    }
    cin >> position;
    head = DeleteNode(head, position);
    PrintSinglyLinkedList(head);
    return 0;
}