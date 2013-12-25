#include <gtest/gtest.h>
#include "define.h"

TEST(define, simple){
	EXPECT_EQ(3.14, PI);
	EXPECT_EQ(4, N);
	EXPECT_NE(16, N * N);
	// N * N == 2 + 2 * 2 + 2
	EXPECT_EQ(8, N * N);
	EXPECT_EQ(16, N1 * N1);
}

TEST(define, function){
	EXPECT_EQ(16, AREA(4));
	EXPECT_NE(16, AREA(2 + 2));
	// AREA(2 + 2) == 2 + 2 * 2 + 2
	EXPECT_EQ(8, AREA(2 + 2));

	EXPECT_EQ(16, AREA1(2 + 2));
	EXPECT_NE(1, AREA1(2 + 2)/AREA1(2 + 2));
	// AREA1(2 + 2)/AREA1(2 + 2) == (2 + 2) * (2 + 2) / (2 + 2) * (2 + 2)
	EXPECT_EQ(16, AREA1(2 + 2)/AREA1(2 + 2));

	EXPECT_EQ(1, AREA2(2 + 2)/AREA2(2 + 2));
}

TEST(define, undef){
	EXPECT_EQ(3.14, PI);
#undef PI
	// EXPECT_ANY_THROW(PI);
}

TEST(define, conditionalCompilation){
	int a;
#ifdef WINDOWS
	a = 1;
#else
	a = 2;
#endif
	EXPECT_EQ(1, a);
}

TEST(Define, operator){
	EXPECT_EQ("abc", A(abc));
	EXPECT_EQ(12345, C(12, 345));
}

int main(int argc, char** argv){
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	return getchar();
}