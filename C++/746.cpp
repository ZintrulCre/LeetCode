class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        int size = cost.size();
        if (size < 2)
            return 0;
        int first = cost[0], second = 0, current;
        for (int i = 1; i < size; ++i) {
            current = min(second, first) + cost[i];
            second = first;
            first = current;
        }
        return min(first, second);
    }
};
