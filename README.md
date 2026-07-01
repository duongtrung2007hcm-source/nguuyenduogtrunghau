lý do chọn dự án:
1. Tính ứng dụng thực tế cao (Real-world Problem)
2. Sự đa dạng của các cấu trúc dữ liệu (DSA Diversity)
3. Thách thức về quản lý bộ nhớ và tối ưu hóa (Technical Complexity)

1.Library Management System (Hệ thống Quản lý Thư viện)

Ứng dụng quản lý thư viện hiện đại, tập trung vào việc tối ưu hóa hiệu suất truy xuất dữ liệu và quản lý luồng nghiệp vụ mượn/trả bằng cách ứng dụng các cấu trúc dữ liệu và giải thuật tối ưu trong C++17.

++Cấu trúc dữ liệu sử dụng

+BST (Binary Search Tree): Dùng để quản lý danh sách sách theo mã định danh (ISBN/ID).

Vì: Cung cấp độ phức tạp O(log n) cho cả thao tác tìm kiếm, thêm mới và xóa, giúp hệ thống duy trì tính ổn định ngay cả khi số lượng sách tăng mạnh.

+Queue: Dùng để quản lý hàng đợi độc giả chờ đợi sách. 

Vì: Đảm bảo tính công bằng (First-In-First-Out - FIFO), người đăng ký mượn trước sẽ được phục vụ trước.

+Linked List: Dùng để quản lý danh sách các cuốn sách cụ thể đang được một độc giả mượn. 

Vì: Số lượng sách mượn của mỗi độc giả là linh động, danh sách liên kết cho phép cấp phát bộ nhớ động hiệu quả.

2.Cấu trúc file:
src/

  main.cpp        — Menu và điều khiển luồng chương trình
  
  structures.h    — Khai báo các struct (Book, Reader) + nguyên mẫu hàm
  
  functions.cpp   — Cài đặt chi tiết các thuật toán xử lý

3.Compile và chạy

Sử dụng trình biên dịch hỗ trợ C++17 trở lên: g++ -std=c++17 src/main.cpp src/functions.cpp -o app && ./app

4.Chức năng
Tra cứu sách: Tìm kiếm thông tin sách qua mã định danh bằng cây BST.

Quản lý mượn sách: Đăng ký mượn sách, cập nhật tình trạng sách trong hệ thống.

Xử lý trả sách: Cập nhật danh sách mượn của độc giả và giải phóng sách về kho.

Hàng đợi độc giả: Tự động thông báo nếu sách đã được người khác đặt trước trong hàng đợi.

6.Test cases:
+Tests Case 1:
mô tả: Tìm kiếm mã sách không tồn tại
kết quả mong đợi:Trả về thông báo "Không tìm thấy sách".

+Tests Case 2:
mô tả:Mượn sách khi sách còn trong kho
kết quả mong đợi:Trạng thái sách chuyển thành "Đã mượn", thêm vào danh sách mượn của độc giả.

+Tests Case 3:
mô tả:Trả sách đã mượn
kết quả mong đợi:Sách được xóa khỏi danh sách mượn của độc giả, trạng thái trở về "Available".

+Tests Case 4:
mô tả:Mượn sách khi sách đang được mượn
kết quả mong đợi:Hệ thống đẩy độc giả vào Queue chờ đợi.

+Tests Case 5:
mô tả:Xóa đầu sách đang có người mượn
kết quả mong đợi:Hệ thống từ chối xóa để đảm bảo toàn vẹn dữ liệu (Integrity Constraint).

Bản đồ kết nối Cấu trúc dữ liệu (Architecture Map):
   
1. Bộ não chính: BST (Quản lý kho sách) cho phép tìm kiếm nhanh $O(\log n)$.
   
2. Hàng đợi: Queue (Hàng đợi mượn) cho mỗi đầu sách, đảm bảo công bằng.
   
3. Lịch sử: Stack (Undo) giúp quay lại thao tác nhầm lẫn, tăng tính chuyên nghiệp.
   
4. Lưu trữ: File .txt (Cần dùng cơ chế đọc/ghi tuần tự khi khởi động/đóng chương trình).

Phân tích các hàm xử lý quan trọng
Để thực hiện 7 chức năng trên, bạn cần chú ý vào 3 logic phức tạp nhất:

++Logic Trả sách & Thông báo (Tính năng 4):
HÀM TrảSách(MãSách, NgườiTrả):
    CậpNhậtTrạngThái(MãSách, "Available")
    XóaNgườiDùngKhỏiDanhSáchMượn(NgườiTrả, MãSách)
    
    NẾU CóNgườiTrongQueue(MãSách):
        NgườiTiếpTheo = Queue.Dequeue(MãSách)
        THÔNG_BÁO("Sách đã sẵn sàng cho: " + NgườiTiếpTheo)
  ++Logic Undo thao tác (Tính năng 5):
  HÀM PushThaoTác(HànhĐộng):
    Stack.Push(HànhĐộng)

HÀM Undo():
    HànhĐộngCuối = Stack.Pop()
    NẾU HànhĐộngCuối LÀ MượnSách:
        ThựcHiệnTrảSáchNgượcLại()
    NẾU HànhĐộngCuối LÀ TrảSách:
        ThựcHiệnMượnSáchNgượcLại()
        
++Gợi ý kỹ thuật cho Thống kê (Tính năng 6)
Để thống kê "sách được mượn nhiều nhất", bạn đừng cố tìm cách lọc cây BST, vì nó sẽ rất chậm.

Mẹo: Trong struct Book, hãy thêm một trường int borrowCount. Mỗi lần mượn thành công, bạn tăng biến này lên borrowCount++.

Kết quả: Khi cần thống kê, bạn chỉ cần duyệt cây (In-order traversal) và đưa tất cả các đầu sách vào một Mảng động (Dynamic Array), 
sau đó dùng thuật toán Quick Sort hoặc Merge Sort để sắp xếp theo borrowCount giảm dần.

++Lưu và Đọc file (Tính năng 7)
Đọc dữ liệu: Khi khởi động chương trình, hãy đọc từng dòng trong file .txt
dùng hàm split (hoặc stringstream trong C++) để tách dữ liệu và Insert từng cuốn vào BST.

Lưu dữ liệu: Khi người dùng chọn "Thoát chương trình" 
bạn cần duyệt toàn bộ cây BST (Pre-order traversal là tốt nhất) để ghi lại toàn bộ trạng thái hiện tại xuống file.

**Lời khuyên cuối trước khi bạn bắt đầu code:

Đừng dùng raw pointers lung tung: Hãy quản lý bộ nhớ thật kỹ.

Mỗi khi bạn new một Node, phải đảm bảo có hàm delete tương ứng trong hàm hủy (Destructor) hoặc khi chương trình kết thúc.

Code theo module: Viết functions.cpp thật tách bạch. 

Ví dụ: các hàm liên quan đến cây thì gom vào một chỗ, các hàm xử lý file riêng, menu riêng. Điều này giúp bạn dễ dàng debug khi chương trình bị crash.
