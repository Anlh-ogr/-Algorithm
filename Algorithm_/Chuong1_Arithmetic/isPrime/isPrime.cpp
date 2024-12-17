#include "iostream"

bool isPrime(int nVal) {
    if(nVal<=1) return false;
    for(int i=2;i<nVal;++i)
        if(nVal%i==0) return false;
    return true;
}

int main() {
    std::cout<<"Enter n: ";
    int n; std::cin>>n;

    isPrime(n)?std::cout<<"true":std::cout<<"false";
}