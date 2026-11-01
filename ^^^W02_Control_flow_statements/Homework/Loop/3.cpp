/*Số đảo ngược
Viết hàm revert_number để tạo và trả về số đảo ngược của số nguyên dương n.

Số đảo ngược được tạo bằng cách đọc các chữ số của n theo thứ tự từ phải sang trái.

Để xử lý từng chữ số của n, sinh viên có thể sử dụng:

n % 10 để lấy chữ số cuối cùng;

n / 10 để loại bỏ chữ số cuối cùng.

Ví dụ
Input	Result
123	     321
Lưu ý
Các chữ số 0 ở đầu của số sau khi đảo sẽ không được giữ lại vì kiểu dữ liệu trả về là số nguyên. Nên sinh viên chú ý các trường hợp tận cùng là số 0.

Ví dụ:

1200 → 0021 → 21

For example:

Input	Result
123      321
*/
/*Cách này bị lỗi test case ở các số có 0 ở giữa (602) vì đã bỏ qua mọi số 0
#include <iostream>
using namespace std;

int main() {
    int n,number;
    cin>>n;
    while (n>0) {
        number = n % 10;
        if (n%10 !=0) cout<<number;
        n = n/10;
    }
    return 0;
}*/
#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int dao = 0;
while (n > 0) {
    dao = dao * 10 + n % 10; /* khác với number (in từng kí tự không có cách hay endl -> tạo thành số , dao ở đây là được viết dưới dạng 1 con số)
                                dao không mặc định số 0 ở đầu sẽ bỏ mà là nếu 0 thì cộng dồn các số sau nó mới bắt đầu có giá trị*/
    n /= 10;
}
cout << dao;
    return 0;
}