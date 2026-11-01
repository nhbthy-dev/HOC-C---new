#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int Max = 0;
    while (n>0) {
    int k = n%10;
    if (k>Max) Max = k;
    n/=10;
    }
    cout<<Max<<endl;
    int Min = n%10;
    while (n>0) {
    int k = n%10;
    if (k<Min) Min = k;
    n/=10;
    }
    cout<<Min;
    return 0;
}


