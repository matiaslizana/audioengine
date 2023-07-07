#include <iostream>
#include "Position.h"
#include "AudioObject.h"
#include "Mixer.h"
#include "Position.h"
#include "portaudio.h"


typedef struct
{
    float left_phase;
    float right_phase;
}
paTestData;

static double DeltaSine = 0.f;
static const double PI = 3.14159265358979323846;

static int patestCallback(const void* inputBuffer, void* outputBuffer,
    unsigned long framesPerBuffer,
    const PaStreamCallbackTimeInfo* timeInfo,
    PaStreamCallbackFlags statusFlags,
    void* userData)
{
    double f = 1.0 / 1500.0;
    /* Cast data passed through stream to our structure. */
    paTestData* data = (paTestData*)userData;
    float* out = (float*)outputBuffer;
    int numOfFrames = framesPerBuffer;

    for (int i = 0; i < numOfFrames; i++)
    {
       /* if (i % 2 == 1)
            return 0;*/

        out[i] = 0.5 * sin(DeltaSine * PI * 2.0);
        DeltaSine += f;
        if (DeltaSine > 1.0)
            DeltaSine = 0;

        //data->left_phase += 0.00f;
        ///* When signal reaches top, drop back down. */
        //if (data->left_phase >= 8.0f) data->left_phase -= 1.6f;
        ///* higher pitch so we can distinguish left and right. */
        //data->right_phase += 0.004f;
        //if (data->right_phase >= 8.0f) data->right_phase -= 1.6f;
    }
    return 0;
}


int main()
{
    // =================================================================
    // Setup Sources and objects
    // =================================================================
     
    Position audioObjectPosition{ 1, 1 };
    AudioObject* audioObject = new AudioObject(audioObjectPosition, "resources/test.wav");

    Mixer mainOutput {};
    Mixer channel1 {};
    Mixer channel2 {};

    mainOutput.AddMixerChannel(&channel1);
    mainOutput.AddMixerChannel(&channel2);

    // =================================================================
    // Port Audio Setup
    // =================================================================

	std::cout << "Initilize Port Audio" << std::endl;
	PaError err = Pa_Initialize();
    if (err != paNoError)
    {
        std::cout << err << std::endl;
    }
    PaStream* stream;
    void* data;

    err = Pa_OpenDefaultStream(
        &stream,        /* passes back stream pointer */
        0,              /* no input channels */
        2,              /* stereo output */
        paFloat32,      /* 32 bit floating point output */
        44100,          /* sample rate */
        256,            /* frames per buffer */
        patestCallback, /* specify our custom callback */
        &data      /* pass our data through to callback */
    );       

    err = Pa_StartStream(stream);
    
    // =================================================================
    // Port Audio Setup end


    Pa_Sleep(5 * 1000);


    // =================================================================
    // Port Audio TERMINATE 
    err = Pa_StopStream(stream);
    Pa_Terminate();
    // =================================================================

	return 0;
}
