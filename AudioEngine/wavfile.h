#pragma once

#include <fstream>
#include <iostream>
#include <al.h>

class WavFile 
{
public:
	static bool load_wav_file_header(std::ifstream& file, std::uint8_t& channels, std::int32_t& sampleRate, std::uint8_t& bitsPerSample, ALsizei& size);
	static char* load_wav(const std::string& filename, std::uint8_t& channels, std::int32_t& sampleRate, std::uint8_t& bitsPerSample);
	static bool format(uint8_t channels, uint8_t bitsPerSample, ALenum& format);
};