#include <gtest/gtest.h>
#include "namespace.h"

TEST(namespace, simple){
	int b = 1;
	// 名字空间增加了变量的访问控制来避免名字冲突。它不会改变变量的属性，例如：namespace B中的b变量是全局变量，无论在何处使用B，b变量都是全局变量
	using namespace B;
	EXPECT_EQ(1, b);
	EXPECT_EQ(100, B::b);

	using namespace A;
	EXPECT_EQ(1, a);
	using A::sum;
	EXPECT_EQ(2, sum(1, 1));
	a = 100;
	EXPECT_EQ(100, a);

	int a = 10;
	EXPECT_EQ(10, a);
	if(true){
		using namespace A::A1;
		EXPECT_STREQ("zjuwwq", t);
		t = "abc";
	}
	using namespace A::A1;
	// t has modified in previous block
	EXPECT_STREQ("abc", t);
}

int main(int argc, char** argv){
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	return getchar();
}

