// union是一种类型,它一定程度上打破了类型系统的限制,同一块内存可以具有不同的类型
union{
	int i;
	struct{
		char first;
		char second;
	} cs;
	double d;
} x;

union T{
	char c;
	int i;
};
