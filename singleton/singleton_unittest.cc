#include <gtest/gtest.h>
#include "singleton.h"

TEST(singleton, simple){
	Singleton *a = Singleton::getInstance();
	Singleton *b = Singleton::getInstance();

	EXPECT_EQ(a, b);
}

int main(int argc, char** argv){
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	return getchar();
}