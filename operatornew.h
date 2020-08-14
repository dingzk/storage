//
// Created by zhenkai on 2020/8/10.
//

#ifndef KWFILTER_SHARED_ALLOCATOR_H
#define KWFILTER_SHARED_ALLOCATOR_H

#include <iostream>
#include <stdio.h>

extern void* operator new(std::size_t size, char* file, unsigned int line) throw(std::bad_alloc);
//extern void operator delete(void * pMemory) throw();
//
extern void* operator new[](std::size_t size, char* file, unsigned int line) throw(std::bad_alloc);
//extern void operator delete[](void * pMemory) throw();
//
extern void *operator new (std::size_t size, void * ptr, char* file, unsigned int line) throw();
//extern void operator delete(void * pMemory, void *ptr) throw();
//
extern void* operator new(std::size_t size, const std::nothrow_t& nt, char* file, unsigned int line) throw();
//extern void operator delete(void *pMemory, const std::nothrow_t&) throw();
//
extern void* operator new[](std::size_t size, const std::nothrow_t& nt, char* file, unsigned int line) throw();
//extern void operator delete[](void *pMemory, const std::nothrow_t&) throw();



#endif //KWFILTER_SHARED_ALLOCATOR_H
