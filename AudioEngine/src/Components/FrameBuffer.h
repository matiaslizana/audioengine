#pragma once
#include <array>
#include "../Engine/AudioEngineSettings.h"
#include "../Common/Common.h"

/// <summary>
/// This will replicate the settings from AudioEngineSettinggs 
/// and the overall buffer size we are working with.
/// It's meant as only working with the buffer size and passing blocks around
/// </summary>
class FrameBuffer
{
public:
	FrameBuffer() {};

	int GetBufferSize();
	int GetNumOfChannels();

	/// <summary>
	/// Writes the whole buffer size block into the channel specified.
	/// </summary>
	void WriteBlock(FrameBuffer& inBuffer, int channel);

	/// <summary>
	/// Writes the whole buffer size block for all channels.
	/// </summary>
	void WriteBlock(FrameBuffer& inBuffer);

	/// <summary>
	/// Adds to the exisitng sample of the buffersize, for the channel specified.
	/// </summary>
	void AddBlock(FrameBuffer& inBuffer, int channel);

	/// <summary>
	/// Adds to the exisitng sample of the buffersize, for all channels.
	/// </summary>
	void AddBlock(FrameBuffer& inBuffer);

	/// <summary>
	/// Clears the whole buffer, and sets all samples to 0.0
	/// </summary>
	void Reset();

	/// <summary>
	/// Get a sample from the given index and channel.
	/// </summary>
	SampleType GetSample(int index, int channel);

	/// <summary>
	/// Write / overwrite a sample at the given index and channel.
	/// </summary>
	void WriteSample(int index, int channel, SampleType sample);

	/// <summary>
	/// Add to existing sample at the given index and channel.
	/// </summary>
	void AddSample(int index, int channel, SampleType sample);

private:
	std::array<SampleType, BUFFER_SIZE_TOTAL> frameBuffer {};
};

