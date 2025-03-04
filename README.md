# Báo cáo Bài tập lớn - Nhóm 8

## 1. Thông tin nhóm
| STT | Họ và tên | MSSV | Vai trò |
|---|---|---|---|
| 1 | Dương Hoàng Anh | 24022762 | Nhóm trưởng |
| 2 | Nguyễn Hoàng Anh | 24022764 | Thành viên |
| 3 | Ngô Gia Huy | 24022801 | Thành viên |
| 4 | Quách Đại Dương| 24021444 | Thành viên |  

---

## 2. Thông tin bài tập
- **Knight's tour**: Trên bàn cờ NxN, con mã điểm (x, y). Tìm đường đi qua mọi ô đúng 1 lần.
Gợi ý:
	Đệ quy thử từng nước đi.
	Nếu thăm hết mọi ô, thành công.
	Nếu đi vào ngõ cụt, quay lui.


---

## 3. Hướng giải quyết bài toán
### a. Phân tích bài toán
(Mô tả sơ bộ về bài toán, yêu cầu đầu vào - đầu ra, các ràng buộc nếu có)
Bài toán Knight's Tour - Mã đi tuần : à bài toán tìm một đường đi của quân mã (knight) trên bàn cờ cỡ n x n sao cho từ một vị trí bất kì quân mã có thể đi qua mọi ô đúng 1 lần
input : số nguyên dương n (kích cỡ bàn cờ)
        Hai số nguyên (x,y) >=0 đại diện cho vị trí của quân mã được đặt ngẫu nhiên
        
output: in ra bàn cờ thể hiện các nước đi quân mã (nếu đã hoàn thành yêu cầu)
        in ra "không tìm được đường đi nếu không có nước hợp lệ nào 

Ràng buộc : 
- Di chuyển hợp lệ (valid moves) : Quân mã chỉ được đi hình chữ L theo 8 hướng
- Không đi ra ngoài bàn cờ : nằm trong giới hạn 0<= x,y <=n
- Không đi vào ô đã thăm : Không đi lại ô đã đánh dấu
- Không phải lúc nào cũng tồn tại valid moves thỏa mãn bài toán

### b. Thuật toán/Hướng tiếp cận
(Mô tả chi tiết cách giải quyết bài toán, có thể kèm theo sơ đồ hoặc giả mã để minh họa)
Hướng tiếp cận : 
+ Xuất phát từ ô (x,y) quân mã sẽ thử đi đến ô hợp lệ kế tiếp
+ Nếu sau n^2 bước mà đi hết bàn cờ -> đã tìm thấy lời giải
+ Nếu bị kẹt -> quay lui lại (back tracking) để tìm hướng giải khác

Thuật toán back tracking 
- Khởi tạo bàn cờ n x n
- n×n với tất cả các ô được đánh dấu là chưa đi qua (-1).
- Đặt vị trí bắt đầu của quân mã thành 0.
- Duyệt tất cả 8 hướng di chuyển hợp lệ của quân mã, thử từng nước đi.
- Nếu đi đến một ô chưa đi và hợp lệ:
+ Đánh số bước đi.
+ Gọi đệ quy để tiếp tục thử hướng tiếp theo.
+ Nếu giải pháp hợp lệ, trả về true.
+ Nếu gặp ngõ cụt, quay lui (gán lại giá trị -1 cho ô đó).
- Nếu không có hướng nào hợp lệ, trả về false.

  Thuật toán tối ưu
  - Vì backtracking chọn ngẫu nhiên 8 hướng -> duyệt quá nhiều khả năng -> xử lí chậm / tăng độ phức tạp

  - tối ưu bằng cách : Luôn lựa chọn nước đi ít lựa chọn nhất (nước đi mà có các nước đi kế tiếp là valid moves ít nhất)
  -> + Khi chọn như vậy sẽ tránh việc để lại các nước đi ít lựa chọn nhất cuối cùng, dẫn đến ngõ cụt phải quay lui làm tốn thời gian

  - Các Bước của thuật toán tối ưu này:
  + Khởi tạo bàn cờ và đặt quân mã vào vị trí ban đầu.
  + Tính toán số nước đi hợp lệ từ mỗi ô kề cận.
  + Sắp xếp danh sách nước đi theo số lượng ô có thể đi tiếp tăng dần.
  + Chọn nước đi có ít lựa chọn nhất trước để tăng khả năng tìm lời giải nhanh hơn.
  + Tiếp tục đi quân mã theo hướng này cho đến khi:
      Điền đầy bàn cờ → Tìm được lời giải.
      Nếu đi vào ngõ cụt, quay lui và thử hướng khác.
  + Nếu không tìm được đường đi, trả về false.


  Giả mã:
  function chessboard(n, start_x, start_y):
  -   Khởi tạo bàn cờ nxn với tất cả ô được gán giá trị -1 (chưa đi qua).
  -   Đặt quân mã tại (start_x, start_y), đánh dấu bước đi đầu tiên là 0.
  -   Nếu knight_tour(start_x, start_y, 1) == TRUE:
      +    Xuất ra bàn cờ.
  -     Ngược lại:
        +  Xuất "Không tìm được đường đi".

function knight_tour(x, y, step):
- Nếu step == n * n: (đã đi hết bàn cờ)
-          Trả về TRUE.
-     Tạo danh sách nước đi hợp lệ từ ô (x, y).
-   Sắp xếp danh sách theo số lượng ô có thể đi tiếp (ít nhất lên trước).
-    Duyệt từng nước đi (next_x, next_y) trong danh sách:
        + Nếu ô (next_x, next_y) hợp lệ:
        +    Đặt bước đi step vào ô đó.
        +     Gọi đệ quy knight_tourl(next_x, next_y, step + 1).
        +     Nếu thành công, trả về TRUE.
        +     Nếu thất bại, quay lui (gán lại giá trị -1).
 -    Nếu không tìm thấy nước đi hợp lệ, trả về FALSE.


---

## 4. Ví dụ minh hoạ
### Ví dụ 1
**Input:**  6
2 2
(Mô tả input) (Tức là bàn cờ cỡ vừa 6x6, quân mã bắt đầu ở ô (2,2))  
**Output:**  

12  1 20 29 10  7  
21 28 11  8 19 30  
 2 13  0 27  6  9  
35 22 15 18 31 26  
14  3 24 33 16  5  
23 34 17  4 25 32  

(Mô tả output)  in ra bàn cờ thể hiện nước đi quân mã thỏa mãn yêu cầu bài toán
**Giải thích:**  
(Mô tả cách giải)
khởi tạo bàn cờ : gán tất cả các ô là giá trị -1 (tức chưa đi qua)

-1  -1  -1  -1  -1  -1  
-1  -1  -1  -1  -1  -1  
-1  -1   0  -1  -1  -1  
-1  -1  -1  -1  -1  -1  
-1  -1  -1  -1  -1  -1  
-1  -1  -1  -1  -1  -1  

- Quân mã được đặt ô 2,2 tức ô xuất phát sẽ có giá trị là 0
- Xét tất cả 8 hướng đi hợp lệ của quân mã
- Thử các tất cả các nước đi có thể từ vị trí mới này
  Cho vào 1 list chứa cặp giá trị <số nước đi, index> sắp xếp tăng dần
- Cho quân mã đi theo các nước đi vừa sắp xếp
- Nếu tìm được đường đi tiếp theo, đánh dấu số bước và tiếp tục gọi đệ quy để tìm nước đi tiếp theo
- Nếu đi đến bước cuối cùng mà vẫn hợp lệ, bài toán kết thúc thành công
- Nếu gặp ngõ cụt, quay lui để thử hướng đi khác
- Nếu giải được bài toán in ra output như trên là nước đi quân mã, nếu không in ra màn hình " không có nước đi hợp lệ"
  
### Ví dụ 2
**Input:**  10
9 9
(Mô tả input)  (Bàn cờ cỡ siêu to 10x10, quân mã bắt đầu ở 9x9 góc dưới bên phải)
**Output:**  

30  57  26   7  28  55  42   5  46  49  
25   8  29  56  41   6  51  48  43   4  
58  31  74  27  60  79  54  45  50  47  
 9  24  59  40  77  52  61  88   3  44  
32  73  70  75  80  89  78  53  62  91  
23  10  39  82  71  76  93  90  87   2  
38  33  72  69  94  81  86  65  92  63  
11  22  83  36  85  66  95  98   1  16  
34  37  20  13  68  97  18  15  64  99  
21  12  35  84  19  14  67  96  17   0  

(Mô tả output)  các nước đi của quân mã
**Giải thích:**  
(Mô tả cách giải)
- Nếu thuật toán không tối ưu : có thể không tìm được lời giải trong thời gian hợp lí / hoặc thất bại
  
- Quân mã được đặt ô 9,9 tức ô xuất phát sẽ có giá trị là 0
- Xét tất cả 8 hướng đi hợp lệ của quân mã
- Thử các tất cả các nước đi có thể từ vị trí mới này
  Cho vào 1 list chứa cặp giá trị <số nước đi, index> sắp xếp tăng dần
- Cho quân mã đi theo các nước đi vừa sắp xếp
- Nếu tìm được đường đi tiếp theo, đánh dấu số bước và tiếp tục gọi đệ quy để tìm nước đi tiếp theo
- Nếu đi đến bước cuối cùng mà vẫn hợp lệ, bài toán kết thúc
- Nếu gặp ngõ cụt, quay lui để thử hướng đi khác
- Nếu giải được bài toán in ra output như trên là nước đi quân mã, nếu không in ra màn hình " không có nước đi hợp lệ"
  
### Ví dụ 3
**Input:**  3
0 0
(Mô tả input)  (Bàn cờ cỡ nhỏ nhất có thể giải được 3x3, quân mã đặt ở ô 0,0)
**Output:**  "Không có nước đi hợp lệ"
(Mô tả output)  Không tìm thấy nước đi thỏa mãn yêu cầu đề bài
**Giải thích:**  
(Mô tả cách giải)
- Tạo bàn cờ cỡ 3x3
- Cho quân mã ở góc trên bên trái
- Đi thử tất cả 8 hướng đi và kiểm tra -> không có nước đi nào hợp lệ
  -> in ra màn hình " Không có nước đi hợp lệ"


---

## 5. Link video báo cáo
[Video báo cáo nhóm X](#)

---

## 6. Link source code
[Thư mục src](./src)

# Knight-sMoveProject
