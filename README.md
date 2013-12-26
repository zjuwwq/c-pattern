# C Pattern
通过详细的用例来阐明C/C++的基本语法与模式。
这里的测试用例是基于[google test](code.google.com/p/googletest/)的
## 使用
### 编译配置google test

#### 1. 获取google test源码
```
svn checkout http://googletest.googlecode.com/svn/trunk/ gtest
```
#### 2. 编译google
```
cd gtest
mkdir mybuild
cd mybuild
cmake ../
make
```
#### 3. 拷贝头文件和静态库
```
cp libgtest_main.a /usr/local/lib/
cp libgtest.a /usr/local/lib/
cp -a ../include/gtest /usr/local/include/
```

### 编译执行用例
例如编译用例define
#### 1. 编译用例
```
cd define
make
```
#### 2. 执行用例
```
./define_unittest.out
```
