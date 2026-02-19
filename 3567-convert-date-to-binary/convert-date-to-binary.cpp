class Solution {
public:
    string toBinary(int x) {
        string res = "";
        while (x > 0) {
            res = char('0' + (x % 2)) + res;
            x /= 2;
        }
        return res;
    }

    string convertDateToBinary(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));

        return toBinary(year) + "-" + toBinary(month) + "-" + toBinary(day);
    }
};