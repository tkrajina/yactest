#include <stdio.h>

#include "ctest.h"

CTEST_INIT();
    // Inline test:
    CTEST_INLINE(test1234, {
        CTEST_ASSERT(1 + 2 == 3);
        CTEST_OK();
    });

    // New suite:
    CTEST_SUITE(suite2);

    // Function test:
    int test_function_alone() {
        CTEST_ASSERT(3 * 4 == 12);
        CTEST_OK();
    }
    CTEST_FUNCTION(test_with_function, test_function_alone);
CTEST_FINISH()
