#include <stdio.h>

void displayBitPattern(int num) {
    int i;
    for(i = (sizeof(int) * 8) - 1; i >= 0; i--){
        if(i % 4 == 3){
            printf(" ");
        }
        printf("%d", (num >> i) & 1);
    }
}

int main() {
    int num = 10;
    displayBitPattern(num);
    return 0;
}