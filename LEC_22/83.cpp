//bruteforce

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        set<int> s;

        ListNode* temp = head;

        while (temp != nullptr) {
            s.insert(temp->val);
            temp = temp->next;
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        for (int x : s) {
            tail->next = new ListNode(x);
            tail = tail->next;
        }

        return dummy.next;
    }
};

//optimal

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;

        while (curr != nullptr && curr->next != nullptr) {
            if (curr->val == curr->next->val) {
                curr->next = curr->next->next; // Skip duplicate
            } else {
                curr = curr->next; // Move forward
            }
        }

        return head;
    }
};

