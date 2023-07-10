#include "AudioEngine.h"
#include "../Components/AudioObject.h"

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

void AudioEngine::OpenStream(void* userData)
{
    PaError result;

    result = Pa_OpenDefaultStream(
        &stream,        /* passes back stream pointer */
        0,              /* no input channels */
        2,              /* stereo output */
        paFloat32,      /* 32 bit floating point output */
        44100,          /* sample rate */
        256,            /* frames per buffer */
        StreamCallback, /* specify our custom callback */
        userData        /* pass our data through to callback */
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

int StreamCallback(const void* inputBuffer, void* outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void* userData)
{
    //TODO: Change that for a group of AudioObjects later or AudioMixer (we discuss)
    AudioObject* audioObject = (AudioObject*)userData;
    if (!audioObject->IsPlaying())
    {
        return 0;
    }

    AudioFile<float> audioFile = audioObject->audioFile;
    float* out = (float*)outputBuffer;
    audioObject->Process(out, framesPerBuffer);

    return 0;
}