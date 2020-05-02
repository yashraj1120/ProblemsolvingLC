class Solution {
public:
	int numJewelsInStones(string J, string S) {
		set<char> jewels(J.begin(), J.end());
		int res = 0;
		for (int i = 0; i < S.length(); i++)
		{
			if (jewels.find(S[i]) != jewels.end())
			{
				res++;
			}
		}
		return res;

	}
};