class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        ListNode* current = head;
        
        while (current) {
            if (current->next && current->val == current->next->val) {
                while (current->next && current->val == current->next->val) {
                    current = current->next;
                }
                current = current->next;
            } else {
                tail->next = current;
                tail = current;
                current = current->next;
            }
        }
        
        tail->next = nullptr;

        return dummy.next;
    }
};