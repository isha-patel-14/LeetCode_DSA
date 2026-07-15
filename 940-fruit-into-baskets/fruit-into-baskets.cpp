class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int last=-1 , secLast=-1, curr=0, maxFruit=0 , lastCount=0;
        for(int i=0;i<fruits.size();i++){
            int fruit=fruits[i];
            if(fruit==last||fruit==secLast){
                curr++;
            }else{
                curr=lastCount+1;
            }
            if(fruit==last){
                lastCount++;
            }else{
                lastCount=1;
                secLast=last;
                last=fruit;
            }
            if(curr>maxFruit){
                maxFruit=curr;
            }
        }
        return maxFruit;
    }
};