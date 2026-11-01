/*Tính tuổi
Input
Một số nguyên là năm sinh ( 0 ≤ year ≤ 2026).

Output
Số tuổi được tính bằng 2026 - năm sinh.

For example:

Input	Result
1990     36
*/
#include <iostream>
using namespace std;
int main () {
    int birthyear;
    cin>>birthyear;
    int age = 2026 - birthyear;
    cout<<age;
}