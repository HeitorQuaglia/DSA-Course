#include<vector>
#include<iostream>
#include<algorithm>

int rob(const std::vector<int>& nums);
void compareAndPrint(int idx, int a, int b) {
    std::cout << idx << ": " << (a == b ? "Correto" : "Incorreto") << std::endl;
}
int main(void) {
    std::vector<int> nums;
    int expected;

    // Caso 1: Array Vazio (O ladrão não tem casas para roubar)
    nums = {};
    expected = 0;
    compareAndPrint(1, expected, rob(nums));

    // Caso 2: Exemplo clássico do LeetCode (Alternância simples)
    // Decisão: Roubar casa 1 (1) e casa 3 (3) -> Total: 4
    nums = {1, 2, 3, 1};
    expected = 4;
    compareAndPrint(2, expected, rob(nums));

    // Caso 3: Salto maior (Otimização de valor)
    // Decisão: Roubar casa 1 (2), casa 3 (9) e casa 5 (1) -> Total: 12
    nums = {2, 7, 9, 3, 1};
    expected = 12;
    compareAndPrint(3, expected, rob(nums));

    // Caso 4: Casas com valores iguais
    // Decisão: Rouba todas as casas ímpares ou pares -> Total: 2 + 2 = 4
    nums = {2, 2, 2, 2};
    expected = 4;
    compareAndPrint(4, expected, rob(nums));

    // Caso 5: Uma única casa de alto valor cercada por baixos
    // Decisão: Roubar apenas a casa do meio (100) é melhor que o resto
    nums = {1, 100, 1, 1, 1};
    expected = 100;
    compareAndPrint(5, expected, rob(nums));
}


int rob(const std::vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    int one_before, two_before = 0;

    for (auto n : nums) {
        auto temp = std::max(n + two_before, one_before);
        two_before = one_before;
        one_before = temp;
    }

    return one_before;
}