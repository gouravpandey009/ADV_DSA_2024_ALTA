class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Count frequency of every number
        unordered_map<int, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        // Min heap: {frequency, number}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        // Keep only the k most frequent numbers
        for (auto it : freq) {

            pq.push({it.second, it.first});

            // Remove the least frequent number
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> ans;

        // Remaining k elements are our answer
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};