#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		if (nums.empty())
		{
			return 0;
		}
		int len = nums.size();
		map<int, int> countMap;
		int count = 0;
		int max_len = 0;
		for (int i = 0; i < len; i++)
		{
			if (nums[i] == 0)
			{
				count--;
			}
			else
			{
				count++;
			}
			if (count == 0)
			{
				max_len = max(max_len, i + 1);
			}
			if (countMap.find(count) == countMap.end())
			{
				countMap[count] = i;
			}
			max_len = max(max_len, i - countMap[count]);
		}
		return max_len;

	}
};