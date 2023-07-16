#pragma once
#include <iostream>
#include "portaudio.h"
#include "../Components/Mixer.h"
#include "AudioEngineSettings.h"
#include "../Components/FrameBuffer.h"

class AudioEngine
{
private:
	PaStream* stream;
	Mixer mainMixer;
	FrameBuffer mixOutputBuffer {};

public:
	void Initialize();
	void OpenStream(void* userData);
	void Terminate();
	void Process(const void* inputBuffer, void* outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags);
};

//QUESTION: Why this one can't be part of AudioEngine class?
int ProcessCallback(const void* inputBuffer, void* outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void* userData);
