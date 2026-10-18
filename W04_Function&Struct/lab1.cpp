/*Ugly Number
Viết hàm isUgly để kiểm tra số nguyên n có phải là Ugly Number hay không.

Một số nguyên dương được gọi là Ugly Number nếu các thừa số nguyên tố của nó chỉ gồm:

2, 3, 5
Ví dụ:

6 = 2 × 3 nên 6 là Ugly Number.
8 = 2 × 2 × 2 nên 8 là Ugly Number.
14 = 2 × 7 nên 14 không phải là Ugly Number.
Quy ước:

1 được xem là Ugly Number.
Mọi giá trị n <= 0 không phải là Ugly Number.
Hàm trả về true nếu n là Ugly Number, ngược lại trả về false.

Sinh viên cần tự định nghĩa đầy đủ hàm dựa trên prototype sau:

bool isUgly(int n);
For example:

Input	Result
6         1
*/
bool isUgly(int n) {
    // Theo quy ước: n <= 0 không phải là Ugly Number
    if (n <= 0) {
        return false;
    }
    
    // Chia n cho 2 cho đến khi không chia hết nữa
    while (n % 2 == 0) {
        n /= 2;
    }
    
    // Chia n cho 3 cho đến khi không chia hết nữa
    while (n % 3 == 0) {
        n /= 3;
    }
    
    // Chia n cho 5 cho đến khi không chia hết nữa
    while (n % 5 == 0) {
        n /= 5;
    }
    
    // Nếu n rút gọn về 1 thì n là Ugly Number, ngược lại thì không
    return n == 1;
}