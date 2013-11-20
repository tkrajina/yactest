#ifndef CTEST_H_INCLUDED
#define CTEST_H_INCLUDED

#define CTEST_INIT() \
int main(int argv, char *argc[]) { \
    char *ctest_name_expression = argv > 0 ? argc[1] : "";
    int ctest_test_no = 0; \
    int ctest_results[1000]; \
    char ctest_names[1000][1000]; \
    char *ctest_suite = "default";

#define __CTEST_SAVE_AND_RUN_TEST(test_name, function_name) \
        ctest_results[ctest_test_no] = function_name(); \
        sprintf(ctest_names[ctest_test_no], "%s.%s", ctest_suite, #test_name); \
        printf("Running %s\n", ctest_names[ctest_test_no]); \
        ctest_results[ctest_test_no] = function_name(); \
        printf("\t\t\t\t%s\n\n", ctest_results[ctest_test_no] ? "OK" : "FAIL"); \
        ctest_test_no++;

/*
 * Inline test for simple tests.
 */
#define CTEST_INLINE(test_name, body) \
    { \
        int test_function() body \
        __CTEST_SAVE_AND_RUN_TEST(test_name, test_function) \
    }

/*
 * Testing using a predefined function.
 */
#define CTEST_FUNCTION(test_name, function_name) \
    { \
        __CTEST_SAVE_AND_RUN_TEST(test_name, function_name) \
    }

#define CTEST_BLOCK_START() \
    { \
        int test_function() { \

#define CTEST_BLOCK_FINISH(test_name) \
        } \
        __CTEST_SAVE_AND_RUN_TEST(test_name, test_function) \
    }

#define CTEST_FINISH() \
    printf("\n\nTests:\n--------------------------------------------------------------------------------\n"); \
    int i = 0, result = 1, failed = 0; \
    for(i = 0; i < ctest_test_no; i++) { \
        if(ctest_name_expression && strstr(ctest_names[i], ctest_name_expression)) { \
            printf("%30s... %s\n", ctest_names[i], ctest_results[i] ? "OK" : "FAIL"); \
            if(!ctest_results[i]) ++failed; \
            result = result && ctest_results[i]; \
        } \
    } \
    printf("\n\n%i out of %i tests failed.\n", failed, ctest_test_no); \
    return !result; \
}

#define CTEST_SUITE(suite_name) \
    ctest_suite = #suite_name;

#define CTEST_ASSERT(expression) \
    if(!(expression)) { \
        printf("Failed: %s -> %i\n", #expression, expression); \
        return 0; \
    }

#define CTEST_OK() \
    return 1;

#endif
