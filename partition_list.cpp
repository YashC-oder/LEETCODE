class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* left = &dummy;
        ListNode* right = head;
        ListNode* prev = &dummy;

        while (right) {
            if (right->val < x) {
                if (left->next == right) {
                    left = left->next;
                    prev = right;
                    right = right->next;
                } else {
                    prev->next = right->next;
                    right->next = left->next;
                    left->next = right;
                    left = left->next;
                    right = prev->next;
                }
            } else {
                prev = right;
                right = right->next;
            }
        }

        return dummy.next;
    }
};
