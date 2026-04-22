class Solution {
public:

    bool isValid(string &a, string &b) {
        int count = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                count++;
                if (count > 2) return false;
            }
        }
        return true;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        for (int i = 0; i < queries.size(); i++) {
            for (int j = 0; j < dictionary.size(); j++) {
                if (isValid(queries[i], dictionary[j])) {
                    result.push_back(queries[i]);
                    break;
                }
            }
        }
        return result;
    }
};