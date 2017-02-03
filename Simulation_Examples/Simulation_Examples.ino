//Specify digital pin on the Arduino that the positive lead of piezo buzzer is attached.
#define PIN_PIEZO    9
#define PIN_POT     A5
#define POUT_PWM     3
#define LED_BUILTIN 13
 
void setup() {

    Serial1.begin(9600);
    
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(PIN_PIEZO, OUTPUT);
    pinMode(POUT_PWM, OUTPUT);
    pinMode(PIN_POT, INPUT);
    
    tone(PIN_PIEZO, 1300, 20);
    delay(250);
    tone(PIN_PIEZO, 900, 20);
    delay(250);

    Serial1.println("Hello!");
}
 
void loop() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(250);
    digitalWrite(LED_BUILTIN, LOW);
    delay(250);

    int pot_adc = analogRead(PIN_POT);
    float pot_value = pot_adc/1023.0 * 100.0;

    Serial1.print("Potentiometer value: ");
    Serial1.println(pot_value);
    analogWrite(POUT_PWM, (int) pot_value/100.0 * 255);    
}
