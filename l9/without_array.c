#include <stdio.h>
#include <stdbool.h>

bool is_num(char ch)
{
    return (ch >= '0' && ch <= '9') ? true : false;
}

bool is_operand(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/') ? true : false;
}

int main()
{
    char ch;
    float result = 0;
    int current = 0;
    char operand = ' ';
    while ((ch = getchar())) {
        if (is_num(ch)) {
            current *= 10;
            current += ch - '0';
        } else if (is_operand(ch) || ch == '\n') {
            switch (operand) {
                case ' ':
                    result = current;
                    break;
                case '+':
                    result += current;
                    break;
                case '-':
                    result -= current;
                    break;
                case '/':
                    result /= current;
                    break;
                case '*':
                    result *= current;
                    break;
                default:
                    break;
            }
            current = 0;
            operand = ch;
            if (ch == '\n') {
                printf("Result: %f\n", result);
                return 0;
            }

        } else {
            printf("Incorrect input\n");
            return -1;
        }
    }

    return 0;
}

