#include <iostream>
using namespace std;

// Definición para un nodo de árbol binario.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Función para realizar un recorrido en Preorden (Preorder DFS)
void preorder(TreeNode* root) {
    if (root == nullptr) return;  // Caso base: si el nodo es NULL, no hay nada que recorrer
    
    cout << root->val << " ";  // Procesamos el nodo actual (la raíz)
    preorder(root->left);  // Recursivamente recorrer el subárbol izquierdo
    preorder(root->right);  // Recursivamente recorrer el subárbol derecho
}

int main() {
    // Creamos un árbol binario de ejemplo
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    
    // Ejecutamos el recorrido en preorden (DFS Preorder)
    cout << "Recorrido Preorden del árbol: ";
    preorder(root);  // El resultado será: 1 2 4 5 3 6
    
    return 0;
}
