#include "event_data.h"
#include <spine/spine.h>

using namespace spine;

spine_event_data spine_event_data_create(const char* name) {
    return (spine_event_data) new (__FILE__, __LINE__) EventData(String(name));
}

void spine_event_data_dispose(spine_event_data self) {
    delete (EventData*)self;
}

const char* spine_event_data_get_name(spine_event_data self) {
    return ((EventData*)self)->getName().buffer();
}

int spine_event_data_get_int(spine_event_data self) {
    return ((EventData*)self)->getInt();
}

void spine_event_data_set_int(spine_event_data self, int inValue) {
    ((EventData*)self)->setInt(inValue);
}

float spine_event_data_get_float(spine_event_data self) {
    return ((EventData*)self)->getFloat();
}

void spine_event_data_set_float(spine_event_data self, float inValue) {
    ((EventData*)self)->setFloat(inValue);
}

const char* spine_event_data_get_string(spine_event_data self) {
    return ((EventData*)self)->getString().buffer();
}

void spine_event_data_set_string(spine_event_data self, const char* inValue) {
    ((EventData*)self)->setString(String(inValue));
}

const char* spine_event_data_get_audio_path(spine_event_data self) {
    return ((EventData*)self)->getAudioPath().buffer();
}

void spine_event_data_set_audio_path(spine_event_data self, const char* inValue) {
    ((EventData*)self)->setAudioPath(String(inValue));
}

float spine_event_data_get_volume(spine_event_data self) {
    return ((EventData*)self)->getVolume();
}

void spine_event_data_set_volume(spine_event_data self, float inValue) {
    ((EventData*)self)->setVolume(inValue);
}

float spine_event_data_get_balance(spine_event_data self) {
    return ((EventData*)self)->getBalance();
}

void spine_event_data_set_balance(spine_event_data self, float inValue) {
    ((EventData*)self)->setBalance(inValue);
}
