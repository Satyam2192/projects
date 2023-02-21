#include <iostream>
#include <string>

#include "google/cloud/text_to_speech/v1/cloud_tts_client.h"
#include "google/cloud/text_to_speech/v1/synthesis_input.pb.h"
#include "google/cloud/text_to_speech/v1/voice_selection_params.pb.h"
#include "google/cloud/text_to_speech/v1/audio_config.pb.h"

using google::cloud::text_to_speech::v1::CloudTtsClient;
using google::cloud::text_to_speech::v1::SynthesisInput;
using google::cloud::text_to_speech::v1::VoiceSelectionParams;
using google::cloud::text_to_speech::v1::AudioConfig;

int main() {
    // Create a Text-to-Speech client
    CloudTtsClient client("[YOUR_GOOGLE_CLOUD_PROJECT_ID]");

    // Set the input text
    SynthesisInput input;
    string text;
    cout << "Enter text: ";
    getline(cin, text);
    input.set_text(text);

    // Set the voice options
    VoiceSelectionParams voice;
    voice.set_language_code("en-US");
    voice.set_name("en-US-Wavenet-C"); // Change this to a different voice if desired
    input.mutable_voice()->CopyFrom(voice);

    // Set the audio configuration options
    AudioConfig config;
    config.set_audio_encoding(AudioConfig::MP3);
    config.set_speaking_rate(1.0); // Change the speaking rate if desired

    // Synthesize the text to speech
    auto response = client.SynthesizeSpeech(input, config);
    cout << "Synthesized audio: " << response.audio_content() << endl;

    return 0;
}
