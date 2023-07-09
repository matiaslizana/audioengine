#pragma once
#include <iostream>
#include "portaudio.h"

class AudioEngine
{
private:
	PaStream* stream;
public:
	void Initialize();
	void OpenStream(PaStreamCallback* callback, void* userData);
	void Terminate();
};

