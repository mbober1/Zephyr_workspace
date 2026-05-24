#include <zephyr/ztest.h>

ZTEST(my_suite, test_example)
{
    zassert_equal(1 + 1, 2, "Math broken");
}

ZTEST_SUITE(my_suite, NULL, NULL, NULL, NULL, NULL);