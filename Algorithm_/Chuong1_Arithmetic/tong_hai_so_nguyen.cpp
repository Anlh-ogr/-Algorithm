#include "iostream"

int sum(int a, int b) {
    return a + b;
}

int main() {
    int a_val, b_val;
    std::cout << "Nhap vao 2 so nguyen: ";
    std::cin >> a_val >> b_val;
    std::cout << "Tong 2 so nguyen: 4 " << sum(a_val, b_val) << std::endl;

    return 0;
}