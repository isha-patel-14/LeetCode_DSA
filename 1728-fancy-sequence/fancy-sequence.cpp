class Fancy {
public:
    vector<long long> arr;
    long long add = 0;
    long long mul = 1;
    int MOD = 1000000007;

    long long modInverse(long long a) {
        long long res = 1;
        long long p = MOD - 2;

        while(p){
            if(p & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            p >>= 1;
        }

        return res;
    }

    Fancy() {}

    void append(int val) {
        long long inv = modInverse(mul);
        long long stored = ((val - add + MOD) % MOD * inv) % MOD;
        arr.push_back(stored);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx) {
        if(idx >= arr.size())
            return -1;

        return (arr[idx] * mul + add) % MOD;
    }
};