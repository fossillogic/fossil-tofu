
// Generated Fossil Logic Test Runner
#include <fossil/test/framework.h>

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test List
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_EXPORT(cpp_dqueue_tofu_tests);
FOSSIL_TEST_EXPORT(cpp_pqueue_tofu_tests);
FOSSIL_TEST_EXPORT(c_vector_tofu_tests);
FOSSIL_TEST_EXPORT(cpp_generic_tofu_tests);
FOSSIL_TEST_EXPORT(c_pqueue_tofu_tests);
FOSSIL_TEST_EXPORT(cpp_tuple_tofu_tests);
FOSSIL_TEST_EXPORT(cpp_vector_tofu_tests);
FOSSIL_TEST_EXPORT(cpp_queue_tofu_tests);
FOSSIL_TEST_EXPORT(c_flist_tofu_tests);
FOSSIL_TEST_EXPORT(c_stack_tofu_tests);
FOSSIL_TEST_EXPORT(cpp_set_tofu_tests);
FOSSIL_TEST_EXPORT(c_generic_tofu_tests);
FOSSIL_TEST_EXPORT(c_tuple_tofu_tests);
FOSSIL_TEST_EXPORT(cpp_dlist_tofu_tests);
FOSSIL_TEST_EXPORT(cpp_flist_tofu_tests);
FOSSIL_TEST_EXPORT(cpp_stack_tofu_tests);
FOSSIL_TEST_EXPORT(c_dlist_tofu_tests);
FOSSIL_TEST_EXPORT(c_set_tofu_tests);
FOSSIL_TEST_EXPORT(c_queue_tofu_tests);
FOSSIL_TEST_EXPORT(c_dqueue_tofu_tests);

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Runner
// * * * * * * * * * * * * * * * * * * * * * * * *
int main(int argc, char **argv) {
    FOSSIL_TEST_START(argc, argv);
    FOSSIL_TEST_IMPORT(cpp_dqueue_tofu_tests);
    FOSSIL_TEST_IMPORT(cpp_pqueue_tofu_tests);
    FOSSIL_TEST_IMPORT(c_vector_tofu_tests);
    FOSSIL_TEST_IMPORT(cpp_generic_tofu_tests);
    FOSSIL_TEST_IMPORT(c_pqueue_tofu_tests);
    FOSSIL_TEST_IMPORT(cpp_tuple_tofu_tests);
    FOSSIL_TEST_IMPORT(cpp_vector_tofu_tests);
    FOSSIL_TEST_IMPORT(cpp_queue_tofu_tests);
    FOSSIL_TEST_IMPORT(c_flist_tofu_tests);
    FOSSIL_TEST_IMPORT(c_stack_tofu_tests);
    FOSSIL_TEST_IMPORT(cpp_set_tofu_tests);
    FOSSIL_TEST_IMPORT(c_generic_tofu_tests);
    FOSSIL_TEST_IMPORT(c_tuple_tofu_tests);
    FOSSIL_TEST_IMPORT(cpp_dlist_tofu_tests);
    FOSSIL_TEST_IMPORT(cpp_flist_tofu_tests);
    FOSSIL_TEST_IMPORT(cpp_stack_tofu_tests);
    FOSSIL_TEST_IMPORT(c_dlist_tofu_tests);
    FOSSIL_TEST_IMPORT(c_set_tofu_tests);
    FOSSIL_TEST_IMPORT(c_queue_tofu_tests);
    FOSSIL_TEST_IMPORT(c_dqueue_tofu_tests);

    FOSSIL_TEST_RUN();
    FOSSIL_TEST_SUMMARY();
    FOSSIL_TEST_END();
} // end of main
