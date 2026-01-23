class Solution {
public:
    int minimumPairRemoval(vector<int>& numsInput) {
        int n = numsInput.size();
        if (n <= 1) return 0;

        vector<long long> nums(n);
        for (int i = 0; i < n; i++) nums[i] = numsInput[i];

        vector<int> left(n), right(n);
        vector<bool> alive(n, true);

        for (int i = 0; i < n; i++) {
            left[i] = i - 1;
            right[i] = i + 1;
        }

        int bad = 0;
        for (int i = 0; i + 1 < n; i++) {
            if (nums[i] > nums[i + 1]) bad++;
        }

        if (bad == 0) return 0;

        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<>> pq;

        for (int i = 0; i + 1 < n; i++) {
            pq.push({nums[i] + nums[i + 1], i});
        }

        int ops = 0;

        while (true) {
            auto [sum, i] = pq.top();
            pq.pop();

            if (!alive[i] || right[i] == n || !alive[right[i]])
                continue;

            int j = right[i];

            if (sum != nums[i] + nums[j])
                continue;

            if (left[i] != -1 && nums[left[i]] > nums[i]) bad--;
            if (nums[i] > nums[j]) bad--;
            if (right[j] != n && nums[j] > nums[right[j]]) bad--;

            nums[i] += nums[j];
            alive[j] = false;

            right[i] = right[j];
            if (right[j] != n)
                left[right[j]] = i;

            if (left[i] != -1 && nums[left[i]] > nums[i]) bad++;
            if (right[i] != n && nums[i] > nums[right[i]]) bad++;

            ops++;

            if (bad == 0) return ops;

            if (left[i] != -1)
                pq.push({nums[left[i]] + nums[i], left[i]});
            if (right[i] != n)
                pq.push({nums[i] + nums[right[i]], i});
        }
    }
};
