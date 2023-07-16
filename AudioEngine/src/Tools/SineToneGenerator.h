#pragma once
#include <array>
#include "../Components/FrameBuffer.h"

class SineToneGenerator
{
private:
	const double frequency = 440.0;
	const double delta = (frequency / 44100.0);
	double progression = 0;

public:
	void GenerateTestTone(FrameBuffer& outputBuffer);
};

