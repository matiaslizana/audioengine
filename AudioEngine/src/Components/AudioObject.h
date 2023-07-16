#pragma once
#include "../Common/Position.h"
#include "AudioFile.h"
#include <string>
#include "Mixer.h"

class AudioObject
{
private:
	Position position;
	bool isLoop;
	int currentSample;
	bool isPlaying;
	Mixer* outputMixer;

public:
	AudioFile<float> audioFile;

	AudioObject(Position position, std::string wavFile, bool isLoop = false);
	bool IsPlaying();
	void Play();
	void Stop();
	void Pause();
	void Process(float* out, int numSamples);
};