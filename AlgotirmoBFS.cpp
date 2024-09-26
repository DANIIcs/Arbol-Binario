#include <iostream>
#include <queue>
using namespace std;

// Definición para un nodo de árbol binario.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Función para realizar un recorrido BFS (Breadth-First Search)
void bfs(TreeNode* root) {
    if (root == nullptr) return;  // Si el árbol está vacío, no hay nada que recorrer
    
    queue<TreeNode*> q;  // Cola para gestionar los nodos por nivel
    q.push(root);        // Se agrega el nodo raíz a la cola
    
    while (!q.empty()) {
        TreeNode* node = q.front();  // Se obtiene el nodo al frente de la cola
        q.pop();  // Se elimina el nodo de la cola
        
        cout << node->val << " ";  // Se imprime el valor del nodo actual
        
        // Se agregan los hijos del nodo actual a la cola, si existen
        if (node->left != nullptr) {
            q.push(node->left);  // Agregar el hijo izquierdo
        }
        if (node->right != nullptr) {
            q.push(node->right);  // Agregar el hijo derecho
        }
    }
}

int main() {
    // Creamos un árbol binario de ejemplo
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    
    // Ejecutamos el recorrido BFS (por niveles)
    cout << "Recorrido BFS del árbol: ";
    bfs(root);  // El resultado será: 1 2 3 4 5 6
    
    return 0;
}
