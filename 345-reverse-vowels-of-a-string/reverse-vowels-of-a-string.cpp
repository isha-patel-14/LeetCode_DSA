class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> v = {'a','e','i','o','u','A','E','I','O','U'};
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r && !v.count(s[l])) l++;
            while (l < r && !v.count(s[r])) r--;
            swap(s[l++], s[r--]);
        }
        return s;
    }
};


// class Solution {
// public:
//     string reverseVowels(string s) {
//         int i = 0, j = s.size() - 1;
//         while (i < j) {
//             if(!(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||
//                 s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
//                 s[i] == 'o' || s[i] == 'u')) {
//                 i++;
//                 continue;
//             }
//             if (!(s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' ||
//                   s[j] == 'U' || s[j] == 'a' || s[j] == 'e' || s[j] == 'i' ||
//                   s[j] == 'o' || s[j] == 'u')) {
//                 j--;
//                 continue;
//             }
//             swap(s[i],s[j]);
//             i++;
//             j--;
//         }
//         return s;
//     }
// };