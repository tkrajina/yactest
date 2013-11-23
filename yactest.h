/*
 * Yet Another C Test(ing)...
 */
#ifndef YTEST_H_INCLUDED
#define YTEST_H_INCLUDED

#include <string.h>
#include <stdio.h>

#define YTESTS_INIT() \
int main(int argv, char *argc[]) { \
    char *ytest_name_expression = argv > 0 ? argc[1] : "";
    int ytest_test_no = 0; \
    int ytest_results[1000]; \
    char ytest_names[1000][1000]; \
    char *ytest_suite = "default";

#define YTESTS_RUN() \
    printf("\n\nTests:\n--------------------------------------------------------------------------------\n"); \
    int i = 0, result = 1, failed = 0; \
    for(i = 0; i < ytest_test_no; i++) { \
        printf("%40s... %s\n", ytest_names[i], ytest_results[i] ? "OK" : "FAIL"); \
        if(!ytest_results[i]) ++failed; \
        result = result && ytest_results[i]; \
    } \
    if(failed) { \
        printf("\n\n%i out of %i tests failed.\n", failed, ytest_test_no); \
    } else { \
        printf("\n\n %i test(s) OK.\n", ytest_test_no); \
    } \
    return !result; \
}

#define YTEST_BEGIN(test_name) \
    { \
        char *ytest_name = #test_name; \
        int test_function() { \

#define YTEST_END() \
            return 1; \
        } \
        sprintf(ytest_names[ytest_test_no], "%s.%s", ytest_suite, ytest_name); \
        if(!ytest_name_expression || strstr(ytest_names[ytest_test_no], ytest_name_expression)) { \
            printf("Running %s\n", ytest_names[ytest_test_no]); \
            ytest_results[ytest_test_no] = test_function(); \
            printf("\t%s\n\n", ytest_results[ytest_test_no] ? "OK" : "FAIL"); \
            ytest_test_no++; \
        } \
    }

#define YTEST_SUITE(suite_name) \
    ytest_suite = #suite_name;

#define YTEST_ASSERT(expression) \
    if(expression) { \
        printf("\tOK: %s\n", #expression); \
    } else { \
        printf("\tFailed: (%s) == %i\n", #expression, expression); \
        return 0; \
    }

#define YTEST_OK() \
    return 1;

#endif
