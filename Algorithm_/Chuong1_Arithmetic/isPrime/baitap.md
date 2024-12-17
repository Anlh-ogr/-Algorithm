## `Bài tập`
Một số nguyên tố là một số tự nhiên lớn hơn `1` và không thể tạo thành từ tích của hai số tự nhiên nhỏ hơn.

Ví dụ số `2, 3, 5` được gọi là số nguyên tố. Viết một hàm xác định xem một số nguyên dương đã cho có phải là số nguyên tố hay không.

**Ví dụ**
- Với `n = 47`, kết quả `isPrime(n) = true`.
- Với `n = 4`, kết quả `isPrime(n) = false`.

**Đầu vào/Đầu ra**
- [Giới hạn thời gian chạy] 0.5 giây
- [Đầu vào] Integer `n`
    * Điều kiện tiền đề: `0 ≤ n ≤ 10^9`.
- [Đầu ra] Boolean
    * `true` nếu `n` là số nguyên tố, `false` nếu không phải.

**Gợi ý**
- Kiểm tra xem `n` có chia hết cho số nào trong khoảng từ `2` đến `căn bậc hai của n`-`sqrt(n)` không? Nếu không thì `n` là số nguyên tố, ngược lại tức là `n` không phải là số nguyên tố.


## Lý thuyết
Cách kiểm tra một số có phải là số nguyên dương n có phải là số nguyên tố hay không?

- Lần lượt xét các số từ `2` đến `n-1`
  [^1], và kiểm tra xem số nguyên tố đó có phải là **ước của n** [^2] không? Nếu là ước của n thì `return false`, ngược lại `return true`.
- Code hàm:
  ```c++
    bool isPrime(int n) {
        if (n<=1) return false;
        for (int i = 2; i < n; ++i)
            if (n % i == 0) return false;
        return true;
    }
  ```
- Độ phức tạp của thuật toán: `O(n)` [^3] [^4].


[^1]: Khi n=7 -> xét: {2,3,4,5,6} 
[^2]: **Ước của một số** là một số nguyên chia hết số đó mà không dư. Nói cách khác, nếu `𝑎` là ước của `𝑛`, thì tồn tại một số nguyên `𝑘` sao cho `𝑛=𝑎×𝑘`. 
[^3]: Độ phức tạp thời gian `Time Complexity` cho biết thời gian thực hiện thuật toán tăng lên như thế nào khi kích thước đầu vào `n` tăng.
[^4]: Kí hiệu `O(n)` cho biết thuật toán có **độ phức tạp tỷ lệ tuyến tính với kích thước đầu vào** `n`. Nếu đầu vào tăng gấp đôi thì thời gian thực hiện thuật toán cũng tăng gấp đôi. Nếu đầu vào là 100 phần tử, thời gian thực thi sẽ mất khoảng`𝑘×100`đơn vị thời gian.