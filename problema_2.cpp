/* Definition for a binary tree node.*/

#include <string>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    string Ejercicio2(TreeNode* root) {
        if (root == nullptr) return "";
        string result = to_string(root->val);
        if (root->left != nullptr || root->right != nullptr) {
            result += "(" + Ejercicio2(root->left) + ")";
            if (root->right != nullptr) {
                result += "(" + Ejercicio2(root->right) + ")";
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);

    cout << solution.Ejercicio2(root) << endl;

    return 0;
}