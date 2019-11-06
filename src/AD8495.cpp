#include <AD8495.h>
#include "Arduino.h"

//double adc_voltage_resolution = AREF/adc_max_value;

AD8495::AD8495(int analogPin) {
  _analogPin = analogPin;
  _adc_max_value = pow(2,_adcResolution)-1;
}

AD8495::AD8495(int analogPin, double adcRefV) {
  _analogPin = analogPin;
  _adcRefV = adcRefV;
  _adc_max_value = pow(2,_adcResolution)-1;
}

AD8495::AD8495(int analogPin, int adcRefV, int adcRes) {
  _analogPin = analogPin;
  _adcRefV = adcRefV;
  _adcResolution = adcRes;
  _adc_max_value = pow(2,_adcResolution)-1;
}

double AD8495::readCelsius(void) {
  _voltage = (analogRead(_analogPin)*_adcRefV) / _adc_max_value;
  return (_voltage - _ampRefV) / 0.005;
}

void AD8495::setAmpRefV(double ampRefV) {
  _ampRefV = ampRefV;
}
