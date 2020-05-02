class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zp = 0;
        int np = 0;
        int len = nums.size();
        while(true)
        {
            while(zp<len && nums[zp]!=0)++zp;
            while(np<len && nums[np]==0)++np;
            if(zp>=len || np>=len)break;
            if(zp<np)
            {
                swap(nums[zp],nums[np]);
            }
            np++;
        }
    }
};