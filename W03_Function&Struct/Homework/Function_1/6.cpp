/*Đọc số
Viết hàm read_number nhận vào một số nguyên n thỏa điều kiện: 0 <= n < 1000000000

Hàm trả về một chuỗi biểu diễn cách đọc của số n. 

Chuỗi kết quả sử dụng các từ không dấu: khong, mot, hai, ba, bon, nam, sau, bay, tam, chin, muoi, tram, nghin, trieu, le

Để đơn giản, mỗi chữ số chỉ có một cách đọc duy nhất:

1 = mot
4 = bon
5 = nam
Không sử dụng các cách đọc khác như mot thành mot/mốt, bon thành tu, hoặc nam thành lam.

Hàm format_read_number đã được cung cấp sẵn để loại bỏ các khoảng trắng dư trong chuỗi kết quả.

Sinh viên chỉ cần hiện thực hàm read_number và có thể gọi format_read_number trước khi trả về kết quả.

Sinh viên cần tự định nghĩa hàm dựa trên prototype sau:

string read_number(int n);
Ví dụ
Input	     Result
900000000	chin tram trieu
900000021	chin tram trieu khong tram nghin khong tram hai muoi mot
900100021	chin tram trieu mot tram nghin khong tram hai muoi mot
For example:

Input	      Result
900000000    chin tram trieu
*/
/*string read_group(int g, bool full) {
    const string digit[10] = {"khong", "mot", "hai", "ba", "bon",
                              "nam", "sau", "bay", "tam", "chin"};
    int h = g / 100, t = (g / 10) % 10, u = g % 10;
    string s = "";
    bool showHundred = full || h > 0;

    if (showHundred) {
        s += digit[h] + " tram";
    }

    if (t == 0) {
        if (u != 0) {
            if (showHundred) s += " le";
            s += " " + digit[u];
        }
    } else {
        if (t == 1) s += " muoi";
        else s += " " + digit[t] + " muoi";
        if (u != 0) s += " " + digit[u];
    }
    return s;
}

string read_number(int n) {
    if (n == 0) return "khong";

    int g2 = n / 1000000;
    int g1 = (n / 1000) % 1000;
    int g0 = n % 1000;

    string result = "";
    bool leading = true; // chưa đọc nhóm nào

    if (g2 > 0) {
        result += read_group(g2, false) + " trieu";
        leading = false;
    }

    if (g1 > 0 || (g2 > 0 && g0 > 0)) {
        result += " " + read_group(g1, !leading) + " nghin";
        leading = false;
    }

    if (g0 > 0) {
        result += " " + read_group(g0, !leading);
    }

    return format_read_number(result);
}
*/