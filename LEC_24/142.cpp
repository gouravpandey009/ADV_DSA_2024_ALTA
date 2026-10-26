//brute force

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> visited;

        ListNode* temp = head;

        while (temp != nullptr) {
            // Repeated address means cycle starts here
            if (visited.count(temp)) {
                return temp;
            }

            visited.insert(temp);
            temp = temp->next;
        }

        return nullptr; // No cycle
    }
};

//optimal approach

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Find a meeting point
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Step 2: Reset slow to head
                slow = head;

                // Step 3: Find cycle start
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        return nullptr; // No cycle
    }
};