/*Kiểm tra chẵn lẽ
Trả về 1 nếu số nguyên x là số chẵn, ngược lại trả về 0
Input: 2
Output :1
*/
#include <iostream>
using namespace std;

int main() {
    int x;
    cin>>x;
    if (x %2 ==0) cout<<1;
    else cout<<0;
    return 0;
}