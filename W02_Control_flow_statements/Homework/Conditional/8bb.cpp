/*Tính giá cước internet
Tính tiền sử dụng internet dựa trên thời điểm bắt đầu start và thời điểm kết thúc end
***Thời gian được biểu diễn dưới dạng số thực, trong đó:
.00: tương ứng với 0 phút
.25: tương ứng với 15 phút
.50: tương ứng với 30 phút
.75: tương ứng với 45 phút
Ví dụ: 12.25 : tương ứng với 12 giờ 15 phút
***Giá cước tính theo từng khung giờ:
- Từ 07:00 đến trước 17:00 : 400đ/phút
Nếu tổng thời gian truy cập trong khung giờ này lớn hơn 6 giờ, giảm 10% tiền cước của phần thời gian thuộc khung giờ này.
- Từ 17:00 đến trước 24:00 : 350đ/phút
Nếu tổng thời gian truy cập trong khung giờ này lớn hơn 4 giờ, giảm 12% tiền cước của phần thời gian thuộc khung giờ này.
- Từ 00:00 đến trước 7:00 : 300đ/phút
Nếu tổng thời gian truy cập trong khung giờ này lớn hơn 4 giờ, giảm 15% tiền cước của phần thời gian thuộc khung giòe này.
***Nếu khoảng thời gian truy cập đi qua nhiều khung giờ khác nhau, cần tách thời gian sử dụng theo khung giờ và tính tiền riêng cho từng phần
- Khoảng thời gian sử dụng không vượt quá 24 giờ
- Nếu start < end, thời gian bắt đầu và kết thúc được hiểu là trong cùng 1 ngày
- Nếu start > end, thời gian truy cập được hiểu là kéo dài qua ngày hôm sau. KHi đó thời gian sử dụng được tính từ start tới 24:00 của ngày hiện tại , sau đó tiếp tục từ 00:00 đến end của ngày hôm sau
- Nếu srart = end, xem như người này đã truy cập liên tục trong 24 giờ
Ví dụ: start = 23.00 và end = 1.00, thì người này sử dụng từ 23:00 của ngày hiện tại đến 1:00 của ngày hôm sau, tương ứng với tổng thời gian sử dụng là 2 giờ
***Lưu ý: không được tính toàn bộ thời gian sử dụng theo một mức giá duy nhất nếu khoảng truy cập đi qua nhiều khung giờ khác nhau. Mỗi phần thời gian phải được tính theo đúng mức giá và mức giảm tương ứng của giờ đó.
***Đặc biệt, trường hợp start > end không phải là thời gian không hợp lệ mà được hiểu là phần truy cập kéo dài sang ngày hôm sau
Input: 16.5 19.25
Output: 59250
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double start, end;
    cin >> start >> end;

    // Đoạn 1: [a1, b1)    Đoạn 2: [a2, b2)
    double a1, b1, a2, b2;

    if (start < end) {
        a1 = start; b1 = end;   // cùng ngày: chỉ có 1 đoạn
        a2 = 0;     b2 = 0;     // đoạn 2 rỗng (dài 0 giờ)
    } else {
        a1 = start; b1 = 24;    // từ start đến nửa đêm
        a2 = 0;     b2 = end;   // từ nửa đêm đến end
    }

    double h1 = 0, h2 = 0, h3 = 0;//h1,h2,h3 là số giờ dùng trong mỗi khung giờ
    double lo, hi;//lo: mốc bắt đầu, hi: mốc kết thúc (không dùng trực tiếp các biến a1,a2,b1,b2 vì nó sẽ giúp không làm thay đổi giá trị gốc ban đầu, vì chương trình chạy tuần tự từ trên xuống)

    // ===== Xử lý đoạn 1 (tính số giờ dùng trong mỗi khung giờ, cùng ngày)===== 
    lo = a1; hi = b1;                       // khung 1: [0, 7)
    if (hi > 7) hi = 7;                     // vì giờ nằm trong khoảng từ 0 -> 24 => không cần đặt điều kiện cho a (lo)
    if (hi > lo) h1 += hi - lo;

    lo = a1; hi = b1;                       // khung 2: [7, 17)
    if (lo < 7) lo = 7;                     //không được bỏ lo, hi ở các đoạn sau vì nếu bỏ đi thì nó sẽ dùng giá trị ở đoạn lệnh trước để tính
    if (hi > 17) hi = 17;
    if (hi > lo) h2 += hi - lo;

    lo = a1; hi = b1;                       // khung 3: [17, 24)
    if (lo < 17) lo = 17;                   // vì giờ nằm trong khoảng từ 0 -> 24 => không cần đặt điều kiện cho b (hi)
    if (hi > lo) h3 += hi - lo;

    // ===== Xử lý đoạn 2 (tính số giờ dùng trong mỗi khung giờ, khác ngày) =====
    lo = a2; hi = b2;
    if (hi > 7) hi = 7;
    if (hi > lo) h1 += hi - lo;

    lo = a2; hi = b2;
    if (lo < 7) lo = 7;
    if (hi > 17) hi = 17;
    if (hi > lo) h2 += hi - lo;

    lo = a2; hi = b2;
    if (lo < 17) lo = 17;
    if (hi > lo) h3 += hi - lo;

    // ===== Tính tiền =====
    double c1 = h1 * 60 * 300;
    if (h1 > 4) c1 *= 0.85;

    double c2 = h2 * 60 * 400;
    if (h2 > 6) c2 *= 0.90;

    double c3 = h3 * 60 * 350;
    if (h3 > 4) c3 *= 0.88;

    cout << llround(c1 + c2 + c3) << endl;
    return 0;
}
