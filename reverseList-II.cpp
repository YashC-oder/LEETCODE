// 4ms
class Solution {
private:
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        return prev;
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        for (int i = 1; i < left; ++i) {
            prev = prev->next;
        }

        ListNode* current = prev->next;
        ListNode* tail = current;
        for (int i = 0; i < right - left; ++i) {
            tail = tail->next;
        }
        ListNode* nextSegment = tail->next;
        tail->next = nullptr;

        prev->next = reverseList(current);

        current->next = nextSegment;

        return dummy.next;
    }
};

/*--------------------------------------------------------------*/
// 0ms
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> values;

        int i = 1;
        ListNode* node = head;

        while(node){
            if(i >= left && i <= right){
                values.push_back(node->val);
            }
            node = node->next;
            i++;
        }


        i = 1;
        node = head;

        while(node){
            if(i >= left && i <= right){
                node->val = values.back();
                values.pop_back();
            }
            node = node->next;
            i++;
        }

        return head;
    }
};
