#include <iostream>

class Point
{
public:
	Point(int x = 0, int y = 0)
		: x_(x), y_(y)
	{}
	void	Print() const {std::cout << x_ << ", " << y_ << std::endl;}
private:
	int	x_;
	int	y_;
};

class PointPtr
{
public:
	PointPtr(Point* ptr)
		: ptr_(ptr)
	{}
private:
	Point*	ptr_;
};

class A {
	public:
	int val;
	int	v2;
	A(int val) : val(val)
	{
		std::cout << "A ctor " << std::endl;
		std::cout << "val: " << this->val << std::endl;
	}
};

int main(void)
{
	A a = 3;

	return (0);
}
