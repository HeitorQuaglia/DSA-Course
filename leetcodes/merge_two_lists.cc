#include <list>
#include <iostream>

void compareAndPrint(int idx, const std::list<int>& a, const std::list<int>& b);
std::list<int> merge_two_lists(std::list<int>& l1, std::list<int>& l2);

int main(void) {
std::list<int> l1, l2, expected;

    // Caso 1: Ambas vazias
    l1 = {};
    l2 = {};
    expected = {};
    compareAndPrint(1, expected, merge_two_lists(l1, l2));

    // Caso 2: Uma vazia
    l1 = {};
    l2 = {1, 3, 5};
    expected = {1, 3, 5};
    compareAndPrint(2, expected, merge_two_lists(l1, l2));

    // Caso 3: Intercaladas (mesmo tamanho)
    l1 = {1, 3, 5};
    l2 = {2, 4, 6};
    expected = {1, 2, 3, 4, 5, 6};
    compareAndPrint(3, expected, merge_two_lists(l1, l2));

    // Caso 4: Tamanhos diferentes
    l1 = {1, 10, 20};
    l2 = {5, 11};
    expected = {1, 5, 10, 11, 20};
    compareAndPrint(4, expected, merge_two_lists(l1, l2));

    // Caso 5: Elementos duplicados
    l1 = {1, 2, 4};
    l2 = {1, 3, 4};
    expected = {1, 1, 2, 3, 4, 4};
    compareAndPrint(5, expected, merge_two_lists(l1, l2));

    return 0;
}

std::list<int> merge_two_lists(std::list<int>& l1, std::list<int>& l2) {
    std::list<int> dummy;

    while (!l1.empty() && !l2.empty()) {
        if (*l1.begin() < *l2.begin()) {
            dummy.splice(dummy.end(), l1, l1.begin());
        } else {
            dummy.splice(dummy.end(), l2, l2.begin());
        }
    }

    if (!l1.empty()) {
        dummy.splice(dummy.end(), l1);
    } else {
        dummy.splice(dummy.end(), l2);
    }

    return dummy;
}

void compareAndPrint(int idx, const std::list<int>& a, const std::list<int>& b) {
    bool is_equal = (a == b);
    std::cout << idx << ": " << (is_equal ? "Correto" : "Incorreto") << std::endl;

    if (!is_equal) {
        std::cout << "  Expected: ";
        for (int x : a) std::cout << x << " ";
        std::cout << "\n  Received: ";
        for (int x : b) std::cout << x << " ";
        std::cout << std::endl;
    }
}