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
