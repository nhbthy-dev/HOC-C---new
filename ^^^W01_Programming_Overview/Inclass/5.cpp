/*Chu vi và diện tích hình tròn
Input
Một số thực là bán kính r.

Output
Dòng 1: chu vi 2 * PI * r.

Dòng 2: diện tích PI * r * r.

Mỗi giá trị có đúng 5 chữ số sau dấu chấm, với biến PI = 3.14159 đã được định nghĩa sẵn.

For example:

Input	  Result
3.5     21.99113
        38.48448
*/
#include <iostream>
#include <iomanip>
#define PI 3.14159
using namespace std;
int main () {
    double r;
    cin>>r;
    double chuvi = 2*PI*r;
    double dientich = r*r*PI;
    cout<<chuvi<<endl<<dientich<<endl;
    return 0;
}