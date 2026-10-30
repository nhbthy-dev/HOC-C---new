/*Đếm chữ số nguyên tố
Viết hàm count_prime_digits để đếm số lượng chữ số nguyên tố xuất hiện trong số nguyên dương n.

Các chữ số nguyên tố gồm:

2, 3, 5, 7
Ví dụ:

235709  ->  4
Hàm trả về số lượng chữ số thuộc tập {2, 3, 5, 7} có trong n.

Sinh viên cần tự định nghĩa đầy đủ hàm dựa trên prototype sau:

int count_prime_digits(unsigned long long n);
For example:

Input	Result
235709  4

*/

//Giải thuật thêm cho trường hợp không tính các số trùng nhau
//Input: 2222 -> Output:1
#include <iostream>
using namespace std;

int count_prime_digits(unsigned long long n) {
    bool seen[10] = {false};
    int count = 0;
    while (n > 0) {
        int d = n % 10;
        if ((d == 2 || d == 3 || d == 5 || d == 7) && !seen[d]) {
            seen[d] = true;
            count++;
        }
        n /= 10;
    }
    return count;
}

int main() {
    unsigned long long n;
    cin >> n;
    cout << count_prime_digits(n) << endl;
    return 0;
}
/*Câu hỏi	             Trả lời
seen là gì?	            Dãy 10 công tắc, mỗi chữ số 0..9 một công tắc
seen[d] là gì?	        Công tắc của chữ số d (true = đã đếm)
!seen[d] là gì?	        “d chưa được đếm”
seen[d] = true làm gì?	Ghi nhớ “d đã đếm rồi” để lần sau bỏ qua
seen[10] -> nghĩa là có 10 công tắc cho 10 số từ 0-> 9
mỗi lần seen [d] -> lưu lại giá trị khi gặp sẽ không đếm lại
*/