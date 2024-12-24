#include "iostream"

int main () {
    int n; std::cin>>n;

    float numerators[n], denominators[n];
    for (int i=0; i<n; ++i) std::cin>>numerators[i];
    for (int i=0; i<n; ++i) std::cin>>denominators[i];

    float max=0;
    float maxFraction;
    float elementFraction[n];

    for (int i=0; i<n; ++i) {
        elementFraction[i]=numerators[i]/denominators[i];
        if (elementFraction[i]>elementFraction[i+1]) {
            maxFraction=elementFraction[i];
            max = i;
        }
    }   

    std::cout<<"max:"<<maxFraction<<"-locate:"<<max;

    return 0;
}