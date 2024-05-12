// Integrantes:
// 202120533 - Aldair Seminario Sanchez
// 202210081 - Matias Castillo Quincho
// 202220226 - Renzo Felix Aponte
// 202220354 - Jefri Vargas Fernandez

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Ejercicio 1: Fusionar dos árboles binarios
class Solution1 {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return nullptr;
        int val = (root1 ? root1->val : 0) + (root2 ? root2->val : 0);
        TreeNode* merged = new TreeNode(val);
        merged->left = mergeTrees(root1 ? root1->left : nullptr, root2 ? root2->left : nullptr);
        merged->right = mergeTrees(root1 ? root1->right : nullptr, root2 ? root2->right : nullptr);
        return merged;
    }

    void printTree(TreeNode* root) {
        if (root != nullptr) {
            printTree(root->right);
            cout << root->val << " ";
            printTree(root->left);
        }
    }
};

void ejecutarEjercicio1() {
    Solution1 sol1;
    TreeNode* root1_1 = new TreeNode(5);
    root1_1->left = new TreeNode(4);
    root1_1->left->left = new TreeNode(4);
    root1_1->right = new TreeNode(19);

    TreeNode* root1_2 = new TreeNode(5);
    root1_2->left = new TreeNode(2);
    root1_2->right = new TreeNode(13);

    TreeNode* mergedTree = sol1.mergeTrees(root1_1, root1_2);
    cout << "Arbol fusionado: ";
    sol1.printTree(mergedTree);
    cout << endl;
}

// Ejercicio 2: Convertir un árbol binario a una representación en string
class Solution2 {
public:
    string treeToStr(TreeNode* root) {
        if (!root) return "";
        string result = to_string(root->val);
        if (root->left || root->right) {
            result += "(" + treeToStr(root->left) + ")";
            if (root->right) result += "(" + treeToStr(root->right) + ")";
        }
        return result;
    }
};

void ejecutarEjercicio2() {
    Solution2 sol2;
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    cout << sol2.treeToStr(root2) << endl;
}

// Ejercicio 3: Convertir un árbol binario a un BST mayor
class Solution3 {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        convert(root, sum);
        return root;
    }

private:
    void convert(TreeNode* node, int& sum) {
        if (!node) return;
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

void ejecutarEjercicio3() {
    vector<int*> input1 = {new int(4), new int(1), new int(6), new int(0), new int(2), new int(5), new int(7), nullptr, nullptr, nullptr, new int(3), nullptr, nullptr, nullptr, new int(8)};
    TreeNode* root3_1 = insertLevelOrder(input1, 0, input1.size());
    Solution3 sol3;
    root3_1 = sol3.convertBST(root3_1);
    cout << "Output 1: ";
    printInOrder(root3_1);
    cout << endl;

    vector<int*> input2 = {new int(0), nullptr, new int(1)};
    TreeNode* root3_2 = insertLevelOrder(input2, 0, input2.size());
    root3_2 = sol3.convertBST(root3_2);
    cout << "Output 2: ";
    printInOrder(root3_2);
    cout << endl;
}

// Función principal para seleccionar el ejercicio a ejecutar
int main() {
    int opcion;
    cout << "Selecciona el ejercicio a ejecutar (1, 2 o 3): ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            ejecutarEjercicio1();
            break;
        case 2:
            ejecutarEjercicio2();
            break;
        case 3:
            ejecutarEjercicio3();
            break;
        default:
            cout << "Opción no válida." << endl;
            break;
    }

    return 0;
}
