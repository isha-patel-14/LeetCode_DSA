class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit){
        int n = values.size();
        vector<pair<int, int>> arr;
        
        for (int i = 0; i < n; i++) {
            arr.push_back({values[i], labels[i]});
        }
        
        sort(arr.begin(), arr.end(), greater<pair<int, int>>());
        
        unordered_map<int, int> freq;
        int count = 0, sum = 0;
        
        for (int i = 0; i < n && count < numWanted; i++) {
            int val = arr[i].first;
            int lab = arr[i].second;
            
            if (freq[lab] < useLimit) {
                sum += val;
                freq[lab]++;
                count++;
            }
        }
        return sum;
    }
};