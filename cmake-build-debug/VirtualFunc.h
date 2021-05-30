//
// Created by Illya on 2021/3/24.
//

#ifndef HEAVEN_VIRTUALFUNC_H
#define HEAVEN_VIRTUALFUNC_H
class base
{
public:
    virtual int fcn();
};
class D1 : public base
{
public:
    int fcn(int);
    virtual void f2();
};
class D2 : public D1
{
public:
    int fcn(int);
    int fcn();
    void f2();
};
#endif //HEAVEN_VIRTUALFUNC_H
