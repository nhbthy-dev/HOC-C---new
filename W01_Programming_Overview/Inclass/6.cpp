/*Diện tích và thể tích hình trụ
Input
Hai số thực: bán kính đáy R và chiều cao h.

Output
Dòng 1: Sday = PI * R * R.

Dòng 2: Sxquanh = 2 * PI * R * h.

Dòng 3: V = Sday * h.

Mỗi giá trị có đúng 5 chữ số sau dấu chấm, với PI = 3.14159.

For example:

Input	           Result
3.5 2.03         38.48448
                 44.64199
                 78.12349
*/
#include <iostream>
#include <iomanip>
# define PI 3.14159
using namespace std;
int main () {
    double r,h;
    cin>>r>>h;
    double Sday=PI*r*r;
    double Sxquanh=2*PI*r*h;
    double V = Sday*h;
    cout<<fixed<<setprecision(5)<<Sday<<endl<<Sxquanh<<endl<<V<<endl;
    return 0;
}