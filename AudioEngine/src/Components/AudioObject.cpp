#include "AudioObject.h"

AudioObject::AudioObject(Position position, std::string wavFile, bool isLoop) 
	: position(position), isLoop(isLoop), isPlaying(false), currentSample(0)
{
	audioFile.load(wavFile);
}

bool AudioObject::IsPlaying() 
{
	return isPlaying;
}

void AudioObject::Play()
{
	isPlaying = true;
}

void AudioObject::Stop()
{

}

void AudioObject::Pause()
{

}

void AudioObject::Process(float* out, int numSamples)
{
    for (int c = 0; c < audioFile.getNumChannels(); c++)
    {
        for (int i = 0; i < numSamples; i++)
        {
            if (currentSample < audioFile.getNumSamplesPerChannel() - numSamples)
            {
                out[(i * 2) + c] = audioFile.samples[c][currentSample + i];
            }
            else
            {
                isPlaying = false;
                break;
            }
        }
    }
    currentSample += numSamples;
}