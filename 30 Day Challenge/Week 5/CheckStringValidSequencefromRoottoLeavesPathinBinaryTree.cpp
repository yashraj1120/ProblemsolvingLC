/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	int arr_len;
	bool isValidSequence(TreeNode* root, vector<int>& arr) {
		if (root == nullptr || arr.empty())
		{
			return false;
		}
		arr_len = arr.size();
		return helper(arr, root, 0);
	}
	bool helper(vector<int>& arr, TreeNode* root, int pos)
	{
		if (root == nullptr)
		{
			return false;
		}
		if (pos >= arr_len)
		{
			return false;
		}
		if (arr[pos] != root->val)
		{
			return false;
		}
		if (pos == arr_len - 1)
		{
			return root->left == nullptr && root->right == nullptr;
		}
		bool res = false;
		res = helper(arr, root->left, pos + 1);
		if (res)
		{
			return res;
		}
		return helper(arr, root->right, pos + 1);


	}


};