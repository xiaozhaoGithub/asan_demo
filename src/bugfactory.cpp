#include "bugfactory.h"

std::unordered_map<uint32_t, std::shared_ptr<AbstractBug>> BugFactory::bugs_;

BugFactory::BugFactory() {}

std::shared_ptr<AbstractBug> BugFactory::GetBug(uint32_t type)
{
    auto iter = bugs_.find(type);
    if (iter != bugs_.end()) {
        return bugs_[type];
    }

    bugs_[type] = CreateBug(type);

    return bugs_[type];
}

std::shared_ptr<AbstractBug> BugFactory::CreateBug(uint32_t type)
{
    std::shared_ptr<AbstractBug> bug;
    switch (type) {
    case kStackOverflow:
        bug = std::make_shared<StackOverflowBug>();
        break;
    case kHeapBufferOverflow:
        bug = std::make_shared<HeapBufferOverflowBug>();
        break;
    case kStackBufferOverflow:
        bug = std::make_shared<StackBufferOverflowBug>();
        break;
    case kHeapUseAfterFree:
        bug = std::make_shared<HeapUseAfterFreeBug>();
        break;
    case kStackUseAfterReturn:
        bug = std::make_shared<StackUseAfterReturnBug>();
        break;
    case kStackUseAfterScope:
        bug = std::make_shared<StackUseAfterScopeBug>();
        break;
    case kDoubleFree:
        bug = std::make_shared<DoubleFreeBug>();
        break;
    case kMemoryLeaks:
        bug = std::make_shared<MemoryLeaksBug>();
        break;
    default:
        break;
    }

    return bug;
}
