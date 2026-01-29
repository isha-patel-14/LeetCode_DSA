class Solution {
public:
    int countPoints(string rings) {
        bool rod[10][3] = {false};
        for(int i = 0; i < rings.size(); i += 2) {
            char color = rings[i];
            int num = rings[i + 1] - '0';
            if(color == 'R') rod[num][0] = true;
            else if(color == 'G') rod[num][1] = true;
            else if(color == 'B') rod[num][2] = true;
        }
        int count = 0;
        for(int i = 0; i < 10; i++) {
            if(rod[i][0] && rod[i][1] && rod[i][2]) {
                count++;
            }
        }
        return count;
    }
};