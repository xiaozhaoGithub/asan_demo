#ifndef BUGFACTORY_H_
#define BUGFACTORY_H_

#include <memory>
#include <unordered_map>

#include "bugs.h"

enum BugType
{
    kStackOverflow,
    kHeapBufferOverflow,
    kStackBufferOverflow,
    kHeapUseAfterFree,
    kStackUseAfterReturn,
    kStackUseAfterScope,
    kDoubleFree,
    kMemoryLeaks,
};

// simple pattern + flyweight pattern
class BugFactory
{
public:
    BugFactory();

    static std::shared_ptr<AbstractBug> GetBug(uint32_t type);

private:
    static std::shared_ptr<AbstractBug> CreateBug(uint32_t type);

private:
    static std::unordered_map<uint32_t, std::shared_ptr<AbstractBug>> bugs_;
};

#endif // BUGFACTORY_H_
