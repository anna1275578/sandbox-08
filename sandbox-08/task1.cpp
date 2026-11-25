#include <iostream>

int count_words(const char* text) {
    int words = 0;
    bool inside = false;
    for (int i = 0; text[i] != '\0'; ++i) {
        char c = text[i];
        if (c == ' ' || c == ',' || c == '\t') {
            inside = false;
        } else if (!inside) {
            inside = true;
            words = words + 1;
        }
    }
    return words;
}

int main() {
    std::cout << count_words("one,two three") << ' ' << count_words("  a,,b ") << '\n';
}