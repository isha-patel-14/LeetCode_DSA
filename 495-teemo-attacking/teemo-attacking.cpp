class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int count=0;
        for(int i=0;i<timeSeries.size()-1;i++){
            if(timeSeries[i+1]-timeSeries[i]<duration){
                count+=timeSeries[i+1]-timeSeries[i];
            }else{
                count+=duration;
            }
        }
        return count+=duration;
    }
};

// class Solution {
// public:
//     int findPoisonedDuration(vector<int>& timeSeries, int duration) {
//         int count=0;
//         for(int i=1;i<timeSeries.size();i++){
//             if(timeSeries[i]-timeSeries[i-1]<duration){
//                 count+=timeSeries[i]-timeSeries[i-1];
//             }else{
//                 count+=duration;
//             }
//         }
//         count+=duration;
//         return count;
//     }
// };