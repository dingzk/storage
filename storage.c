//
// Created by zhenkai on 2020/8/13.
//

#include "storage.h"


void shm_startup(uint32_t size, char **err)
{
    int ret = shared_alloc_startup(size);
    if (ret == ALLOC_FAILURE) {
        *err = "alloc startup error";
    }

    return;
}

void *shm_alloc(uint32_t size)
{
    return zend_shared_alloc(size);
}

void shm_clear()
{
    zend_shared_clear();
}

void *shm_get_pointer()
{
    return zend_get_pointer();
}

void shm_destory()
{
    shared_alloc_shutdown();
}