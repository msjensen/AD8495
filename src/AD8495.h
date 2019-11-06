#ifndef AD8495_H
#define AD8495_H

class AD8495 {
  public:

    AD8495(int analogPin);
    AD8495(int analogPin, double adcRefV);
    AD8495(int analogPin, int adcRefV, int adcRes);
    double readCelsius(void);
    void setAmpRefV(double ampRefV);

  private:
    int _analogPin;
    int _adc_max_value;
    int _adcResolution = 10;
    double _adcRefV = 5;
    double _ampRefV = 1.842;
    double _voltage = 0;
};
#endif
