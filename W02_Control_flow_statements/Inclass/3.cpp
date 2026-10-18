/*Tổng các chữ số
Viết hàm sum_all_number để tính tổng tất cả các chữ số của số nguyên dương n.

Để tách từng chữ số của n, sinh viên có thể sử dụng:

n % 10 để lấy chữ số cuối cùng;

n / 10 để loại bỏ chữ số cuối cùng.

Lặp lại quá trình trên cho đến khi n = 0, đồng thời cộng dồn các chữ số vào biến tổng.

Ví dụ
Input	Result
1	1
123456	21
Với n = 123456:

1 + 2 + 3 + 4 + 5 + 6 = 21

nên hàm trả về 21.

For example:

Input	Result
123456   21
*/
#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int sum =0;
    while (n>0) {
        sum +=n%10;
        n/=10;
    }
    cout<<sum;
    return 0;
}