#include "AudioObject.h"

AudioObject::AudioObject(Position position, std::string wavFile) : position(position)
{
	audioFile.load(wavFile);
}