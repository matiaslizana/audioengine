#pragma once
class Vector
{
	// TODO: copy and move constructor in order to make it safer and usable.
public:
	Vector(int x, int y) : x(x), y(y) {}
	Vector(const Vector& v) : x(v.x), y(v.y) {}

	Vector() : x(0), y(0) {}

	bool operator== (const Vector& vector)
	{
		return ((vector.x == x) && (vector.y == y));
	}

	Vector operator* (int scale)
	{
		Vector v{ x, y };
		v.x *= scale;
		v.y *= scale;
		return v;
	}
	
	Vector operator+ (const Vector& add)
	{
		Vector v{ x, y };
		v.x += add.x;
		v.y += add.y;
		return v;
	}

	void operator*= (int scale)
	{
		x *= scale;
		y *= scale;
	}

	void operator*= (Vector scaler)
	{
		x *= scaler.x;
		y *= scaler.y;
	}

	int x;
	int y;
};

