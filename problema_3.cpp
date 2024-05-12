#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        convert(root, sum);
        return root;
    }

private:
    void convert(TreeNode* node, int& sum) {
        if (node == nullptr) return;
        convert(node->right, sum);
        sum += node->val;
        node->val = sum;
        convert(node->left, sum);
    }
};

TreeNode* insertLevelOrder(vector<int*> values, int i, int n) {
    if (i < n && values[i] != nullptr) {
        TreeNode* temp = new TreeNode(*values[i]);
        temp->left = insertLevelOrder(values, 2 * i + 1, n);
        temp->right = insertLevelOrder(values, 2 * i + 2, n);
        return temp;
    }
    return nullptr;
}


void printInOrder(TreeNode* root) {
    if (root != nullptr) {
        printInOrder(root->left);
        cout << root->val << " ";
        printInOrder(root->right);
    }
}

int main() {
    // Case 1
    vector<int*> input1 = {new int(4), new int(1), new int(6), new int(0), new int(2), new int(5), new int(7), nullptr, nullptr, nullptr, new int(3), nullptr, nullptr, nullptr, new int(8)};
    TreeNode* root1 = insertLevelOrder(input1, 0, input1.size());
    Solution sol;
    root1 = sol.convertBST(root1);
    cout << "Output 1: ";
    printInOrder(root1);
    cout << endl;

    // Case 2
    vector<int*> input2 = {new int(0), nullptr, new int(1)};
    TreeNode* root2 = insertLevelOrder(input2, 0, input2.size());
    root2 = sol.convertBST(root2);
    cout << "Output 2: ";
    printInOrder(root2);
    cout << endl;

    return 0;
}