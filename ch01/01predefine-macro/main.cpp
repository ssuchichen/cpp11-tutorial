#include <iostream>
using namespace std;

const char* hello() {
    // const char* __func__ = "hello";
    return __func__; // 返回所在函数的名字
}
const char* world() {
    return __func__;
}

class TestStruct {
public:
    TestStruct() : m_name(__func__) {}
    const char* m_name;
};

// 替换省略号所代表的字符串
#define LOG(...) {\
    fprintf(stderr, "%s: LINE: %d\t", __FILE__, __LINE__);\
    fprintf(stderr, __VA_ARGS__);\
    fprintf(stderr, "\n");\
}

void foo(...) {}

int main() {
    // 编译器目标系统是否包含完整的标准C库
    cout << "standard clib: " <<  __STDC_HOSTED__ << endl;
    // 编译器的实现是否和标准C一致
    cout << "standard c: " << __STDC__ << endl;

#ifdef __APPLE__
    cout << "cpp threads: " << __STDCPP_THREADS__ << endl;
#else
    cout << "ISO/IEC" << __STDC_ISO_10646__ << endl;
#endif

    cout << hello() << " " << world() << endl;

    TestStruct s;
    cout << s.m_name << endl;

    LOG("ERROR");

    cout << __cplusplus << endl;
#if __cplusplus < 201103L
#error "should use C++11"
#endif


    return 0;
}
