# **Phần mềm thi trắc nghiệm trên console**

## **Giới thiệu**  
Đây là một phần mềm thi trắc nghiệm được viết bằng C++, hiển thị trên giao diện console. Phần mềm hỗ trợ:  
- Quản lý câu hỏi thi (thêm, sửa, xóa).  
- Tạo bài thi từ ngân hàng câu hỏi.  
- Hiển thị bài thi và chấm điểm tự động.  

## **Mục tiêu**  
- Tạo công cụ giúp người dùng thi trắc nghiệm dễ dàng.  
- Quản lý câu hỏi và kết quả thi một cách hiệu quả.
  
## **Tính năng chính**  
### 1. Quản lý câu hỏi  
- Thêm, sửa, xóa câu hỏi.  
- Lưu trữ câu hỏi vào file và tải lại khi cần.  

### 2. Tạo bài thi  
- Tạo bài thi ngẫu nhiên từ ngân hàng câu hỏi.  
- Quản lý thời gian làm bài.  

### 3. Chấm điểm và lưu kết quả  
- Tự động chấm điểm.  
- Hiển thị kết quả chi tiết: số câu đúng, sai và điểm tổng.  
- Lưu kết quả vào file để tra cứu sau.

## **Hướng dẫn sử dụng**  

### 1. Biên dịch và chạy chương trình  
- Sử dụng Dev-C++ hoặc Visual Studio để mở file `main.cpp`.  
- Biên dịch và chạy chương trình.  

### 2. Quản lý câu hỏi  
- Chọn tùy chọn "Quản lý câu hỏi" từ menu chính.  
- Thêm, sửa hoặc xóa câu hỏi trực tiếp.  

### 3. Thi trắc nghiệm  
- Chọn "Bắt đầu thi" để thực hiện bài thi.  
- Trả lời câu hỏi trong thời gian giới hạn.  

### 4. Xem kết quả  
- Sau khi thi xong, kết quả sẽ được hiển thị chi tiết.  
- Có thể xem lại lịch sử thi qua chức năng "Xem kết quả".

## **Cấu trúc dự án**  

```plaintext
.
├── main.cpp         # File chính chạy chương trình
├── question.cpp     # Quản lý câu hỏi
├── exam.cpp         # Quản lý bài thi
├── result.cpp       # Lưu trữ và xem kết quả
├── data/            # Thư mục lưu trữ câu hỏi và kết quả
└── README.md        # Tài liệu hướng dẫn
