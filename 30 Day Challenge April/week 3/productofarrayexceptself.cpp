class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int len = nums.size();
        res.push_back(1);
        for(int i = 1;i<len;i++)
        {
            res.push_back(nums[i-1]*res[i-1]);
        }
        int r=1;
        for(int i=len-1;i>=0;i--)
        {
            res[i] = r*res[i];
            r*=nums[i];
        }
        return res;
    }
};