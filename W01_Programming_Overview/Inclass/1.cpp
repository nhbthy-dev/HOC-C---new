/*Tính thương của hai số
Input
Hai số thực a b.

Output
Nếu b != 0, in thương a / b với đúng 3 chữ số sau dấu chấm.

Nếu b = 0, in Phep chia khong hop le.

For example:

Input	Result
5 2      2.500
*/

#include <iostream>
#include <iomanip>
using namespace std;
int main () {
    double a,b;
    cin>>a>>b;
    if (b!=0) {
        double thuong = a/b;
        cout<<fixed<<setprecision(3)<<thuong;
    } else {
        cout<<"Phep chia khong hop le";
    }
    return 0;
}