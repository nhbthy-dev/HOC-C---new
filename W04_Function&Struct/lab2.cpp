/*Happy Number
Viết hai hàm nextNumber và isHappy để kiểm tra một số nguyên dương n có phải là Happy Number hay không.

Hàm nextNumber(n) tạo ra một số mới bằng cách tính tổng bình phương các chữ số của n.

Ví dụ:

19 → 12 + 92 = 82

Một số được gọi là Happy Number nếu khi lặp lại quá trình trên, cuối cùng nhận được giá trị 1.

Ví dụ với n = 19:

19 → 82 → 68 → 100 → 1
Nếu quá trình không đi đến 1, các giá trị sẽ lặp lại theo một chu kỳ.

Để phát hiện chu kỳ mà không sử dụng mảng hoặc cấu trúc dữ liệu khác, sử dụng hai biến:

slow: mỗi vòng lặp gọi nextNumber một lần.
fast: mỗi vòng lặp gọi nextNumber hai lần.
Dừng khi slow == fast. Nếu giá trị gặp nhau là 1 thì n là Happy Number.

Lưu ý: Đây là bài thực hành về hàm. Hàm isHappy cần gọi và sử dụng hàm nextNumber.

Sinh viên cần tự định nghĩa đầy đủ các hàm dựa trên các prototype sau:

int nextNumber(int n);

bool isHappy(int n);
For example:

Input	Result
19      82
*/
#include <iostream>
using namespace std;


int nextNumber(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}


bool isHappy(int n) {
    int slow = n;
    int fast = n;

    do {
        slow = nextNumber(slow);                // Tiến 1 bước
        fast = nextNumber(nextNumber(fast));    
    } while (slow != fast);

    return (slow == 1);
}