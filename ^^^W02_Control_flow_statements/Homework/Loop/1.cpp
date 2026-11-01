/*Liệt kê ước số
Viết hàm get_divisors để tìm và liệt kê tất cả các ước số dương của số nguyên n.

Một số nguyên dương i được gọi là ước số của n nếu:

n % i == 0

Hàm cần:

ghép các ước số theo thứ tự tăng dần vào một chuỗi;

các ước số cách nhau đúng một khoảng trắng;

không có khoảng trắng dư ở cuối chuỗi.

Để chuyển một số nguyên thành chuỗi, sinh viên có thể sử dụng hàm:

to_string(i)

Sau khi chuyển số thành chuỗi, có thể thực hiện phép nối chuỗi bằng toán tử + hoặc += để thêm giá trị đó vào biến kết quả result.

Ví dụ:

result += to_string(i);

Nếu cần thêm khoảng trắng giữa các ước số, có thể nối thêm chuỗi " " vào result.

Ví dụ
Input	Result
1	     1
36	     1 2 3 4 6 9 12 18 36
Lưu ý
Kết quả cuối cùng phải là một chuỗi string, trong đó các ước số được nối lại theo đúng thứ tự tăng dần.

For example:

Input	Result
6      1 2 3 6
*/
#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) cout<<i<<" ";// muốn cout i thỏa mãn -> dùng if
         
    }
    return 0;
}