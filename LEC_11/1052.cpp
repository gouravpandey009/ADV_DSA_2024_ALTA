class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

        int n = customers.size();

        // Normal satisfied customers
        int satisfied = 0;

        // Customers we can make satisfied using secret technique
        int extra = 0;

        // Maximum extra customers we can satisfy
        int maxExtra = 0;

        // First window
        for (int i = 0; i < minutes; i++) {
            if (grumpy[i] == 1)
                extra += customers[i];
        }

        maxExtra = extra;

        // Slide the window
        for (int i = minutes; i < n; i++) {

            // Add new customer
            if (grumpy[i] == 1)
                extra += customers[i];

            // Remove customer leaving the window
            if (grumpy[i - minutes] == 1)
                extra -= customers[i - minutes];

            // Update maximum extra customers
            maxExtra = max(maxExtra, extra);
        }

        // Count customers who are already satisfied
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0)
                satisfied += customers[i];
        }

        // Already satisfied + maximum extra satisfied
        return satisfied + maxExtra;
    }
};