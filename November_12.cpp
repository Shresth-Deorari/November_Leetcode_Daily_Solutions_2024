class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // Step 1: Track max beauty for each price
        map<int, int> beauty;
        for (auto &item : items) {
            beauty[item[0]] = max(beauty[item[0]], item[1]);
        }

        // Step 2: Calculate cumulative max beauty
        int maxBeauty = 0;
        for (auto &entry : beauty) {
            maxBeauty = max(maxBeauty, entry.second);
            entry.second = maxBeauty;
        }

        // Step 3: Prepare the sorted prices and cumulative beauties
        vector<int> prices, beauties;
        for (const auto &entry : beauty) {
            prices.push_back(entry.first);
            beauties.push_back(entry.second);
        }

        // Step 4: Answer each query with `lower_bound` to find the floor price
        vector<int> result;
        for (int q : queries) {
            auto it = lower_bound(prices.begin(), prices.end(), q);
            if (it == prices.begin() && *it > q) {
                result.push_back(0);  // No price ≤ q
            } else {
                if (it == prices.end() || *it > q) --it;  // Move back if out of bounds or too large
                result.push_back(beauties[it - prices.begin()]);
            }
        }

        return result;
    }
};
