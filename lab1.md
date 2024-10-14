#include <iostream>

int dev(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;

    std::cout << "mutqagreq tvery: ";
    std::cin >> num1 >> num2;

    int result = dev(num1, num2);

    std::cout << num1 << "-i ev " << num2 << "-i amenamec yndhanur bajanarary " << result << "-n e" << std::endl;

    return 0;
}
