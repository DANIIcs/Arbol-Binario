#include <iostream>
using namespace std;

// Definición de un nodo de la lista enlazada
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Definición de un nodo del árbol binario
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
    TreeNode* sortedListToBST(ListNode* head) {
        // Si la lista está vacía, devolvemos nullptr
        if (head == nullptr) {
            return nullptr;
        }
        
        // Si la lista solo tiene un nodo, ese nodo es la raíz del BST
        if (head->next == nullptr) {
            return new TreeNode(head->val);
        }
        
        // Paso 1: Encontrar el nodo medio de la lista
        ListNode* mid = findMiddle(head);
        
        // Paso 2: Crear un nuevo nodo con el valor del nodo medio
        TreeNode* root = new TreeNode(mid->val);
        
        // Paso 3: Recursivamente construir el subárbol izquierdo
        root->left = sortedListToBST(head);
        
        // Paso 4: Recursivamente construir el subárbol derecho
        root->right = sortedListToBST(mid->next);
        
        return root;
    }

private:
    // Función para encontrar el nodo medio de la lista enlazada
    ListNode* findMiddle(ListNode* head) {
        // Usaremos los punteros rápido y lento
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        
        // Avanzamos hasta que el puntero rápido llegue al final de la lista
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Si prev no es nullptr, desconectamos la mitad izquierda de la lista
        if (prev != nullptr) {
            prev->next = nullptr;
        }
        
        return slow;  // slow será el nodo medio
    }
};
