#include "AD8495.h"
#include "Arduino.h"

//double adc_voltage_resolution = AREF/adc_max_value;

AD8495::AD8495(int analogPin) {
  _analogPin = analogPin;
}

double AD8495::readCelsius(void) {
  _voltage = (analogRead(_analogPin)*_aref) / _adc_max_value;
  return (_voltage - 2.49) / 0.005;
}
