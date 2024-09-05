// https://mp.weixin.qq.com/s?__biz=MzkzMTY3NDYwNQ==&mid=2247484608&idx=1&sn=ca805b1366b2bd4f5903cbb7e426cb1b&chksm=c2662442f511ad54ad2b535925dd76b3f569ec977d346bd1abac2b260f814c9322b95ad85aa7&cur_album_id=3386784075163844618&scene=189&poc_token=HFZI2WajA3a4XwdKZvV-ubQRDzMXPYzxS_iYKrhL
#include <cstdlib>
#include <cstdio>
#include <cstdarg> // 包含处理变长参数的头文件

struct __attribute__((aligned(16))) AlignedStruct {
    int a;
    double b;
};


struct __attribute__((packed)) PackedStruct {
    char a;
    int b;
};


__attribute__((deprecated)) void old_function() {
    // 旧函数实现
}

__attribute__((noreturn)) void exit_program() {
    std::exit(1);
}

void __attribute__((unused)) unused_function() {
    // 此函数未使用
}
inline void __attribute__((always_inline)) inline_function() {
    // 内联函数实现
}

void __attribute__((format(printf, 1, 2))) my_printf(const char* format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

int main() {
    AlignedStruct s1;
    // s1 现在被 16 字节对齐

    PackedStruct s2;
    // s2 现在是紧凑排列的，没有填充字节

    old_function(); // 使用时会产生编译警告

    exit_program(); // 编译器知道此函数不会返回
    // 这里的代码永远不会执行

    int __attribute__((unused)) unused_variable;
    // 这里 unused_function 和 unused_variable 不会引发编译警告

    inline_function(); // 此函数将始终内联

    my_printf("%s %d\n", "Number:", 42); // 编译器将检查格式字符串和参数
    return 0;
}