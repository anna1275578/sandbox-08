#include <iostream>

void lex(const char* line) {
    for (int i = 0; line[i] != '\0'; ) {
        char c = line[i];
        if (c >= '0' && c <= '9') {
            std::cout << "Number(";
            while (line[i] >= '0' && line[i] <= '9') {
                std::cout << line[i];
                i = i + 1;
            }
            std::cout << ") ";
        } else if (c >= 'a' && c <= 'z') {
            std::cout << "Ident(";
            while (line[i] >= 'a' && line[i] <= 'z') {
                std::cout << line[i];
                i = i + 1;
            }
            std::cout << ") ";
        } else {
            std::cout << "Punct(" << c << ") ";
            i = i + 1;
        }
    }
    std::cout << '\n';
}

int main() {
    lex("ab=7");
    lex("count=12+x");
}