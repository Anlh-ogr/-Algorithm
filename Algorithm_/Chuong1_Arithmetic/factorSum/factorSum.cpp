#include "iostream"

int primeFactorSum(int nVal) {
    int total = 0;
    int temp = 2;

    while (nVal>1) {
        while (nVal%temp==0) {
            total += temp;
            nVal /= temp;
        }
        temp++;
    }
    return total;
}

int factorSum(int n) {
    while(n != primeFactorSum(n))
        n = primeFactorSum(n);
    return n;
}

int main() {
    int n; std::cin>>n;
    std::cout<<factorSum(n);
    return 0;
}