class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maximum=0;
        for(int c : candies){
            maximum=max(maximum,c);
        }
        vector<bool>ans;
        for(int c : candies){
            ans.push_back(c+extraCandies>=maximum);
        }
        return ans;
    }
};