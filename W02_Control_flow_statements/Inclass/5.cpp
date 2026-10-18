/*Tính tiền phòng
Viết hàm calculate_room_fee để tính tổng số tiền thuê phòng dựa trên số ngày thuê days và loại phòng type_room.

Quy ước loại phòng:

type_room = 1: phòng loại A

type_room = 2: phòng loại B

type_room = 3: phòng loại C

Đơn giá theo ngày:

Phòng loại A: 250.000 đồng/ngày

Phòng loại B: 200.000 đồng/ngày

Phòng loại C: 150.000 đồng/ngày

Nếu số ngày thuê từ 12 ngày trở lên, áp dụng giảm giá trên tổng tiền phòng:

Phòng loại A: giảm 10%

Phòng loại B: giảm 8%

Phòng loại C: giảm 8%

Hàm trả về tổng số tiền thuê phòng dưới dạng long. Kết quả cuối cùng được làm tròn bằng hàm round.

Lưu ý
Mức giảm giá chỉ được áp dụng khi số ngày thuê lớn hơn hoặc bằng 12. Nếu thuê dưới 12 ngày, tính theo đơn giá thông thường và không áp dụng giảm giá.

For example:

Input	    Result
15 1       3375000
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int type_room,days;
    cin>>type_room>>days;
    long long total_amout = 0;
    if (type_room == 1) {
        total_amout = days * 250000.0;
        if (days >= 12) {
            total_amout = total_amout * 0.9;
        }
    }
    else if (type_room == 2) {
        total_amout = days * 200000.0;
        if (days >= 12) {
            total_amout = total_amout * 0.92;
        }
    }
    else if (type_room == 3) {
        total_amout = days * 150000.0;
        if (days >= 12) {
            total_amout = total_amout * 0.92;
        }
    }
    cout<<(long long) round(total_amout);
    return 0;
}