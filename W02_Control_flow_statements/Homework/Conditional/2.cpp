/*Tính ngày
Chọn ngày tháng năm bất kì
- Nếu ngày không hợp lệ: valid =0, các giá trị ngày trước và ngày sau giữ nguyên giá trị khởi tạo
- Nếu ngày hợp lệ: valid = 1, xác định ngày liền trước và ngày liền sau
Input: 12 3 2000
Output: 1 11 3 2000 13 3 2000
*/
#include <iostream>
using namespace std;

int main() {
    int d, m, y;
    cin >> d >> m >> y;

    int valid = 0;
    int pd = 0, pm = 0, py = 0;   // ngày trước (giữ 0 nếu không hợp lệ)
    int nd = 0, nm = 0, ny = 0;   // ngày sau   (giữ 0 nếu không hợp lệ)

    // Bước 1: năm nhuận và số ngày của tháng hiện tại
    bool leap = (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;

    int maxDay = 0;   // tháng sai thì giữ 0 → d >= 1 && d <= 0 luôn sai
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) maxDay = 31;
    else if (m == 4 || m == 6 || m == 9 || m == 11) maxDay = 30;
    else if (m == 2) {
        if (leap) maxDay = 29;
        else maxDay = 28;
    }

    // Bước 2: kiểm tra hợp lệ
    if (d >= 1 && d <= maxDay) valid = 1;

    if (valid == 1) {
        // Bước 3: ngày liền sau (mặc định cùng tháng, cùng năm)
        nd = d + 1; nm = m; ny = y;
        if (d == maxDay) {            // ngày cuối tháng
            nd = 1;
            nm = m + 1;
            if (nm > 12) {            // qua năm mới
                nm = 1;
                ny = y + 1;
            }
        }

        // Bước 4: ngày liền trước (mặc định cùng tháng, cùng năm)
        pd = d - 1; pm = m; py = y;
        if (d == 1) {                 // ngày đầu tháng → lùi về tháng trước
            pm = m - 1;
            if (pm < 1) {             // lùi qua năm cũ
                pm = 12;
                py = y - 1;
            }
            if (pm == 4 || pm == 6 || pm == 9 || pm == 11) pd = 30;
            else if (pm == 2) {       // pm == 2 nghĩa là m == 3, cùng năm nên dùng leap
                if (leap) pd = 29;
                else pd = 28;
            }
            else pd = 31;
        }
    }

    cout << valid << " " << pd << " " << pm << " " << py
         << " " << nd << " " << nm << " " << ny << endl;
    return 0;
}