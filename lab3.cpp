#include <iostream>
#include <cstring>

void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = (text[i] + shift) % 128;
    }
}

void decrypt(char *text, int shift) {
    encrypt(text, 128 - (shift % 128));
}

int main() {
    char text[100];
    int shift;

    std::cout << "Enter text: ";
    std::cin.getline(text, sizeof(text));

    std::cout << "Enter shift (1-127): ";
    std::cin >> shift;

    if (shift < 1 || shift > 127) {
        std::cout << "Shift must be between 1 and 127." << std::endl;
        return 1;
    }

    encrypt(text, shift);
    std::cout << "Encrypted text: ";
    for (int i = 0; text[i] != '\0'; i++) {
        std::cout << text[i];
    }
    std::cout << std::endl;

    decrypt(text, shift);
    std::cout << "Decrypted text: ";
    for (int i = 0; text[i] != '\0'; i++) {
        std::cout << text[i];
    }
    std::cout << std::endl;

    return 0;
}
