## `Bài tập`

Cho một danh sách các phân số, hãy tìm chỉ số của phân số lớn nhất (đếm từ 0).

Giả định rằng không có các phân số bằng nhau trong tập đầu vào.

**Ví dụ:**
- Với `numerators = [5, 2, 5]` và `denominators = [6, 3, 4]`, thì kết quả `maxFraction(numerators, denominators) = 2`. $\frac{5}{4}$ là phân số lớn nhất có chỉ số là 2.

Khi chạy hàm maxFraction(numerators, denominators), bước tính toán được hiểu là $\frac{numerators_i}{denominators_i}$, với {`i`=0,1,2,..,n}. Các phân số tương ứng là $\frac{5}{6}$, $\frac{2}{3}$, $\frac{5}{4}$. Kết luận $\frac{5}{4}$ là phân số lớn nhất trong danh sách nằm ở vị trí thứ 2.

**Đầu vào/Đầu ra:**
- [Thời gian chạy] 0.5 giây

- [Đầu vào] **array.integer numerators**

    Mảng các số nguyên thể hiện tử số của các phân số.
    Điều kiện: `2<=numerators.length<=10^5`, `1<=numerators[i]<=10^5`.

- [Đầu vào] **array.integer denominators**
 
    Mảng có cùng độ dài với `numerators`, thể hiện mẫu số của các phân số.
    Điều kiện: `denominators.length = numerators.length`, `1<=denominators[i]<=10^5`.

- [Đầu ra] **integer**
    Chỉ số của phân số lớn nhất (đếm từ 0).

## `Ý tưởng`
- Cách 1
  - Trước tiên lấy giá trị ở vị trí thứ `i` của `numerators` và `denominators` để tạo ra phân số $\frac{numerators[i]}{denominators[i]}$.
  - Sau đó lưu giá trị này vào 1 mảng rỗng và tương tự cho các phần tử còn lại.
  - Cuối cùng, duyệt mảng và so sánh các phân số với nhau để tìm ra phân số lớn nhất.
  - Cách 1 sẽ giúp bạn hiểu rõ hơn về cách thức hoạt động của phân số và cách so sánh chúng với nhau nhưng sẽ tốn thời gian hơn so với cách 2.

- Cách 2
  - Sử dụng công thức so sánh phân số để tìm ra phân số lớn nhất.
  - Để so sánh 2 phân số, ta chỉ cần so sánh `numerators[i]*denominators[j]` với `numerators[j]*denominators[i]` với `i!=j`. Nếu `numerators[i]*denominators[j]`> `numerators[j]*denominators[i]` thì phân số thứ `i` lớn hơn phân số thứ `j`.
  - Cách 2 sẽ giúp giảm thiểu số lần duyệt mảng và tìm ra phân số lớn nhất nhanh chóng hơn.

- Code mẫu:
    ``` cpp 
        int maxFraction(std::vector<int> numerators, std::vector<int> denominators) {
            int maxIndex=0;
            for (int i=1; i<numerators.size(); ++i)
                if (numerators[maxIndex]*denominators[i]>numerators[i]*denominators[maxIndex])
                    maxIndex=i;

            return maxIndex;
        } 
    ```

- Code mẫu này sử dụng thư viện vector để lưu trữ các phần tử của mảng. Duyệt mảng từ `i=1` đến `numerators.size()-1` và so sánh phân số tại vị trí `i` với phân số lớn nhất hiện tại. Nếu phân số tại vị trí `i` lớn hơn phân số lớn nhất hiện tại, ta cập nhật chỉ số của phân số lớn nhất hiện tại.

- Mô tả luồng xử lý:
  - numerators=[5, 2, 5]
  - denominators=[6, 3, 4]
  - maxIndex=0
  - duyệt mảng từ `i=1` đến `numerators.size()-1` để 


## `Lý thuyết`
- Phân số $\frac{a}{b}$ lớn hơn phân số $\frac{c}{d}$ khi và chỉ khi $\frac{(ad-bc)}{bd}$>0 .Nếu dữ kiện cho `a, b, c, d > 0`, thì để so sánh 2 phân số, ta chỉ cần so sánh `ad-bc` với `0` là được.
- **Ví dụ:** $\frac{2}{3}$ > $\frac{1}{2}$ vì $2*2-3*1=1>0$.
- `!` Tại sao không khai báo kiểu biến số thực rồi so sánh trực tiếp luôn?
    * Thực tế là, máy tính không thể tính toán chính xác được những phân số không hữu hạn. Nó sẽ làm tròn giá trị phân số đến 1 lượng chữ số thập phân nào đấy. Và sẽ có rủi ro phần lẻ khi bạn tính toán, so sánh các phân số với nhau.
    * Chỉ cần làm tròn khác đi 1 chút, thì 2 phân số bằng nhau cũng sẽ bị tính là khác biệt. Vậy nên, nếu dữ liệu không quá lớn, khuyến khích sử dụng phép toán so sánh ở cách trên.

- `?` Làm thế nào để so sánh nhanh chóng các phân số trong danh sách? 
    * Để so sánh nhanh chóng các phân số, ta chỉ cần so sánh `numerators[i]*denominators[j]` với `numerators[j]*denominators[i]` với `i!=j`. Nếu `numerators[i]*denominators[j]`> `numerators[j]*denominators[i]` thì phân số thứ `i` lớn hơn phân số thứ `j`.
    * Để tìm phân số lớn nhất, ta chỉ cần so sánh phân số lớn nhất hiện tại với phân số tiếp theo trong danh sách. Nếu phân số tiếp theo lớn hơn, ta cập nhật chỉ số của phân số lớn nhất hiện tại.

- `!` Lưu ý:
    * Để tránh trường hợp số nguyên quá lớn, ta nên sử dụng kiểu dữ liệu `long long` cho các biến số.

