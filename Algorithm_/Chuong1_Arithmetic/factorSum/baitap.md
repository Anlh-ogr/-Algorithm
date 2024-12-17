## `Bài tập`

Ta có một số nguyên dương `n`. Mỗi một lần thay thế `n` bằng tổng các thừa số nguyên tố[^1] của nó (ví dụ `12=2*2*3` thì `12` sẽ được thay thế bằng số `2+2+3=7`).

Áp dụng phép toán này vào số hiện tại cho đến khi kết quả thu được giống với số hiện tại. Cho một số tự nhiên, hãy tìm kết quả cuối cùng của phép toán trên.

**Ví dụ:**
- Với `n=24`, kết quả `factorSum(n) = 5`.
  `24 -> (2*2*2*3)=24 -> (2+2+2+3)=9 -> (3+3)=6 -> (2+3)=5 -> 5`.
  - Phân tích 24 thành thừa số nguyên tố:`24=2×2×2×3`.
    - Tổng các thừa số nguyên tố là:`2+2+2+3=9`.

  - Phân tích 9 thành thừa số nguyên tố:`9=3×3`.
    - Tổng các thừa số nguyên tố là:`3+3=6`.

  - Phân tích 6 thành thừa số nguyên tố:`6=2×3`.
    - Tổng các thừa số nguyên tố là:`2+3=5`.
  - 5 là số nguyên tố, nên dừng lại.
  Vì vậy kết quả trong trường hợp `n=24` là `5`.

**Đầu vào/Đầu ra**
- [Thời gian chạy] 0.5 giây
- [Đầu vào] Integer `n`
    * Điều kiện tiền đề: `2 ≤ n ≤ 10^9`.
- [Đầu ra] Integer

## Lý thuyết
Cách kiểm tra một số nguyên dương n có phải là số nguyên tố hay không?
- Nhận thấy rằng một số nguyên `n > 1` không phải là một số nguyên tố khi và chỉ khi `n` có thể biểu diễn dưới dạng: `n = x * y`, với `x,y` là hai số nguyên dương lớn hơn `1`.
  - Giả sử rằng `x<=y => x*x<=x*y=n => x<=√n`.
  - Từ nhận xét trên ta thấy rằng để kiểm tra xem n có chia hết cho một số nào nhỏ hơn nó hay không ta chỉ việc xét các số từ `2` đến `√n` thay vì xét các số từ `2` đến `n-1` như **isPrime**
  ```c++
    bool isPrime(int n) {
        if (n<=1) return false;
        for (int i = 2; i*i <= n; ++i)
            if (n % i == 0) return false;
        return true;
    }
  ```

- Độ phức tạp của thuật toán: `O(√n)`.


## Hướng dẫn bài tập.
- Phân tích thừa số nguyên tố
  - Dùng vòng lặp để chia số `𝑛` cho các số nguyên tố từ 2 trở đi.
  - Cộng các thừa số nguyên tố vào tổng.
- Kiểm tra số nguyên tố
  - Viết một hàm để kiểm tra xem một số có phải là số nguyên tố không.
  - Nếu tổng hiện tại là số nguyên tố, kết thúc thuật toán.
  - Nếu không, lặp lại quá trình.


[^1]: **Thừa số nguyên tố của một số** là những **số nguyên tố** khi nhân lại với nhau sẽ cho ra số ban đầu. 
[^2]: `Ước số của một số` là `số nguyên` mà khi chia số ban đầu cho nó sẽ không dư. Nói cách khác, nếu `𝑑` là ước số của `𝑛`, thì `𝑛 mod 𝑑=0` (`𝑛` chia hết cho `𝑑`)