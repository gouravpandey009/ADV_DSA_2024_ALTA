//brute force 

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n = 0;
        ListNode* temp = head;

        // Count all nodes
        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }

        // Move to the middle
        temp = head;

        for (int i = 0; i < n / 2; i++) {
            temp = temp->next;
        }

        return temp;
    }
};


//optimal

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;       // One step
            fast = fast->next->next; // Two steps
        }

        return slow;
    }
};

