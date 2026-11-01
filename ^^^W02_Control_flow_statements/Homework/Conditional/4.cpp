/*Tìm max giữa 3 số
Trả về giá trị lớn nhất trong 3 số thực a,b,c
Input:1.2  3.012  2.222
Output: 3.012
*/
#include <iostream>
using namespace std;

int main() {
    double a,b,c;
    cin>>a>>b>>c;
    double max = a;
    if (max<b) max =b;
    if (max<c) max =c;
    cout<<max;
    return 0;
}