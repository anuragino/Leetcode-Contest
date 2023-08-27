// QUESTION ID 2833. Furthest Point From Origin
/*
        You are given a string moves of length n consisting only of characters 'L', 'R', and '_'.
        The string represents your movement on a number line starting from the origin 0.

    In the ith move, you can choose one of the following directions:
    
    move to the left if moves[i] = 'L' or moves[i] = '_'
    move to the right if moves[i] = 'R' or moves[i] = '_'
    Return the distance from the origin of the furthest point you can get to after n moves.


    Input: moves = "_R__LL_"
    Output: 5
    Explanation: The furthest point we can reach from the origin 0 is point -5 through the following sequence of moves "LRLLLLL".


*/

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        // Initialize counters for left, right, and down moves
        int Lcnt = 0;
        int Rcnt = 0;
        int Dcnt = 0;

        // Iterate through each move in the input string
        for (auto i : moves) {
            if (i == 'L')
                Lcnt++; // Increment the left move counter
            else if (i == '_')
                Dcnt++; // Increment the down move counter (underscore represents down)
            else
                Rcnt++; // Increment the right move counter
        }

        // Calculate the furthest distance from the origin
        // Distance = down moves + absolute difference between left and right moves
        return Dcnt + abs(Lcnt - Rcnt);
    }
};
