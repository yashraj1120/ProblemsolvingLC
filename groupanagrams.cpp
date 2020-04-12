class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> anagrams;
        vector<vector<string>> res;
        for(auto str:strs)
        {
            string cpy = str;
            sort(str.begin(),str.end());
            if(anagrams.find(str)==anagrams.end())
            {
                vector<string> temp;
                anagrams[str] = temp;
            }
            anagrams[str].push_back(cpy);
        }
        for(auto x:anagrams)
        {
            res.push_back(x.second);
        }
        return res;
    }
};