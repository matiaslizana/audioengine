#include <iostream>
#include "AudioListener.h"
#include "AudioObject.h"

int main()
{
	Position listenerPosition{ 0, 0 };
	AudioListener* audioListener = new AudioListener(listenerPosition);

	Position audioObjectPosition{ 1, 1 };
	AudioObject* audioObject = new AudioObject(listenerPosition, "resources/test.wav");

	return 0;
}
