#include <al.h>
#include <alc.h>
#include <iostream>
#include "wavfile.h"

int main()
{
	//Opens audio device
	ALCdevice* openALDevice = alcOpenDevice(nullptr);
	if (!openALDevice)
	{
		std::cerr << "ERROR: Could not open audio device" << std::endl;
		return 0;
	}

	//Creates audio context
	ALCcontext* openALContext = alcCreateContext(openALDevice, nullptr);
	if (!openALContext)
	{
		std::cerr << "ERROR: Could not create audio context" << std::endl;
		return 0;
	}

	//Makes context current
	ALCboolean contextMadeCurrent = alcMakeContextCurrent(openALContext);
	if (contextMadeCurrent != ALC_TRUE)
	{
		std::cerr << "ERROR: Could not make audio context current" << std::endl;
		return 0;
	}

	std::uint8_t channels;
	std::int32_t sampleRate;
	std::uint8_t bitsPerSample;
	char* soundData;

	ALsizei size;
	ALenum format;
	soundData = WavFile::load_wav("resources/test.wav", channels, sampleRate, bitsPerSample, size, format);

	ALuint buffer;
	alGenBuffers(1, &buffer);

	alBufferData(buffer, format, soundData, size, sampleRate);

	ALuint source;
	alGenSources(1, &source);
	alSourcef(source, AL_PITCH, 1);
	alSourcef(source, AL_GAIN, 1.0f);
	alSource3f(source, AL_POSITION, 0, 0, 0);
	alSource3f(source, AL_VELOCITY, 0, 0, 0);
	alSourcei(source, AL_LOOPING, AL_FALSE);
	alSourcei(source, AL_BUFFER, buffer);

	alSourcePlay(source);

	ALint state = AL_PLAYING;

	while (state == AL_PLAYING)
	{
		alGetSourcei(source, AL_SOURCE_STATE, &state);
	}

	alDeleteSources(1, &source);
	alDeleteBuffers(1, &buffer);

	alcMakeContextCurrent(openALContext);
	alcDestroyContext(openALContext);

	ALCboolean closed = alcCloseDevice(openALDevice);

	return 0;
}