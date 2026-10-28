/*
1. Khai báo (Declaration / Prototype)

Cho compiler biết hàm tồn tại trước khi dùng. Thường đặt ở đầu file hoặc trong file .h.

cpp
kiểu_trả_về tên_hàm(kiểu_tham_số1 tên1, kiểu_tham_số2 tên2);

Ví dụ:

cpp
int cong(int a, int b);

Tên tham số trong khai báo có thể bỏ: int cong(int, int);

2. Định nghĩa (Body)

Phần chứa code thực thi.

cpp
kiểu_trả_về tên_hàm(kiểu_tham_số1 tên1, kiểu_tham_số2 tên2)
{
    // các câu lệnh
    return giá_trị;   // nếu kiểu trả về khác void
}

Ví dụ:

cpp
int cong(int a, int b)
{
    int tong = a + b;
    return tong;
}
3. Gọi hàm (Calling)
cpp
tên_hàm(đối_số1, đối_số2);

Ví dụ:

cpp
int ketQua = cong(5, 3);   // ketQua = 8
*/