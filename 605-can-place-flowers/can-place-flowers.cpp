class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        int count = 0;
        for(int i = 0; i < size; i++) {
            if(flowerbed[i] == 0) {
                if(i == 0 || flowerbed[i-1] == 0) {
                    if(i == size-1 || flowerbed[i+1] == 0) {
                        count++;
                        flowerbed[i] = 1; 
                    }
                }
            }
        }
        return count >= n;
    }
};