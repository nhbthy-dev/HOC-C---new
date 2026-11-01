
/*Tính xấp xỉ lũy thừa cơ số tự nhiên
Viết chương trình sử dụng các hàm để tính xấp xỉ giá trị ex theo chuỗi:

ex ≈ 1 + x / 1! + x2 / 2! + x3 / 3! + ... + xn / n!

Trong đó:

compute_factorial(n) dùng để tính n!.
exponentiation(x, n) dùng để tính xn.
power_of_e(x, n) sử dụng hai hàm trên để tính giá trị xấp xỉ của ex.
Hàm power_of_e có tham số mặc định:

n = 20
Kết quả của power_of_e phải được làm tròn đến 5 chữ số thập phân bằng hàm round_to_decimal đã được cung cấp sẵn.

Sinh viên cần tự định nghĩa đầy đủ cả ba hàm dựa trên các prototype sau:

long long compute_factorial(int n);

double exponentiation(double x, int n);

double power_of_e(double x, int n = 20);
For example:

Input	Result
3
20.08554
*/
/*long long compute_factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

double exponentiation(double x, int n) {
    double result = 1;
    for (int i = 0; i < n; i++) {
        result *= x;
    }
    return result;
}

double power_of_e(double x, int n = 20) {
    double sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += exponentiation(x, i) / compute_factorial(i);
    }
    return round_to_decimal(sum, 5);
}
*/