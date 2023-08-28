/*
                2836. Maximize Value of Function in a Ball Passing Game
  You are given a 0-indexed integer array receiver of length n and an integer k.There are n players having a unique id in the range [0, n - 1]
  who will play a ball passing game, and receiver[i] is the id of the player who receives passes from the player with id i. Players can pass to themselves,
  i.e. receiver[i] may be equal to i.
You must choose one of the n players as the starting player for the game, and the ball will be passed exactly k times starting from the chosen player.
For a chosen starting player having id x, we define a function f(x) that denotes the sum of x and the ids of all players who receive the ball during the
k passes, including repetitions. In other words, f(x) = x + receiver[x] + receiver[receiver[x]] + ... + receiver(k)[x].
Your task is to choose a starting player having id x that maximizes the value of f(x).Return an integer denoting the maximum value of the function.
Note: receiver may contain duplicates.

Example 1:
Input: receiver = [2,0,1], k = 4
Output: 6
Explanation: The table above shows a simulation of the game starting with the player having id x = 2. 
From the table, f(2) is equal to 6. 
It can be shown that 6 is the maximum achievable value of the function. 
Hence, the output is 6. 
  
*/


#define ll long long
class Solution {
public:
    
    // Function to recursively calculate the sum based on the condition
    ll solve(int node, int par, ll k, vector<vector<pair<int,ll>>>& dp) {
        // Base case: if the parent node is -1, return 0
        if(par == -1) {
            return 0;
        }
        
        // If the kth bit of k is 0, skip to the previous parent
        if((k & (1ll << par)) == 0) {
            return solve(node, par - 1, k, dp);
        }
        
        // Otherwise, return the sum of the current node value and the recursive result
        return dp[par][node].second + solve(dp[par][node].first, par - 1, k, dp);
    }
    
    // Main function to calculate the maximum function value
    ll getMaxFunctionValue(vector<int>& receiver, long long k) {
        int m = 40, n = receiver.size();
        
        // 2D vector to store pairs of nodes and their values for dynamic programming
        vector<vector<pair<int,ll>>> dp(m, vector<pair<int,ll>>(n));
        
        // Initialize the base case for the first level of the dynamic programming
        for(int i = 0; i < n; ++i) {
            dp[0][i] = make_pair(receiver[i], receiver[i]);
        }
        
        // Populate the dynamic programming table using the previous levels
        for(int i = 1; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                // Update the current node's value and sum based on the previous node
                int x = dp[i-1][j].first;
                dp[i][j] = make_pair(dp[i-1][x].first, dp[i-1][j].second + dp[i-1][x].second);
            }
        }
        
        // Initialize the result variable to store the maximum function value
        ll res = 0;
        // Iterate through each node and calculate the maximum function value
        for(int i = 0; i < n; ++i) {
            // Update the result by considering the current node and the recursion result
            res = max(solve(i, m - 1, k, dp) + i, res);
        }
        
        // Return the final maximum function value
        return res;
    }
};
