class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty())
		{
			return 0;
		}
		vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
		int res = 0;
		int rows = grid.size();
		int cols = grid[0].size();
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (visited[i][j] == false)
				{
					if (grid[i][j] == '1')
					{
						visited[i][j] = true;
						dfs(grid, visited, i, j);
						++res;
					}
				}
			}
		}
		return res;

	}
	void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int r, int c)
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
			if (r - 1 >= 0 && visited[r - 1][c] == false && grid[r - 1][c] == '1')
			{
				visited[r - 1][c] = true;
				points_stack.push_back(make_pair(r - 1, c));
			}
			if (r + 1 < grid.size() && visited[r + 1][c] == false && grid[r + 1][c] == '1')
			{
				visited[r + 1][c] = true;
				points_stack.push_back(make_pair(r + 1, c));
			}
			if (c - 1 >= 0 && visited[r][c - 1] == false && grid[r][c - 1] == '1')
			{
				visited[r][c - 1] = true;
				points_stack.push_back(make_pair(r, c - 1));
			}
			if (c + 1 < grid[0].size() && visited[r][c + 1] == false && grid[r][c + 1] == '1')
			{
				visited[r][c + 1] = true;
				points_stack.push_back(make_pair(r, c + 1));
			}
		} while (!points_stack.empty());



		/*if (r - 1 >= 0 && visited[r - 1][c] == false && grid[r - 1][c] == '1')
		{
			visited[r - 1][c] = true;
			dfs(grid, visited, r - 1, c);
		}
		if (r + 1 < grid.size() && visited[r + 1][c] == false && grid[r + 1][c] == '1')
		{
			visited[r + 1][c] = true;
			dfs(grid, visited, r + 1, c);
		}
		if (c - 1 >= 0 && visited[r][c - 1] == false && grid[r][c - 1] == '1')
		{
			visited[r][c - 1] = true;
			dfs(grid, visited, r, c - 1);
		}
		if (c + 1 < grid[0].size() && visited[r][c + 1] == false && grid[r][c + 1] == '1')
		{
			visited[r][c + 1] = true;
			dfs(grid, visited, r, c + 1);
		}*/
	}
};