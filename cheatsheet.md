//dùng ctrl+shift+o
# Cheatsheet C++

> Quy ước: mỗi mục = tiêu đề (việc muốn làm) + tag + code ngắn + lưu ý (nếu cần).
> Tag dùng cả tiếng Việt lẫn tiếng Anh để Ctrl+F dễ ra.

## Mục lục
- [Nhập / Xuất](#nhập--xuất)
- [Kiểu dữ liệu & Toán tử](#kiểu-dữ-liệu--toán-tử)
- [Điều kiện & Vòng lặp](#điều-kiện--vòng-lặp)
- [Mảng & Vector](#mảng--vector)
- [Chuỗi](#chuỗi)
- [Hàm](#hàm)
- [Thư viện](#thư-viện)
- [Mẫu code hay dùng](#mẫu-code-hay-dùng)

---

### Chuyển đổi ký tự ↔ mã ASCII `#ascii` `#char` `#int` `#ép-kiểu` `#cast` `#W01-Inclass-4`
```cpp
char c; int n;
cin >> c >> n;

cout << (int)c << endl;    // ký tự → mã ASCII:  'A' → 65
cout << (char)n << endl;   // mã ASCII → ký tự:  97  → 'a'
```
> ⚠️ `cout << c` in ra ký tự, còn `cout << (int)c` mới in ra mã số. Cùng một giá trị, in ra khác nhau vì kiểu dữ liệu khác nhau.

**Mốc ASCII nên nhớ:**

| Ký tự | Mã |
|---|---|
| `'0'` – `'9'` | 48 – 57 |
| `'A'` – `'Z'` | 65 – 90 |
| `'a'` – `'z'` | 97 – 122 |

**Mẹo hay dùng:**
```cpp
int digit = c - '0';        // '7' → 7 (ký tự số → số nguyên)
char ch = digit + '0';      // 7 → '7'
char upper = c - 32;        // 'a' → 'A' (hoặc dùng toupper(c))
char next = c + 1;          // 'a' → 'b'
```
### Khai báo hằng số PI `#pi` `#const` `#define``#W01-Inclass-5`
```cpp
#include <cmath>
const double PI = acos(-1);   // chính xác nhất
#define PI 3.14159            // cách nhanh (KHÔNG có = và ;)
```
### Tách từng chữ số của một số nguyên `#digit` `#chữ-số` `#while` `#modulo` `#W02-Inclass-4`
```cpp
long long n;
cin >> n;
while (n > 0) {
    int digit = n % 10;   // chữ số cuối
    // ... xử lý digit ...
    n /= 10;              // bỏ chữ số cuối
}
```
> ⚠️ Duyệt từ **phải sang trái** (từ chữ số cuối về chữ số đầu). Số lớn như `111234540234` vượt giới hạn `int` nên phải dùng `long long`.

---

### Tìm độ dài chuỗi liên tiếp dài nhất (mẫu đếm + max) `#count` `#maxlen` `#liên-tiếp` `#streak``#W02-Inclass-4`
```cpp
int maxlen = 0, count = 0;
while (n > 0) {
    if (n % 2 != 0) count++;      // thỏa điều kiện → tăng bộ đếm
    else count = 0;               // bị ngắt → đếm lại từ đầu
    if (count > maxlen) maxlen = count;   // cập nhật kỷ lục
    n /= 10;
}
cout << maxlen;
```
> Mẫu chung gồm 2 biến: `count` (độ dài chuỗi hiện tại, reset khi bị ngắt) và `maxlen` (kỷ lục đã tìm được, không bao giờ reset).
> Dùng được cho: chuỗi chữ số lẻ/chẵn liên tiếp, dãy số tăng liên tiếp, chuỗi ký tự giống nhau liên tiếp...

---

### Rút gọn code: bỏ biến trung gian và bỏ `if` lồng nhau `#tối-ưu` `#clean-code``#W02-Inclass-4`

**Mẹo 1: Dùng thẳng `n % 2` thay vì qua `digit`**
```cpp
// Cách dài
int digit = n % 10;
if (digit % 2 != 0) ...

// Cách gọn
if (n % 2 != 0) ...
```
> Vì `n % 10` và `n % 2` luôn cùng tính chẵn lẻ (10 là số chẵn nên chữ số cuối quyết định tính chẵn lẻ của cả số). Chỉ đúng với kiểm tra **chẵn/lẻ**; nếu cần so sánh giá trị chữ số (ví dụ `digit > 5`) thì vẫn phải dùng `n % 10`.

**Mẹo 2: Các câu lệnh trong `while` chạy tuần tự, không cần `if` lồng `if`**
```cpp
// Cách 1: if lồng trong if
if (digit % 2 != 0) {
    count++;
    if (count > maxlen) {
        maxlen = count;
    }
} else {
    count = 0;
}

// Cách 2: tách ra, viết tuần tự
if (n % 2 != 0) count++;
else count = 0;
if (count > maxlen) maxlen = count;   // chạy sau, mỗi vòng lặp đều kiểm tra
```
> Khi `count = 0` thì `count > maxlen` luôn sai nên việc kiểm tra thêm ở vòng đó không gây hại, và code ngắn, dễ đọc hơn.
### Làm tròn số thực `#round` `#làm-tròn` `#cmath` `#ceil` `#floor`
```cpp
#include <cmath>

round(2.4)   // = 2    làm tròn gần nhất
round(2.5)   // = 3    (.5 trở lên thì làm tròn lên)
round(-2.5)  // = -3   (số âm: làm tròn ra xa số 0)

ceil(2.1)    // = 3    làm tròn lên
floor(2.9)   // = 2    làm tròn xuống
trunc(2.9)   // = 2    cắt bỏ phần thập phân
```
> ⚠️ Cả 4 hàm đều **trả về `double`**, không phải `int`.

### In kết quả `round` ra số nguyên `#round` `#cout` `#ép-kiểu`
```cpp
double total = 3375000.0;

cout << round(total);              // ❌ số lớn có thể in ra 3.375e+06
cout << (long long)round(total);   // ✅ 3375000
cout << fixed << setprecision(0) << round(total);   // ✅ 3375000 (cần <iomanip>)
```
> ⚠️ `cout` mặc định chỉ in 6 chữ số có nghĩa, nên số lớn sẽ bị đổi sang dạng khoa học (`e+06`).
> Đề yêu cầu trả về `long`/`int` thì ép kiểu luôn: `(long)round(x)`.

### Làm tròn đến N chữ số thập phân `#round` `#thập-phân`
```cpp
// Chỉ để IN ra: dùng fixed + setprecision (tự làm tròn khi in)
cout << fixed << setprecision(2) << 3.14159;   // 3.14

// Muốn làm tròn GIÁ TRỊ (để tính tiếp): nhân - round - chia
double x = round(3.14159 * 100) / 100;         // 3.14
```
> Làm tròn 1 chữ số: nhân/chia 10; 2 chữ số: 100; 3 chữ số: 1000.
### Chọn giữa `if - else if` và `if` độc lập `#if` `#else-if` `#điều-kiện`
```cpp
// Loại trừ nhau (chỉ 1 đúng) → if - else if
if (type == 1) { ... }
else if (type == 2) { ... }
else if (type == 3) { ... }

// Không loại trừ (có thể đúng cùng lúc) → if độc lập
if (n % 3 == 0) { ... }
if (n % 5 == 0) { ... }
```
> - `if - else if`: gặp nhánh đúng là **dừng**, không kiểm tra các nhánh sau.
> - `if` độc lập: **luôn kiểm tra hết** mọi điều kiện.
> - `else` = "tất cả trường hợp còn lại", kể cả giá trị không hợp lệ. Muốn chỉ đúng một giá trị cụ thể thì dùng. chỉ nhận những gì chưa bị các nhánh phía trên bắt. `else if (điều kiện)`.
> - ⚠️ Dùng `if` độc lập cho các trường hợp loại trừ dễ lỗi khi một nhánh làm đổi biến đang kiểm tra.

### Dùng return thay vì cout; Thay đổi về cách viết biểu thức trong if nhưng phải hiểu cách operate (không được viết sai thứ tự) `return` `if`
int getSeason(int month) {
    if (month < 1 || month > 12) return -1;   // loại trường hợp sai trước
    if (month <= 3) return 1;                 // lúc này chắc chắn month >= 1
    if (month <= 6) return 2;                 // chắc chắn month >= 4
    if (month <= 9) return 3;                 // chắc chắn month >= 7
    return 4;                                 // còn lại là 10-12
}
Mỗi dòng if đã return nên các dòng phía dưới chỉ chạy khi các điều kiện phía trên sai. Nhờ vậy nhánh dưới không cần kiểm tra lại cận dưới.
So với cách đầy đủ month >= 4 && month <= 6, cách này chỉ cần month <= 6 vì month <= 3 đã bị loại ở dòng trước.
Dòng cuối return 4; không cần if vì sau khi loại hết các trường hợp trên thì chỉ còn tháng 10-12.
⚠️ Phụ thuộc thứ tự: phải kiểm tra trường hợp không hợp lệ (< 1 || > 12) đầu tiên. Nếu đảo thứ tự, tháng 0 hoặc số âm sẽ lọt vào month <= 3 và trả về 1 (sai).
⚠️ Không đổi chỗ các dòng <= 3, <= 6, <= 9. Nếu để <= 9 lên trước thì tháng 1-3 cũng thỏa và trả về 3.
Mẫu chung: chặn giá trị sai ở đầu hàm (guard / early return) → xử lý các khoảng từ nhỏ đến lớn → trường hợp còn lại để cuối cùng.

### Lùi tháng rồi mới tra số ngày của tháng mới (tránh tự suy “tháng nào đứng sau tháng 30 ngày”) #lùi-tháng #số-ngày-trong-tháng #ngày-trước #test-case #biên #tháng-8 #if #W03-homework-2
cpp
// ❌ Cách dễ sai: liệt kê "tháng m nào thì ngày trước là 30 hay 31"
if (m == 5 || m == 7 || m == 8 || m == 10 || m == 12) bd = 30;   // sai với m == 8

// ✅ Cách an toàn: lùi tháng trước, rồi tra số ngày của THÁNG MỚI (bm)
if (d == 1) {
    bm = m - 1;
    by = y;
    if (bm < 1) { bm = 12; by = y - 1; }      // lùi qua năm cũ

    if (bm == 4 || bm == 6 || bm == 9 || bm == 11) bd = 30;
    else if (bm == 2) {
        if (leap) bd = 29;
        else bd = 28;
    }
    else bd = 31;
}
### Phân biệt = (gán) và == (so sánh) trong if #gán #so-sánh #= #== #if #lỗi-hay-gặp #bug #điều-kiện
cpp
int valid = 0, d = 5, maxday = 31;

// ❌ Sai: dùng = trong điều kiện (đây là GÁN, không phải so sánh)
if (valid = 1) { ... }        // gán valid = 1, rồi luôn đúng
if (d = maxday) { ... }       // gán d = maxday (làm hỏng d), rồi luôn đúng (nếu maxday != 0)

// ✅ Đúng: dùng == để so sánh
if (valid == 1) { ... }
if (d == maxday) { ... }