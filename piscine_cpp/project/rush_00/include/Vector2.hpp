#ifndef VECTOR2_HPP
#define VECTOR2_HPP

template<typename T>
class	Vector2
{
public:

	Vector2(T X = 0, T Y = 0) : x(X), y(Y) {}
	~Vector2() {}

	Vector2(const Vector2& v) { *this = v; }

	Vector2&	operator=(const Vector2& v) { x = v.x; y = v.y; return *this; }

	template<typename CT> operator Vector2<CT>() const
	{
		return Vector2<CT>(static_cast<CT>(x), static_cast<CT>(y));
	}

	bool operator!=(T v) const { return (x != v || y != v); }

	Vector2 operator*(T v) const { return Vector2(x * v, y * v); }

	Vector2	operator+(const Vector2& v) const { return Vector2(x + v.x, y + v.y); }

	void	operator+=(const Vector2& v) { x += v.x; y += v.y; }

	T	x;
	T	y;

private:

};

typedef Vector2<int>			Vector2i;
typedef Vector2<unsigned int>	Vector2u;
typedef Vector2<float>			Vector2f;

#endif
