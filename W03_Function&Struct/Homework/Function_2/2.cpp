/*Hồi quy tuyến tính đơn biến bậc 1
Viết hàm linear_regression để tìm mô hình tuyến tính có dạng:

y = m × x + b

từ tập dữ liệu data_points. Sau khi tìm được hai hệ số m và b, sử dụng mô hình để dự đoán giá trị y tương ứng với giá trị new_data.

Ban đầu, khởi tạo: m = 0, b = 0

 
Trong mỗi vòng lặp, tính hai gradient:

grad_m = -(2 / n) × sum(x_i × (y_i - (m × x_i + b)))

grad_b = -(2 / n) × sum(y_i - (m × x_i + b))

Trong đó n là số lượng điểm dữ liệu.

Sau khi tính gradient, cập nhật hai hệ số:

m = m - learning_rate * grad_m;

b = b - learning_rate * grad_b;
Quá trình trên được thực hiện lặp lại num_iterations lần.

Hai tham số có giá trị mặc định:

learning_rate = 1e-3
num_iterations = 50000
Sau khi quá trình Gradient Descent kết thúc, sử dụng mô hình đã tìm được để dự đoán giá trị mới:

prediction = m × new_data + b

Kết quả trả về phải được làm tròn đến 3 chữ số thập phân bằng hàm round_to_decimal đã được cung cấp sẵn.

Mỗi điểm dữ liệu được biểu diễn bằng cấu trúc:

struct Point {
    float x;
    float y;
};
Sinh viên cần tự định nghĩa hàm dựa trên prototype sau:

float linear_regression(
    Point data_points[],
    int num_data_points,
    float new_data,
    float learning_rate = 1e-3,
    int num_iterations = 50000
);
Lưu ý: Test của bài này chấp nhận một sai số nhỏ do kết quả của quá trình Gradient Descent có thể thay đổi nhẹ tùy theo độ chính xác số thực.

Ví dụ
Cho tập dữ liệu: {{1, 2}, {3, 6}, {2, 4}, {5, 10}, {11, 22}} và: new_data = 6

Mô hình học được xấp xỉ: y = 2 * x

Do đó kết quả dự đoán xấp xỉ: 12

For example:

Result
1

*/