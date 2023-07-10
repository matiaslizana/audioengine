#include <iostream>
#include "Components/AudioObject.h"
#include "Components/Mixer.h"
#include "Common/Position.h"
#include "portaudio.h"
#include "Engine/AudioEngine.h"
#include "../libs/AudioFile.h"
#include <Windows.h>



int main()
{
    //TODO: Test initialization to be moved to script or game engine
     
    AudioEngine audioEngine;
    
    Position audioObjectPosition { 1, 1 };
    AudioObject audioObject { audioObjectPosition, "resources/test.wav" };

    Mixer mainOutput {};
    Mixer channel1 {};
    Mixer channel2 {};

    mainOutput.AddMixerChannel(&channel1);
    mainOutput.AddMixerChannel(&channel2);

    //Audio Engine Setup

    audioEngine.Initialize();
    audioEngine.OpenStream(&audioObject);

    bool keyPressed = false;
    while (true)
    {
        if (GetKeyState('A') & 0x8000)/*Check if high-order bit is set (1 << 15)*/
        {
            if (!keyPressed)
            {
                audioObject.Play();
                keyPressed = true;
            }
        }
        else
            keyPressed = false;
    }

    audioEngine.Terminate();

	return 0;
}
