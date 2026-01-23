class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char>s_To_T;
        unordered_map<char, char>t_To_S;

        for(int i = 0; i < s.size(); i++){
            char a=s[i];
            char b=t[i];

            if(s_To_T.count(a) && s_To_T[a]!=b)
                return false;

            if(t_To_S.count(b) && t_To_S[b]!=a)
                return false;

            s_To_T[a]=b;
            t_To_S[b]=a;
        }
        return true;
    }
};
