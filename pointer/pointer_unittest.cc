#include <gtest/gtest.h>

TEST(pointer, simple){
	int *pi, i = 10;
	pi = &i;
	EXPECT_EQ(10, *pi);

	char *str = "zjuwwq";
	EXPECT_EQ('u', *(str + 2));

	int a[] = {1, 2, 3};
	EXPECT_NE(1, (long)(a + 1) - (long)a);
	// [1] 指针和整数的运算，实际上是指针和步长(sizeof(type))的整数倍的运算，如：a + 1 == a + 1*sizeof(int)
	EXPECT_EQ(sizeof(int), (long)(a + 1) - long(a));
}

// null pointer, not point to any object
TEST(pointer, null){
	int *p = NULL;
	EXPECT_EQ(0, p);
	// check before dereference
	if(p != NULL){
		*p;
	}
}

// void pointer, not define any type to point
TEST(pointer, void){
	void *v;
	// *v; // error
	// malloc return void pointer
	char *pc = (char *)malloc(sizeof(char));
	EXPECT_EQ(1, sizeof(*pc));
	free(pc);
}

TEST(pointer, PointerAndArray){
	// [2] 编译器将数组名关联的值设为数组第一个元素（注意类型）的首地址
	int a[] = {1, 2, 3, 4, 5};
	int *pi = a;
	EXPECT_EQ(2, *(a + 1));
	EXPECT_EQ(2, *(pi + 1));

	// 声明数组时，同时分配了用于容纳数组元素的空间；而声明一个指针时，只分配了用于容纳指针本身的空间
	EXPECT_NE(sizeof(pi), sizeof(a));
	EXPECT_EQ(5 * sizeof(int), sizeof(a));

	int b[][3] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
	// 根据注释[2], b被初始化为数组的首地址，又因为b是整数数组的数组，所以b类型是整数数组
	// 根据注释[2], b + 1 == b + sizeof(type).因为b是整数数组的数组=>指向的数据的类型是整数数组(长度为3)=>sizeof(type) == 3*sizeof(int)
	EXPECT_EQ(3 * sizeof(int), (long)(b + 1) - long(b));
	EXPECT_EQ(3 * sizeof(int), sizeof(b[0]));

	// 根据注释[2], b[1] + 1 == b[1] + sizeof(type).因为b[1]是整数的数组=>b[1]指向的数据的类型是整数=>sizeof(type) == sizeof(int)
	EXPECT_EQ(sizeof(int), (long)(b[1] + 1) - (long)b[1]);
	EXPECT_EQ(5, *(b[1] + 1));
}

int *sum(int a, int b){
	static int result = a + b;
	return &result;
}

int multiply(int a, int b){
	return a * b;
}

TEST(pointer, PointerFunctionAndFunctionPointer){
	// pointer function - 一个函数，函数的返回值是指针
	EXPECT_EQ(3, *sum(1, 2));

	// function pointer - 一个指针，指针指向的类型是函数
	int (*fp)(int, int);
	fp = multiply;
	EXPECT_EQ(2, (*fp)(1, 2));
	EXPECT_EQ(2, fp(1, 2));

	// C语言规定函数名会被转换为指向这个函数的指针，除非这个函数作为 & 操作符或sizeof操作符的操作数
	EXPECT_TRUE(multiply == &multiply);
	EXPECT_TRUE(multiply == *multiply);
	// 不能修改函数指针
	// fp++ // error
	// fp = fp + 2 // error
	
	// pointer function + function pointer
	int *(*p)(int, int);
	p = sum;
	EXPECT_EQ(3, *p(1, 2));
}

int substract(int a, int b){
	return a - b;
}

TEST(pointer, PointerArrayAndArrayPointer){
	// pointer array - 一个数组，数组里面的每一项都是指针
	int x = 1, y = 2, z = 3;
	int *pa[10] = {&x, &y, &z};
	EXPECT_EQ(1, *pa[0]);
	EXPECT_EQ(2, *pa[1]);
	EXPECT_EQ(2, **(pa + 1));

	// 函数指针数组
	int (*fp[2])(int, int) = {substract, multiply};
	EXPECT_EQ(4, fp[0](5, 1));

	// array pointer - 一个指针，指针指向的是数组，等价于多维数组
	int (*ap)[3];
	int b[][3] = {
		{1, 2, 3},
		{4, 5, 6}
	};
	ap = b;
	EXPECT_EQ(1, (*ap)[0]);
	EXPECT_EQ(5, (*(ap + 1))[1]);
}

int main(int argc, char ** argv){
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	return getchar();
}