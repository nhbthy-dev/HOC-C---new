/*Chuyển đổi mã ASCII
Input
Một ký tự và một số nguyên trong khoảng 1..255.

Output
Dòng 1: mã ASCII của ký tự.

Dòng 2: ký tự có mã ASCII bằng số nguyên đã nhập.

For example:

Input	Result
a 43    97
        +
*/
#include <iostream>
using namespace std;
int main () {
    char character;
    int number;
    cin>>character>>number;
    cout<<(int)character<<endl;
    cout<<(char)number<<endl;
    return 0;
}