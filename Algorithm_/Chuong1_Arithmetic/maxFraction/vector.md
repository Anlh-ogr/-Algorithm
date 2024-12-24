## `Vector`

`std::vector` là một container trong thư viện **Standard Template Library (STL)** của C++, được sử dụng để quản lý các mảng động (dynamic arrays). Cung cấp nhiều tính năng mạnh mẽ hơn mảng thông thường, bao gồm khả năng tự động thay đổi kích thước, dễ dàng thêm/xóa phần tử, và tích hợp các thuật toán STL.

- **Khai báo-Sử dụng**
    ``` cpp
        #include "vector"

        std::vector<data_type> vector_name;
    ```

- **Khởi tạo giá trị**
    ``` cpp
        std::vector<int> v1; // vector rỗng
        std::vector<int> v2(5); // vector với 5 phần tử có giá trị mặc định (0)
        std::vector<int> v3(5, 1); // vector với 5 phần tử có giá trị 1
        std::vector<int> v4 = {1, 2, 3, 4, 5}; // vector với 5 phần tử có giá trị 1, 2, 3, 4, 5
    ```

- **Truy cập phần tử**
    ``` cpp
        #include "iostream"
        #include "vector"

        std::vector<int> v;
    ```
  
    **Thêm phần tử:**
  - `push_back(value):` thêm phần tử vào cuối vector.
    ``` cpp
        v.push_back(10);
        v.push_back(20);
    ```
        v = {10, 20};
  

  - `insert(position, value):` chèn phần tử vào vị trí cụ thể.
    ``` cpp
        v.insert(v.begin(), 5); // chèn 5 vào đầu vector
        v.insert(v.begin()+1, 15); // chèn 15 vào vị trí thứ 1
        v.insert(v.begin()+2, 11); // chèn 11 vào vị trí thứ 2
        v.insert(v.end(), 21); // chèn 21 vào cuối vector
    ```
        v = {5, 15, 11, 10, 20, 21};

    **Truy cập phần tử:**

  - `dùng chỉ số(index):` truy cập phần tử tại vị trí index.
    ``` cpp
        std::cout << v[0] << std::endl; // 5
        std::cout << v[1] << std::endl; // 15
        std::cout << v[2] << std::endl; // 11
    ```

  - `dùng at():` truy cập phần tử tại vị trí index (an toàn hơn)
    ``` cpp
        std::cout << v.at(0) << std::endl; // 5
        std::cout << v.at(1) << std::endl; // 15
        std::cout << v.at(2) << std::endl; // 11
    ```

  - `dùng front():` truy cập phần tử đầu tiên.
    ``` cpp
        std::cout << v.front() << std::endl; // 5
    ```

  - `dùng back():` truy cập phần tử cuối cùng.
    ``` cpp
        std::cout << v.back() << std::endl; // 21
    ```

    **Xóa phần tử:**
  - `pop_back():` xóa phần tử cuối cùng.
    ``` cpp
        v.pop_back();
    ```
        v = {5, 15, 11, 10, 20};

  - `erase(position):` xóa phần tử tại vị trí cụ thể.
    ``` cpp
        v.erase(v.begin()+1); // xóa phần tử thứ 1
    ```
        v = {5, 11, 10, 20};

  - `clear():` xóa tất cả phần tử.
    ``` cpp
        v.clear();
    ```
        v = {};


## `Luồng xử lý`
1. Quản lý bộ nhớ
    - Khi một` std::vector` được tạo, nó sẽ **cấp phát bộ nhớ**[^1] ban đầu đủ để chứa các phần tử.
    - Khi cần thêm phần tử và không còn đủ bộ nhớ, `std::vector` sẽ tự động cấp phát thêm bộ nhớ lớn hơn (thường là gấp đôi dung lượng hiện tại).

2. Tự động mở rộng
    - Khi vector mở rộng, các phần tử cũ được sao chép sang vùng nhớ mới. Điều này có thể gây tốn chi phí tính toán, nhưng nhờ tối ưu nội bộ, việc mở rộng không diễn ra thường xuyên.

3. Truy cập phần tử
    - Truy cập phần tử theo chỉ số có độ phức tạp **O(1)**, tương tự như mảng tĩnh.

4. Thêm/Xóa phần tử
    - Thêm hoặc xóa phần tử ở cuối có độ phức tạp **O(1)**.
    - Thêm hoặc xóa phần tử ở giữa hoặc đầu vector có độ phức tạp **O(1)** do cần dịch chuyển các phần tử còn lại.


## `Ưu điểm & nhược điểm`
**Ưu điểm**
    - Quản lý bộ nhớ tự động.
    - Cung cấp nhiều hàm tiện lợi (thêm, xóa, truy cập).
    - An toàn hơn mảng thông thường (có thể sử dụng `at()` để kiểm tra biên).

**Nhược điểm**
    - Hiệu suất có thể thấp hơn mảng thông thường trong một số trường hợp (do cấp phát bộ nhớ động và sao chép phần tử).
    - Khi thêm/xóa phần tử giữa vector, cần dịch chuyển các phần tử khác.

## `Khi nào nên sử dụng`
- Sử dụng `std::vector` khi cần quản lý mảng động, thêm/xóa phần tử thường xuyên, hoặc cần sử dụng các thuật toán STL.
- Sử dụng mảng thông thường khi cần hiệu suất cao, không cần thêm/xóa phần tử, hoặc không cần các tính năng của `std::vector`.

## `Thao tác với vector`
``` cpp
    #include "iostream"
    #include "vector"

    int main() {
        std::vector<int> numbers;

        numbers.push_back(1);
        numbers.push_back(2);
        numbers.push_back(3);

        std::cout<<"Size: ";
        for (int i=0; i<numbers.size(); ++i)
            std::cout<<numbers[i]<<" ";
        std::cout<<std::endl;


        std::cout<<"First element: "<<numbers.front()<<std::endl;
        std::cout<<"Last element: "<<numbers.back()<<std::endl;


        numbers.pop_back();
        std::cout<<"Size: ";
        for (int n : numbers)
            std::cout<<n<<" ";
        std::cout<<std::endl;

        return 0;
    }
```