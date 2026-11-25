#include <iostream>

void calc(const char* expr) {
    int i = 0;
    int left = 0;
    while (expr[i] >= '0' && expr[i] <= '9') {
        left = left * 10 + (expr[i] - '0');
        i = i + 1;
    }
    char op = expr[i];
    i = i + 1;
    int right = 0;
    while (expr[i] >= '0' && expr[i] <= '9') {
        right = right * 10 + (expr[i] - '0');
        i = i + 1;
    }
    if (expr[i] != '\0') {
        std::cout << "error at " << i << '\n';
        return;
    }
    int result = (op == '+') ? left + right : (op == '-') ? left - right : left * right;
    std::cout << result << '\n';
}

int main() {
    calc("12+34");
    calc("7*6x");
}