//brute force

class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> visited;

        ListNode* temp = head;

        while (temp != nullptr) {
            // If this node was seen before, a cycle exists
            if (visited.count(temp)) {
                return true;
            }

            visited.insert(temp);
            temp = temp->next;
        }

        return false;
    }
};

//optimal

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;       // One step
            fast = fast->next->next; // Two steps

            // Both pointers meet inside a cycle
            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};