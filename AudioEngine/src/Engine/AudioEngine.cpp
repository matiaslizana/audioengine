#include "AudioEngine.h"
#include "../Components/AudioObject.h"

constexpr int NUM_OF_CHANNELS = 2;
constexpr int SAMPLE_RATE = 44100;
constexpr int BUFFER_SIZE = 512;
constexpr int BUFFER_SIZE_TOTAL = NUM_CHANNELS * BUFFER_SIZE;

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
        NUM_CHANNELS,              /* stereo output */
        paFloat32,      /* 32 bit floating point output */
        SAMPLE_RATE,          /* sample rate */
        BUFFER_SIZE,            /* frames per buffer */
        ProcessCallback, /* specify our custom callback */
        this        /* pass our data through to callback */
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

void AudioEngine::Process(const void* inputBuffer, void* outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags)
{
    //TODO: Change that for a group of AudioObjects later or AudioMixer (we discuss)

    //sineTone.GenerateTestTone(mixOutputBuffer);
    mainMixer.Process(mixOutputBuffer);

    float* outBuffer = reinterpret_cast<float*>(outputBuffer);
    if (outBuffer == nullptr)
        return;

    int writePosition = 0;
    int readPosition = 0;
    while (writePosition < BUFFER_SIZE_TOTAL)
    {
        outBuffer[writePosition++] = mixOutputBuffer[readPosition];
        outBuffer[writePosition++] = mixOutputBuffer[readPosition];

        ++readPosition;
    }
}

int ProcessCallback(const void* inputBuffer, void* outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void* userData)
{

    AudioEngine* audioEngine = reinterpret_cast<AudioEngine*>(userData);
    if (audioEngine)
        audioEngine->Process(inputBuffer, outputBuffer, framesPerBuffer, timeInfo, statusFlags);

    return 0;
}

