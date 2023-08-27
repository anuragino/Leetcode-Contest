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
