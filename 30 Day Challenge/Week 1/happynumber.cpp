class Solution {
public:
    bool isHappy(int n) {

        if(n==0)
        {
            return false;
        }
        set<int> found;
        while(n!=1)
        {
            int temp = 0;
            while(n>0)
            {
                int k = n%10;
                temp+= (k*k);
                n/=10;
            }
            if(found.find(temp)!=found.end())
            {
                return false;
            }
            found.insert(temp);
            n=temp;
        }
        return 1;
    }
};