// Cac khai niem co ban ve ly thuyet do thi
// Đơn đồ thị
// Đa đồ thị
// Giả đồ thị vô huóng

// Vô Hướng:

// 1. Đơn đồ thị vô hướng
/// G = <V,E>, gồm V là tập các đỉnh, E là tập các cặp không có thứ tự gồm hai phần từ khác nhau của V gọi là các cạnh
/// note : Các cặp cạnh "không có thứ tự", giữa đỉnh A và B chỉ có 1 cạnh

// 2. Đa đồ thị vô huóng
/// G = <V,E> :  Giưa hai đỉnh có thê tồn tại nhiều cặp cạnh
/// nếu chung cặp đỉnh thì gọi là cạnh "bội"

// 3. Giả đồ thị vô hướng(ít dùng)
/// G = <V,E> : cạnh không nhất thiết phải khác đỉnh
/// nếu cạnh bắt đầu bởi đỉnh đó và kết thúc bởi đỉnh đó thì gọi cạnh "khuyên"

// Có Hướng:

// 4. Đơn đồ thị có hướng
/// G = <V,E> : tập các cặp cạnh có thứ tự gồm hai phần tử V gọi là "cung"
/// note : Các ạnh có "thứ tự", giữa đỉnh A và B tồn tại một cạnh

// 5. Đa đồ thị có hướng
/// G = <V,E>: Giưa hai đỉnh có thể tồn tại các cặp cạnh có chung đỉnh
/// e1, e2 gọi là cung lặp

// 6. Đỉnh Kề và cạnh liên thuộc
/// Tồn tại cạnh nối giữa hai đỉnh ->  Đỉnh kề
/// Cạnh nỗi giữa hai đỉnh -> cạnh liên thuộc với hai đỉnh

// 7. Bậc của đỉnh trên đồ thị vô hướng(deg(...))*note : chỉ áp dụng với đồ thị vô hướng
/// Bậc của đỉnh: Số cạnh liên thuộc với đỉnh đó
/// deg(0) : đỉnh cô lập
/// dg(1) : đỉnh treo
/// đồ thị có M cạnh -> tổng các bậc 2*M

// 8. Bán bậc vào của đỉnh trên đồ thị có hướng
/// Bán bậc của đỉnh:
//// Bán bậc ra (deg+(...)): số cung từ đỉnh hiện tại có thể chạy sang được đỉnh khác
//// Bán bậc vào (deg-(...)): sô cung vào tại đỉnh hiện tại
/// tổng bán bậc ra  =  tổng bán bậc vào của các đỉnh và bằng số lượng cạnh

// 9. Đuòng đi
/// Dãy các đỉnh (dãy các cạnh) trong đó 2 đỉnh liên tiếp có cạnh nối
/// Đường đi đơn: Các đỉnh trên đường đi phân biệt
/// Độ dài là số cạnh rên đường đi

// 10. Chu trình
/// là đường đi gồm các "cạnh phân biệt" có đỉnh đầu trùng với đỉnh cuối
/// Chu trình đơn:  Các đinh != đỉnh đâu và cuối

// Note: Chi tồn tại trên đồ thị vô hướng
// 11. liên thông(note)
/// Giữa hai đỉnh bất kỳ luôn có đường đi

// 12. Thành phần liên thông(0 liên thông)
/// phân ra ...

// Note: Đồ thị có hướng
// 13. liên thông mạnh, yếu
/// liên thông mạnh:  Nếu giữa 2 đỉnh bất kỳ đó luôn có đường đi
/// liên thông yếu: đồ thị vô hướng tương úng