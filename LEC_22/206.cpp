//bruteforce approach:

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        vector<int> a;

        ListNode* temp = head;

        // Store all values
        while (temp != nullptr) {
            a.push_back(temp->val);
            temp = temp->next;
        }

        // Write values in reverse order
        temp = head;
        int i = a.size() - 1;

        while (temp != nullptr) {
            temp->val = a[i];
            i--;
            temp = temp->next;
        }

        return head;
    }
};


//optimal - reverse pointers

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next; // Save next node
            curr->next = prev;               // Reverse link
            prev = curr;                     // Move prev
            curr = nextNode;                 // Move curr
        }

        return prev; // New head
    }
};

