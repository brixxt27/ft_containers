#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>
#include <vector>
template <typename T>
class Vector
{
public:
	typedef T	value_type;

	//Vector();
	Vector(int n);
	//Vector(const Vector& other);
	//Vector&	operator=(const Vector& rhs);
	~Vector();	

	T	operator[](int i);

	void	push_back(T s);
	void	remove(int x);
	int		size();

private:
	T*	mData;
	int	mCapacity;
	int	mLength;
};

template <typename T>
Vector<T>::Vector(int n = 1)
	: mData(new T[n])
	, mCapacity(n)
	, mLength(0)
{}

template <typename T>
Vector<T>::~Vector()
{
	if (mData != NULL)
		delete[] mData;
}

template <typename T>
void	Vector<T>::push_back(T s)
{
	if (mCapacity <= mLength) {
		T*	temp = new T[mCapacity * 2];

		for (int i = 0; i < mLength; i++) {
			temp[i] = mData[i];
		}
		delete[] mData;
		mData = temp;
		mCapacity *= 2;
	}

	mData[mLength] = s;
	++mLength;
}
std::ostream&	operator<<(std::ostream& out, typename Vector<T>& rhs);

#endif
