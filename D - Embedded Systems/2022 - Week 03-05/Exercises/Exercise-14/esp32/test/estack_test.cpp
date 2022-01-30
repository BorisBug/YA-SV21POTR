#include "estack.h"
#include <stdlib.h>
#include <unity.h>

static estack_t *estack = NULL;

void setUp(void)
{
    embedded_stack_init_t init;
    init.embedded_malloc = malloc;
    init.embedded_free = free;
    embedded_estack_init(&init);    
}

void tearDown(void)
{
    estack_destroy(&estack);
    embedded_estack_init(NULL);
}

void test_create_estacks(void)
{
    estack = estack_create(10);
    TEST_ASSERT_NOT_NULL(estack);
    TEST_ASSERT_EQUAL_UINT16(10, estack_size(estack));
    TEST_ASSERT_EQUAL_INT32(0, estack_available(estack));

    TEST_ASSERT_NULL(estack_create(0));
    TEST_ASSERT_EQUAL_UINT16(0, estack_size(NULL));
    TEST_ASSERT_EQUAL_INT32(-1, estack_available(NULL));

    estack_t *temp = estack_create(20);
    TEST_ASSERT_NOT_NULL(temp);
    TEST_ASSERT_EQUAL_UINT16(20, estack_size(temp));
    TEST_ASSERT_EQUAL_INT32(0, estack_available(temp));

    estack_destroy(&temp);
    TEST_ASSERT_NULL(temp);

    estack_destroy(NULL);
    estack_destroy(&temp);
}

void test_estack_push_clear(void)
{
    estack = estack_create(10);
    TEST_ASSERT_NOT_NULL(estack);
    TEST_ASSERT_EQUAL_UINT16(10, estack_size(estack));
    TEST_ASSERT_EQUAL_INT32(0, estack_available(estack));

    TEST_ASSERT_TRUE(estack_push(estack, 20));
    TEST_ASSERT_EQUAL_INT32(1, estack_available(estack));

    TEST_ASSERT_TRUE(estack_clear(estack));
    TEST_ASSERT_EQUAL_INT32(0, estack_available(estack));

    TEST_ASSERT_FALSE(estack_clear(NULL));

    TEST_ASSERT_FALSE(estack_push(NULL, 100));

    uint16_t size = estack_size(estack);
    for (int i = 1; i <= size; i++)
    {
        TEST_ASSERT_TRUE(estack_push(estack, i));
        TEST_ASSERT_EQUAL_INT32(i, estack_available(estack));
    }
    TEST_ASSERT_FALSE(estack_push(estack, 100));
}

void test_estack_push_pop(void)
{
    estack = estack_create(10);
    TEST_ASSERT_NOT_NULL(estack);
    TEST_ASSERT_EQUAL_UINT16(10, estack_size(estack));
    TEST_ASSERT_EQUAL_INT32(0, estack_available(estack));

    TEST_ASSERT_TRUE(estack_push(estack, 20));
    TEST_ASSERT_EQUAL_INT32(1, estack_available(estack));

    uint8_t data = 0;
    TEST_ASSERT_TRUE(estack_pop(estack, &data));
    TEST_ASSERT_EQUAL_INT32(0, estack_available(estack));
    TEST_ASSERT_EQUAL_UINT8(20, data);

    TEST_ASSERT_FALSE(estack_pop(estack, &data));

    TEST_ASSERT_FALSE(estack_pop(NULL, &data));
    TEST_ASSERT_FALSE(estack_pop(NULL, NULL));
    TEST_ASSERT_TRUE(estack_push(estack, 20));
    TEST_ASSERT_EQUAL_INT32(1, estack_available(estack));
    TEST_ASSERT_FALSE(estack_pop(estack, NULL));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_create_estacks);
    RUN_TEST(test_estack_push_clear);
    RUN_TEST(test_estack_push_pop);

    return UNITY_END();
}
