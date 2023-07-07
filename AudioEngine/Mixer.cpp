#include "Mixer.h"

Mixer::Mixer() : audioObjects(), mixers(), volume(0)
{
	
}

void Mixer::AddMixerChannel(Mixer* mixerChannel)
{
	mixers.push_back(mixerChannel);
}

void Mixer::Subscribe(AudioObject* audioObject)
{
	audioObjects.push_back(audioObject);
}

Volume Mixer::Mix()
{
	Volume volume = 0;
	for (size_t i = 0; i < mixers.size(); i++)
	{
		volume+=mixers[i]->Mix();
	}
	return volume;
}
