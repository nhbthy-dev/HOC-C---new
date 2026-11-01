/*Xây dựng thư viện phân số
Sinh viên xây dựng thư viện xử lý phân số bằng hai tập tin riêng biệt:

fraction_utils.h: khai báo các hàm.
fraction_utils.cpp: hiện thực các hàm. Có thể viết thêm hàm phụ trong file này.
Upload đúng hai file trên. Không upload main.cpp.

Thư viện được phép sử dụng:

#include <iostream>
Quy ước: Mẫu số luôn khác 0. Kết quả cuối cùng phải tối giản và mẫu số phải dương. Nếu tử số bằng 0, chuẩn hóa thành 0/1.

1. Rút gọn và chuẩn hóa phân số
Rút gọn numerator/denominator về dạng tối giản. Nếu mẫu số âm, chuyển dấu âm lên tử số.

Prototype:

void reduce_fraction(int& numerator, int& denominator);
2. So sánh hai phân số
So sánh n1/d1 và n2/d2. Trả về -1, 0, hoặc 1 tương ứng với nhỏ hơn, bằng nhau, hoặc lớn hơn.

Prototype:

int compare_fractions(int n1, int d1, int n2, int d2);
3. Cộng hai phân số
Tính tổng n1/d1 + n2/d2. Kết quả trả qua numerator và denominator, đồng thời phải được rút gọn và chuẩn hóa.

Prototype:

void add_fractions(int n1, int d1,
                   int n2, int d2,
                   int& numerator, int& denominator);
Lưu ý:

Giữ đúng tên file fraction_utils.h và fraction_utils.cpp.
Không upload main.cpp.
Nên dùng include guard hoặc #pragma once.
Không đặt using namespace std; trong header.
Giữ nguyên prototype.
Khuyến khích viết hàm phụ để tái sử dụng mã nguồn.
For example:

Input	     Result
8 12         2 3
1 2 2 3      -1
1 2 1 3      5 6
*/
#include <iostream>
#include "fraction_utils.h"
int gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
void reduce_fraction(int& numerator, int& denominator) {
    if (numerator == 0) {
        denominator = 1;
        return;
    }
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    int g = gcd(numerator, denominator);
    numerator = numerator / g;
    denominator = denominator / g;
}
int compare_fractions(int n1, int d1, int n2, int d2) {
    if (d1 < 0) {
        n1 = -n1;
        d1 = -d1;
    }
    if (d2 < 0) {
        n2 = -n2;
        d2 = -d2;
    }
    int x = n1 * d2;
    int y = n2 * d1;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}
void add_fractions(int n1, int d1,
                   int n2, int d2,
                   int& numerator, int& denominator) {
    numerator = n1 * d2 + n2 * d1;
    denominator = d1 * d2;
    reduce_fraction(numerator, denominator);
}