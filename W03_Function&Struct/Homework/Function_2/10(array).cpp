/*Bảng số xoắn ốc từ ngoài vào
Viết hàm spiral_outside_in để tạo một bảng số vuông kích thước n × n.

Các số từ 1 đến n * n được sắp xếp theo đường xoắn ốc theo chiều kim đồng hồ, bắt đầu từ góc trên bên trái và đi dần từ ngoài vào trong.

Ví dụ với n = 3:

1 2 3
8 9 4
7 6 5
Quy ước chuỗi kết quả:

Các số trên cùng một dòng cách nhau đúng một khoảng trắng.
Các dòng cách nhau bằng ký tự xuống dòng \n.
Không có ký tự xuống dòng dư ở cuối chuỗi.
Sinh viên cần tự định nghĩa đầy đủ hàm dựa trên prototype sau:

string spiral_outside_in(int n);
For example:

Input	
3
Result
1 2 3
8 9 4
7 6 5

*/
#include <iostream>
#include <string>
using namespace std;

string spiral_outside_in(int n) {
    int a[100][100] = {0};
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int num = 1;

    while (num <= n * n) {
        for (int j = left; j <= right && num <= n * n; j++) a[top][j] = num++;
        top++;
        for (int i = top; i <= bottom && num <= n * n; i++) a[i][right] = num++;
        right--;
        for (int j = right; j >= left && num <= n * n; j--) a[bottom][j] = num++;
        bottom--;
        for (int i = bottom; i >= top && num <= n * n; i--) a[i][left] = num++;
        left++;
    }

    string result = "";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result += to_string(a[i][j]);
            if (j < n - 1) result += " ";
        }
        if (i < n - 1) result += "\n";
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    cout << spiral_outside_in(n) << endl;
    return 0;
}