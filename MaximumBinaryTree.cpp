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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // Si el vector está vacío, devolvemos nullptr (no hay más nodos que crear)
        if (nums.empty()) {
            return nullptr;
        }
        
        // Paso 1: Encontrar el valor máximo y su índice
        int maxIndex = findMaxIndex(nums);
        int maxValue = nums[maxIndex];
        
        // Paso 2: Crear el nodo raíz con el valor máximo
        TreeNode* root = new TreeNode(maxValue);
        
        // Paso 3: Llamar recursivamente para construir los subárboles
        vector<int> leftSubarray(nums.begin(), nums.begin() + maxIndex);  // Elementos a la izquierda del máximo
        vector<int> rightSubarray(nums.begin() + maxIndex + 1, nums.end()); // Elementos a la derecha del máximo
        
        root->left = constructMaximumBinaryTree(leftSubarray);   // Subárbol izquierdo
        root->right = constructMaximumBinaryTree(rightSubarray); // Subárbol derecho
        
        return root; // Devolver la raíz del árbol
    }

private:
    // Función para encontrar el índice del valor máximo en el vector
    int findMaxIndex(const vector<int>& nums) {
        int maxIndex = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }
        return maxIndex;
    }
};
