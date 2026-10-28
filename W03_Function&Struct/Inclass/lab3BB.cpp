/*Reverse Integer
Viết hàm reverse nhận vào một số nguyên 32-bit có dấu x và trả về số được tạo bằng cách đảo ngược thứ tự các chữ số của x.

Ví dụ:

123   → 321
-123  → -321
120   → 21
Các chữ số 0 ở đầu kết quả sau khi đảo không được giữ lại.

Kết quả phải nằm trong miền của kiểu int 32-bit:

-2147483648 <= result <= 2147483647
Nếu kết quả sau khi đảo vượt khỏi miền trên, hàm phải trả về:

0
Lưu ý: Không chuyển số thành chuỗi để đảo. Hãy sử dụng phép chia /, phép chia dư %, vòng lặp và rẽ nhánh.

Sinh viên cần tự định nghĩa đầy đủ hàm dựa trên prototype sau:

int reverse(int x);
For example:

Input	Result
123       321
*/
#include <iostream>
#include <climits>

using namespace std;

int reverse(int x) {
    int res = 0;
    
    while (x != 0)  //không dùng x>0 để cho số âm cũng chạy được
    {
        int pop = x % 10;
        x /= 10;
        
        if (res > INT_MAX / 10 || (res == INT_MAX / 10 && pop > 7)) {
            return 0;
        }
        if (res < INT_MIN / 10 || (res == INT_MIN / 10 && pop < -8)) {
            return 0;
        }
        
        res = res * 10 + pop;
    }
    //không để res trước để tránh trường hợp bị tràn số
    // /10 là vì res còn nhân 10 và cộng pop
    return res;
}

int main() {
    int x;
    cin >> x;
    cout << reverse(x);
    
    return 0;
}