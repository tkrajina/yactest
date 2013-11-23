#include "yactest.h"

YTESTS_INIT();

    YTEST_BEGIN(very_simple_test);
        YTEST_ASSERT(1 + 2 == 3);
    YTEST_END();

    YTEST_BEGIN(another_very_simple_test);
        YTEST_ASSERT(1 - 2 == -1);
    YTEST_END();

    // Start new suite:
    YTEST_SUITE(more_tests);

    // Test block of code, this is the preferred way;
    YTEST_BEGIN(block_test);
        int a = 1 + 2;
        int b = 5 - 2;
        YTEST_ASSERT(a == b);
    YTEST_END();

YTESTS_RUN()
