#include <assert.h>


#define TEST_ASSERT(x,y) assert(x == y)
#define RUNTEST(x) printf("TESTING: %s -> %s\n", __FILE__, #x); \
    x();
