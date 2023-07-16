#pragma once
#include "SineToneGenerator.h"

constexpr double PI = 3.1415926535897931;

void SineToneGenerator::GenerateTestTone(FrameBuffer& outputBuffer)
{
	const int numOfChannels = outputBuffer.GetNumOfChannels();
	const int bufferSize = outputBuffer.GetBufferSize();

	for (int i = 0; i < bufferSize; i++)
	{
		SampleType sine = static_cast<SampleType>(0.5 * sin(2.0 * PI * progression));
		for (int j = 0; j < numOfChannels; ++j)
		{
			outputBuffer.WriteSample(i, j , sine);
		}

		progression += delta;
		if (progression >= 1.0)
			progression = 0.0;
	}
}
