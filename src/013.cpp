// https://mp.weixin.qq.com/s?__biz=MzkzMTY3NDYwNQ==&mid=2247484509&idx=1&sn=f1b62483c64e402128a9845f33a03a9b&chksm=c26624dff511adc9140ae44b8ea10a5d658a71212513be2d832073f21766612e2f927776129d&cur_album_id=3386784075163844618&scene=189#wechat_redirect
#include <functional>
#include <cstdio>
#include <iostream>
#include <iomanip>

#include <algorithm>
#include <vector>
#include <iostream>


void foo(int a, int b, int c) {
    std::cout << a << ", " << b << ", " << c << std::endl;
}

bool is_even(int n) {
    return n % 2 == 0;
}

int main() {
    auto boundFoo = std::bind(foo, 1, std::placeholders::_1, std::placeholders::_2);
    
    // 后续调用时，只需要提供剩余的参数
    boundFoo(2, 3);  // 输出: 1, 2, 3

    int num = 42;
    double pi = 3.14159;
    printf("Number: %d, Pi: %.2f\n", num, pi);
    std::cout << "Number: " << num << ", Pi: " << std::fixed << std::setprecision(2) << pi << std::endl;


    std::vector<int> numbers = {1, 2, 3, 4, 5, 6};
    auto it = std::find_if(numbers.begin(), numbers.end(), is_even);
    if(it != numbers.end())
        std::cout << "First even number is: " << *it << std::endl;


    
    auto add = [](int x, int y) { return x + y; };
    std::cout << "Sum: " << add(3, 4) << std::endl;


    return 0;
}