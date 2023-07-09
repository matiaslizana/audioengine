#include <iostream>
#include "AudioObject.h"
#include "Mixer.h"
#include "Position.h"
#include "portaudio.h"
#include "AudioEngine.h"

int patestCallback(const void* inputBuffer, void* outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void* userData)
{
    AudioObject* audioObject = (AudioObject*)userData;
    char* audioData = audioObject->Data();
    float* out = (float*)outputBuffer;
    //QUESTION: Why is framesPerBuffer unsigned long?
    unsigned long currentBufferFrame = AudioEngine::currentBufferFrame;
    unsigned long endBufferFrame = currentBufferFrame + framesPerBuffer;

    //TODO: WavFile reader is wrong (it fails on the other testfloat.wav
    //TODO: Move this when loading the wav file
    //QUESTION: How to convert 4 bytes char into a float? Does outputBuffer need to be float?
    for (unsigned long i = 0; i < framesPerBuffer; i++)
    {
        out[i] = audioData[currentBufferFrame + i];
    }
    AudioEngine::currentBufferFrame = endBufferFrame;

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
