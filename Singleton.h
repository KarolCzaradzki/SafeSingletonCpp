/*
 * Free to use, sell, modify, copy and any other thing you want to do with it.
 * CppExtensions.h provides std::make_unique implementation which is included
 * in c++ 14 standard.
 *
 * Author: Karol Czaradzki
 */

#ifndef __SolvedIOS__Singleton__
#define __SolvedIOS__Singleton__

#include <stdlib.h>
#include <stdio.h>
#include <thread>
#include <mutex>

#include "CppExtensions.h"

template <typename T>
class Singleton{
private:
    static std::unique_ptr<T> instance_;
    static std::mutex instanceLock;
    
public:
    virtual ~Singleton() = default;
    
    static T* instance();
    static void end();
};

template <typename T>
std::unique_ptr<T> Singleton<T>::instance_;

template <typename T>
std::mutex Singleton<T>::instanceLock;

template <typename T>
T* Singleton<T>::instance()
{
    if(!instance_)
    {
        std::lock_guard<std::mutex> lock(instanceLock);
        if(!instance_)
        {
            instance_ = std::make_unique<T>();
            return instance_.get();
        }
    }
    return instance_.get();
}

template <typename T>
void Singleton<T>::end()
{
    std::lock_guard<std::mutex> lock(instanceLock);
    if(instance_)
    {
        instance_ = new T;
        return instance_;
    }
}



#endif /* defined(__SolvedIOS__Singleton__) */
