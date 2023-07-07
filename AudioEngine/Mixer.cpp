#include "Mixer.h"

Mixer::Mixer() : audioObjects(), volume(0)
{
	
}

void Mixer::Subscribe(AudioObject& audioObject)
{
	audioObjects.push_back(audioObject);
}
