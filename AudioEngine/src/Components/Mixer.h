#pragma once
#include <vector>
#include "AudioObject.h"
#include "../Common/Common.h"

class Mixer
{
private:
	std::vector<AudioObject*> audioObjects;
	std::vector<Mixer*> mixers;
	Volume volume;

public:
	Mixer();
	void AddMixerChannel(Mixer* mixerChannel);
	void Subscribe(AudioObject* audioObject);
	Volume Mix();
};