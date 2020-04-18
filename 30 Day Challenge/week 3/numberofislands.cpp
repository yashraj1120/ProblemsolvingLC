#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {

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
					if(grid[i][j]=='1')
					{
						cout << "i=" << i << " j=" << j << endl;
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
		cout << r << " " << c << endl;
		if (r - 1 >= 0 && visited[r - 1][c] == false && grid[r - 1][c] == '1')
		{
			visited[r - 1][c] = true
			dfs(grid, visited, r - 1, c);
		}
		if (r + 1 < grid.size() && visited[r + 1][c] == false && grid[r + 1][c] == '1')
		{
			visited[r + 1][c] = true
			dfs(grid, visited, r + 1, c);
		}
		if (c - 1 >= 0 && visited[r][c - 1] == false && grid[r][c - 1] == '1')
		{
			visited[r][c - 1] = true
			dfs(grid, visited, r, c - 1);
		}
		if (c + 1 < grid.size() && visited[r][c + 1] == false && grid[r][c + 1] == '1')
		{
			visited[r][c + 1] = true
			dfs(grid, visited, r, c + 1);
		}
	}
};