#pragma once
#include "Position.h"
#include "wavfile.h"

class AudioObject
{
private:
	Position position;
	//TODO: void*? Who takes care of the size and storage? AudioEngine when initializing stream?
	char* audioFile;
	int32_t audioFileSize;

public:
	AudioObject(Position position, std::string wavFile);
	char* Data();
	int32_t Size();
};