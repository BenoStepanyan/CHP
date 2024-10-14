#include <iostream>
#include <cstring>

void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + shift) % 26 + 'a'; 
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + shift) % 26 + 'A'; 
        }
        text[i] = ch;
    }
}

void decrypt(char *text, int shift) {
    encrypt(text, 26 - (shift % 26)); 
}

int main() {
    char text[100];
    int shift;

    std::cout << "Enter text: ";
    std::cin.getline(text, 100); 

    std::cout << "Enter key (1-25): ";
    std::cin >> shift;

    encrypt(text, shift);
    std::cout << "Encrypted text: " << text << std::endl;

    decrypt(text, shift);
    std::cout << "Decrypted text: " << text << std::endl;

    return 0;
}
