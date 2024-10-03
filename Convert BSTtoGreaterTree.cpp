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
    int sum = 0; // Variable para acumular la suma de los nodos mayores
    
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        
        // Paso 1: Recorrer el subárbol derecho
        convertBST(root->right);
        
        // Paso 2: Actualizar el valor del nodo actual con la suma acumulada
        sum += root->val;
        root->val = sum;
        
        // Paso 3: Recorrer el subárbol izquierdo
        convertBST(root->left);
        
        return root;
    }
};
