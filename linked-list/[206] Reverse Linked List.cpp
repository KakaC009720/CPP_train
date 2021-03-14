ListNode* reverseList(ListNode* head) {
        if(!head)
        {
            return NULL;
        }
        ListNode *curr = head->next;
        ListNode *p;
        head->next = NULL;
        while(curr)
        {
            p = curr->next;
            curr->next = head;
            head = curr;
            curr = p;
        }
        return head;
    }
