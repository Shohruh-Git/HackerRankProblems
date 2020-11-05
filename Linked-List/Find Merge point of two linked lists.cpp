int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode *temp = head1;
    while(head2){
        head1 = temp;
        while(head1)
        {
            if(head1==head2)
            {
                return head1->data;
            }
            head1=head1->next; 
        }
        head2 = head2->next;
    }
    return 0;
}
