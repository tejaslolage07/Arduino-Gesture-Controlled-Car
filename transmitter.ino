#define x A1
#define y A2
#define z A3
#define LD 8  // left direction
#define RD 9  // right direction
#define FD 10 // forward direction
#define BD 11 // backward direction
#define test 5

void setup()
{
    Serial.begin(9600);
    pinMode(x, INPUT);
    pinMode(y, INPUT);
    pinMode(z, INPUT);
    pinMode(LD, OUTPUT);
    pinMode(RD, OUTPUT);
    pinMode(FD, OUTPUT);
    pinMode(BD, OUTPUT);
    pinMode(test, INPUT);
}
void loop()
{
    float temp_x;
    float temp_y;

    float temp_z;
    analogRead(x);
    analogRead(y);
    analogRead(z);
    temp_x = analogRead(x);
    temp_y = analogRead(y);
    temp_z = analogRead(z);
    /* Can print the value of acceleration in x, y, z direction on serial monitor and calibrate the accelerometer */
    If(temp_x < 340) // Can use acceleration in y, z direction also according to the model
    {
        digitalWrite(LD, HIGH);
        digitalWrite(RD, LOW);
        digitalWrite(FD, LOW);
        digitalWrite(BD, LOW);
        Serial.println("LD");
    }
    else if (temp_x > 370) // Can use acceleration in y, z direction also according to the model
    {
        digitalWrite(RD, HIGH);
        digitalWrite(LD, LOW);
        digitalWrite(FD, LOW);
        digitalWrite(BD, LOW);
        Serial.println("RD");
    }
    else if (temp_y > 365) // Can use acceleration in x, z direction also according to the model
    {

        digitalWrite(FD, HIGH);
        digitalWrite(RD, LOW);
        digitalWrite(LD, LOW);
        digitalWrite(BD, LOW);
        Serial.println("FD");
    }
    else

        if (temp_y < 332) // Can use acceleration in x, z direction also according to the model
    {
        digitalWrite(BD, HIGH);
        digitalWrite(RD, LOW);
        digitalWrite(FD, LOW);
        digitalWrite(LD, LOW);
        Serial.println("BD");
    }
    else if (temp_x > 340 && temp_x < 370 && temp_y < 365 && temp_y > 332)
    {
        digitalWrite(LD, LOW);
        digitalWrite(RD, LOW);
        digitalWrite(FD, LOW);
        digitalWrite(BD, LOW);
        Serial.println("stop");
    }
    Serial.println(digitalRead(test));
    Serial.print("acceleration of x = ");
    Serial.print(analogRead(x));

    Serial.print(" ");
    Serial.print("acceleration of y = ");
    Serial.print(analogRead(y));
    Serial.print(" ");
    Serial.print("acceleration of z = ");
    Serial.println(analogRead(z));
}