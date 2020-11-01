#include <iostream>

using namespace std;

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};


SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {

    SinglyLinkedListNode* prev_node = NULL;
    SinglyLinkedListNode* current_node = head;
    SinglyLinkedListNode* next_node;

    while (current_node)
    {
        next_node = current_node->next;
        current_node->next = prev_node;
        prev_node = current_node;
        current_node = next_node;
    }
    return prev_node;

}
void PrintSinglyLinkedList(SinglyLinkedListNode* head)
{
    while (head)
    {
        cout << head->data<<" ";
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

int main()
{
    SinglyLinkedListNode* head = new SinglyLinkedListNode;
   
    int test_cases;
    cin >> test_cases;
    int inner_loop;
    head->next = NULL;
    int data;
    for (int i = 0; i < test_cases; i++)
    {
        cin >> inner_loop;
        cin >> head->data;
        head->next = NULL;
        for (int j = 1; j < inner_loop; j++)
        {
            cin >> data;
            head = InsertIntoSinglyLinkedList(head, data);
        }
        head = reverse(head);
        PrintSinglyLinkedList(head);
    }
    return 0;
}