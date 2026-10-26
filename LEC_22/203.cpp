//bruteforce

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        ListNode* temp = head;

        while (temp != nullptr) {
            if (temp->val != val) {
                tail->next = new ListNode(temp->val);
                tail = tail->next;
            }

            temp = temp->next;
        }

        return dummy.next;
    }
};

//optimal

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* curr = &dummy;

        while (curr->next != nullptr) {
            if (curr->next->val == val) {
                curr->next = curr->next->next; // Remove node
            } else {
                curr = curr->next; // Move forward
            }
        }

        return dummy.next;
    }
};

