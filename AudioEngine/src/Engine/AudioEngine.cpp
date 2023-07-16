#include "AudioEngine.h"
#include "../Components/AudioObject.h"
#include "AudioEngineSettings.h"


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

void AudioEngine::Process(const void* inputBuffer, void* outputBuffer, unsigned long framesPerBuffer, 
                          const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags)
{
    //TODO: Change that for a group of AudioObjects later or AudioMixer (we discuss)
    //Chris: Trying the structure setup here with having mixers calling process to see how that works.

    mixOutputBuffer.Reset();

    mainMixer.Process(mixOutputBuffer);

    float* outBuffer = reinterpret_cast<float*>(outputBuffer);
    if (outBuffer == nullptr)
        return;

    int writePosition = 0;
    int readPosition = 0;
    while (writePosition < BUFFER_SIZE_TOTAL)
    {
        for (int i = 0; i < NUM_CHANNELS; ++i)
        {
			outBuffer[writePosition++] = mixOutputBuffer.GetSample(readPosition, i);
        }
		++readPosition;
    }
}

int ProcessCallback(const void* inputBuffer, void* outputBuffer, unsigned long framesPerBuffer, 
                    const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void* userData)
{

    AudioEngine* audioEngine = reinterpret_cast<AudioEngine*>(userData);
    if (audioEngine)
        audioEngine->Process(inputBuffer, outputBuffer, framesPerBuffer, timeInfo, statusFlags);

    return 0;
}

