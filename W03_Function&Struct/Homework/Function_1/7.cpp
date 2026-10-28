/*Đổi nhiệt độ
Viết hàm convert_temperature để chuyển đổi nhiệt độ giữa Fahrenheit (F) và Celsius (C).

Công thức chuyển từ Fahrenheit sang Celsius:

C = 5 × (F - 32) / 9

Nếu f2c = true (giá trị mặc định), hàm thực hiện chuyển đổi từ Fahrenheit sang Celsius.

Nếu f2c = false, hàm thực hiện chuyển đổi từ Celsius sang Fahrenheit theo công thức:

 F = C × 9 / 5 + 32

Kết quả trả về phải được làm tròn đến 2 chữ số thập phân bằng hàm round_to_decimal đã được cung cấp sẵn.

Sinh viên cần tự định nghĩa hàm dựa trên prototype sau:

float convert_temperature(float temperature, bool f2c = true);
Ví dụ
Lời gọi hàm	Kết quả
convert_temperature(32)	0
convert_temperature(33, false)	91.4
For example:

Input	Result
32      0.00
*/
/*float convert_temperature(float temperature, bool f2c = true) {
    float result;
    if (f2c) {
        result = 5 * (temperature - 32) / 9;
    } else {
        result = temperature * 9 / 5 + 32;
    }
    return round_to_decimal(result, 2);
}*/