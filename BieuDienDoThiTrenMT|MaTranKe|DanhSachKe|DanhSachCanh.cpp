// Biểu Diễn Trên MT

// Ma Tran ke
// Đồ thị vô hướng:
/// có n đỉnh là ma tran vuông cỡ n x n
/// n, m: số đỉnh, số cạnh (đỉnh 1 -> n)
/// có các ph/tu 0 hoặc 1. A = {a[i][j], a[i][j] = 1 nếu cạnh (i,j) là một cạnh cảu đổ thị, a[i][j] = 0 nếu ko là cạnh của đồ thị}
/// Tính Chất: "La ma tran đối xứng", tổng các phần tử trên ma trận bằng 2 lần số cạnh, tổng các phần tử trên hàng hoặc trên cột thứ u
/// là bậc của đỉnh u
/// VD: 6x6
///   1 2 3 4 5 6 | a[i][j] = a[j][i] = 1;
/// 1 0 1 1 1 0 0
/// 2 1 0 0 1 0 0
/// 3 1 0 0 0 1 1
/// 4 1 1 1 0 0 1
/// 5 0 0 1 0 0 1
/// 6 0 0 1 1 1 0

// Đồ thị có hướng
/// có n đỉnh -> mt vuông cỡ n x n
/// các ph/tu la 0 hoặc 1. A = {a[i][j], a[i][j] = 1 nếu là cạnh của đồ thị, a[i][j] = 0 ko là cạnh của đồ thị}
/// Tính chất: Có thể ko đối xứng
/// Tổng các ph/tu cua ma tran bằng số cạnh
/// Tổng các ph/tu hang thứ u là bán bậc ra của đỉnh u
/// Tổng các ph/tu cột thứ u là bán bậc vào cảu đỉnh u
/// VD: 6x6
///   1 2 3 4 5 6 | a[i][j] = 1
/// 1 0 1 1 1 0 0
/// 2 0 0 0 1 0 0
/// 3 0 0 0 1 1 1
/// 4 0 0 0 0 0 1
/// 5 0 0 0 0 0 1
/// 6 0 0 0 0 0 0
/// => Ưu điểm : Đơn giản dễ cài đặt, dễ dàng kiểm tra hai đỉnh có kề nhau hay không O(1) bằng cách kiểm tra  g/tri của a[i][j]
///    Nhược điểm: Tốn bộ nhớ, ko thể biểu diễn đc đồ thị với số đỉnh lớn

// Ma Tran Trong so
///  Mỗi canh của đồ thị có các trọng số, tương tư thay vì gán a[i][j] = 1 la cạnh thì ta thay trọng số của các cạnh, ko thuộc a[i][j] = 0 hoặc vô cùng hoặc âm vô cùng

// Danh Sach Canh
/// Thường được biểu diễn khi đồ thị thưa (số cạnh <= 6 lần số đỉnh)
// Đồ thị vô hướng:
// ko trọng số
/// Nếu tồn tại cạnh giữa hai đỉnh u, v. ->  liệt kê cạnh (u,v) ko  cần liệt kê cạnh (v,u) -> usualy pick u < v
/// Liệt kê thứ tự tăng dần đỉnh đầu của các cạnh
/// Đồ thị có hướng:
/// Mỗi cạnh là bộ có tính đến thứ tự của các đỉnh
/// VD: dùng pair<int, int>
/// Đỉnh đầu | Đỉnh cuối
///     1       2
///     1       3
///     1       4
///     2       4
///     3       4
///     3       4
// Có Trọng số
/// Mỗi cạnh sẽ cố thêm trọng số đi kèm đỉnh đầu và đỉnh cuối
///  Dùng tuple hoặc struct như sau: struct edge{
///                                        int dau, cuot, w;
/// }
/// VD:
///  Đỉnh đầu | Đỉnh cuối | Trọng số
///      1       2           5
///      1       3           4
///      1       4           2
///      2       4           8
///      3       4           1
///      3       4           6
// Đồ thị có hướng; => thì chú ý tới hướng của cạnh tượng nếu có trọng số
/// => Ưu điểm: Tiết Kiệm được bộ nhớ nếu đồ thị thưa, Thuận lợi cho cac bài toán chỉ liên quan tới cạnh của đồ thị
/// Nhược điểm: Khi cần duyệt các đỉnh kề với đỉnh đó, bắt buộc phải duyệt tất cả các cạnh -> chi phí tính toán lớn

// Note :
// Danh Sách kề:
/// Đối với đỉnh u, ta lưa trữ danh sách các đỉnh kề với u. C++ ta dùng Vector
/// VD:
/// vector<int> adj[1001]; hoặc vector các vector : vector<vector<int>> adj;
/// Đỉnh |  Danh Sách Kề
/// 1           {2,3,4}
/// 2           {1,4}
/// 3           {1,4,5,6}
//.....
