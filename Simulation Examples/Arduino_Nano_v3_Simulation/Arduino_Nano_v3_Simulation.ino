#define PIN_POT     A5
#define POUT_PIEZO    9
#define POUT_PWM     3
#define LED_BUILTIN 13
 
void setup() {

    Serial.begin(115200);
    
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(POUT_PIEZO, OUTPUT);
    pinMode(POUT_PWM, OUTPUT);
    pinMode(PIN_POT, INPUT);

    digitalWrite(POUT_PWM, HIGH);
    tone(POUT_PIEZO, 1300, 20);
    delay(250);

    digitalWrite(POUT_PWM, LOW);
    tone(POUT_PIEZO, 900, 20);
    delay(250);
    digitalWrite(POUT_PWM, HIGH);

    Serial.println("Hello Arduino Nano v3.0!");
}
 
void loop() {
    int pot_adc = analogRead(PIN_POT);
    float pot_value = pot_adc/1023.0 * 100.0;

    Serial.print("Potentiometer value: ");
    Serial.print(pot_value);
    Serial.println("%");

    analogWrite(POUT_PWM, (int) pot_value/100.0 * 255);    

    digitalWrite(LED_BUILTIN, HIGH);
    delay(250);
    digitalWrite(LED_BUILTIN, LOW);
    delay(250);
}
