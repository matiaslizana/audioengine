#include "catch.h"
# include "../GameEngine/Vector.h"

TEST_CASE("Default constructor", "Vector")
{
	Vector v{};
	REQUIRE(v.x == 0);
	REQUIRE(v.y == 0);
}

TEST_CASE("Basic value set from constructor", "Vector")
{
	const int x = 10;
	const int y = 50;
	Vector v{ x, y };
	REQUIRE(v.x == x);
	REQUIRE(v.y == y);
}

TEST_CASE("Vector == operator overload", "Vector")
{
	Vector v1;
	Vector v2;
	REQUIRE((v1 == v2) == true);

	v1.x = 2;

	REQUIRE((v1 == v2) == false);
}

TEST_CASE("Vector * operator overload", "Vector")
{
	Vector v1;
	int scaler = 5;
	int x = 2;
	int y = 2;

	REQUIRE(v1.x == 0);
	REQUIRE(v1.y == 0);

	v1.x = x;
	v1.y = y;
	Vector scaled = v1 * scaler;
	REQUIRE(scaled.x == (x * scaler));
	REQUIRE(scaled.y == (y * scaler));
}

TEST_CASE("Scaler int", "Vector")
{
	int scaler = 5;
	int x = 2;
	int y = 2;
	Vector v1 { x, y };

	v1 *= scaler;
	REQUIRE(v1.x == (x * scaler));
	REQUIRE(v1.y == (y * scaler));
}

TEST_CASE("Scaler Vector", "Vector")
{
	int x = 2;
	int y = 2;
	Vector v1 { x, y };
	Vector v2 { x, y };

	v1 *= v2;
	REQUIRE(v1.x == (v2.x * x));
	REQUIRE(v1.y == (v2.y * y));
}
