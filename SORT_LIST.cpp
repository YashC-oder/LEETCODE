// first intuation

// class Solution {
// public:
   
// ListNode* merge(ListNode* list1, ListNode* list2) {
//     ListNode* curr = nullptr;
//     ListNode* head = nullptr;

//     while (list1 && list2) {
//         if (list1->val < list2->val) {
//             if (!head) {
//                 curr = list1;
//                 head = curr;
//             } else {
//                 curr->next = list1;
//                 curr = curr->next;
//             }
//             list1 = list1->next;
//         } else {
//             if (!head) {
//                 curr = list2;
//                 head = curr;
//             } else {
//                 curr->next = list2;
//                 curr = curr->next;
//             }
//             list2 = list2->next;
//         }
//     }

//     if (list1) {
//         curr->next = list1;
//     }
//     if (list2) {
//         curr->next = list2;
//     }

//     return head;
// }



//     ListNode* sortList(ListNode* head1) {
//         if(!head1) return nullptr;
        
//         ListNode* midNode = head1;
//         ListNode* fast = head1;
//         while(fast&&fast->next){
//             midNode = midNode->next;
//             fast = fast->next->next;
//         }
        
//         ListNode* head2 = midNode->next;
//         midNode->next = nullptr;

//         head1 = sortList(head1);
//         head2 = sortList(head2);
        
//         return merge(head1,head2);
//     }
// };

class Solution {
public:
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        
        tail->next = list1 ? list1 : list2;
        
        return dummy.next;
    }

    ListNode* split(ListNode* head, int size) {
        while (size > 1 && head) {
            head = head->next;
            size--;
        }
        if (!head) return nullptr;
        ListNode* second = head->next;
        head->next = nullptr;
        return second;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        int length = 0;
        ListNode* node = head;
        while (node) {
            length++;
            node = node->next;
        }

        ListNode dummy(0);
        dummy.next = head;

        for (int size = 1; size < length; size *= 2) {
            ListNode* prev = &dummy;
            ListNode* curr = dummy.next;

            while (curr) {
                ListNode* left = curr;
                ListNode* right = split(left, size);
                curr = split(right, size);

                prev->next = merge(left, right);
                while (prev->next) {
                    prev = prev->next;
                }
            }
        }

        return dummy.next;
    }
};
