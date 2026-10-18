/*Chiều dài chuỗi số lẻ dài nhất
Viết hàm length_odd_sequence để tìm độ dài lớn nhất của một chuỗi các chữ số lẻ xuất hiện liên tiếp trong số nguyên dương n.

Một chữ số được xem là số lẻ nếu:

digit % 2 != 0

Hàm cần duyệt qua từng chữ số của n và theo dõi:

độ dài của chuỗi chữ số lẻ liên tiếp hiện tại;

độ dài lớn nhất đã tìm được.

Ví dụ
Input	       Result
111234540234	3
Với n = 111234540234, chuỗi chữ số lẻ liên tiếp dài nhất là:

1 1 1

nên kết quả là 3.

For example:

Input	                 Result
111234540234               3
*/


/*CÁCH 1
#include <iostream>
using namespace std;

int main() {
    long long n;
    cin>>n;
    int maxlen=0;
    int count =0;
    while (n>0) {
        int digit = n%10;
        if (digit %2 != 0) {
            count++;
            if (count > maxlen) {
                maxlen = count;
            }
        } else {
            count =0;
        }
    n/=10;
    }
    cout<<maxlen;
    return 0;
}*/
//CÁCH 2
#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    int maxlen = 0, count = 0;
    while (n > 0) {
        if (n % 2 != 0) count++;   // n % 2 chính là tính chẵn lẻ của chữ số cuối
        else count = 0;
        if (count > maxlen) maxlen = count;
        n /= 10;
    }
    cout << maxlen;
    return 0;
}