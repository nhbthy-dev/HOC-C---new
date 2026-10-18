/*Kiểm tra tháng
Trả về mùa tương ứng của tháng
- Xuân (1-3):1
- Hạ (4-6):2
- Thu (7-9): 3
- Đông (10-12):4
Tháng không hợp lể trả về -1
Input: 5
Output: 2
*/
#include <iostream>
using namespace std;

int main() {
    int month;
    cin>>month;
    if (month == 1 || month == 2 || month == 3) {
        cout<<"1"<<endl;
    } else if (month == 4 || month == 5 || month == 6) {
        cout<<"2"<<endl;
    } else if (month == 7 || month == 8 || month == 9) {
        cout<<"3"<<endl;
    } else if (month == 10 || month == 11 || month == 12) {
        cout<<"4"<<endl; 
    } else {
        cout<<"-1"<<endl;
    }
    return 0;
}