#include <iostream>
#include "Components/AudioObject.h"
#include "Components/Mixer.h"
#include "Common/Position.h"
#include "portaudio.h"
#include "Engine/AudioEngine.h"
#include "../libs/AudioFile.h"
#include <Windows.h>

int patestCallback(const void* inputBuffer, void* outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void* userData)
{
    AudioObject* audioObject = (AudioObject*)userData;
    AudioFile<float> audioFile = audioObject->audioFile;
    int numChannels = audioFile.getNumChannels();
    int numSamples = audioFile.getNumSamplesPerChannel();
    float* out = (float*)outputBuffer;
    //QUESTION: Why is framesPerBuffer unsigned long?
    unsigned long currentBufferFrame = AudioEngine::currentBufferFrame;
    unsigned long endBufferFrame = currentBufferFrame + framesPerBuffer;

    for (int c = 0; c < numChannels; c++)
    {
        for (unsigned long i = 0; i < framesPerBuffer; i++)
        {
            if (currentBufferFrame < numSamples - framesPerBuffer)
            {
                out[(i * 2) + c] = audioFile.samples[c][currentBufferFrame + i];
            }
            else
            {
                out[i] = 0;
            }
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

    bool keyPressed = false;
    while (true)
    {
        if (GetKeyState('A') & 0x8000)/*Check if high-order bit is set (1 << 15)*/
        {
            if (!keyPressed)
            {
                std::cout << "Hola!" << std::endl;
                keyPressed = true;
            }
        }
        else
            keyPressed = false;
    }

    audioEngine.Terminate();

	return 0;
}
