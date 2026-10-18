#include <iostream>
#include <string>
#include <iomanip> // Dùng để định dạng số thập phân (fixed, setprecision)

using namespace std;

// 1. Định nghĩa cấu trúc Student
struct Student {
    string id;          // Mã số sinh viên
    string name;        // Họ và tên
    float literature;   // Điểm Văn
    float math;         // Điểm Toán
    float gpa;          // Điểm trung bình GPA
};

// --- Khai báo các hàm (Prototypes) ---
float calcGPA(float literature, float math);

void inputStudent(Student &s);
/*Nhiệm vụ: Khai báo hàm dùng để nhập thông tin cho sinh viên.

void: Hàm không trả về giá trị bằng câu lệnh return.(không gửi trả lại dữ liệu cho nơi gọi)

Student &s (Truyền tham chiếu - Pass-by-reference):

Dấu & là điểm quan trọng nhất. Nó cho phép hàm tác động và ghi dữ liệu trực tiếp vào biến gốc s ngoài hàm main().

Khi bạn gõ cin >> s.id hay cin >> s.name inside hàm này, dữ liệu vừa nhập sẽ lưu thẳng vào sinh viên ở main() chứ không bị mất đi khi thoát hàm.*/
void printStudent(const Student &s);
/*Nhiệm vụ: Khai báo hàm dùng để in/xuất thông tin sinh viên ra màn hình.
void: Hàm chỉ thực hiện hành động in ra màn hình (cout), không cần return giá trị.
const Student &s (Tham chiếu Hằng - Const Reference):
Từ khóa const: Đảm bảo an toàn dữ liệu. Nó tuyên bố hàm này chỉ được phép ĐỌC để in ấn, tuyệt đối không được sửa đổi bất kỳ thông tin nào của sinh viên s. Nếu bạn lỡ tay viết lệnh sửa dữ liệu trong hàm này, trình biên dịch sẽ báo lỗi ngay lập tức.
Dấu & (Tham chiếu): Giúp hàm lấy trực tiếp biến gốc mà không tạo bản sao (copy). Điều này giúp chương trình chạy nhanh hơn và tiết kiệm bộ nhớ (nhất là khi Student chứa nhiều chuỗi hay mảng dữ liệu lớn).*/
int main() {
    Student s;

    cout << "=== NHAP THONG TIN SINH VIEN ===" << endl;
    inputStudent(s);

    cout << "\n=== THONG TIN SINH VIEN SE CUNG CAP ===" << endl;
    printStudent(s);

    return 0;
}

// 2. Hàm tính điểm GPA (Trả về float)
float calcGPA(float literature, float math) {
    return (literature + math) / 2.0f;
}

// 3. Hàm nhập thông tin sinh viên (Sử dụng tham chiếu & để thay đổi trực tiếp biến s)
void inputStudent(Student &s) {
    cout << "Nhap MSSV: ";
    getline(cin, s.id);
/*getline cho nhập kí tự có khoảng trắng*/
    cout << "Nhap ho va ten: ";
    getline(cin, s.name);
/*getline (cin,biến chuỗi). Có thể đọc và loại bỏ \n(enter)*/
    cout << "Nhap diem Van: ";
    cin >> s.literature;
/*cin>>biến số. Chừa lại \n trong bộ nhớ đệm (nguyên nhân gây trôi lệch).Trôi lệnh ở đây là không cho nhập hàm tiếp theo. Xử lí: cin.ignore(); sau các câu lệnh cin>>biến số*/
    cout << "Nhap diem Toan: ";
    cin >> s.math;

    // Tự động tính GPA sau khi nhập điểm
    s.gpa = calcGPA(s.literature, s.math);
}


// 4. Hàm xuất thông tin sinh viên (Truyền giá trị/hằng tham chiếu)
void printStudent(const Student &s) {
    cout << "MSSV: " << s.id << endl;
    cout << "Ho va ten: " << s.name << endl;
    cout << "Diem Van: " << s.literature << endl;
    cout << "Diem Toan: " << s.math << endl;
    cout << "GPA: " << fixed << setprecision(2) << s.gpa << endl;
}