/*Sắp xếp tăng dần
Sắp xếp 3 số nguyên a,b,c theo thứ tự tăng dần
Hàm cần xác định:
min: giá trị nhỏ nhất
middle : giá trị nằm giữa
max: giá trị lớn nhất
Sau đó trả về kết quả dưới dạng (min,middle,max)
Các giá trị có thể âm, dương, trùng nhau hoặc bằng 0
*/
//Cách 1: dùng các biến minv,middlev,maxv
#include <iostream>
using namespace std;

int main() {
    int a,b,c;
    cin>>a>>b>>c;
    int minv = a;
    if (minv>b) minv=b;
    if (minv>c) minv=c;
    int maxv=a;
    if (maxv<b) maxv=b;
    if (maxv<c) maxv=c;
    int middle = a + b + c - maxv - minv;
    cout<<minv<<" "<<middle<<" "<<maxv<<endl;
    return 0;
}
