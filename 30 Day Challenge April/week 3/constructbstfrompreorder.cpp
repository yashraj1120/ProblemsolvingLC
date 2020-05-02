#include<iostream>
#include<vector>
#include<map>
#include<stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	TreeNode* bstFromPreorder(vector<int>& preorder)
	{
		if (preorder.empty())
		{
			return nullptr;
		}
		unordered_map<int, TreeNode> tree_map;
		stack<int> order;
		TreeNode* head = new TreeNode(preorder[0]);
		tree_map[preorder[0]] = head;
		order.push(preorder[0]);
		for (int i = 1; i < preorder.size(); i++)
		{
			int temp = preorder[i];
			TreeNode* temp_node = new TreeNode(temp);
			tree_map[temp] = temp_node;
			int order_val = -1;
			if (temp < order.top())
			{
				tree_map[order_val]->left = tree_node;
				order.push(temp);

			}
			else
			{
				while (!order.empty() && temp > order.top())
				{
					order_val = order.top();
					order.pop();
				}
				order.push(temp);
				tree_map[order_val]->right = tree_node;
			}
		}
		return head;
	}

};