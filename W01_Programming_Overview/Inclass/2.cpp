/*Tính tổng
Input
Một số nguyên a và một số thực b.

Output
Tổng a + b với đúng 3 chữ số sau dấu chấm.

For example:

Input	Result
3 2.0   5.000
*/
#include <iostream>
#include <iomanip>
using namespace std;
int main () {
    int a;
    double b;
    cin>>a>>b;
    double sum = a + b;
    cout<<fixed<<setprecision(3)<<sum;
    return 0;
}