//brute force

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> a;

        while (list1 != nullptr) {
            a.push_back(list1->val);
            list1 = list1->next;
        }

        while (list2 != nullptr) {
            a.push_back(list2->val);
            list2 = list2->next;
        }

        sort(a.begin(), a.end());

        ListNode dummy(0);
        ListNode* tail = &dummy;

        for (int x : a) {
            tail->next = new ListNode(x);
            tail = tail->next;
        }

        return dummy.next;
    }
};

//optimal 

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }

            tail = tail->next;
        }

        // Attach the remaining nodes
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        return dummy.next;
    }
};

