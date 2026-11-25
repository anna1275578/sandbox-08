#include <iostream>

int hex_digit(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }
    return c - 'A' + 10;
}

bool check_nmea(const char* s) {
    int sum = 0;
    int i = 1;
    while (s[i] != '*' && s[i] != '\0') {
        sum = sum ^ s[i];
        i = i + 1;
    }
    if (s[i] != '*' || s[i + 1] == '\0' || s[i + 2] == '\0') {
        return false;
    }
    int expected = hex_digit(s[i + 1]) * 16 + hex_digit(s[i + 2]);
    return sum == expected;
}

int main() {
    const char* good = "$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47";
    const char* bad = "$GPGGA,123519,4807.039,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47";
    std::cout << check_nmea(good) << ' ' << check_nmea(bad) << '\n';
}