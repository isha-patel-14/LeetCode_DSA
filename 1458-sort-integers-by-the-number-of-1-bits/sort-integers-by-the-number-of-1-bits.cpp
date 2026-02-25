class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n=arr.size();
        vector<pair<int,int>>temp;
        for(int i=0;i<n;i++){
            int bits=__builtin_popcount(arr[i]);
            temp.push_back(make_pair(bits,arr[i]));
        }
        sort(temp.begin(),temp.end());
        for(int i=0;i<n;i++){
            arr[i]=temp[i].second;
        }
        return arr;
    }
};