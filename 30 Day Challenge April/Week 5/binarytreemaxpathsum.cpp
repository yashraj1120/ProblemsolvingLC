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

#pragma GCC optimize ("Ofast")
static auto _ = [] { std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0); std::cerr.tie(0); return 0; } ();
class Solution {
public:
	int max_sum = INT_MIN;
	int maxPathSum(TreeNode* root) {
		if (root == nullptr)
		{
			return 0;
		}
		helper(root);
		return max_sum;
	}
	int helper(TreeNode* node)
	{
		if (node == nullptr)
		{
			return 0;
		}
		int left_max = helper(node->left);
		int right_max = helper(node->right);
		int branch_max = max(left_max, right_max);
		max_sum = max(max_sum, branch_max + node->val);
		max_sum = max(max_sum, max(left_max + right_max + node->val, node->val));
		return max(node->val, branch_max + node->val);

	}
};