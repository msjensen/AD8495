#define TC_PIN A8
#define AREF 3.3
#define ADC_RESOLUTION 10

double adc_max_value = pow(2,ADC_RESOLUTION)-1;

//double adc_voltage_resolution = AREF/adc_max_value;

double voltage = 0;
double voltage_awg = 0;
double voltage_new = 0;
double voltage_last = 0;
double temperature = 0;
int analog_read = 0;
int count = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //analogReference(EXTERNAL);

}

void loop() {
  // put your main code here, to run repeatedly:
  if ( count < 10 ) {
    analog_read += analogRead(TC_PIN);//* adc_voltage_resolution;
    count++;
    delay(100);
  }
  else{
    analog_read /= 10;
    voltage = (analog_read * AREF) / adc_max_value;
    Serial.print("Voltage = ");
    Serial.println(voltage, 4);
    Serial.println();
    temperature = (voltage - 1.6383) / 0.005;
    //temperature = (voltage - 2.528) / 0.005;
    Serial.print("Temperatur = ");
    Serial.println(temperature);
    count = 0;
    analog_read = 0;
  }
  /*
  analog_read = analogRead(TC_PIN);//* adc_voltage_resolution;
  voltage_new = (analog_read * AREF) / adc_max_value;
  voltage_awg = voltage_new;
  //voltage_awg = ( voltage_new + voltage_last ) / 2;
  Serial.print("Voltage = ");
  Serial.println(voltage_awg);
  Serial.println();
  //temperature = (voltage_awg - 1.25) / 0.005;
  temperature = (voltage_awg - 2.528) / 0.005;
  Serial.print("Temperatur = ");
  Serial.println(temperature);
  //count = 0;
  //voltage_last = voltage_awg;
  delay(1000);
  */
}
