class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool a = false, b = false, c = false;

        for (const auto& triplet : triplets) {
            if (triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]) {
                a = a || (triplet[0] == target[0]);
                b = b || (triplet[1] == target[1]);
                c = c || (triplet[2] == target[2]);
            }
        }
        return a&&b&&c;
    }
};