class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int curr_sum = nums[0];
        int max_sum = max(INT_MIN,curr_sum);

        for(int i = 1;i<len;i++)
        {
            curr_sum = curr_sum<0?0:curr_sum;
            curr_sum+=nums[i]; 
            max_sum = max(max_sum,curr_sum);
           
        }
        return max(max_sum,curr_sum);
    }
};