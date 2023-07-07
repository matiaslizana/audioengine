#include "AudioListener.h"
#include "AudioObject.h"
#include "Mixer.h"

int main()
{
	Position listenerPosition{ 0, 0 };
	AudioListener* audioListener = new AudioListener(listenerPosition);

	Position audioObjectPosition{ 1, 1 };
	AudioObject* audioObject = new AudioObject(listenerPosition, "resources/test.wav");

	Mixer mainOutput {};
	Mixer channel1 {};
	Mixer channel2 {};

	mainOutput.AddMixerChannel(&channel1);
	mainOutput.AddMixerChannel(&channel2);

	return 0;
}