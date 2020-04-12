class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.empty())
        {
            return 0;
        }
        priority_queue<int> q;
        for(int i =0;i<stones.size();i++)
        {
            q.push(stones[i]);
        }
        while(q.size()>1)
        {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            if(a==b)
            {
                continue;
            }else if(a>b)
            {
                swap(a,b);
            }
            q.push(b-a);
        }
        if(!q.empty())
        {
            return q.top();
            }
        return 0;
    }
};