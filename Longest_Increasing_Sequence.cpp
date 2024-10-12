class Solution {
public:
    // Custom comparator for sorting coordinates
    static bool compareCoordinates(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];  // If x-values are equal, sort by y in descending order
        }
        return a[0] < b[0];  // Otherwise, sort by x in ascending order
    }

    // Function to compute the Longest Increasing Subsequence (LIS)
    int longestIncreasingSubsequence(const vector<int>& sequence) {
        if (sequence.empty()) {
            return 0;  // If the sequence is empty, the LIS length is 0
        }

        vector<int> lis;  // Vector to store the current LIS
        for (int num : sequence) {
            // Find the position where `num` can be inserted to maintain sorted order
            auto it = lower_bound(lis.begin(), lis.end(), num);
            if (it == lis.end()) {
                lis.push_back(num);  // If `num` is larger than all elements, add it to the end
            } else {
                *it = num;  // Otherwise, replace the first element that is >= num
            }
        }
        return lis.size();  // Return the length of the LIS
    }

    // Function to calculate the maximum path length based on the coordinates
    int maxPathLength(vector<vector<int>>& coordinates, int referenceIndex) {
        int referenceY = coordinates[referenceIndex][1];  // Reference point's y-coordinate
        int referenceX = coordinates[referenceIndex][0];  // Reference point's x-coordinate

        // Sort the coordinates using the custom comparator
        sort(coordinates.begin(), coordinates.end(), compareCoordinates);

        vector<int> leftSequence, rightSequence;  // Store y-coordinates for left and right parts

        // Separate coordinates into left and right based on their relation to the reference point
        for (const auto& coordinate : coordinates) {
            int x = coordinate[0];
            int y = coordinate[1];

            if (x < referenceX && y < referenceY) {
                leftSequence.push_back(y);  // Points in the lower-left quadrant
            }
            if (x > referenceX && y > referenceY) {
                rightSequence.push_back(y);  // Points in the upper-right quadrant
            }
        }

        // Compute the LIS for the left and right sequences
        int lisLeft = longestIncreasingSubsequence(leftSequence);
        int lisRight = longestIncreasingSubsequence(rightSequence);

        // The maximum path length is the sum of the left LIS, the reference point itself (+1), and the right LIS
        return lisLeft + 1 + lisRight;
    }
};