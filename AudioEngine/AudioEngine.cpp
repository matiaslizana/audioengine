#include "AudioEngine.h"

void AudioEngine::Initialize()
{
    std::cout << "Initializing Audio Engine..." << std::endl;
    PaError result;
    
    result = Pa_Initialize();
    if (result != paNoError)
    {
        std::cout << result << std::endl;
    }
    std::cout << "Audio Engine Initialized!" << std::endl;
}

void AudioEngine::OpenStream(PaStreamCallback* callback, void* userData)
{
    PaError result;

    //Opens Default Stream
    result = Pa_OpenDefaultStream(
        &stream,        /* passes back stream pointer */
        0,              /* no input channels */
        2,              /* stereo output */
        paFloat32,      /* 32 bit floating point output */
        44100,          /* sample rate */
        256,            /* frames per buffer */
        callback,       /* specify our custom callback */
        &userData       /* pass our data through to callback */
    );
    if (result != paNoError)
    {
        std::cout << result << std::endl;
    }

    result = Pa_StartStream(stream);
}

void AudioEngine::Terminate()
{
    PaError result;

    result = Pa_StopStream(stream);
    if (result != paNoError)
    {
        std::cout << result << std::endl;
    }

    result = Pa_Terminate();
    if (result != paNoError)
    {
        std::cout << result << std::endl;
    }
}