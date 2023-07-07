#pragma once

#include <fstream>
#include <iostream>
#include <bit>

enum WavFormat
{
	MONO8,
	MONO16,
	STEREO8,
	STEREO16
};

class WavFile 
{
public:
	static std::int32_t convert_to_int(char* buffer, std::size_t len);
	static bool load_wav_file_header(std::ifstream& file, std::uint8_t& channels, std::int32_t& sampleRate, std::uint8_t& bitsPerSample, int32_t& size);
	static char* load_wav(const std::string& filename, std::uint8_t& channels, std::int32_t& sampleRate, std::uint8_t& bitsPerSample, int32_t& size, WavFormat& sampleFormat);
	static bool format(uint8_t channels, uint8_t bitsPerSample, WavFormat& format);
};