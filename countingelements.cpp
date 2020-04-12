class Solution {
public:
    int countElements(vector<int>& arr) {
        map<int,int> count;
        int res = 0;
        for(auto x :arr)
        {
            if(count.find(x)==count.end())
            {
                count[x]=0;
            }
            count[x]++;
        }
        for(auto x:count)
        {
            if(count.find(x.first+1)!=count.end())
            {
                res+=x.second;
            }
        }
        return res;
    }
};