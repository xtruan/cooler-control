// number of analog samples to take per reading
#define NUM_SAMPLES 10
// number of seconds between loops
#define SECS_BETWEEN_LOOPS 60

int sum = 0;                    // sum of samples taken
unsigned char sample_count = 0; // current sample number
float voltage = 0.0;            // calculated voltage

void setup()
{
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
}

void loop()
{
    // take a number of analog samples and add them up
    while (sample_count < NUM_SAMPLES) {
        sum += analogRead(A2);
        sample_count++;
        delay(10);
    }
    
    // calculate the voltage
    // use 5.0 for a 5.0V ADC reference voltage
    voltage = ((float)sum / (float)NUM_SAMPLES) * (5.0 / 1023.0);

    // threshold of 2.5V
    if (voltage > 2.5) {
      digitalWrite(13, HIGH);
      digitalWrite(12, LOW);
    } else {
      digitalWrite(13, LOW);
      digitalWrite(12, HIGH);
    }
    
    sample_count = 0;
    sum = 0;

    // wait before looping again to 
    // avoid cycling too rapidly
    for (int i = 0; i < SECS_BETWEEN_LOOPS; i++) {
      delay(1000);
    }
}
