# **Phần mềm thi trắc nghiệm trên console**

## **Giới thiệu**  
Đây là một phần mềm thi trắc nghiệm được viết bằng C++, hiển thị trên giao diện console. Phần mềm hỗ trợ:  
- Quản lý câu hỏi thi (thêm, sửa, xóa).  
- Tạo bài thi từ ngân hàng câu hỏi.  
- Hiển thị bài thi và chấm điểm tự động.  

## **Mục tiêu**  
- Quản lý sinh viên các lớp
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

### 4. Quản lý lớp
- Đọc thêm sửa xóa lớp
- Thêm sửa xóa sinh viên của lớp
- In bảng điểm của lớp đó theo môn học

### 5. Quản lý môn học
- Đọc thêm sửa xóa môn học
- Tạo các câu hỏi theo môn học

## **Hướng dẫn sử dụng**  

### 1. Biên dịch và chạy chương trình  
- Sử dụng Dev-C++ hoặc Visual Studio để mở file `main.cpp`.  
- Biên dịch và chạy chương trình.  

### 2. Quản lý câu hỏi  
- Chọn tùy chọn "Môn học" từ menu chính.
- Sau đó nhấn Enter vào môn học bạn muốn thêm câu hỏi
- Thêm, sửa hoặc xóa câu hỏi trực tiếp.  

### 3. Thi trắc nghiệm  
- Chọn môn thi số câu hỏi và thời gian để thực hiện bài thi.  
- Trả lời câu hỏi trong thời gian giới hạn.  

### 4. Xem kết quả  
- Sau khi thi xong, kết quả sẽ được hiển thị chi tiết.  
- Có thể xem lại lịch sử thi qua chức năng "Xem kết quả".

## **Cấu trúc dự án**  

```plaintext
.
├── main.cpp         # File chính chạy chương trình
├── ClassData        # Thư mục lưu trữ danh sách lớp
├── SubjectData      # Thư mục lưu trữ môn học và câu hỏi
├── ExamRecordData   # Thư mục lưu trữ bài kiểm tra của sinh viên đã làm 
└── README.md        # Tài liệu hướng dẫn

## **Công nghệ sử dụng**  
- **Ngôn ngữ**: C++.  
- **IDE**: Dev-C++ hoặc Visual Studio.  
- **Hệ điều hành**: Windows.  
- **File lưu trữ**: Text file (`.txt`) để lưu câu hỏi và kết quả thi.

## **Tác giả**  
- **Tên**: Vũ Duy Dũng, Lê Lam Hải, Cao Ngọc Huy 
- **Email**: duydung1271998@gmail.com 
- **Liên kết GitHub**: lelamhai/Project

## **Tóm tắt**  
Phần mềm thi trắc nghiệm trên console là một công cụ đơn giản nhưng hiệu quả, được xây dựng để hỗ trợ thi trắc nghiệm nhanh chóng và tiện lợi.  

Cảm ơn bạn đã sử dụng phần mềm!
