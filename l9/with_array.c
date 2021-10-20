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

void get_string(char *str)
{
    int ctr = 0;
    char ch;

    while( (ch = getchar()) != '\n') {
        *str++ = ch;
        ctr++;
    }
}

int main()
{
    char ch;
    char string[100] = { 0 };
    float result = 0;
    int current = 0;
    char operand = ' ';
    
    get_string(string);
    
    for (int i = 0; i < 100; i++) {
        ch = string[i];
        if (is_num(ch)) {
            current *= 10;
            current += ch - '0';
        } else if (is_operand(ch) || ch == '\0') {
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
            if (ch == '\0') {
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


