/*Số thuận nghịch
Viết hàm check_palindromic_number để kiểm tra số nguyên dương n có phải là số thuận nghịch hay không.

Một số được gọi là số thuận nghịch (palindrome) nếu khi đọc các chữ số từ trái sang phải hoặc từ phải sang trái đều cho cùng một giá trị.

Hàm cần:

trả về 1 nếu n là số thuận nghịch;

trả về 0 nếu n không phải là số thuận nghịch.

Ví dụ
Input	Result
7	1
121	1
12312	21321
Ví dụ với: n = 121 . Số đảo ngược cũng là: 121 nên hàm trả về 1.

Ngược lại: n = 12312 . Số đảo ngược là: 21321 hai giá trị không bằng nhau nên hàm trả về 0.

For example:

Input	Result
12312     0
*/
#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int n1 = n; //để giá trị n được giữ nguyên để so sánh với dao -> dùng biến phụ để lưu
    int dao = 0;
while (n > 0) {
    dao = dao * 10 + n % 10;
    n /= 10;
}
if (dao==n1) cout<<1;
else cout << 0;
return 0;
}