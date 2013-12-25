// typedef 为现有的类型定义简单易记忆的别名

typedef long Byte4;
typedef char *Name;

// define在预处理时实现文本替换，typedef在编译时被解释，让编译器应付超越预处理器能力的文本替换
typedef char *String0;
#define String1 char *

// 对复杂变量建立一个类型别名，只要在传统的变量声明表达式里用类型名替代变量名，然后加上关键字typedef
typedef char Line[80];

// int *(*a[5])(int, char*); ==> 返回值为int *, 参数为int, char*的函数指针数组
typedef int *(*FunPtr0)(int, char *);
FunPtr0 a[5];

// int (*b[10])(void (*)()); ==> 返回值void, 参数为函数指针(void (*)())的函数指针数组
typedef void (*FunAsParamPtr)();
typedef int (*FunPtr1)(FunAsParamPtr);
FunPtr1 b[10];

// typedef 通过别名增加了一层抽象层，广泛用于平台差异性的类型定义，size_t，ptrdiff 和 fpos_t等