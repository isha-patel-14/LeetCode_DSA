class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int>result(num_people,0);
        int give=1,index=0;
        while(candies>0){
            int current=min(give,candies);
            result[index]+=current;
            candies-=current;
            give++;
            index=(index+1)%num_people;
        }
        return result;
    }
};