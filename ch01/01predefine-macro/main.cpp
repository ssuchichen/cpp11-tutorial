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

int main() {
    // 编译器目标系统是否包含完整的标准C库
    cout << "standard clib: " <<  __STDC_HOSTED__ << endl;
    // 编译器的实现是否和标准C一致
    cout << "standard c: " << __STDC__ << endl;
    cout << "ISO/IEC" << __STDC_ISO_10646__ << endl;

    cout << hello() << " " << world() << endl;
    TestStruct s;
    cout << s.m_name << endl;

    return 0;
}
