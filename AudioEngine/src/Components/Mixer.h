#pragma once
#include <vector>
#include "../Common/Common.h"

class Mixer
{
private:
	std::vector<Mixer*> mixers;
	Volume volume;

public:
	Mixer();
	void AddMixerChannel(Mixer* mixerChannel);
	Volume Mix();
};