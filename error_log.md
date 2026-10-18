//dùng ctrl+shift+o
### [Mã Lỗi / Tên Lỗi] - Tóm tắt ngắn gọn lỗi là gì

- **1. Bối cảnh (Context):** Đang làm bài gì, viết hàm nào thì bị?
- **2. Báo lỗi (Error Message):** Thông báo lỗi từ Compiler / Terminal hoặc mô tả Output sai.
- **3. Nguyên nhân (Bug Cause):** Tại sao dòng code đó lại gây ra lỗi?
- **4. Cách khắc phục (Fix):** So sánh Code Lỗi vs. Code Đúng.
- **5. Bài học rút ra (Takeaway):** Nguyên tắc cần nhớ để không lặp lại.
> **Mẹo tra cứu nhanh:**
> - Bật mục lục tự động (Outline) ở góc trái dưới VS Code.
> - Nhấn `Ctrl + F` gõ từ khóa lỗi (ví dụ: `segmentation`, `overflow`, `cin`).

### cout in số thực bị mất phần thập phân (8.0 → 8)

`#cpp` `#cout` `#format` | 15/10/2026

- **Triệu chứng:** Đề yêu cầu đúng 3 chữ số sau dấu chấm, nhưng output sai
```
  Input:  3 5.0
  Output: 8        (cần: 8.000)
```
- **Bối cảnh:** Bài "Tính tổng" (int a + double b), in kết quả với 3 chữ số thập phân.
- **Nguyên nhân:** `cout` mặc định bỏ các số 0 ở cuối phần thập phân. Dù `sum` là `double`, kiểu dữ liệu không quyết định cách in.
- **Cách sửa:**
```cpp
  // ❌ Sai
  cout << sum;
  // ✅ Đúng (cần #include <iomanip>)
  cout << fixed << setprecision(3) << sum;
```
- **Bài học:** Đề yêu cầu "đúng N chữ số sau dấu chấm" thì luôn dùng `fixed << setprecision(N)`. Kiểu `double` chỉ quyết định giá trị, còn định dạng in phải tự chỉ định.

---

### Nhập số thực vào biến int bị đọc sai (3.5 → a=3, phần .5 trôi sang biến sau)

`#cpp` `#cin` `#input` | 15/10/2026

- **Triệu chứng:** Kết quả tổng sai so với tính tay
```
  Input:  3.5 3
  Output: 3.5      (mong đợi 6.5)
```
- **Bối cảnh:** Bài "Tính tổng", tự test với input không đúng đề (a là số thực).
- **Nguyên nhân:** `cin >> a` (kiểu `int`) chỉ đọc `3` rồi dừng ở dấu `.`. Phần `.5` còn lại bị `cin >> b` đọc thành `0.5`, và số `3` phía sau không được đọc. Thực tế tính là 3 + 0.5 = 3.5.
- **Cách sửa:** Code không sai. Cần test đúng định dạng đề cho (a nguyên, b thực). Nếu đề cho cả hai là số thực thì khai báo cả hai là `double`.
- **Bài học:** `cin` đọc theo kiểu của biến và dừng ngay khi gặp ký tự không hợp lệ, phần còn lại ở lại trong bộ đệm cho lần đọc sau. Khi kết quả lạ, hãy in lại `a` và `b` ngay sau khi nhập để kiểm tra.

### Đặt tên biến trùng từ khóa hoặc tên hàm có sẵn của C++ #đặt-tên-biến #từ-khóa #keyword #max #min #std #namespace #ambiguous #lỗi-hay-gặp #bug #vscode
cpp
// ❌ Trùng từ khóa → lỗi biên dịch ngay
int new = 5;          // new là từ khóa
int class = 3;        // class là từ khóa
double default = 1.5; // default là từ khóa

// ⚠️ Trùng tên hàm của thư viện std (có using namespace std;) → dễ lỗi ngầm
double max = a;       // trùng std::max
int count = 0;        // trùng std::count
int distance = 10;    // trùng std::distance

// ✅ Đặt tên rõ nghĩa, không trùng
double maxVal = a;
int cnt = 0;
int dist = 10;

### Thứ tự các nhánh if - else if: loại đặc biệt (hẹp) phải đứng trước loại tổng quát (rộng) #thứ-tự #else-if #code-chết #dead-code #tam-giác-đều #tam-giác-cân #loại-trừ #lỗi-hay-gặp #bug
cpp
// ❌ Sai: cân (rộng) đứng trước đều (hẹp)
if (a == b || a == c || b == c) cout << 2;     // tam giác đều cũng thỏa → in 2
else if (a == b && b == c) cout << 3;          // KHÔNG BAO GIỜ chạy tới đây

// ✅ Đúng: đều (hẹp) trước, cân (rộng) sau
if (a == b && b == c) cout << 3;               // đều
else if (a == b || a == c || b == c) cout << 2; // cân (lúc này chắc chắn không phải đều)
else cout << 1;                                // thường

### Không viết a == b == c, phải tách bằng && #so-sánh #== #&& #chuỗi-so-sánh #lỗi-hay-gặp #bug #ba-giá-trị #toán-học-vs-c++
cpp
// ❌ Sai: viết theo kiểu toán học
if (a == b == c) cout << 3;

// ✅ Đúng: tách thành từng cặp, nối bằng &&
if (a == b && b == c) cout << 
