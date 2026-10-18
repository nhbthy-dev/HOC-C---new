/*Dãy số Collatz
Viết hàm length_collatz_sequence để đếm số bước cần thiết đưa số nguyên dương n về giá trị 1 theo quy tắc Collatz.

Tại mỗi bước:

Nếu n là số chẵn:
n = n / 2

Nếu n là số lẻ:
n = 3 * n + 1

Lặp lại quá trình trên cho đến khi n = 1.

Hàm cần trả về số bước biến đổi đã thực hiện.

Ví dụ
Với n = 6:

6 → 3 → 10 → 5 → 16 → 8 → 4 → 2 → 1

Có tổng cộng 8 bước biến đổi, vì vậy:

length_collatz_sequence(6) → 8

Một số ví dụ khác
Input	Result
1	0
2	1
7	16
For example:

Input	Result
6         8
*/
/*#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int length = 0;
    while (n%2==0) {
        n = n/2;
        length++;
        if (n==1) cout<<length;
    }

    while (n%2!=0) {
        n = 3*n+1;
        length++;
        if (n==1) cout<<length;;
    }
    return 0;
}
****Không thể dùng 2 vòng while: mỗi vòng while chỉ chạy một đợt liên tục, xong là thoát và không bao giờ quay lại. Nhưng dãy Collatz phải xen kẽ qua lại giữa chẵn và lẻ nhiều lần.
*/ 
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int length = 0; //nếu khong gán giá trị cho length ở đây thì nó sẽ mặc định lấy giá trị rác
    while (n != 1) {          // chưa về 1 thì còn làm tiếp
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        length++;             // mỗi lần biến đổi là 1 bước
    }

    cout << length << endl;
    return 0;
}