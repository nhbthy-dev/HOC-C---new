/*Bảng số xoắn ốc từ trong ra
Viết hàm spiral_inside_out để tạo một bảng số vuông kích thước n × n.

Số nhỏ nhất nằm ở vùng trung tâm. Các giá trị tăng dần theo các lớp từ trong ra ngoài.

Quy ước cách sắp xếp là dạng đảo giá trị của bảng xoắn ốc từ ngoài vào. Nếu giá trị tại một vị trí trong bảng xoắn ốc ngoài-vào là v, thì giá trị tương ứng trong bảng xoắn ốc trong-ra là:

n * n + 1 - v

Ví dụ với n = 3:

9 8 7
2 1 6
3 4 5
Quy ước chuỗi kết quả:

Các số trên cùng một dòng cách nhau đúng một khoảng trắng.
Các dòng cách nhau bằng ký tự xuống dòng \n.
Không có ký tự xuống dòng dư ở cuối chuỗi.
Sinh viên cần tự định nghĩa đầy đủ hàm dựa trên prototype sau:

string spiral_inside_out(int n);
For example:

Input	Result
3
9 8 7
2 1 6
3 4 5

*/