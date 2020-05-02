class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		int len1 = text1.length();
		int len2 = text2.length();

		vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
		for (int i = 0; i < len1+1; i++)
		{
			char curr = text1[i];
			for (int j = 0; j < len2+1; j++)
			{
				dp[i + 1][j + 1] += max(dp[i + 1][j], dp[i][j + 1])
				if (curr == text[j])
				{
					dp[i + 1][j + 1] += 1;
				}
			}
		}
		return dp[len1][len2];

	}
};