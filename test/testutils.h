#include <assert.h>
#include <stdio.h>


#define RUNTEST(x) \
    printf("[ RUN ] %s -> %s\n", __FILE__, #x); \
    x();


#define TEST_ASSERT(x,y) assert(x == y)

