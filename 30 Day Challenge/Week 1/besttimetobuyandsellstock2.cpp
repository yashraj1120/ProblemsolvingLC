class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(!len)
        {
            return 0;
        }
        int res = 0;
        int curr_min = prices[0];
        for(int i = 1 ;i<len;i++)
        {
            if(curr_min<=prices[i])
            {
                res += prices[i]-curr_min;
            }
            curr_min = prices[i];
        }
        return res;
    }
};