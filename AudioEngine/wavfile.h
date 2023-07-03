#pragma once

#include <fstream>
#include <iostream>
#include <al.h>
#include <bit>

class WavFile 
{
public:
	static std::int32_t convert_to_int(char* buffer, std::size_t len);
	static bool load_wav_file_header(std::ifstream& file, std::uint8_t& channels, std::int32_t& sampleRate, std::uint8_t& bitsPerSample, ALsizei& size);
	static char* load_wav(const std::string& filename, std::uint8_t& channels, std::int32_t& sampleRate, std::uint8_t& bitsPerSample, ALsizei& size);
	static bool format(uint8_t channels, uint8_t bitsPerSample, ALenum& format);
};