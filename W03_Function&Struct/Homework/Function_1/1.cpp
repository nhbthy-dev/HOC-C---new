/*Tính tổ hợp
Viết hai hàm compute_factorial và compute_combination.

Hàm compute_factorial(n) dùng để tính giai thừa của số nguyên không âm n:

n! = 1 × 2 × 3 × ... × n

Quy ước:

0! = 1
Sau đó, sử dụng hàm compute_factorial bên trong hàm compute_combination(n, k) để tính tổ hợp chập k của n theo công thức:

C(n, k) = n! / (k! × (n - k)!)

Điều kiện dữ liệu:

0 <= k <= n
Lưu ý: Đây là bài thực hành về hàm. Hàm compute_combination cần gọi và sử dụng kết quả của hàm compute_factorial để thực hiện phép tính.

Sinh viên cần tự định nghĩa đầy đủ các hàm dựa trên các prototype sau:

long long compute_factorial(int n);

long long compute_combination(int n, int k);
For example:

Input	Result
9 5     126
*/
/*long long compute_factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

long long compute_combination(int n, int k) {
    return compute_factorial(n) / (compute_factorial(k) * compute_factorial(n - k));
}
*/