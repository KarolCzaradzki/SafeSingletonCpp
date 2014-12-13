SafeSingletonCpp
================

This is thread-safe c++ 11 singleton implementation.
It can be used without any limitation.

Usage:

class MyClass : public Singleton<MyClass>{
public:
    void myMethod();
};

MyClass::instance()->myMethod();
