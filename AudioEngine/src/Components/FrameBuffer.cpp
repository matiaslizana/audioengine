#include "FrameBuffer.h"
#include <cassert>

int FrameBuffer::GetBufferSize()
{
	return BUFFER_SIZE;
}

int FrameBuffer::GetNumOfChannels()
{
	return NUM_CHANNELS;
}

void FrameBuffer::WriteBlock(FrameBuffer& inBuffer, int channel)
{
	for (int index = 0; index < BUFFER_SIZE; ++index)
	{
		WriteSample(index, channel, inBuffer.GetSample(index, channel));
	}
}

void FrameBuffer::WriteBlock(FrameBuffer& inBuffer)
{
	for (int channel = 0; channel < NUM_CHANNELS; ++channel)
	{
		for (int index = 0; index < BUFFER_SIZE; ++index)
		{
			WriteSample(index, channel, inBuffer.GetSample(index, channel));
		}
	}
}

void FrameBuffer::AddBlock(FrameBuffer& inBuffer, int channel)
{
	for (int index = 0; index < BUFFER_SIZE; ++index)
	{
		AddSample(index, channel, inBuffer.GetSample(index, channel));
	}
}

void FrameBuffer::AddBlock(FrameBuffer& inBuffer)
{
	for (int channel = 0; channel < NUM_CHANNELS; ++channel)
	{
		for (int index = 0; index < BUFFER_SIZE; ++index)
		{
			AddSample(index, channel, inBuffer.GetSample(index, channel));
		}
	}
}

void FrameBuffer::Reset()
{
	for (int index = 0; index < frameBuffer.size(); ++index)
	{
		frameBuffer[index] = SAMPLE_ZERO;
	}
}

SampleType FrameBuffer::GetSample(int index, int channel)
{
	return frameBuffer[index + (channel * BUFFER_SIZE)];
}

inline void FrameBuffer::WriteSample(int index, int channel, SampleType sample)
{
	frameBuffer[index + (channel * BUFFER_SIZE)] = sample;
}

inline void FrameBuffer::AddSample(int index, int channel, SampleType sample)
{
	frameBuffer[index + (channel * BUFFER_SIZE)] += sample;
}


