/*
            2834. Find the Minimum Possible Sum of a Beautiful Array

            
    You are given positive integers n and target.

    An array nums is beautiful if it meets the following conditions:
    
    nums.length == n.
    nums consists of pairwise distinct positive integers.
    There doesn't exist two distinct indices, i and j, in the range [0, n - 1], such that nums[i] + nums[j] == target.
    Return the minimum possible sum that a beautiful array could have.

    Input: n = 3, target = 3
    Output: 8
    Explanation: We can see that nums = [1,3,4] is beautiful.
    - The array nums has length n = 3.
    - The array nums consists of pairwise distinct positive integers.
    - There doesn't exist two distinct indices, i and j, with nums[i] + nums[j] == 3.
    It can be proven that 8 is the minimum possible sum that a beautiful array could have.
*/
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
