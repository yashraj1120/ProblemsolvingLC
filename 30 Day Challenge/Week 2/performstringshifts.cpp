#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	string stringShift(string s, vector<vector<int>> &shift)
	{
		if (s.empty())
		{
			return s;
		}
		int p = 0;
		int len = s.length();
		for (auto x : shift)
		{
			int dir = x[0];
			int amount = x[1] % len;
			if (dir)
			{
				p -= amount;
				if (p < 0)
				{
					p = len + p;
				}
			}
			else
			{
				p += amount;
				p = p % len;
			}
		}
		return s.substr(p, len - p) + s.substr(0, p);
	}
};