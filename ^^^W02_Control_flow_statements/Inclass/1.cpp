/*Tìm Max
Viết hàm trả về giá trị lớn nhất trong hai số nguyên a và b.

Hai giá trị a và b đã được truyền trực tiếp vào hàm thông qua tham số, vì vậy sinh viên không cần sử dụng cin để nhập dữ liệu.

Ví dụ
find_max(3, 5) → 5

For example:

Input	Result
3 5      5
*/
#include <iostream>
using namespace std;

int main() {
    int a,b;
    cin>>a>>b;
    int max = a;
    if (a<b) {
        max=b;
    }
    cout<<max<<endl;
    return 0;
}