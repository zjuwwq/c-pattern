#include <gtest/gtest.h>
#include "union.h"

TEST(union, simple){
	// 30577 == 0x7771 == "wq"
	x.i = 30577;
	EXPECT_EQ(x.cs.first, 'q');
	EXPECT_EQ(x.cs.second, 'w');
	EXPECT_EQ(8, sizeof(x));
}

char IntToChar(int i){
	T t;
	memset(&t, 0, sizeof(t));
	t.i = i;
	return t.c;
}

int CharToInt(char c){
	T t;
	memset(&t, 0, sizeof(t));
	t.c = c;
	return t.i;
}

TEST(union, typeConversion){
	EXPECT_EQ('A', IntToChar(65));
	EXPECT_EQ(65, CharToInt('A'));
}

int main(int argc, char** argv){
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	return getchar();
}