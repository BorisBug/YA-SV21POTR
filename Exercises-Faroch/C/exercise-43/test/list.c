#include <unity.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"


void setUp(void) {}
void tearDown(void) {}

#define SIZE_ARR(a)     (sizeof(a)/sizeof(a[0]))


node_t *list_insert_from_buffer(node_t *list, uint8_t *buffer, size_t size)
{
    for(size_t i=0; i<size; i++)
    {
        list = list_insert_new(list, buffer[i]);
        TEST_ASSERT_NOT_NULL(list);
        TEST_ASSERT_EQUAL_size_t(i+1, list_count(list));
    }

    return list;
}

void test_list_insert(void)
{
    uint8_t data;
    uint8_t buffer[] = {30, 20, 10, 40, 20};
    node_t *list = NULL;

    TEST_ASSERT_EQUAL_size_t(0, list_count(list));
    list = list_insert_from_buffer(list, buffer, SIZE_ARR(buffer));
    TEST_ASSERT_EQUAL_size_t(5, list_count(list));

    TEST_ASSERT_NOT_NULL(list_get_nth(list, 0, &data));
    TEST_ASSERT_EQUAL_UINT8(10, data);
    TEST_ASSERT_NOT_NULL(list_get_nth(list, 1, &data));
    TEST_ASSERT_EQUAL_UINT8(20, data);
    TEST_ASSERT_NOT_NULL(list_get_nth(list, 2, &data));
    TEST_ASSERT_EQUAL_UINT8(20, data);
    TEST_ASSERT_NOT_NULL(list_get_nth(list, 3, &data));
    TEST_ASSERT_EQUAL_UINT8(30, data);
    TEST_ASSERT_NOT_NULL(list_get_nth(list, 4, &data));
    TEST_ASSERT_EQUAL_UINT8(40, data);

    data = 0xFF;
    TEST_ASSERT_NULL(list_get_nth(list, 10, &data));
    TEST_ASSERT_EQUAL_UINT8(0xFF, data);
    TEST_ASSERT_NULL(list_get_nth(list, -1, &data));
    TEST_ASSERT_EQUAL_UINT8(0xFF, data);

    TEST_ASSERT_NULL((list = list_destroy(list)));
    TEST_ASSERT_EQUAL_size_t(0, list_count(list));
}

void test_list_search(void)
{
    uint8_t buffer[] = {30, 20, 10, 40, 20};
    node_t *list = NULL;

    TEST_ASSERT_EQUAL_size_t(0, list_count(list));
    list = list_insert_from_buffer(list, buffer, SIZE_ARR(buffer));
    TEST_ASSERT_EQUAL_size_t(5, list_count(list));

    TEST_ASSERT_NOT_NULL(list_search(list, 30));
    TEST_ASSERT_NOT_NULL(list_search(list, 10));
    TEST_ASSERT_NULL(list_search(list, 35));
    TEST_ASSERT_NULL(list_search(list, 15));

    TEST_ASSERT_NULL((list = list_destroy(list)));
    TEST_ASSERT_EQUAL_size_t(0, list_count(list));
}

void test_list_delete(void)
{
    uint8_t buffer[] = {30, 20, 10, 40, 20};
    node_t *list = NULL;

    // insert
    TEST_ASSERT_EQUAL_size_t(0, list_count(list));
    list = list_insert_from_buffer(list, buffer, SIZE_ARR(buffer));
    TEST_ASSERT_EQUAL_size_t(5, list_count(list));

    // delete first
    TEST_ASSERT_EQUAL_size_t(10, list->data);
    list = list_delete(list, list);
    TEST_ASSERT_EQUAL_size_t(20, list->data);
    TEST_ASSERT_EQUAL_size_t(4, list_count(list));

    // delete last
    TEST_ASSERT_EQUAL_size_t(40, list_last(list)->data);
    list = list_delete(list, list_last(list));
    TEST_ASSERT_EQUAL_size_t(30, list_last(list)->data);
    TEST_ASSERT_EQUAL_size_t(3, list_count(list));

    // delete all
    TEST_ASSERT_NULL((list = list_destroy(list)));
    TEST_ASSERT_EQUAL_size_t(0, list_count(list));
}

void test_list_edit(void)
{
    uint8_t data;
    uint8_t buffer[] = {30, 20, 10, 40, 20};
    node_t *list = NULL;

    // edit
    TEST_ASSERT_NULL((list = list_edit(list, 10, 15)));

    // insert
    TEST_ASSERT_EQUAL_size_t(0, list_count(list));
    list = list_insert_from_buffer(list, buffer, SIZE_ARR(buffer));
    TEST_ASSERT_EQUAL_size_t(5, list_count(list));

    // edit existing
    TEST_ASSERT_NOT_NULL(list = list_edit(list, 10, 15));
    TEST_ASSERT_EQUAL_UINT8(15, list->data);
    TEST_ASSERT_NOT_NULL(list = list_edit(list, 40, 5));
    TEST_ASSERT_EQUAL_UINT8(5, list->data);
    TEST_ASSERT_NOT_NULL(list = list_edit(list, 20, 45));
    TEST_ASSERT_EQUAL_UINT8(45, list_last(list)->data);

    // verify order after editing
    TEST_ASSERT_EQUAL_UINT8(5, list_get_nth(list, 0, &data)->data);
    TEST_ASSERT_EQUAL_UINT8(15, list_get_nth(list, 1, &data)->data);
    TEST_ASSERT_EQUAL_UINT8(20, list_get_nth(list, 2, &data)->data);
    TEST_ASSERT_EQUAL_UINT8(30, list_get_nth(list, 3, &data)->data);
    TEST_ASSERT_EQUAL_UINT8(45, list_get_nth(list, 4, &data)->data);

    // delete all
    TEST_ASSERT_NULL((list = list_destroy(list)));
    TEST_ASSERT_EQUAL_size_t(0, list_count(list));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_list_insert);
    RUN_TEST(test_list_search);
    RUN_TEST(test_list_delete);
    RUN_TEST(test_list_edit);
    return UNITY_END();
}
