#ifndef ABSTRACTBUG_H
#define ABSTRACTBUG_H

class AbstractBug
{
public:
    AbstractBug() = default;
    virtual ~AbstractBug() {}

    virtual void DoWork() = 0;
};

#endif // ABSTRACTBUG_H
