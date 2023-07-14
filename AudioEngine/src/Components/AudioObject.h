#pragma once
#include "../Common/Position.h"
#include "../Components/Mixer.h"
#include "AudioFile.h"
#include <string>

class AudioObject
{
private:
	Position position;
	bool isLoop;
	int currentSample;
	Mixer* channel;
	bool isPlaying;

public:
	AudioFile<float> audioFile;

	AudioObject(Position position, std::string wavFile, Mixer* channel, bool isLoop = false);
	bool IsPlaying();
	void Play();
	void Stop();
	void Pause();
	void Process(float* out, int numSamples);
};