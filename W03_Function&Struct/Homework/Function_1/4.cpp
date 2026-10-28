/*Giải phương trình bậc hai
Viết hàm solve_quadratic để giải phương trình bậc hai:

a × x2 + b × x + c = 0

với điều kiện:

a != 0
Đầu tiên, tính biệt thức:

delta = b2 - 4 × a × c

Sau đó xét các trường hợp:

Nếu delta < 0: phương trình không có nghiệm thực, đặt has_solution = false.
Nếu delta >= 0: phương trình có nghiệm thực, đặt has_solution = true và tính:
x1 = (-b + sqrt(delta)) / (2 × a)

x2 = (-b - sqrt(delta)) / (2 × a)

Nếu phương trình có nghiệm, giá trị của x1 và x2 phải được làm tròn đến 3 chữ số thập phân bằng hàm round_to_decimal đã được cung cấp sẵn.

Kết quả của hàm được lưu trong cấu trúc QuadraticSolution:

struct QuadraticSolution {
    bool has_solution;
    double x1, x2;
};
Sinh viên cần tự định nghĩa hàm dựa trên prototype sau:

QuadraticSolution solve_quadratic(double a, double b, double c);
For example:

Input	    Result
4 -2 -6    1 1.500 -1.000
*/
/*    solution.has_solution = false;
    solution.x1 = 0;
    solution.x2 = 0;

    double delta = b * b - 4 * a * c;

    if (delta >= 0) {
        solution.has_solution = true;
        solution.x1 = round_to_decimal((-b + sqrt(delta)) / (2 * a), 3);
        solution.x2 = round_to_decimal((-b - sqrt(delta)) / (2 * a), 3);
    }
    */