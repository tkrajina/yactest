#include <stdio.h>
#include <string.h>

#include "ctest.h"

CTEST_INIT();
    // Inline test:
    CTEST_INLINE(test1234, {
        CTEST_ASSERT(1 + 2 == 3);
    });

    // Start new suite:
    CTEST_SUITE(more_tests);

    // Function test:
    int test_function_alone() {
        CTEST_ASSERT(3 * 4 == 12);
        // Test functions must return true:
        return 1;
    }
    CTEST_FUNCTION(test_with_function, test_function_alone);

    // Test block of code, this is the preferred way;
    CTEST_BLOCK_START();
        int a = 1 + 2;
        int b = 5 - 2;
        CTEST_ASSERT(a == b);
    CTEST_BLOCK_FINISH(block_test);
CTEST_FINISH()
