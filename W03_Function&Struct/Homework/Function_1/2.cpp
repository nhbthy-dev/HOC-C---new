/*Tính toán biểu thức
Viết hàm exponentiation(x, n) để tính xn, với điều kiện:

n >= 0
Sau đó sử dụng hàm exponentiation trong compute_equation(x, n) để tính:

S = 1.58 + sum(i = 1..n) [ (-1)i × (x + i)i / i2 ]

Cụ thể:

S = 1.58 - (x + 1) / 12 + (x + 2)2 / 22 - (x + 3)3 / 32 + ...

Kết quả của compute_equation phải được làm tròn đến 3 chữ số thập phân bằng hàm round_to_decimal đã được cung cấp sẵn.

Lưu ý: Sinh viên được yêu cầu hiện thực đầy đủ cả hai hàm và sử dụng hàm exponentiation bên trong compute_equation đúng theo yêu cầu của đề bài.

Sinh viên cần tự định nghĩa các hàm dựa trên các prototype sau:

double exponentiation(double x, int n);

double compute_equation(double x, int n);
For example:

Input	Result
0.2 3   21.998
*/
/*double exponentiation(double x, int n) {
    double result = 1;
    for (int i = 0; i < n; i++) {
        result *= x;
    }
    return result;
}

double compute_equation(double x, int n) {
    double S = exponentiation(1.5, 8);
    for (int i = 1; i <= n; i++) {
        double term = exponentiation(x + i, i) / (i * i);
        if (i % 2 == 0) S += term;
        else            S -= term;
    }
    return round_to_decimal(S, 3);
}
*/
#include <iostream>
#include <iomanip>
using namespace std;

// CHỈ để chạy thử trên máy, KHÔNG nộp phần này
double round_to_decimal(double v) {
    return (long long)(v * 1000 + (v >= 0 ? 0.5 : -0.5)) / 1000.0;
}

double exponentiation(double x, int n){
    double F = 1;
    for (int i = 1; i<=n;i++) {
        F*=x;
    }
    return F;
}

double compute_equation(double x, int n){
    double sum = 1.58;
    for (int i = 1; i<=n ; i++) {
        if (i%2!=0) {
            sum-=exponentiation(x+i,i)/exponentiation(i,2);
        }
        else {
            sum+=exponentiation(x+i,i)/exponentiation(i,2);
        }
    }
    return round_to_decimal(sum);
}

int main() {
    double x;
    int n;
    cin>> x >> n;
    cout<< fixed << setprecision(3) << compute_equation(x, n);
    return 0;
}