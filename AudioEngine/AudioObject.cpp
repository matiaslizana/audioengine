#include "AudioObject.h"

AudioObject::AudioObject(Position position, std::string wavFile) : position(position), audioFile(nullptr), audioFileSize(0)
{
	uint8_t channels;
	int32_t sampleRate;
	uint8_t bitsPerSample;
	int32_t size;
	WavFormat sampleFormat;
	audioFile = WavFile::load_wav(wavFile, channels, sampleRate, bitsPerSample, audioFileSize, sampleFormat);
}

char* AudioObject::Data() { return audioFile; }

int AudioObject::Size() { return audioFileSize; }