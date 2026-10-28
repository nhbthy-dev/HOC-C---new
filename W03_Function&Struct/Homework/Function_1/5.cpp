/*Giải hệ phương trình hai ẩn
Viết hàm solve_system_equation để giải hệ phương trình hai ẩn:

a × x + b × y = c

d × x + e × y = f

Sử dụng định lý Cramer để tính các định thức:

D = a * e - b * d
Dx = c * e - b * f
Dy = a * f - c * d
Quy ước giá trị status như sau:

status = -1: hệ phương trình vô nghiệm.
status = 0: hệ phương trình có vô số nghiệm.
status = 1: hệ phương trình có nghiệm duy nhất.
Nếu hệ có nghiệm duy nhất, tính:

x = Dx / D

y = Dy / D

Giá trị của x và y phải được làm tròn đến 3 chữ số thập phân bằng hàm round_to_decimal đã được cung cấp sẵn.

Kết quả của hàm được lưu trong cấu trúc EquationSolution:

struct EquationSolution {
    int status;
    double x, y;
};
Sinh viên cần tự định nghĩa hàm dựa trên prototype sau:

EquationSolution solve_system_equation(
    double a, double b, double c,
    double d, double e, double f
);
For example:

Input	Result
-2 1 5  1 -2.000 1.000
1 3 1    

*/
/*    solution.status = 0;
    solution.x = 0;
    solution.y = 0;

    double D  = a * e - b * d;
    double Dx = c * e - b * f;
    double Dy = a * f - c * d;

    if (D != 0) {
        solution.status = 1;
        solution.x = round_to_decimal(Dx / D, 3);
        solution.y = round_to_decimal(Dy / D, 3);
    } else if (Dx == 0 && Dy == 0) {
        solution.status = 0;   // vô số nghiệm
    } else {
        solution.status = -1;  // vô nghiệm
    }
*/