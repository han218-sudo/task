#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./calculator \"<num1> <operator> <num2>\"\n");
        return 1;
    }

    int num1, num2;
    char operator;

    // Parse the input string
    if (sscanf(argv[1], "%d %c %d", &num1, &operator, &num2) != 3) {
        printf("Error: Invalid input format. Use: \"<num1> <operator> <num2>\"\n");
        return 1;
    }

    // Perform the calculation
    switch (operator) {
        case '+':
            printf("%d + %d = %d\n", num1, num2, add(num1, num2));
            break;
        case '-':
            printf("%d - %d = %d\n", num1, num2, subtract(num1, num2));
            break;
        case '*':
            printf("%d * %d = %d\n", num1, num2, multiply(num1, num2));
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
                return 1;
            }
            printf("%d / %d = %.2f\n", num1, num2, divide(num1, num2));
            break;
        default:
            printf("Error: Unsupported operator '%c'\n", operator);
            return 1;
    }

    return 0;
}

// Function definitions
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

float divide(int a, int b) {
    return (float)a / b;
}
