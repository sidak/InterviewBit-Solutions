class Solution {
public:

    void doWork(vector<int> &candidates, int index, vector<int> &current, int currentSum, int target, vector<vector<int> > &ans) {
    	if (currentSum > target) {
		return;
	}
	if (currentSum == target) {
		ans.push_back(current);
		return;
	}
	if (index >= candidates.size()) {
		return;
	}

	int endIndex;
	for (endIndex = index + 1; endIndex < candidates.size() && candidates[endIndex] == candidates[endIndex - 1]; endIndex++);
	int countIndex = endIndex - index; 
	for (int i = 0; i <= countIndex; i++) {
		for (int j = 0; j < i; j++) current.push_back(candidates[index]);
		currentSum += i * candidates[index];
		doWork(candidates, endIndex, current, currentSum, target, ans);
		currentSum -= i * candidates[index];
		for (int j = 0; j < i; j++) current.pop_back();
	}
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<int> current; 
	vector<vector<int> > ans;
	sort(candidates.begin(), candidates.end());
	doWork(candidates, 0, current, 0, target, ans); 
	return ans;
    }
};
