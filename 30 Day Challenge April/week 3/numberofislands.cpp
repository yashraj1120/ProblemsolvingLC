class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty())
		{
			return 0;
		}
		int res = 0;
		int rows = grid.size();
		int cols = grid[0].size();
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (grid[i][j] == '1')
				{
					visited[i][j] = true;
					dfs(grid, i, j);
					++res;
				}
			}
		}
		return res;

	}
	void dfs(vector<vector<char>>& grid, int r, int c)
	{
		vector<pair<int, int>> points_stack;
		do
		{
			if (!points_stack.empty())
			{
				auto x = points_stack.back();
				r = x.first;
				c = x.second;
				points_stack.pop_back();
			}
			if (r - 1 >= 0 && grid[r - 1][c] == '1')
			{
				grid[r - 1][c] = '!';
				points_stack.push_back(make_pair(r - 1, c));
			}
			if (r + 1 < grid.size() && grid[r + 1][c] == '1')
			{
				grid[r + 1][c] = '!';
				points_stack.push_back(make_pair(r + 1, c));
			}
			if (c - 1 >= 0 && grid[r][c - 1] == '1')
			{
				grid[r][c - 1] = '!';
				points_stack.push_back(make_pair(r, c - 1));
			}
			if (c + 1 < grid[0].size() && grid[r][c + 1] == '1')
			{
				grid[r][c + 1] = '!';
				points_stack.push_back(make_pair(r, c + 1));
			}
		} while (!points_stack.empty());

	}
};