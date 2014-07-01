#include <stdlib.h>
#include <check.h>

#include "libstuff.h"


START_TEST(test_stuff_one)
{
    int a = one();
    ck_assert_int_eq(a, 1);
}
END_TEST

START_TEST(test_stuff_two)
{
    int b = two();
    ck_assert_int_eq(b, 2);
}
END_TEST

START_TEST(test_stuff_multiply)
{
    int c = multiply(25, 30);
    ck_assert_int_eq(c, 25*30);

    int d = multiply(-2, 10);
    ck_assert_int_eq(d, -20);
}
END_TEST


Suite *
stuff_suite(void)
{
    Suite *s = suite_create("Stuff");

    // Core Tests
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_stuff_one);
    tcase_add_test(tc_core, test_stuff_two);
    tcase_add_test(tc_core, test_stuff_multiply);
    suite_add_tcase(s, tc_core);

    return s;
}

int
main(void)
{
    int number_failed;
    Suite *s = stuff_suite();
    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
