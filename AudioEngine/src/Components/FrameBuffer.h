#pragma once
#include <array>
#include "../Engine/AudioEngineSettings.h"
#include "../Common/Common.h"

class FrameBuffer
{
public:
	FrameBuffer() {};

	int GetBufferSize();
	int GetNumOfChannels();
	void WriteBlock(FrameBuffer& inBuffer, int channel);
	void WriteBlock(FrameBuffer& inBuffer);
	void AddBlock(FrameBuffer& inBuffer, int channel);
	void AddBlock(FrameBuffer& inBuffer);
	void Reset();
	SampleType GetSample(int index, int channel);
	void WriteSample(int index, int channel, SampleType sample);
	void AddSample(int index, int channel, SampleType sample);

private:
	std::array<SampleType, BUFFER_SIZE_TOTAL> frameBuffer {};
};

