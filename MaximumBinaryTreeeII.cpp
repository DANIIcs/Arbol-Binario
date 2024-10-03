#include <iostream>
using namespace std;

// Definición de un nodo de árbol binario
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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        // Caso base: Si no hay raíz, devolvemos un nuevo nodo con el valor 'val'
        if (!root) {
            return new TreeNode(val);
        }
        
        // Si 'val' es mayor que el valor de la raíz actual, 'val' se convierte en la nueva raíz
        if (val > root->val) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;  // El árbol original se convierte en el hijo izquierdo
            return newRoot;
        }
        
        // Si 'val' es menor o igual, intentamos insertarlo en el subárbol derecho
        root->right = insertIntoMaxTree(root->right, val);
        return root;
    }
};
