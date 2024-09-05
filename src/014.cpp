// https://mp.weixin.qq.com/s?__biz=MzkzMTY3NDYwNQ==&mid=2247484505&idx=1&sn=22e833f9954358e0484762e8826d4781&chksm=c26624dbf511adcd0c5159a5b47c7f59f6e48c8f2520b0aa9b03b21d651ded3bd236e9d5bd52&cur_album_id=3386784075163844618&scene=189#wechat_redirect
#include <array>
#include <iostream>

// 1. 编译时计算数组大小
constexpr auto computeSize(int maxVal) {
    return [=] (int threshold) constexpr {
        int count = 0;
        for(int i = 0; i <= maxVal; ++i) {
            if(i % threshold == 0) ++count;
        }
        return count;
    };
}

// 使用constexpr lambda计算满足条件的数字数量，并据此初始化数组
constexpr auto sizeCalculator = computeSize(100);
constexpr std::size_t arraySize = sizeCalculator(10); // 编译时计算
std::array<int, arraySize> numbers; // 编译时确定数组大小


// 2.用于元编程构造
// template<typename T, typename Func>
// constexpr auto generateTuple(Func func, std::size_t N) {
//     return [&func, N] () constexpr {
//         std::tuple<T, T, ..., T> tuple{}; // 假设有N个T，C++17并不直接支持变长模板，此处仅为示意
//         for(std::size_t i = 0; i < N; ++i) {
//             std::get<i>(tuple) = func(i);
//         }
//         return tuple;
//     };
// }

// // 使用constexpr lambda生成一个包含5个由索引计算得到的值的tuple
// constexpr auto createTuple = generateTuple<int>([](int index) { return index * index; }, 5);
// // 注意：上述代码中直接生成变长tuple的语法是错误的，实际应用中可能需要借助其他技术如递归模板等实现


int main() {
    std::cout<<numbers.size()<<std::endl;
    std::cout<<numbers.max_size()<<std::endl;
    return 0;
}