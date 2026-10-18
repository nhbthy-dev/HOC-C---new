/*Nth Divisible Number
Viết hai hàm isDivisible và nthDivisibleNumber.

Hàm isDivisible(x, a, b, c) kiểm tra số nguyên dương x có chia hết cho ít nhất một trong ba số a, b, c hay không.

Hàm trả về true nếu:

x % a == 0 hoặc x % b == 0 hoặc x % c == 0

Sau đó, sử dụng hàm isDivisible bên trong nthDivisibleNumber để tìm số nguyên dương thứ n chia hết cho ít nhất một trong ba số a, b, c.

Ví dụ với:

n = 5
a = 2
b = 3
c = 5
Các số nguyên dương thỏa điều kiện đầu tiên là:

2, 3, 4, 5, 6, ...
Do đó số thứ 5 là:

6
Điều kiện dữ liệu:

1 <= n <= 1000
1 <= a, b, c <= 100
Lưu ý: Một số chia hết cho nhiều hơn một trong ba giá trị vẫn chỉ được tính một lần. Hàm nthDivisibleNumber cần gọi và sử dụng hàm isDivisible.

Sinh viên cần tự định nghĩa đầy đủ các hàm dựa trên các prototype sau:

bool isDivisible(int x, int a, int b, int c);

int nthDivisibleNumber(int n, int a, int b, int c);
For example:

Input	       Result
10 2 3 5         1
*/

bool isDivisible(int x, int a, int b, int c) {
    return (x % a == 0 || x % b == 0 || x % c == 0);
}
int nthDivisibleNumber(int n, int a, int b, int c) {
    int count = 0;
    int x = 1;

    while (true) {
        if (isDivisible(x, a, b, c)) {
            count++;
            if (count == n) {
                return x;
            }
        }
        x++;
    }
}