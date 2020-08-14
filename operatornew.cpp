//
// Created by zhenkai on 2020/8/10.
//

#include "operatornew.h"
#include <iostream>
#include <stdlib.h>

#include <new>

void* operator new(std::size_t size, char* file, unsigned int line) throw(std::bad_alloc)
{
#ifdef DEBUG
    std::cout << "operator new with throw(std::bad_alloc)" << " size:" << size << " file:" << file << " line:" << line << std::endl;
#endif

    return ::operator new(size);
}

void* operator new[](std::size_t size, char* file, unsigned int line) throw(std::bad_alloc)
{
#ifdef DEBUG
    std::cout << "operator new[] with throw(std::bad_alloc)" << " size:" << size << " file:" << file << " line:" << line << std::endl;
#endif

    return ::operator new[](size);
}

//void operator delete(void * pMemory, char* file, unsigned int line) throw()
//{
//#ifdef DEBUG
//    std::cout << "operator delete with throw() 987" << std::endl;
//#endif
//
//    ::operator delete(pMemory);
//}
//
//void operator delete[](void * pMemory, char* file, unsigned int line) throw()
//{
//#ifdef DEBUG
//    std::cout << "operator delete[] with throw()" << std::endl;
//#endif
//
//    ::operator delete(pMemory);
//}

void *operator new (std::size_t size, void * ptr, char* file, unsigned int line) throw()
{
#ifdef DEBUG
    std::cout << "operator placement new with throw()" << " size:" << size << " file:" << file << " line:" << line<< std::endl;
#endif

    return ::operator new(size, ptr);
}

/**
 * The call to the class-specific T::operator delete on a polymorphic class is the only case where a static member function is called through dynamic dispatch.
 * https://en.cppreference.com/w/cpp/memory/new/operator_delete
 * @param pMemory
 * @param ptr
 */

//void operator delete(void * pMemory, void *ptr, char* file, unsigned int line) throw()
//{
//#ifdef DEBUG
//    std::cout << "operator placement delete with throw()" << std::endl;
//#endif
//
//    ::operator delete(pMemory, ptr);
//}

void* operator new(std::size_t size, const std::nothrow_t& nt, char* file, unsigned int line) throw()
{
#ifdef DEBUG
    std::cout << "operator new with throw()"  << " size:" << size << " file:" << file << " line:" << line << std::endl;
#endif

    return ::operator new(size, nt);
}

void* operator new[](std::size_t size, const std::nothrow_t& nt, char* file, unsigned int line) throw()
{
#ifdef DEBUG
    std::cout << "operator new[] with throw()"  << " size:" << size << " file:" << file << " line:" << line << std::endl;
#endif

    return ::operator new[](size, nt);
}

//void operator delete(void *pMemory, const std::nothrow_t&, char* file, unsigned int line) throw()
//{
//#ifdef DEBUG
//    std::cout << "operator delete with throw() 123" << std::endl;
//#endif
//
//    ::operator delete(pMemory);
//}

//void operator delete[](void *pMemory, const std::nothrow_t&, char* file, unsigned int line) throw()
//{
//#ifdef DEBUG
//    std::cout << "operator delete[] with throw()" << std::endl;
//#endif
//
//    ::operator delete(pMemory);
//}

#ifdef DEBUG
//#define new new(__FILE__, __LINE__)
#define new(x) new(x, __FILE__, __LINE__)
#endif

#ifdef TEST

int main()
{
    char *p1 = new (std::nothrow)int[20];
    char *p2 = new (std::nothrow)int;
    char *p3 = new char;

    delete[] p1;
    delete p2;

    return 0;
}
#endif