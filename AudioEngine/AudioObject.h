#pragma once
#include "Position.h"
#include "wavfile.h"

class AudioObject
{
private:
	void* audioFile;
	Position position;

public:
	AudioObject(Position position, std::string wavFile);
	void* GetData();
};