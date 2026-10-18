//dùng ctrl+shift+o
# Command Cheatsheet (VS Code + WSL)

> Quy ước: mỗi mục = việc muốn làm + tag + lệnh + lưu ý.
> Ctrl+F theo tag hoặc dùng Outline để tìm nhanh.

## Mục lục
- [Phím tắt & Cửa sổ](#phím-tắt--cửa-sổ)
- [Di chuyển thư mục](#di-chuyển-thư-mục)
- [Thư mục & Tập tin](#thư-mục--tập-tin)
- [Biên dịch & Chạy](#biên-dịch--chạy)
- [Lỗi hay gặp](#lỗi-hay-gặp)
- [Tùy chỉnh terminal](#tùy-chỉnh-terminal)

---

## Phím tắt & Cửa sổ

### Mở / tắt terminal `#terminal` `#phím-tắt`
```
Ctrl + `
```

### Chuyển qua lại giữa editor và terminal `#editor` `#terminal` `#chuyển-cửa-sổ`
```
Editor   → Terminal : Ctrl + `
Terminal → Editor   : Ctrl + 1
```

### Copy / dán trong terminal `#copy` `#paste`
```
Copy : Ctrl + Shift + C
Dán  : Ctrl + Shift + V
```
> ⚠️ Trong terminal, Ctrl+C là dừng chương trình, không phải copy.

### Gọi lại lệnh trước đó `#history`
```
Mũi tên ↑ → Enter
```

### Phím tắt thao tác file `#file` `#phím-tắt`
| Việc muốn làm | Phím tắt |
|---|---|
| Mở nhanh file theo tên | `Ctrl+P` → gõ tên → Enter |
| Tạo file mới | `Ctrl+N` (rồi `Ctrl+S` để đặt tên) |
| Đóng file hiện tại | `Ctrl+W` |
| Chuyển qua lại giữa các file đang mở | `Ctrl+Tab` |

---

## Di chuyển thư mục

### Lệnh cd cơ bản `#cd` `#di-chuyển`
```bash
cd Practice      # vào thư mục con (gõ cd P → Tab → Enter)
cd ..            # lùi 1 cấp (phải có dấu cách giữa cd và ..)
cd ../..         # lùi 2 cấp
cd  (hoặc cd ~)  # về thư mục Home (/home/thy)
cd -             # quay lại thư mục vừa ở trước đó (như nút Back)
```

### Truy cập ổ đĩa Windows từ WSL `#wsl` `#mnt` `#ổ-đĩa`
```bash
cd "/mnt/c/HOC C++"
cd "/mnt/c/HOC C++/Practice"
```
> ⚠️ Tên thư mục có khoảng trắng (như `HOC C++`) thì **bắt buộc** bọc đường dẫn trong dấu ngoặc kép `""`.

### Xem vị trí & nội dung thư mục `#pwd` `#ls`
```bash
pwd       # hiển thị đường dẫn thư mục hiện tại
ls        # liệt kê file và thư mục con
ls -a     # liệt kê cả file ẩn
```

---

## Thư mục & Tập tin

### Tạo thư mục mới `#mkdir` `#thư-mục`
```bash
mkdir tên_thư_mục
```
> ⚠️ Tên **không dấu, không khoảng cách** (dùng `_` hoặc `-` thay cho dấu cách).

### Tạo / mở file bằng VS Code `#code` `#tạo-file` `#mở-file`
```bash
code 3.cpp          # mở file; chưa có thì tự tạo (không cần touch)
code 1.cpp 2.cpp    # mở nhiều file cùng lúc
```
> ⚠️ Kiểm tra đúng đuôi `.cpp`, nếu sai đuôi thì snippet không hiện.
> Báo không nhận lệnh `code`: `Ctrl+Shift+P` → **Shell Command: Install 'code' command in PATH**.

### Quy trình không dùng chuột `#workflow`
1. `` Ctrl+` `` mở terminal
2. `code 3.cpp` → Enter
3. Gõ `cpp` → Tab (chèn khung code)
4. Viết code → `Ctrl+S`
5. `` Ctrl+` `` xuống terminal → biên dịch và chạy

---

## Biên dịch & Chạy

### Biên dịch + chạy cùng lúc `#g++` `#compile` `#run`
```bash
g++ bai.cpp -o bai && ./bai
```

### Biên dịch và chạy riêng từng bước `#g++` `#compile` `#run`
```bash
g++ bai.cpp -o bai    # chỉ biên dịch
./bai                 # chỉ chạy
```

### Biên dịch có tối ưu `#O2` `#O3` `#optimize`
```bash
g++ bai.cpp -O2 -o bai && ./bai
```
> `-O2` / `-O3` (mức tối ưu cao nhất) giúp **chương trình chạy nhanh hơn**. Đổi lại thời gian biên dịch có thể lâu hơn một chút và file chạy có thể nặng hơn.

---

## Lỗi hay gặp

### Compile lỗi / `undefined` dù code đã đúng `#save` `#undefined`
> Nguyên nhân thường gặp: **chưa Save** (`Ctrl+S`).

### Sửa code nhưng kết quả chạy vẫn như cũ `#compile-lại`
> Phải **gõ lại lệnh `g++ ...`** để biên dịch lại, không chỉ chạy `./bai` (vì `./bai` chạy bản biên dịch cũ).

---

## Tùy chỉnh terminal

### Cấu hình giao diện Powerlevel10k `#p10k` `#theme`
```bash
p10k configure
```