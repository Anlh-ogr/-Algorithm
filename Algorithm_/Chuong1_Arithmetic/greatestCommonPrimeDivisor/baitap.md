## `Bài tập`
GCPD (Greatest Common Prime Divisor) được định nghĩa là số nguyên tố lớn nhất là `ước của các số nguyên dương`[^1] [^2] [^3] cho trước. Nhiệm vụ là tìm GCPD của hai số nguyên `a` và `b`.

**Ví dụ**
- Với `a=12` và `b=18`, đầu ra là `greatestCommonPrimeDivisor(a, b) = 3`.
- Với `a=12` và `b=13`, đầu ra là `greatestCommonPrimeDivisor(a, b) = -1`.

**Đầu vào/Đầu ra**
- [Thời gian chạy] 0.5 giây
- [Đầu vào] Integer `a`, `b`
    * Điều kiện:
    * `2 ≤ a, b ≤ 10^6`.
- [Đầu ra] Integer
    * GCPD của `a` và `b` hoặc `-1` nếu không tồn tại.

## `Lý thuyết`
**Sàng nguyên tố Eratosthenes**
- Tư tưởng của phương pháp trên là ta sẽ tìm mọi số nguyên tố có giá trị bé hơn hoặc bằng n. Từ đó có thể kết luật được số n có phải là một số nguyên tố hay không?
- Thuật toán được miêu tả như sau:
  1. Lập một danh sách các số liên tiếp từ `2` đến `n`.
  2. Bước đầu tiên ta đặt số `a=2` (là số nguyên tố đầu tiên).
  3. Lần lượt đánh dấu các số `a*a, a*(a+1), a*(a+2),...` có trong danh sách đã tạo trước. Nếu như `a*a > n` thì kết thúc thuật toán.
  4. Tìm số đầu tiên lớn hơn `a` chưa được đánh dấu trong danh sách. Nếu không tìm thấy thì kết thúc thuật toán, ngược lại, gán `a` bằng số đó và lặp lại bước 3.
- Ví dụ minh họa:
  - Một danh sách các số từ `2` đến `20`:
    |   | 2 | 3 | 4 | 5 |
    |---|---|---|---|---|
    | 6 | 7 | 8 | 9 |10 |
    |11 |12 |13 |14 |15 |
    |16 |17 |18 |19 |20 |

**`Step 1`**
  - Bước 2: `a=2`
  - Bước 3: đánh dấu các số `4, 6, 8, 10, 12, 14, 16, 18, 20`
    (vì 2 * 2=4, 2 * 3=6, 2 * 4=8, 2 * 5=10, 2 * 6=12, 2 * 7=14, 2 * 8=16, 2 * 9=18, 2 * 10=20). Được bảng sau:
    |     |  2  |  3  | `4` |  5  |
    |-----|-----|-----|-----|-----|
    | `6` |  7  | `8` |  9  |`10` |
    | 11  |`12` | 13  |`14` | 15  |
    |`16` | 17  |`18` | 19  |`20` |

    - Vì gán `a=2`, các số được đánh dấu là `a*a, a*(a+1), a*(a+2),...`, nhưng khi (a+1)=11 thì `a*(a+1)=2*11 > 20` nên kết thúc bước 3.
  - Bước 4: tìm số đầu tiên lớn hơn `a=2` chưa được đánh dấu, đó là `3`. Gán `a=3`

**`Step 2`**
  - Bước 2: `a=3`
  - Bước 3: đánh dấu các số `9, 15`
    (vì 3 * 3=9, 3 * 5=15). Được bảng sau:
    |     |  2  |  3  |  4  |  5  |
    |-----|-----|-----|-----|-----|
    |  6  |  7  |  8  | `9` | 10  |
    | 11  | 12  | 13  | 14  |`15` |
    | 16  | 17  | 18  | 19  | 20  |

    - Vì gán `a=3`, các số được đánh dấu là `a*a, a*(a+1), a*(a+2),...`, nhưng khi (a+1)=6 thì `a*(a+1)=3*6 > 20` nên kết thúc bước 3.
  - Bước 4: tìm số đầu tiên lớn hơn `a=3` chưa được đánh dấu, đó là `5`. Gán `a=5`
    |     |  2  |  3  | `4` |  5  |
    |-----|-----|-----|-----|-----|
    | `6` |  7  | `8` | `9` |`10` |
    | 11  |`12` | 13  |`14` |`15` |
    |`16` | 17  |`18` | 19  |`20` |

**`Step 3`**
  - Bước 2: `a=5`
  - Bước 3: không có số nào được đánh dấu.
    (vì 5 * 5=25 > 20). Kết thúc bước 3.
  - Bước 4: không tìm thấy số nào lớn hơn `a=5` chưa được đánh dấu. Kết thúc thuật toán.


**`Kết luận`**
  - Bảng thu được sau khi kết thúc thuật toán:
    |     |  2  |  3  | `4` |  5  |
    |-----|-----|-----|-----|-----|
    | `6` |  7  | `8` | `9` |`10` |
    | 11  |`12` | 13  |`14` |`15` |
    |`16` | 17  |`18` | 19  |`20` |
  - Các số trong bảng không được đánh dấu là các số nguyên tố nhỏ hơn hoặc bằng `20` là `2, 3, 5, 7, 11, 13, 17, 19`.


## `Giả sử` 
cho một số nguyên dương n(n<=10^6), hãy đánh dấu tất cả các số nguyên tố trong phạm vi 2->n.

`Ý tưởng`:
- Từ định nghĩa của số nguyên tố, có thể nghĩ đến việc duyệt tất cả các số từ 2 đến n. Nếu n chia hết cho bất cứ số nào nghĩa là n không phải số nguyên tố. Độ phức tạp là O(n).
  ``` cpp
  bool isPrime (int num) {
    for (int i=2; i<num; ++i)
      if (num % i == 0) return false;
    return true;
  }

  int main () {
    int n; std::cin>>n;
    for (int i=2; i<=n; ++i)
      if(!isPrime(i)) mark[i]=1;

    return 0;
  }
  ```
  
  * Nếu n không phải là số nguyên tố thì tồn tại một ước nguyên tố của n nhỏ hơn hoặc bằng √n
  * Giả sử n không phải là số nguyên tố mà các ước của nó đều lớn hơn √n, thì tích của hai ước bất kì sẽ lớn hơn n (vô lý).

- Thay vì phải duyệt tất cả từ 2->n, chỉ cần duyệt các ước đến √n để kiểm tra n có phải số nguyên tố không. Độ phức tạp là O(√n).
  ``` cpp
  bool isPrime (int num) {
    for (int i=2; i*i<=num; ++i)
      if (num % i == 0) return false;
    return true;
  }
  ```

  * Trong đoạn code trên, thấy rằng vòng for loop sử dụng là `i*i<=num` thay vì `i<=√num`?
  * Vì nếu sử dụng `i<=√num` thì tại mỗi vòng lặp của for, máy tính phải tính lại giá trị của √num -> làm cho thuật toán chậm hơn.
  * Nên sử dụng `i*i<=num` để tránh việc tính lại giá trị của √num.
  * Kinh nghiệm khi code. Thay vì viết `i<=n/j` nên thay bằng `i*j<=n`.

- Phương pháp trên chỉ giúp kiểm tra một số có phải là số nguyên tố hay không. Để tìm tất cả các số nguyên tố trong phạm vi 2->n, ta cần sử dụng **sàng nguyên tố Eratosthenes**.
  ``` cpp
  bool mark[1+1e6]; // tạo mảng để đánh dấu

  void sieve (int n) {
    for (int i=2; i*i<=n; ++i)
      if (!mark[i])
        for (int j=i*i; j<=n; j+=i)
          mark[j]=1;
  }

  int main () {
    int n; std::cin>>n;
    sieve(n);
    for (int i=2; i<=n; ++i)
      if (!mark[i]) std::cout<<i<<" ";
    return 0;
  }
  ```
    * Khi i=2 vòng lặp j lặp lại $\frac{n}{2}$ lần.
    * Khi i=3 vòng lặp j lặp lại $\frac{n}{3}$ lần.
    * Khi i=5 vòng lặp j lặp lại $\frac{n}{5}$ lần.
    * ...

  - Tổng số lần lặp của vòng for loop là $\frac{n}{2} + \frac{n}{3} + \frac{n}{5} + ... = n(\frac{1}{2} + \frac{1}{3} + \frac{1}{5} + ...) = n(1 + \frac{1}{2} + \frac{1}{3} + \frac{1}{4} + ...) = n*log(log_n)$.
  - Độ phức tạp của thuật toán là O(n*log(log_n)).


[^1]: `Ước của các số nguyên dương` là các số nguyên dương có thể chia số đó mà không dư. Nói cách khác, nếu `𝑑` là một ước của `𝑛`, thì `𝑛 mod 𝑑=0`.
[^2]: Ex ước của 6 là các số có thể chia 6 mà không dư là 1, 2, 3, 6. Ước của 6 là `{1, 2, 3, 6}`.
[^3]: Để tìm ước của một số `𝑛`, chỉ cần kiểm tra các số từ `1 - √𝑛`. Nếu Nếu `𝑖` chia hết `𝑛`, thì `𝑖` và $\frac{𝑛}{𝑖}$ đều là các ước.