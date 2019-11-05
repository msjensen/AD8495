#ifndef AD8495_H
#define AD8495_H

//#include "Arduino.h"

class AD8495 {
  public:

    AD8495(int analogPin);
    double readCelsius(void);

  private:
    int _aref = 5;
    int _adcResolution = 10;
    int _analogPin;
    int _adc_max_value = pow(2,_adcResolution)-1;
    double _voltage = 0;
};

#endif
