class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        for(int i = 0; i < n; i++){
            int low = 0;
            int high = image[i].size() - 1;
            while(low <= high) {
                int temp1 = image[i][low];
                int temp2 = image[i][high];
                image[i][high] = (temp1 == 0) ? 1 : 0;
                image[i][low]  = (temp2 == 0) ? 1 : 0;
                low++;
                high--;
            }
        }
        return image;
    }
};