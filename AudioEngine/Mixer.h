#pragma once
#include <vector>
#include "AudioObject.h"
#include "Common.h"

class Mixer
{
private:
	std::vector<AudioObject> audioObjects;
	Volume volume;

public:
	Mixer();
	void Subscribe(AudioObject& audioObject);
};