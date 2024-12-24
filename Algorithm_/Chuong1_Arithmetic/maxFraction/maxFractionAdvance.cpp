#include "iostream"
#include "vector"

int maxFraction(std::vector<int> numerators, std::vector<int> denominators) {
    int cs=0;
    for (int i=1; i<numerators.size(); ++i)
        if (numerators[cs]*denominators[i]<numerators[i]*denominators[cs])
            cs=i;
    
    return cs;
}

int main() {
    int n; std::cin>>n;

    std::vector<int> numerators(n), denominators(n);
    for (int i=0; i<n; ++i) std::cin>>numerators[i];
    for (int i=0; i<n; ++i) std::cin>>denominators[i];

    std::cout<<maxFraction(numerators, denominators);
}