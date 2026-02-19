class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> pre(n+1);
        pre[0] = -1;
        for (int i = 0; i < n; i++){
            if (i == 0 || (i>0 && s[i-1] == '0')){
                pre[i+1] = i;
            }else{
                pre[i+1] = pre[i];
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++){
            int cnt0 = s[i-1] == '0';
            int j = i;
            while (j>0 && cnt0 * cnt0 <= n){
                int cnt1 = (i-pre[j]) - cnt0;
                if (cnt0*cnt0 <= cnt1){
                    res += min(j-pre[j], cnt1 - cnt0*cnt0+1);
                }
                j = pre[j];
                cnt0++;
            }
        }
        return res;
    }
};


// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int n = s.size();
//         vector<int> prefix(n, 0);

//         prefix[0] = (s[0] == '1');
//         for (int i = 1; i < n; i++) {
//             prefix[i] = prefix[i - 1] + (s[i] == '1');
//         }

//         int ans = 0;

//         for (int i = 0; i < n; i++) {
//             for (int j = i; j < n; j++) {
//                 int one = prefix[j] - (i == 0 ? 0 : prefix[i - 1]);
//                 int len = j - i + 1;
//                 int zero = len - one;

//                 if (1LL * zero * zero > one) {
//                     int skip = (int)(1LL * zero * zero - one - 1);
//                     j += skip;
//                     continue;
//                 }

//                 ans++;

//                 int maxZeroAllowed = (int)sqrt(one);
//                 int diff = maxZeroAllowed - zero;

//                 if (diff <= 0) continue;

//                 int nextj = min(n - 1, j + diff);
//                 ans += (nextj - j);
//                 j = nextj;
//             }
//         }
//         return ans;
//     }
// };