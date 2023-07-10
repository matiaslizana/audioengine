#pragma once
#include <iostream>
#include "portaudio.h"

class AudioEngine
{
private:
	PaStream* stream;

public:
	void Initialize();
	void OpenStream(void* userData);
	void Terminate();
};

//QUESTION: Why this one can't be part of AudioEngine class?
int StreamCallback(const void* inputBuffer, void* outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void* userData);