// union是一种类型,它可以把相互关联的数据组织在一起
struct Point{
	int x;
	int y;
} p;

struct Triangle{
	Point p0;
	Point p1;
	Point p2;
};