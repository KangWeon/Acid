#include "WaveSoundBuffer.hpp"

#ifdef ACID_BUILD_MACOS
#include <OpenAL/al.h>
#else
#include <al.h>
#endif

#include <dr_libs/dr_wav.h>

#include "Files/Files.hpp"
#include "Maths/Time.hpp"

namespace acid {
const bool WaveSoundBuffer::Registered = Register(".wav", ".wave");

void WaveSoundBuffer::Load(SoundBuffer &soundBuffer, const std::filesystem::path &filename) {
#ifdef ACID_DEBUG
	auto debugStart = Time::Now();
#endif

	auto fileLoaded = Files::Read(filename);

	if (!fileLoaded) {
		Log::Error("SoundBuffer could not be loaded: ", filename, '\n');
		return;
	}

	uint32_t channels;
	uint32_t sampleRate;
	drwav_uint64 totalPCMFrameCount;
	auto sampleData = drwav_open_memory_and_read_pcm_frames_s16(fileLoaded->data(), fileLoaded->size(), &channels, &sampleRate, &totalPCMFrameCount, nullptr);
	if (!sampleData) {
		Log::Error("Error reading OGG ", filename, ", could not load samples\n");
		return;
	}

	uint32_t buffer;
	alGenBuffers(1, &buffer);
	alBufferData(buffer, (channels == 2) ? AL_FORMAT_STEREO16 : AL_FORMAT_MONO16, sampleData, totalPCMFrameCount, sampleRate);

	Audio::CheckAl(alGetError());

	soundBuffer.SetBuffer(buffer);
	
	drwav_free(sampleData, nullptr);

#ifdef ACID_DEBUG
	Log::Out("SoundBuffer ", filename, " loaded in ", (Time::Now() - debugStart).AsMilliseconds<float>(), "ms\n");
#endif
}

void WaveSoundBuffer::Write(const SoundBuffer &soundBuffer, const std::filesystem::path &filename) {
#ifdef ACID_DEBUG
	auto debugStart = Time::Now();
#endif

	// TODO: Implement

#ifdef ACID_DEBUG
	Log::Out("SoundBuffer ", filename, " written in ", (Time::Now() - debugStart).AsMilliseconds<float>(), "ms\n");
#endif
}
}
