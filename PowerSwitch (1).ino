    
#define ANALOG_IN_PIN A0
#define ANALOG_IN_PIN1 A1
 

float adc_voltage = 0.0;
float in_voltage1 = 0.0;
float in_voltage2 = 0.0;
 
float R1 = 330.0;
float R2 = 1000.0; 
 
float ref_voltage = 9.0;
 
int adc_value = 0;
 
void setup()
{

   Serial.begin(9600);
   Serial.println("DC Voltage Test");
   pinMode(13 , OUTPUT);
}
 
void loop(){
   adc_value = analogRead(ANALOG_IN_PIN);
   adc_voltage  = (adc_value * ref_voltage) / 1024.0; 
   in_voltage1 = adc_voltage / (R2/(R1+R2)) ; 
  Serial.print("Input Voltage 1 = ");
  Serial.println(in_voltage1, 2);
   delay(500);
   digitalWrite(13  ,HIGH);

   adc_value = analogRead(ANALOG_IN_PIN1);
   adc_voltage  = (adc_value * ref_voltage) / 1024.0; 
   in_voltage2 = adc_voltage / (R2/(R1+R2)) ; 
   
  Serial.print("Input Voltage 2 = ");
  Serial.println(in_voltage2, 2);
  delay(500);

  if(in_voltage1<in_voltage2)
    {digitalWrite(13, HIGH);
    }
    else
{
    digitalWrite(13, LOW);
} 
}
