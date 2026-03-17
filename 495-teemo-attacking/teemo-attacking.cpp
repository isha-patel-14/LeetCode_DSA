class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int count=0;
        for(int i=1;i<timeSeries.size();i++){
            if(timeSeries[i]-timeSeries[i-1]<duration){
                count+=timeSeries[i]-timeSeries[i-1];
            }else{
                count+=duration;
            }
        }
        count+=duration;
        return count;
    }
};