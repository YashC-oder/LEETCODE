class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

    ListNode* split(ListNode* node, int k) {
        while (k > 1 && node) {
            node = node->next;
            k--;
        }
        if (!node) return nullptr;
        ListNode* nextSegment = node->next;
        node->next = nullptr;
        return nextSegment;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Calculate the length of the list
        int length = 0;
        ListNode* node = head;
        while (node) {
            node = node->next;
            length++;
        }

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr = head;

        for (int i = 0; i < length / k; i++) {
            ListNode* nextSegment = split(prev->next, k);
           // if (!nextSegment) break; // No more segments to reverse

            prev->next = reverseList(prev->next); // Reverse the current segment

            // Move prev to the end of the reversed segment
            while (prev->next) {
                prev = prev->next;
            }

            // Link the reversed segment to the next segment
            prev->next = nextSegment;
        }

        return dummy.next;
    }
};