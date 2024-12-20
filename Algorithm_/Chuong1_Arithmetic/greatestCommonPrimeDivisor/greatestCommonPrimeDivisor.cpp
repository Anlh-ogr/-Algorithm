#include "iostream"

bool arr[1 + static_cast<int>(1e6)];

void Eratosthenes (int n) {
    for (int i=2; i<n; ++i)
        arr[i]=1;
    arr[0]=arr[1]=0;

    for (int i=2; i*i<=n; ++i)
        if (arr[i])
            for (int j=2*i; j<=n; j+=i)
                arr[j]=0;
}

int greatestCommonPrimeDivisor(int a, int b) {
    Eratosthenes(std::min(a,b));

    for (int i=std::min(a,b); i>=2; --i)
        if (arr[i] && a%1==0 && b%i==0)
            return i;

    return -1;
}

int main() {
    int a, b; std::cin>>a>>b;
    std::cout<<greatestCommonPrimeDivisor(a,b);
}