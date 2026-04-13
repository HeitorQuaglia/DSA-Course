#include <stdio.h>
#include <stdint.h>

typedef uint8_t b8;


void reverse_word(char *p1, char *p2) {
    if (p1 >= p2) return;

    char temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    return reverse_word(p1 + 1, p2 - 1);
}

int main(void) {
    char str[] = "car bart";
    
    char *p1 = &str[0];
    char *p2 = 0x0;
    char *middle = 0x0;
    int i = 0;
    //find space
    while(str[i]) {
        if (str[i] == ' ') {
            middle = &str[i];
        } 

        i++;
    }

    p2 = &str[i];
    --p2;
    
    reverse_word(p1, middle - 1);

    reverse_word(++middle, p2);

    i = 0;
    while (str[i]) {
        printf("%c", str[i++]);
    }
    printf("\n");
    return 0;
}