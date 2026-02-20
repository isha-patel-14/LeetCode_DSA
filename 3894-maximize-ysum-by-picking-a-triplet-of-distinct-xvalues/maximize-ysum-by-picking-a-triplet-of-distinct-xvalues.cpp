class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = x.size();
        unordered_map<int, int> best;
        
        for (int i = 0; i < n; i++) {
            best[x[i]] = max(best[x[i]], y[i]);
        }
        
        if (best.size() < 3) return -1;
        
        vector<int> vals;
        for (auto &p : best) {
            vals.push_back(p.second);
        }
        
        sort(vals.begin(), vals.end(), greater<int>());
        
        return vals[0] + vals[1] + vals[2];
    }
};

// class Solution {
// public:
//     int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
//         int n=x.size();
//         if(n<3)return -1;
//         unordered_map<int,int>xToY;
//         for(int i=0;i<n;i++){
//             xToY[x[i]]=max(xToY[x[i]],y[i]);
//         }
//         if(xToY.size()<3) return -1;

//         vector<int>bestY;
//         for(auto& [key,val]:xToY){
//             bestY.push_back(val);
//         }
//         sort(bestY.rbegin(),bestY.rend());
//         return bestY[0]+bestY[1]+bestY[2];
//     }
// };