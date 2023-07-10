#include <iostream>
#include "Components/AudioObject.h"
#include "Components/Mixer.h"
#include "Common/Position.h"
#include "portaudio.h"
#include "Engine/AudioEngine.h"
#include "../libs/AudioFile.h"

int patestCallback(const void* inputBuffer, void* outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void* userData)
{
    AudioObject* audioObject = (AudioObject*)userData;
    AudioFile<float>::AudioBuffer audioData = audioObject->audioFile.samples;
    int numChannels = audioObject->audioFile.getNumChannels();
    float* out = (float*)outputBuffer;
    //QUESTION: Why is framesPerBuffer unsigned long?
    unsigned long currentBufferFrame = AudioEngine::currentBufferFrame;
    unsigned long endBufferFrame = currentBufferFrame + framesPerBuffer;

    //TODO: WavFile reader is wrong (it fails on the other testfloat.wav
    //TODO: Move this when loading the wav file
    //QUESTION: How to convert 4 bytes char into a float? Does outputBuffer need to be float?
    for (unsigned long i = 0; i < framesPerBuffer; i++)
    {
        for (size_t c = 0; c < numChannels; i++)
        {
            out[i] = audioData[c][currentBufferFrame + i];
        }
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
