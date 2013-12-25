#include <gtest/gtest.h>
#include "struct.h"

TEST(struct, simple){
	EXPECT_EQ(8, sizeof(Point));
	p.x = 100;
	p.y = 200;

	Triangle t = {{100,100}, {100, 200}, {200, 200}};
	EXPECT_EQ(100, t.p0.x);
	EXPECT_EQ(200, t.p2.y);
}

int main(int argc, char** argv){
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	return getchar();
}