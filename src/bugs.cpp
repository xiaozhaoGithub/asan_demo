#include "bugs.h"

#include <stdlib.h>
#include <string.h>

int* g_stack_ptr = nullptr;


void StackOverflowBug::DoWork()
{
    // 递归调用函数，无退出条件，栈空间不足，导致栈溢出
    int tmp = 10;
    DoWork();
}

void HeapBufferOverflowBug::DoWork()
{
    // 先分配32字节后，在heap_buf的第30个字节开始，拷贝8个字符
    char* heap_buf = (char*)malloc(32 * sizeof(char));
    memcpy(heap_buf + 30, "overflow", 8);

    free(heap_buf);
}

void StackBufferOverflowBug::DoWork()
{
    // 默认拷贝5字节，包括字符串默认'\0'
    char stack_buf[4] = {0};
    strcpy(stack_buf, "1234");
}

void HeapUseAfterFreeBug::DoWork()
{
    // 分配内存后释放，访问释放后的指针内容
    char* p = (char*)malloc(32 * sizeof(char));
    free(p);

    int aaa = *p;
}

void StackUseAfterReturnBug::DoWork()
{
    // 访问已释放的栈地址内存
    CreateStackPointer();

    int num = *g_stack_ptr;
}

void StackUseAfterReturnBug::CreateStackPointer()
{
    int local[10] = {1};
    local[1] = 100;
    g_stack_ptr = &local[1];

    return;
}

void StackUseAfterScopeBug::DoWork()
{
    // 访问离开作用域已被释放的变量
    int* p = nullptr;
    {
        int val = 10;
        p = &val;
    }

    int num = *p;
}

void DoubleFreeBug::DoWork()
{
    // 重复释放同一指针
    char* p = (char*)malloc(32 * sizeof(char));
    free(p);
    free(p);
}

void MemoryLeaksBug::DoWork()
{
    // 申请 40字节，未释放，导致内存泄漏
    for (int i = 0; i < 10; ++i) {
        int* p = AllocBuffer();
        // do something...

        // forget to delete
    }
}

int* MemoryLeaksBug::AllocBuffer()
{
    int* p = new int;
    return p;
}
