#ifndef BUGS_H
#define BUGS_H

#include "abstractbug.h"

class StackOverflowBug : public AbstractBug
{
public:
    void DoWork() override;
};

class HeapBufferOverflowBug : public AbstractBug
{
public:
    void DoWork() override;
};

class StackBufferOverflowBug : public AbstractBug
{
public:
    void DoWork() override;
};

class HeapUseAfterFreeBug : public AbstractBug
{
public:
    void DoWork() override;
};

class StackUseAfterReturnBug : public AbstractBug
{
public:
    void DoWork() override;

private:
    void CreateStackPointer();
};

class StackUseAfterScopeBug : public AbstractBug
{
public:
    void DoWork() override;
};

class DoubleFreeBug : public AbstractBug
{
public:
    void DoWork() override;
};

class MemoryLeaksBug : public AbstractBug
{
public:
    void DoWork() override;

private:
    int* AllocBuffer();
};


#endif // BUGS_H
