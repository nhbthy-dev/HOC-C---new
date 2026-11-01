/*Tính giá trị biểu thức
Input
Một số thực x.

Output
Dòng 1: y1 = 4 * (x^2 + 10*x*sqrt(x) + 3*x + 1).

Dòng 2: y2 = (sin(PI*x^2) + sqrt(x^2 + 1)) / (exp(2*x) + cos((PI/4)*x)).

Mỗi giá trị có đúng 4 chữ số sau dấu chấm, với PI = 3.14159.

For example:

Input	   Result
3.45    349.3336
        0.0033
*/
#include <iomanip>
#include <iostream>
#include <cmath>
#define PI 3.14159
using namespace std;
int main () {
    double x;
    cin>>x;
    double y1 = 4*(x*x + 10*x*sqrt(x) + 3*x +1);
    double y2 = (sin(PI*x*x) + sqrt (x*x+1))/ (exp(2*x) + cos ((PI/4)*x));
    cout<<fixed<<setprecision(4)<<y1<<endl<<y2<<endl;
    return 0;
}