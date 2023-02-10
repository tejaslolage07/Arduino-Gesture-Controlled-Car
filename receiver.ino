// Since signal from HT12D are in analog form so we read them on analog pins
#define FD A0
#define BD A5
#define LD A1
#define RD A3

#define m11 3 // for left motor
#define m12 4 // for left motor
#define m21 5 // for right motor
#define m22 6 // for right motor
void forward()
{
    // For forward motion we keep both the motor’s one pin high in such a way that polarity should be same
    digitalWrite(m11, HIGH);
    digitalWrite(m12, LOW);
    digitalWrite(m21, HIGH);
    digitalWrite(m22, LOW);
}

void backward()
{
    digitalWrite(m11, LOW);
    digitalWrite(m12, HIGH);
    digitalWrite(m21, LOW);
    digitalWrite(m22, HIGH);
}
void right()
{
    digitalWrite(m11, HIGH); /* for left motion we keep left motor at rest by keeping both the
    m12 and m11 pins high*/
    digitalWrite(m12, HIGH);
    digitalWrite(m21, HIGH);
    digitalWrite(m22, LOW);
}

void left()
{
    digitalWrite(m11, HIGH);
    digitalWrite(m12, LOW);
    digitalWrite(m21, HIGH); /* for left motion we keep left motor at rest by keeping both the
    m12 and m11 pins high*/
    digitalWrite(m22, HIGH);
}
void Stop()
{
    digitalWrite(m11, LOW);
    digitalWrite(m12, LOW);
    digitalWrite(m21, LOW);
    digitalWrite(m22, LOW);
}
void setup()
{
    pinMode(FD, INPUT);
    pinMode(BD, INPUT);
    pinMode(LD, INPUT);
    pinMode(RD, INPUT);

    pinMode(m11, OUTPUT);
    pinMode(m12, OUTPUT);
    pinMode(m21, OUTPUT);
    pinMode(m22, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    int F = digitalRead(FD);
    int B = digitalRead(BD);
    int L = digitalRead(LD);
    int R = digitalRead(RD);
    if (F == 1 && B == 0 && L == 0 && R == 0)
        forward();
    else if (F == 0 && B == 1 && L == 0 && R == 0)
        backward();
    else if (F == 0 && B == 0 && L == 1 && R == 0)
        left();
    else if (F == 0 && B == 0 && L == 0 && R == 1)
        right();
    else
        Stop();
}