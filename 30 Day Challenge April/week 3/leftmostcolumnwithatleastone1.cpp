/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
	int rows, cols;
	int res = -1;
	int leftMostColumnWithOne(BinaryMatrix& binaryMatrix) {
		auto x = binaryMatrix.dimensions();
		rows = x[0];
		cols = x[1];

		for (int i = 0; i < rows; i++)
		{
			int temp = bsearch(binaryMatrix, i);
			res = (res == -1) ? (temp == INT_MAX ? -1 : temp) : min(res, temp);
		}
		return res;
	}
	int bsearch(BinaryMatrix& bm, int r)
	{
		int l = 0;
		int h = cols - 1;

		while (l != h)
		{
			int mid = (l + h) / 2;
			int mid_val = bm.get(r, mid);
			if (mid_val == 1)
			{
				h = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
		if (l == (cols - 1))
		{
			if (bm.get(r, l) == 0)
			{
				return INT_MAX;
			}
		}
		return l;
	}

};