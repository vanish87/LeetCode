class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		if (nums.size() < 2) return nums;

		unordered_map<int, int> Result;
		vector<int> Ret;
		int AnotherTarget = 0;
		int Current = 0;
		for (int it = 0; it < nums.size(); ++it)
		{
			Current = nums[it];
			if (Result.find(Current) != Result.end())
			{
				Ret.push_back(Result[Current] + 1);
				Ret.push_back(it + 1);
				return Ret;
			}
			AnotherTarget = target - Current;
			Result[AnotherTarget] = it;
		}
		return Ret.size() > 1 ? Ret : nums;
	}
};