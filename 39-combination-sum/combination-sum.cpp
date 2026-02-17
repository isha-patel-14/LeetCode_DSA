class Solution {
public:
    vector<vector<int>> result;

    void dfs(vector<int>& candidates, int target, int index, vector<int>& current) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] > target) break;

            current.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, current);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> current;
        dfs(candidates, target, 0, current);
        return result;
    }
};