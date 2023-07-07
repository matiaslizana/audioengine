#pragma once
#include "Position.h"
#include "wavfile.h"

class AudioObject
{
private:
	char* audioFile;
	Position position;

public:
	AudioObject(Position position, std::string wavFile);
};