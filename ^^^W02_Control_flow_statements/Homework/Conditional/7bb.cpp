/*Viết hàm tính tiền taxi
Tính số tiền taxi dựa trên quảng đường (km)
Giá cước được tính theo từng khoảng như sau:
- Khoảng cách <=1: 5000đ
- 1 < Khoảng cách <= 5:  
   km đầu tiên: 5000đ
   phần vượt quá 1km: 4500đ
- 5 < Khoảng cách:
   km đầu tiên: 5000đ
   từ 1 km đến 5km: 4500đ
   phần quảng đường vượt quá 5km: 3500đ
- Nếu tổng quãng đường lớn hơn 120km -> giảm 10% trên tổng số tiền
Hàm cần trả về tổng số tiền dưới dạng long. Kết quả cuối cingf được làm tròn đến số nguyên gần nhất bằng hàm round
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double total = 0;
    double dis;
    cin>>dis;
    if (dis <=1) total = 5000;
    else if (1< dis && dis<=5) total = 5000 + ((dis-1)*4500);
    else if (5<dis && dis<=120) total = 5000 + 4*4500 + ((dis-5)*3500);
    else if (120<dis) total = 0.9*(5000+ 4*4500 + ((dis-5)*3500));
/* if (dis <= 1) total = 5000;
else if (dis <= 5) total = 5000 + (dis - 1) * 4500;
else total = 5000 + 4 * 4500 + (dis - 5) * 3500;

if (dis > 120) total = total * 0.9;   // if riêng, luôn được kiểm tra
*/
    cout<<(double) round (total) <<endl;
    return 0;
}