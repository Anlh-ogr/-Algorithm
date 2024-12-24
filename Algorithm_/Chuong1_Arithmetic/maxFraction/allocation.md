## `Cấp phát bộ nhớ`

1.`Static Allocation:`
- Bộ nhớ được cấp phát tại **thời điểm biên dịch** và nằm trên **stack**.
- Kích thước cố định và không thay đổi.

``` cpp
    int arr[5];
```

2.`Dynamic Allocation:`
- Bộ nhớ được cấp phát tại **thời điểm chạy** (runtime) và nằm trên **heap**.
- Sử dụng toán tử **new** để cấp và **delete** để giải phóng.
- Thay đổi kích thước linh hoạt.

``` cpp
    int *arr = new int[5];
    delete[] arr; // giải phóng bộ nhớ.
```

`Cách cấp phát bộ nhớ:`
- Cấp phát cho một biến
``` cpp
    int *ptr = new int;
    *ptr = 42; // gán giá trị
```

- Cấp phát cho mảng
``` cpp
    int* arr = new int[5]; // Cấp phát mảng động với 5 phần tử
    arr[0] = 1; // Truy cập phần tử
```

`Cách giải phóng bộ nhớ`
- Giải phóng biến động:
``` cpp
    delete ptr;
```
- Giải phóng mảng động:
``` cpp
    delete[] arr;
```