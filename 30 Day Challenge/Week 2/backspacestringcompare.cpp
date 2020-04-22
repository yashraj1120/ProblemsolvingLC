class Solution
{
public:
	bool backspaceCompare(string S, string T)
	{
		int s = S.length() - 1;
		int t = T.length() - 1;
		int ss = 0;
		int ts = 0;
		while (s >= 0 && t >= 0)
		{
			//cout<<S[s]<<" "<<T[t]<<endl;
			while (s >= 0 && (ss || S[s] == '#'))
			{
				if (S[s] == '#')
				{
					ss++;
				}
				else if (ss)
				{
					ss--;
				}
				s--;
			}
			while (t >= 0 && (ts || T[t] == '#'))
			{
				if (T[t] == '#')
				{
					ts++;	
				}
				else if (ts)
				{
					ts--;
				}
				t--;
			}
			//cout<<S[s]<<" "<<T[t]<<endl;
			if (s >= 0 && t >= 0 && !ss && !ts)
			{
				if (T[t] != S[s])
				{
					return false;
				}
				s--;
				t--;
			}
		}

		//cout<<"s :"<<s<<" t: "<<t<<endl;
		int ls = s;
		while (s >= 0)
		{
			if (S[s] == '#')
			{
				ss++;
			}
			else if (ss)
			{
				ss--;
			}
			else
			{
				return false;
			}
			s--;
		}

		int tl = t;
		while (t >= 0)
		{
			if (T[t] == '#')
			{
				ts++;
			}
			else if (ts)
			{
				ts--;
			}
			else
			{
				return false;
			}
			t--;
		}

		return true;
	}
};