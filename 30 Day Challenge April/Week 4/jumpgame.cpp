class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty())
        {
            return false;
        }
        int len = nums.size();
        int max_reach=0;
        for(int i = 0;i<len;i++)
        {
            if(i<=max_reach)
            {
                max_reach=max(max_reach,i+nums[i]);
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};