/*
                2835. Minimum Operations to Form Subsequence With Target Sum

                
    You are given a 0-indexed array nums consisting of non-negative powers of 2, and an integer target.

    In one operation, you must apply the following changes to the array:
    
    Choose any element of the array nums[i] such that nums[i] > 1.
    Remove nums[i] from the array.
    Add two occurrences of nums[i] / 2 to the end of nums.
    Return the minimum number of operations you need to perform so that nums contains a subsequence whose elements sum to target.
    If it is impossible to obtain such a subsequence, return -1.
    
    A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

    Input: nums = [1,32,1,2], target = 12
    Output: 2
    Explanation: In the first operation, we choose element nums[1]. The array becomes equal to nums = [1,1,2,16,16].
    In the second operation, we choose element nums[3]. The array becomes equal to nums = [1,1,2,16,8,8]
    At this stage, nums contains the subsequence [1,1,2,8] which sums up to 12.
    It can be shown that there is no shorter sequence of operations that results in a subsequence that sums up to 12.
*/
class Solution {
public:
    int minOperations(vector<int>& nums, int target) {

        // Initialize a vector to store the counts of numbers with specific bit positions
        vector<int> c(31, 0);

        // Calculate the total sum of all numbers in the array
        long long s = 0;
        for (auto it : nums) {
            // increase the count of the indicies
            c[int(log2(it))]++;
            s += it;
        }

        // If the target sum is greater than the total sum of array elements, return -1
        if (target > s)
            return -1;

        int i = 0, res = 0;

        // Iterate through the bits from least significant to most significant
        while (i < 30) {
            // Check if the current bit is set in the target
            if ((1 << i) & target) {
                // If there are available numbers with this bit position
                if (c[i] > 0) {
                    c[i]--;
                } else {
                    int j = i;

                    // Find the nearest available bit position with count greater than 0
                    while (j < 30 && c[j] == 0) {
                        j++;
                        res++;
                    }
                    c[j]--;
                    // now increase the count form j to i by 1
                    while (j > i) {
                        c[--j]++;
                    }
                }
            }

            // Carry over the half of the count to the next bit position
            c[i + 1] += c[i] / 2;
            i++;
        }

        // Return the result (minimum operations required to reach the target sum)
        return res; 
    }
};
