//
// Created by zhenkai on 2020/8/13.
//

#ifndef KWFILTER_SHARED_STORAGE_H
#define KWFILTER_SHARED_STORAGE_H

#define MAP_SIZE 2047 * 1024 * 1024

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include "allocator/allocator.h"


void shm_startup(uint32_t size, char **err);

void *shm_alloc(uint32_t size);

void shm_clear();

void *shm_get_pointer();

void shm_destory();

#ifdef __cplusplus
}
#endif


#endif //KWFILTER_SHARED_STORAGE_H
