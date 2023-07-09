#include <iostream>
#include "AudioObject.h"
#include "Mixer.h"
#include "Position.h"
#include "portaudio.h"
#include "AudioEngine.h"

static int patestCallback(const void* inputBuffer, void* outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void* userData)
{
    /* Cast data passed through stream to our structure. */
    AudioObject* audioObject = (AudioObject*)userData;
    float* audioData = (float*)audioObject->GetData();
    float* out = (float*)outputBuffer;

    for (unsigned long i = 0; i < framesPerBuffer; i++)
    {
        out[i] = audioData[i];
    }

    return 0;
}


int main()
{
    //TODO: Test initialization to be moved to script or game engine
     
    AudioEngine audioEngine;
    
    Position audioObjectPosition { 1, 1 };
    AudioObject audioObject { audioObjectPosition, "resources/test.wav" };

    Mixer mainOutput {};
    Mixer channel1 {};
    Mixer channel2 {};

    mainOutput.AddMixerChannel(&channel1);
    mainOutput.AddMixerChannel(&channel2);

    //Audio Engine Setup

    audioEngine.Initialize();
    audioEngine.OpenStream(patestCallback, &audioObject);

    while (true)
    {

    }

    audioEngine.Terminate();

	return 0;
}
