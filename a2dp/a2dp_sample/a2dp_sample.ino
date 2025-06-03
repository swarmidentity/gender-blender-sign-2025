#include "AudioTools.h"
#include "BluetoothA2DPSink.h"

// From: https://github.com/pschatzmann/ESP32-A2DP/

AnalogAudioStream out;
BluetoothA2DPSink a2dp_sink(out);

void setup() {
    a2dp_sink.set_stream_reader(read_data_stream);
    a2dp_sink.set_avrc_metadata_callback(avrc_metadata_callback);
    a2dp_sink.set_avrc_rn_volumechange(avrc_volume_change);
    a2dp_sink.start("GenderBlender");
}

void loop() {
}

// Then somewhere in your sketch:
void read_data_stream(const uint8_t *data, uint32_t length)
{
  int16_t *samples = (int16_t*) data;
  uint32_t sample_count = length/2;
  // Do something with the data packet
}

void avrc_metadata_callback(uint8_t data1, const uint8_t *data2) {
  Serial.printf("AVRC metadata rsp: attribute id 0x%x, %s\n", data1, data2);
}

void avrc_volume_change(int data1) {
  //Serial.printf("AVRC Volume rsp: attribute id 0x%x\n", data1);
}