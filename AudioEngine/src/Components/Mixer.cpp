#include "Mixer.h"
#include "AudioObject.h"

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

void Mixer::Process(FrameBuffer& outBuffer)
{
	tempBuffer.Reset();
	const int numOfChannels = outBuffer.GetNumOfChannels();
	const int bufferSize = outBuffer.GetBufferSize();

	for (int i = 0; i < childMixers.size(); ++i)
	{
		childMixers[i].Process(tempBuffer);
	}

	for (int i = 0; i < audioObjects.size(); ++i)
	{
		
	}
	
	sineTone.GenerateTestTone(tempBuffer);
	outBuffer.AddBlock(tempBuffer);
}
