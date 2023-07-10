#pragma once
#include "../Common/Position.h"
#include "../libs/AudioFile.h"
#include <string>

class AudioObject
{
private:
	Position position;

public:
	AudioFile<float> audioFile;
	AudioObject(Position position, std::string wavFile);
};