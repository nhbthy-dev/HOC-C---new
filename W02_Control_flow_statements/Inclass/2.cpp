/*Tính giai thừa
Viết hàm compute_factorial để tính giai thừa của số nguyên n.

Giai thừa của n, ký hiệu là n!, được định nghĩa:

0! = 1

1! = 1

Với n > 1: n! = 1 × 2 × 3 × ... × n

Nếu n < 0, xem như giá trị không hợp lệ và hàm phải trả về -1.

Lưu ý

Sinh viên cần sử dụng cấu trúc vòng lặp để tính tích các số từ 1 đến n.

For example:

Input	Result
5        120
*/
#include <iostream>
using namespace std;

int main() {
    int n;
    int N=1;
    cin>>n;
    /*while (n>0) {
        N=N*n;
        n-=1;
    }*/
   for (int i=1;i<=n;i++) {
       N = N*i;
   }
    cout<<N;
    return 0;
}