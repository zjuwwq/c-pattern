#include <gtest/gtest.h>
#include "typedef.h"

TEST(typedef, simple){
	Byte4 id = 12345;
	Name wwq = "Wenqing Wei";
	EXPECT_EQ(12345, id);
	EXPECT_STREQ("Wenqing Wei", wwq);
}

TEST(typedef, vsDefine){
	String0 a, b;
	EXPECT_EQ(sizeof(char *), sizeof(b));
	// == char* x, y; so y is char not char*
	String1 x, y;
	EXPECT_NE(sizeof(char *), sizeof(y));
	EXPECT_EQ(sizeof(char), sizeof(y));
}

int *Fun0(int age, char* name){
	static int tmp = age;
	return &tmp;
}

void Fun1(){}
int Fun2(FunAsParamPtr){
	return 10;
}

double Fun3(){
	return 1.2;
}

TEST(typedef, complex){
	Line line1 = "This is Africa!";
	EXPECT_STREQ("This is Africa!", line1);

	a[0] = Fun0;
	EXPECT_EQ(29, *a[0](29, "wwq"));

	b[1] = Fun2;
	EXPECT_EQ(10, b[1](Fun1));
}
int main(int argc, char **argv){
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	return getchar();
}