#pragma once

#include "Audio/SoundBuffer.hpp"

namespace acid {
class ACID_EXPORT Mp3SoundBuffer : public SoundBuffer::Registrar<Mp3SoundBuffer> {
	static const bool Registered;
public:
	static void Load(SoundBuffer &soundBuffer, const std::filesystem::path &filename);
	static void Write(const SoundBuffer &soundBuffer, const std::filesystem::path &filename);
};
}
