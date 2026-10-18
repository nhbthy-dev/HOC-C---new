/*Bội chung nhỏ nhất
Viết hàm find_lcm để tìm bội chung nhỏ nhất (Least Common Multiple - LCM) của hai số nguyên dương a và b.

Một số x được gọi là bội chung của a và b nếu:

x % a == 0

x % b == 0

Bội chung nhỏ nhất là số nguyên dương nhỏ nhất thỏa mãn đồng thời hai điều kiện trên.

Sinh viên có thể bắt đầu kiểm tra từ số lớn hơn giữa a và b, sau đó tăng dần giá trị cho đến khi tìm được một số chia hết cho cả a và b.

Ví dụ
Input	Result
3 4	12
Ví dụ với a = 3 và b = 4:

Các bội của 3: 3, 6, 9, 12, ...

Các bội của 4: 4, 8, 12, ...

Số dương nhỏ nhất xuất hiện trong cả hai dãy là 12, do đó:

LCM(3, 4) = 12

For example:

Input	Result
3 4      12
*/
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int lcm = (a > b) ? a : b;   // bắt đầu từ số lớn hơn (vì bội không thể bắt đầu từ số nhỏ)

    while (true) {                                  //while (true) vòng lặp vô tận -> dùng break để ngắt
        if (lcm % a == 0 && lcm % b == 0) {
            break;               // số đầu tiên chia hết cho cả hai
        }
        lcm++;
    }

    cout << lcm << endl;
    return 0;
}
   