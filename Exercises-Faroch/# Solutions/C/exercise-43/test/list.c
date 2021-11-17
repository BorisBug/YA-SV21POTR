#include "list.h"
#include <unity.h>

void setUp(void)
{
}

void tearDown(void)
{
    list_clear();
}

void insert_into_list(size_t len, uint8_t array[len])
{
    for (size_t i = 0; i < len; i++)
    {
        TEST_ASSERT_TRUE(list_insert(array[i]));
        TEST_ASSERT_EQUAL_size_t(i + 1, list_available());
    }
}

void test_list_insert(void)
{
    TEST_ASSERT_EQUAL_size_t(0, list_available());

    uint8_t data[] = {10, 2, 10, 8, 20};
    insert_into_list(sizeof(data) / sizeof(data[0]), data);

    TEST_ASSERT_EQUAL_UINT8(2, list_nth_data(1));
    TEST_ASSERT_EQUAL_UINT8(8, list_nth_data(2));
    TEST_ASSERT_EQUAL_UINT8(10, list_nth_data(3));
    TEST_ASSERT_EQUAL_UINT8(10, list_nth_data(4));
    TEST_ASSERT_EQUAL_UINT8(20, list_nth_data(5));

    TEST_ASSERT_EQUAL_size_t(5, list_available());

    TEST_ASSERT_EQUAL_UINT8(0, list_nth_data(0));
    TEST_ASSERT_EQUAL_UINT8(0, list_nth_data(10));

    list_clear();
    TEST_ASSERT_EQUAL_size_t(0, list_available());
}

void test_search_in_list(void)
{
    // Test if the list is empty
    TEST_ASSERT_EQUAL_size_t(0, list_find(40));

    uint8_t data[] = {10, 2, 10, 8, 20};
    insert_into_list(sizeof(data) / sizeof(data[0]), data);

    TEST_ASSERT_EQUAL_size_t(1, list_find(2));
    TEST_ASSERT_EQUAL_size_t(3, list_find(10));
}

void test_list_delete(void)
{
    TEST_ASSERT_FALSE(list_delete(33));

    uint8_t data[] = {10, 2, 10, 8, 20};
    insert_into_list(sizeof(data) / sizeof(data[0]), data);

    TEST_ASSERT_TRUE(list_delete(8));
    TEST_ASSERT_EQUAL_size_t(4, list_available());

    TEST_ASSERT_EQUAL_UINT8(2, list_nth_data(1));
    TEST_ASSERT_EQUAL_UINT8(10, list_nth_data(2));
    TEST_ASSERT_EQUAL_UINT8(10, list_nth_data(3));
    TEST_ASSERT_EQUAL_UINT8(20, list_nth_data(4));

    TEST_ASSERT_TRUE(list_delete(20));
    TEST_ASSERT_EQUAL_size_t(3, list_available());
}

void test_list_edit(void)
{
    TEST_ASSERT_FALSE(list_edit(33, 1));

    uint8_t data[] = {10, 2, 10, 8, 20};
    insert_into_list(sizeof(data) / sizeof(data[0]), data);

    TEST_ASSERT_TRUE(list_edit(8, 1));

    TEST_ASSERT_EQUAL_UINT8(1, list_nth_data(1));
    TEST_ASSERT_EQUAL_UINT8(2, list_nth_data(2));
    TEST_ASSERT_EQUAL_UINT8(10, list_nth_data(3));
    TEST_ASSERT_EQUAL_UINT8(10, list_nth_data(4));
    TEST_ASSERT_EQUAL_UINT8(20, list_nth_data(5));

    TEST_ASSERT_FALSE(list_edit(80, 100));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_list_insert);
    RUN_TEST(test_search_in_list);
    RUN_TEST(test_list_delete);
    RUN_TEST(test_list_edit);

    return UNITY_END();
}
