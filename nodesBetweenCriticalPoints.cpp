class Solution {
private:
    bool isCritical(ListNode* node, ListNode* prev) {
        if (prev && node->next) {
            int prev_val = prev->val;
            int node_val = node->val;
            int next_val = node->next->val;
            if ((node_val > prev_val && node_val > next_val) || (node_val < prev_val && node_val < next_val)) {
                return true;
            }
        }
        return false;
    }
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int index = 0, first = -1, second = -1;
        ListNode* node = head;
        ListNode* prev = nullptr;
        int mini = INT_MAX, maxi = INT_MIN;

        while (node && node->next) {
            if (isCritical(node, prev)) {
                if (first == -1) {
                    first = index;
                    second = index;
                } else {
                    mini = min(mini, index - second);
                    maxi = max(maxi, index - first);
                    second = index;
                }
            }
            prev = node;
            node = node->next;
            index++;
        }

        if (maxi == INT_MIN) maxi = -1;
        if (mini == INT_MAX) mini = -1;

        return {mini, maxi};
    }
};
