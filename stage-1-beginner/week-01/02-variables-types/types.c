#include <stdio.h>

int main(void) {
    /* TODO 1: Declare one variable of each type: int, float, double, char */
    int age = 20;
    float price = 3.99;
    double pi = 3.14159;
    char grade = 'A';
    /* TODO 2: Print each variable and its sizeof() */
    printf("age: %d, size: %zu bytes\n", age, sizeof(age));
    printf("price: %.2f, size: %zu bytes\n", price, sizeof(price));
    printf("pi: %.5f, size: %zu bytes\n", pi, sizeof(pi));
    printf("grade: %c, size: %zu bytes\n", grade, sizeof(grade));

    /* TODO 3: Observe what happens when you assign 300 to a char */
    char new_char = 300; // This will cause overflow since char can only hold values from -128 to 127 (or 0 to 255 if unsigned)
    printf("new_char: %d, size: %zu bytes\n", new_char, sizeof(new_char));
    return 0;
}
