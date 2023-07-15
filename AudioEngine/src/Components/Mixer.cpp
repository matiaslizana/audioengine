#include "Mixer.h"

Mixer::Mixer() : childMixers(), volume(0)
{
	
}

void Mixer::AddChildMixer(Mixer mixerChannel)
{
	childMixers.push_back(mixerChannel);
}

Volume Mixer::Mix()
{
	Volume volume = 0;
	for (size_t i = 0; i < childMixers.size(); i++)
	{
		volume+=childMixers[i].Mix();
	}
	return volume;
}

void Mixer::Process(std::array<float, STANDARD_TEMP_BUFFER_SIZE>& outBuffer)
{
	for (int i = 0; i < childMixers.size(); ++i)
	{
		childMixers[i].Process(tempBuffer);
	}

	for (int i = 0; i < audioObjects.size(); ++i)
	{
		
	}

	for (int i = 0; i < STANDARD_TEMP_BUFFER_SIZE; ++i)
	{
		outBuffer[i] = tempBuffer[i];
	}
}
