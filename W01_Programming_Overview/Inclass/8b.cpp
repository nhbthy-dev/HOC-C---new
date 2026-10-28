/*Đổi tiền
Input
Một số nguyên N ≥ 0.

Output
Bốn số nguyên lần lượt là số tờ 10, 5, 2 và 1 đồng.

For example:

Input	Result
543     54 0 1 1
*/
#include <iostream>
using namespace std;
int main () {
    int N,to10,to5,to2,to1;
    cin>>N;
    to10 = N/10;
    N=N-to10*10;
    to5=N/5;
    N=N-to5*5;
    to2=N/2;
    N=N-to2*2;
    to1=N/1;
    N=N -1*to1;
    cout<<to10<<" "<<to5<<" "<<to2<<" "<<to1<<endl;
    return 0;
}