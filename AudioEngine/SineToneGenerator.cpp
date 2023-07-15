#pragma once
#include "SineToneGenerator.h"

constexpr double PI = 3.1415926535897931;

void SineToneGenerator::GenerateTestTone(std::array<float, 1024>& outputBuffer)
{
	for (int i = 0; i < 512; i++)
	{
		float sine = static_cast<float>(0.5 * sin(2.0 * PI * progression));
		outputBuffer[i] = sine;
		outputBuffer[i + 512] = sine;
		progression += delta;
		if (progression >= 1.0)
			progression = 0.0;
	}
}
