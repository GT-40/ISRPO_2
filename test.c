#include"../Unity/src/unity.h"
#include"funcs.h"

void test_addDate(){
	TEST_ASSERT_EQUAL_STRING("10.10",addDate());
}

void setUp(){}

void tearDown(){}


int main(){
	UNITY_BEGIN();
	RUN_TEST(test_addDate);
	return UNITY_END();

}
