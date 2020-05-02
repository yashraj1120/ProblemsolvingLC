
class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.empty())
		{
			return -1;
		}
		int pivot = -1;
		int l = 0;
		int h = nums.size() - 1;
		while (l < h)
		{
			int mid = (l + h) / 2;
			if (nums[mid] > nums[h])
			{
				l = mid + 1;
			}
			else
			{
				h = mid;
			}
		}
		pivot = l;
		if (target <= nums.back())
		{
			return bsearch(nums, pivot, nums.size() - 1, target);
		}
		return bsearch(nums, 0, pivot - 1, target);
	}
	int bsearch(vector<int>& nums, int l, int h, const int& target)
	{
		int mid = -1;
		int temp = -1;
		while (l <= h)
		{
			mid = (l + h) / 2;
			temp = nums[mid];
			if (temp == target)
			{
				return mid;
			}
			if (temp > target)
			{
				h = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
		return -1;
	}
};