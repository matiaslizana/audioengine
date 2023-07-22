#include "catch.h"
# include "../GameEngine/Bounds.h"
#include "../GameEngine/Vector.h"

TEST_CASE("Bounds constructor", "Bounds")
{
	//Setup
	Vector boundsFirstCenter { 1, 1 };
	Vector boundsFirstExtends{ 2, 2 };
	Bounds boundsFirst{ boundsFirstCenter, boundsFirstExtends };
	
	REQUIRE((boundsFirst.GetCenter() == boundsFirstCenter));
	REQUIRE((boundsFirst.GetExtends() == boundsFirstExtends));
}

TEST_CASE("Intersects", "Bounds")
{
	//Setup
	Vector b1Center { 0, 0 };
	Vector b1Extends{ 4, 4 };
	Bounds b1{ b1Center, b1Extends };

	Vector b2Center { 1, 1 };
	Vector b2Extends{ 4, 4 };
	Bounds b2{ b2Center, b2Extends };

	Vector b3Center { 100, 100 };
	Vector b3Extends{ 4, 4 };
	Bounds b3{ b3Center, b3Extends };


	REQUIRE(b1.Intersects(b2));
	REQUIRE(b2.Intersects(b1));
	
	REQUIRE(b1.Intersects(b3) == false);
	REQUIRE(b3.Intersects(b1) == false);
}