#include <algorithm>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode* root);

void compareAndPrint(int idx, int a, int b) {
    std::cout << idx << ": " << (a == b ? "Correto" : "Incorreto") << std::endl;
}

int main(void) {
    TreeNode* root = nullptr;
    int expected = 0;

    // Caso 1: Árvore Vazia
    root = nullptr;
    expected = 0;
    compareAndPrint(1, expected, maxDepth(root));

    // Caso 2: Apenas o nó raiz
    root = new TreeNode(1);
    expected = 1;
    compareAndPrint(2, expected, maxDepth(root));

    // Caso 3: Árvore completa (Equilibrada)
    //      1
    //     / \
    //    2   3
    root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    expected = 2;
    compareAndPrint(3, expected, maxDepth(root));

    // Caso 4: Árvore degenerada (Lista ligada para a direita)
    //  1 -> 2 -> 3 -> 4
    root = new TreeNode(1, nullptr, new TreeNode(2, nullptr, new TreeNode(3, nullptr, new TreeNode(4))));
    expected = 4;
    compareAndPrint(4, expected, maxDepth(root));

    // Caso 5: Árvore assimétrica (LeetCode Example)
    //      3
    //     / \
    //    9  20
    //      /  \
    //     15   7
    root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));
    expected = 3;
    compareAndPrint(5, expected, maxDepth(root));
}

int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;

    int max_d = 0;
    int current_d = 0;
    TreeNode* curr = root;
    TreeNode* prev = nullptr;
    struct StackNode { TreeNode* node; int depth; } stack[10000];
    int top = -1;

push:
    top++;
    stack[top].node = curr;
    stack[top].depth = ++current_d;

    if (current_d > max_d) max_d = current_d;

    if (curr->left) {
        curr = curr->left;
        goto push;
    }

check_right:
    curr = stack[top].node;
    current_d = stack[top].depth;

    if (curr->right && curr->right != prev) {
        curr = curr->right;
        goto push;
    }

pop:
    prev = curr;
    top--;
    if (top >= 0) goto check_right;

    return max_d;
}