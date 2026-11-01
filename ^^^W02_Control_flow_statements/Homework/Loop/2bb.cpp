/*Tìm số lớn nhất thỏa mãn
Viết hàm find_max_number để tìm số nguyên dương k lớn nhất sao cho:

1 + 2 + 3 + ... + k ≤ n

Ví dụ
Input	Result
20	5
Với n = 20:

1 + 2 + 3 + 4 + 5 = 15 ≤ 20

nhưng:

1 + 2 + 3 + 4 + 5 + 6 = 21 > 20

nên kết quả là k = 5.

For example:

Input	Result
20        5
*/
/*#include <iostream>
using namespace std;

int main() {
    int n;
    int S =0;
    cin>>n;
    for (int i=1; i <= n ; i++) {
        if (S <= n) {
            S+=i;
            cout<<i-1;
        }
    }
    return 0;
}*/
/*#include <iostream>
using namespace std;

int main() {
    int n;
    int S = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        S += i;
        if (S > n) {
            cout << i - 1;
            break;   //vì điều kiện i<= n sẽ khiến i chạy đến n nhưng thực tế chỉ cần cho tông của i không vượt quá n -> dùng break
        }
    }
    return 0;
}*/
//C1 (dùng S + i <=n)
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int S = 0, k = 0;
    for (int i = 1; S + i <= n; i++) {   // cộng i vào mà vẫn <= n thì mới chạy tiếp
        S += i;
        k = i;                            // lưu số lớn nhất đã cộng được
    }

    cout << k;
    return 0;
}
//C2 (dùng S <= n)
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int S = 0, k = 0;
    for (int i = 1; S <= n; i++) {
        S += i;
        k = i;
    }

    cout << k - 1;   // k lúc này là số đã làm tổng vượt n, nên trừ 1
    return 0;
}
//test-case 1 -> 1