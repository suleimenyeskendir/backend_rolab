#define D1_ENA 37
#define D1_IN1 35
#define D1_IN2 33
#define D1_IN3 36
#define D1_IN4 34
#define D1_ENB 32

#define D2_ENA 53
#define D2_IN1 51
#define D2_IN2 49
#define D2_IN3 52
#define D2_IN4 50
#define D2_ENB 48

#define D3_ENA 45
#define D3_IN1 43
#define D3_IN2 41
#define D3_IN3 44
#define D3_IN4 42
#define D3_ENB 40

int x = 0;
int SerialMovement();
void forward();
void left_turn();
void right_turn();
void backward();
void nullify();

void setup() {
Serial.begin(115200);
Serial.setTimeout(1);

pinMode(D1_ENA, OUTPUT);
pinMode(D1_IN1, OUTPUT);
pinMode(D1_IN2, OUTPUT);
pinMode(D1_IN3, OUTPUT);
pinMode(D1_IN4, OUTPUT);
pinMode(D1_ENB, OUTPUT);

pinMode(D2_ENA, OUTPUT);
pinMode(D2_IN1, OUTPUT);
pinMode(D2_IN2, OUTPUT);
pinMode(D2_IN3, OUTPUT);
pinMode(D2_IN4, OUTPUT);
pinMode(D2_ENB, OUTPUT);

pinMode(D3_ENA, OUTPUT);
pinMode(D3_IN1, OUTPUT);
pinMode(D3_IN2, OUTPUT);
pinMode(D3_IN3, OUTPUT);
pinMode(D3_IN4, OUTPUT);
pinMode(D3_ENB, OUTPUT);

analogWrite(D1_ENA, 255);
analogWrite(D1_ENB, 255);

analogWrite(D2_ENA, 255);
analogWrite(D2_ENB, 255);

analogWrite(D3_ENA, 255);
analogWrite(D3_ENB, 255);

nullify();

}

void loop() {
x = SerialMovement();
switch (x) {
    case 0:
        nullify();
        break;
    case 1:
        forward();
        delay(100);
        break;
    case 2:
        left_turn();
        delay(100);
        break;
    case 3:
        right_turn();
        delay(100);
        break;
    case 4:
        backward();
        delay(100);
        break;
    // default:

    //     break;
}

}

void forward(){
    digitalWrite(D1_IN1, HIGH);
    digitalWrite(D1_IN2, LOW);
    digitalWrite(D1_IN3, LOW);
    digitalWrite(D1_IN4, HIGH);

    digitalWrite(D2_IN1, HIGH);
    digitalWrite(D2_IN2, LOW);
    digitalWrite(D2_IN3, LOW);
    digitalWrite(D2_IN4, HIGH);

    digitalWrite(D3_IN1, HIGH);
    digitalWrite(D3_IN2, LOW);
    digitalWrite(D3_IN3, LOW);
    digitalWrite(D3_IN4, HIGH);
}

void left_turn(){
    digitalWrite(D1_IN1, LOW);
    digitalWrite(D1_IN2, HIGH);
    digitalWrite(D1_IN3, LOW);
    digitalWrite(D1_IN4, HIGH);

    digitalWrite(D2_IN1, LOW);
    digitalWrite(D2_IN2, HIGH);
    digitalWrite(D2_IN3, LOW);
    digitalWrite(D2_IN4, HIGH);

    digitalWrite(D3_IN1, LOW);
    digitalWrite(D3_IN2, HIGH);
    digitalWrite(D3_IN3, LOW);
    digitalWrite(D3_IN4, HIGH);
}

void right_turn(){
    digitalWrite(D1_IN1, HIGH);
    digitalWrite(D1_IN2, LOW);
    digitalWrite(D1_IN3, HIGH);
    digitalWrite(D1_IN4, LOW);

    digitalWrite(D2_IN1, HIGH);
    digitalWrite(D2_IN2, LOW);
    digitalWrite(D2_IN3, HIGH);
    digitalWrite(D2_IN4, LOW);

    digitalWrite(D3_IN1, HIGH);
    digitalWrite(D3_IN2, LOW);
    digitalWrite(D3_IN3, HIGH);
    digitalWrite(D3_IN4, LOW);
}

void backward(){
    digitalWrite(D1_IN1, LOW);
    digitalWrite(D1_IN2, HIGH);
    digitalWrite(D1_IN3, HIGH);
    digitalWrite(D1_IN4, LOW);

    digitalWrite(D2_IN1, LOW);
    digitalWrite(D2_IN2, HIGH);
    digitalWrite(D2_IN3, HIGH);
    digitalWrite(D2_IN4, LOW);

    digitalWrite(D3_IN1, LOW);
    digitalWrite(D3_IN2, HIGH);
    digitalWrite(D3_IN3, HIGH);
    digitalWrite(D3_IN4, LOW);
}

void nullify(){
    digitalWrite(D1_IN1, LOW);
    digitalWrite(D1_IN2, LOW);
    digitalWrite(D1_IN3, LOW);
    digitalWrite(D1_IN4, LOW);

    digitalWrite(D2_IN1, LOW);
    digitalWrite(D2_IN2, LOW);
    digitalWrite(D2_IN3, LOW);
    digitalWrite(D2_IN4, LOW);

    digitalWrite(D3_IN1, LOW);
    digitalWrite(D3_IN2, LOW);
    digitalWrite(D3_IN3, LOW);
    digitalWrite(D3_IN4, LOW);
}

int SerialMovement(){
    while (!Serial.available());
    return Serial.readString().toInt();;
}
