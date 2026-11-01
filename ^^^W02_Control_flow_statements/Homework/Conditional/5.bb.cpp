/*Kiểm tra tam giác
Kiểm tra ba số nguyên dương a,b,c có thể tạo thành một tam giác hay không và xác định loại tam giác tương ứng
Ba cạnh tạo thành một tam giác hợp lệ khi: {a,b,c} >0;
Điều kiện để thỏa là tam giác: {a+b>c ; a+c>b ; b+c >a}
Nếu 3 cạnh không thỏa mản các điều kiện trên, hàm trả về -1
Nếu là tam giác hợp lệ -> Xác định loại tam giác và trả về
1: tam giác thường
2: tam giác cân (có ít nhất 2 cạnh bằng nhau)
3: tam giác đều (có 3 cạnh bằng nhau)
4: tam giác vuông (bình phương cạnh lớn nhất bằng tổng bình phương 2 cạnh còn lại)
Input : 3 3 1
Output : 2
*/
#include <iostream>
using namespace std;

int main() {
    int a,b,c;
    cin>>a>>b>>c;
    if (a <= 0 || b<=0 || c<=0) cout<<-1;
    if (a>0 && b>0 && c>0) {
        if (a+b>c && a+c>b && b+c>a) {
            if ( a==b && b==c ) cout<<3;
            else if ((a==b) || (a==c) || (b==c)) cout<<2;
            else if ((a*a==b*b+c*c) || (b*b==a*a+c*c) || (c*c==a*a+b*b)) cout<<4;
            else cout<<1;
        }
    else {cout<<-1;}
    }

    return 0;
}