#include <LedControl.h>

// www.elegoo.com
// 2016.12.09

// Arduino pin numbers
const int SW_pin = 8; // digital pin connected to switch output
const int X_pin  = 0; // analog pin connected to X output
const int Y_pin  = 1; // analog pin connected to Y output

LedControl lc = LedControl(5, 4, 3, 1);

int x             = 0;
int y             = 0;
int click         = 0;
int thresholdup   = 600;
int thresholddown = 400;

void setup() {
    pinMode(SW_pin, INPUT);
    digitalWrite(SW_pin, HIGH);
    Serial.begin(9600);

    /*
     The MAX72XX is in power-saving mode on startup,
     we have to do a wakeup call
     */
    lc.shutdown(0, false);
    /* Set the brightness to a medium values */
    lc.setIntensity(0, 5);
    /* and clear the display */
    lc.clearDisplay(0);
}

void right() {
    byte a[8] = {B00011000, B00011000, B00011000, B00011000,
                 B10011001, B11011011, B01111110, B00111100};

    lc.setRow(0, 0, a[0]);
    lc.setRow(0, 1, a[1]);
    lc.setRow(0, 2, a[2]);
    lc.setRow(0, 3, a[3]);
    lc.setRow(0, 4, a[4]);
    lc.setRow(0, 5, a[5]);
    lc.setRow(0, 6, a[6]);
    lc.setRow(0, 7, a[7]);
}

void left() {
    byte a[8] = {B00111100, B01111110, B11011011, B10011001,
                 B00011000, B00011000, B00011000, B00011000};

    lc.setRow(0, 0, a[0]);
    lc.setRow(0, 1, a[1]);
    lc.setRow(0, 2, a[2]);
    lc.setRow(0, 3, a[3]);
    lc.setRow(0, 4, a[4]);
    lc.setRow(0, 5, a[5]);
    lc.setRow(0, 6, a[6]);
    lc.setRow(0, 7, a[7]);
}

void up() {
    byte a[8] = {B00011000, B00001100, B00000110, B11111111,
                 B11111111, B00000110, B00001100, B00011000};

    lc.setRow(0, 0, a[0]);
    lc.setRow(0, 1, a[1]);
    lc.setRow(0, 2, a[2]);
    lc.setRow(0, 3, a[3]);
    lc.setRow(0, 4, a[4]);
    lc.setRow(0, 5, a[5]);
    lc.setRow(0, 6, a[6]);
    lc.setRow(0, 7, a[7]);
}

void down() {
    byte a[8] = {B00011000, B00110000, B01100000, B11111111,
                 B11111111, B01100000, B00110000, B00011000};

    lc.setRow(0, 0, a[0]);
    lc.setRow(0, 1, a[1]);
    lc.setRow(0, 2, a[2]);
    lc.setRow(0, 3, a[3]);
    lc.setRow(0, 4, a[4]);
    lc.setRow(0, 5, a[5]);
    lc.setRow(0, 6, a[6]);
    lc.setRow(0, 7, a[7]);
}

void upright() {
    byte a[8] = {B11000000, B11100000, B01110011, B00111011,
                 B00011111, B00001111, B00111111, B00111111};

    lc.setRow(0, 0, a[0]);
    lc.setRow(0, 1, a[1]);
    lc.setRow(0, 2, a[2]);
    lc.setRow(0, 3, a[3]);
    lc.setRow(0, 4, a[4]);
    lc.setRow(0, 5, a[5]);
    lc.setRow(0, 6, a[6]);
    lc.setRow(0, 7, a[7]);
}

void upleft() {
    byte a[8] = {B00111111, B00111111, B00001111, B00011111,
                 B00111011, B01110011, B11100000, B11000000};

    lc.setRow(0, 0, a[0]);
    lc.setRow(0, 1, a[1]);
    lc.setRow(0, 2, a[2]);
    lc.setRow(0, 3, a[3]);
    lc.setRow(0, 4, a[4]);
    lc.setRow(0, 5, a[5]);
    lc.setRow(0, 6, a[6]);
    lc.setRow(0, 7, a[7]);
}

void downleft() {
    byte a[8] = {B11111100, B11111100, B11110000, B11111000,
                 B11011100, B11001110, B00000111, B00000011};

    lc.setRow(0, 0, a[0]);
    lc.setRow(0, 1, a[1]);
    lc.setRow(0, 2, a[2]);
    lc.setRow(0, 3, a[3]);
    lc.setRow(0, 4, a[4]);
    lc.setRow(0, 5, a[5]);
    lc.setRow(0, 6, a[6]);
    lc.setRow(0, 7, a[7]);
}

void downright() {
    byte a[8] = {B00000011, B00000111, B11001110, B11011100,
                 B11111000, B11110000, B11111100, B11111100};

    lc.setRow(0, 0, a[0]);
    lc.setRow(0, 1, a[1]);
    lc.setRow(0, 2, a[2]);
    lc.setRow(0, 3, a[3]);
    lc.setRow(0, 4, a[4]);
    lc.setRow(0, 5, a[5]);
    lc.setRow(0, 6, a[6]);
    lc.setRow(0, 7, a[7]);
}

void point() {
    byte a[8] = {B00000000, B00000000, B00111100, B00111100,
                 B00111100, B00111100, B00000000, B00000000};

    lc.setRow(0, 0, a[0]);
    lc.setRow(0, 1, a[1]);
    lc.setRow(0, 2, a[2]);
    lc.setRow(0, 3, a[3]);
    lc.setRow(0, 4, a[4]);
    lc.setRow(0, 5, a[5]);
    lc.setRow(0, 6, a[6]);
    lc.setRow(0, 7, a[7]);
}

void circle() {
    byte a[8] = {B00000000, B00000000, B00111100, B00100100,
                 B00100100, B00111100, B00000000, B00000000};

    lc.setRow(0, 0, a[0]);
    lc.setRow(0, 1, a[1]);
    lc.setRow(0, 2, a[2]);
    lc.setRow(0, 3, a[3]);
    lc.setRow(0, 4, a[4]);
    lc.setRow(0, 5, a[5]);
    lc.setRow(0, 6, a[6]);
    lc.setRow(0, 7, a[7]);
}

void loop() {

    click = digitalRead(SW_pin);
    x     = analogRead(X_pin);
    y     = analogRead(Y_pin);

    Serial.print("Switch:  ");
    Serial.print(click);
    Serial.print("\n");
    Serial.print("X-axis: ");
    Serial.print(x);
    Serial.print("\n");
    Serial.print("Y-axis: ");
    Serial.println(y);
    Serial.print("\n\n");

    if (x > thresholdup && y > thresholdup) {
        downright();
    } else if (x > thresholdup && y < thresholddown) {
        upright();
    } else if (x < thresholddown && y > thresholdup) {
        downleft();
    } else if (x < thresholddown && y < thresholddown) {
        upleft();
    } else if (x > thresholdup) {
        right();
    } else if (x < thresholddown) {
        left();
    } else if (y > thresholdup) {
        down();
    } else if (y < thresholddown) {
        up();
    } else if (click == LOW) {
        circle();
    } else {
        point();
    }

    delay(5);
}
