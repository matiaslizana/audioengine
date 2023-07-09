#include "AudioObject.h"

AudioObject::AudioObject(Position position, std::string wavFile) : position(position)
{
	uint8_t channels;
	int32_t sampleRate;
	uint8_t bitsPerSample;
	int32_t size;
	WavFormat sampleFormat;
	audioFile = WavFile::load_wav(wavFile, channels, sampleRate, bitsPerSample, size, sampleFormat);
}

void* AudioObject::GetData() { return audioFile; }