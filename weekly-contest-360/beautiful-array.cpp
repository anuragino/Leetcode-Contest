class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        // Initialize the variable to store the final answer
        long long ans = 0;
        
        // Create a set to store the selected positive integers
        set<int> st;
        
        // Iterate from 1 to find n distinct positive integers that sum up to the given target
        for (int i = 1; st.size() < n; i++) {
            // Check if the current integer i is not already present in the set
            if (st.find(target - i) == st.end()) {
                // If not present, add the integer to the set and update the answer
                st.insert(i);
                ans += i;
            }
        }
        
        // Return the calculated sum of n distinct positive integers
        return ans;
    }
};
