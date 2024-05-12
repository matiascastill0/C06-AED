#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr),right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* printeo(TreeNode* root) {
        if (root != nullptr) {
            printeo(root->right);
            cout << root->val << " "; // Imprimir el valor del nodo
            printeo(root->left);
        }
        cout << endl;
        return root;

    }

    TreeNode* ejercicio_1(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2)
            return nullptr;

        int val = (root1 ? root1->val : 0) + (root2 ? root2->val : 0); // Sumar los valores de los nodos
        TreeNode* merged = new TreeNode(val);

        merged->left = ejercicio_1(root1 ? root1->left : nullptr, root2 ? root2->left : nullptr); // Recursión izquierda
        merged->right = ejercicio_1(root1 ? root1->right : nullptr, root2 ? root2->right : nullptr); // Recursión derecha

        return merged;
    }




};


int main() {
    Solution sol;

    // Ejemplo de uso de la función printeo
    TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(4);
    root1->left->left=new TreeNode(4);
    root1->right = new TreeNode(19);
    cout << "Arbol original 1: ";
    sol.printeo(root1);

    // Ejemplo de uso de la función printeo
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(13);
    cout << "Arbol original 1: ";
    sol.printeo(root2);





    // Ejemplo de uso de la función ejercic

    TreeNode* mergedTree = sol.ejercicio_1(root1, root2);
    cout << "Arbol fusionado: ";
    sol.printeo(mergedTree);
    cout << endl;

    return 0;
}