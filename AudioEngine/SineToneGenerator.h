#pragma once
#include <array>

class SineToneGenerator
{
private:
	const double frequency = 440.0;
	const double delta = (frequency / 44100.0);
	double progression = 0;

public:
	void GenerateTestTone(std::array<float, 1024>& outputBuffer);
};

