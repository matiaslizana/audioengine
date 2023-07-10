#pragma once
#include "../Common/Position.h"
#include "../libs/AudioFile.h"
#include <string>

class AudioObject
{
private:
	Position position;
	bool isLoop;
	int currentSample;
	bool isPlaying;

public:
	AudioFile<float> audioFile;
	AudioObject(Position position, std::string wavFile, bool isLoop = false);
	bool IsPlaying();
	void Play();
	void Stop();
	void Pause();
	void Process(float* out, int numSamples);
};