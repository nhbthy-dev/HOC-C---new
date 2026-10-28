/*Happy Number
Viết hai hàm nextNumber và isHappy để kiểm tra một số nguyên dương n có phải là Happy Number hay không.

Hàm nextNumber(n) tạo ra một số mới 
bằng cách tính tổng bình phương các chữ số của n.

Ví dụ:

19 → 12 + 92 = 82

Một số được gọi là Happy Number nếu khi lặp lại quá trình trên, cuối cùng nhận được giá trị 1.

Ví dụ với n = 19:

19 → 82 → 68 → 100 → 1
Nếu quá trình không đi đến 1, các giá trị sẽ lặp lại theo một chu kỳ.

Để phát hiện chu kỳ mà không sử dụng mảng hoặc cấu trúc dữ liệu khác, sử dụng hai biến:

slow: mỗi vòng lặp gọi nextNumber một lần.
fast: mỗi vòng lặp gọi nextNumber hai lần.
Dừng khi slow == fast. Nếu giá trị gặp nhau là 1 thì n là Happy Number.

Lưu ý: Đây là bài thực hành về hàm. Hàm isHappy cần gọi và sử dụng hàm nextNumber.

Sinh viên cần tự định nghĩa đầy đủ các hàm dựa trên các prototype sau:

int nextNumber(int n);

bool isHappy(int n);
For example:

Input	Result
19      82
*/
/*#include <iostream>
using namespace std;


int nextNumber(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}


bool isHappy(int n) {
    int slow = n;
    int fast = n;

    do {
        slow = nextNumber(slow);                // Tiến 1 bước
        fast = nextNumber(nextNumber(fast));    
    } while (slow != fast);

    return (slow == 1);
}*/


/*Sẽ rơi vào vòng lặp quan tọng kết quả cuối cùng của vòng lặp 
là 1 hay là một số khác sẽ quyết định đó có phải là happy không đúng không*/
#include <iostream>
using namespace std;

int nextNumber(int n);
bool isHappy(int n);

int nextNumber(int n) {
    int sum = 0;
    while (n > 0) {
        int d = n % 10;   // lấy chữ số cuối
        sum += d * d;     // cộng bình phương chữ số
        n /= 10;          // bỏ chữ số cuối
    }
    return sum;
}

bool isHappy(int n) {
    int slow = n, fast = n;
    do {                                     //Với do...while, vòng đầu tiên luôn chạy: slow đi 1 bước, 
                                             //fast đi 2 bước, lúc này hai biến mới tách nhau ra, 
                                             //rồi mới bắt đầu so sánh.
        slow = nextNumber(slow);               // đi 1 bước
        fast = nextNumber(nextNumber(fast));   // đi 2 bước
    } while (slow != fast);
    return slow == 1;   // gặp nhau ở 1 → Happy    (return ở bool thường là biểu thức so sánh trả về true/false)
    //không return n==1 vì n là giá trị ban đầu không bị thay đổi.cũng có thể là fast==1.
}
/*slow = fast = n
   ↓
lặp: slow đi 1 bước, fast đi 2 bước
   ↓
slow và fast gặp nhau? ── chưa ──→ lặp tiếp
   ↓ rồi
số gặp nhau là 1? ── có ──→ true (Happy)
                  └─ không ──→ false (không Happy)
*/
/*Điểm mấu chốt: so sánh GIÁ TRỊ, không phải so sánh VỊ TRÍ
slow != fast so sánh số đang cầm trong tay, không phải họ đi được bao nhiêu bước. 
Hai người ở vị trí khác nhau nhưng nếu cùng đứng trên số 1, thì giá trị của họ bằng nhau.*/
/*Giá trị của slow và fast luôn cùng nằm trên một dãy duy nhất (một số chỉ có 1 số kế tiếp).
Nếu dãy dẫn tới 1 thì fast tới trước, đứng đợi ở 1, slow tới sau là gặp.
Nếu dãy dẫn tới vòng quay thì fast đuổi kịp slow trong vòng.*/

int main() {
    int n;
    cin >> n;
    cout << nextNumber(n)<<endl;   // ví dụ đề: n = 19 → in 82
    cout << isHappy(n);
    return 0;
}