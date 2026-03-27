#include <iostream>

int hamming_weight(int n);
void compareAndPrint(int idx, int n, int n2);

int main(void) {
    int n = 11;
    int expected = 3;
    compareAndPrint(1,expected, hamming_weight(n));

    n = 128;
    expected = 1;
    compareAndPrint(2,expected, hamming_weight(n));

    n = 0;
    expected = 0;
    compareAndPrint(3,expected, hamming_weight(n));

    n = 2147483647;
    expected = 31;
    compareAndPrint(4,expected, hamming_weight(n));

    n = 4294967295;
    expected = 32;
    compareAndPrint(5,expected, hamming_weight(n));

    return 0;
}

int hamming_weight(int n) {
    int res = 0;
    int numberOfBits = n;
    while (numberOfBits) {
        res += numberOfBits & 1;
        numberOfBits = numberOfBits >> 1;
    }

    return res;
}

void compareAndPrint(int idx, int n, int n2) {
    std::cout << idx << ": " << (n == n2 ? "Correto" : ("Incorreto, expected: " + std::to_string(n) + " received: " + std::to_string(n2))) << std::endl;
} 