#include <stdio.h>
int and(int *a, int *b, int *c) {
    return *a + *b + *c;
}

int main() {
    int x = 10, y = 20, z = 30;
    int result = and(&x, &y, &z); // Pass the addresses of the variables
    printf("The sum is: %d\n", result);
    return 0;
}
