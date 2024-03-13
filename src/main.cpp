#include <assert.h>
#include <iostream>

#include "bugfactory.h"

using namespace std;

int main()
{
    cout << "Start to make bugs!" << endl;

    auto bug = BugFactory::GetBug(kStackOverflow);
//     auto bug = BugFactory::GetBug(kHeapBufferOverflow);
//     auto bug = BugFactory::GetBug(kStackBufferOverflow);
//     auto bug = BugFactory::GetBug(kHeapUseAfterFree);
//     auto bug = BugFactory::GetBug(kStackUseAfterReturn);
//     auto bug = BugFactory::GetBug(kStackUseAfterScope);
//     auto bug = BugFactory::GetBug(kDoubleFree);
//     auto bug = BugFactory::GetBug(kMemoryLeaks);

    bug->DoWork();

    cout << "Stop to make bugs!" << endl;

    return 0;
}
