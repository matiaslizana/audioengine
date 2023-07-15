#pragma once
#include <iostream>
#include "portaudio.h"
#include "../Components/Mixer.h"
#include "../../SineToneGenerator.h"

constexpr int NUM_CHANNELS = 2;
constexpr int NUM_SAMPLES = 512;
constexpr int TEMP_BUFFER_SIZE = NUM_CHANNELS * NUM_SAMPLES;

class AudioEngine
{
private:
	PaStream* stream;
	Mixer mainMixer;
	std::array<float, TEMP_BUFFER_SIZE> mixOutputBuffer;
	SineToneGenerator sineTone;

public:
	void Initialize();
	void OpenStream(void* userData);
	void Terminate();
	void Process(const void* inputBuffer, void* outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags);
};

//QUESTION: Why this one can't be part of AudioEngine class?
int ProcessCallback(const void* inputBuffer, void* outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void* userData);
