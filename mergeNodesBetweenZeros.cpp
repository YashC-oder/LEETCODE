class Solution {
private: 
    void merge(ListNode* current ,ListNode* prev){
        if(current->val == 0){
            if(!current->next){
                prev->next = nullptr;
                return;
            }
            prev->next = current;
            prev = current;
        }
        prev->val += current->val;
        merge(current->next,prev);
    }
public:
    ListNode* mergeNodes(ListNode* head) {
        merge(head->next,head);
        return head;
    }
};