#include <iostream>
#include <vector>
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
    // Función principal para balancear el árbol
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> values;
        // Paso 1: Recorrer el árbol en inorden para obtener los valores ordenados
        inOrderTraversal(root, values);
        
        // Paso 2: Reconstruir el árbol balanceado a partir de los valores ordenados
        return buildBalancedTree(values, 0, values.size() - 1);
    }

private:
    // Recorrido inorden para obtener los valores en orden ascendente
    void inOrderTraversal(TreeNode* node, vector<int>& values) {
        if (node == nullptr) {
            return;
        }
        inOrderTraversal(node->left, values);
        values.push_back(node->val);  // Almacenar los valores en el vector
        inOrderTraversal(node->right, values);
    }
    
    // Función para construir un árbol balanceado a partir de los valores ordenados
    TreeNode* buildBalancedTree(const vector<int>& values, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        
        int mid = start + (end - start) / 2;  // Elegimos el elemento medio
        TreeNode* node = new TreeNode(values[mid]);  // Crear un nuevo nodo con el valor medio
        
        // Construimos recursivamente los subárboles izquierdo y derecho
        node->left = buildBalancedTree(values, start, mid - 1);
        node->right = buildBalancedTree(values, mid + 1, end);
        
        return node;
    }
};
