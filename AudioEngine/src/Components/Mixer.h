#pragma once
#include <vector>
#include <array>
#include "../Common/Common.h"
#include "../Components/Framebuffer.h"
#include "../Tools/SineToneGenerator.h"

class AudioObject;

constexpr int STANDARD_NUM_CHANNELS = 2;
constexpr int STANDARD_BUFFER_SIZE = 512;
constexpr int STANDARD_TEMP_BUFFER_SIZE = STANDARD_NUM_CHANNELS * STANDARD_BUFFER_SIZE;

class Mixer
{
private:
	std::vector<Mixer> childMixers;
	std::vector<AudioObject> audioObjects;
	Volume Mix();
	Volume volume;
	FrameBuffer tempBuffer {};
	SineToneGenerator sineTone {};

public:
	Mixer();
	void AddChildMixer(Mixer mixerChannel);
	void Process(FrameBuffer& outBuffer);
};