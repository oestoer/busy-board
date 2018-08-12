/*
Busy Board
 */

#define GREEN_BTN 2
#define GREEN_LED 3
#define AMBER_BTN 4
#define AMBER_LED 5
#define RED_BTN   7 // due to the PWM availability the order is swapped for red
#define RED_LED   6
#define BLUE_BTN  8
#define BLUE_LED  9
#define WHITE_BTN 10
#define WHITE_LED 11
#define DARKEST 0
#define BRIGHTEST 255

int greenBrightness = DARKEST;
int amberBrightness = DARKEST;
int redBrightness   = DARKEST;
int blueBrightness  = DARKEST;
int whiteBrightness = DARKEST;

int const fadeAmount = 5;

void setup() {
  pinMode(GREEN_BTN, INPUT_PULLUP);
  pinMode(GREEN_LED, OUTPUT);
  analogWrite(GREEN_LED, greenBrightness);

  pinMode(AMBER_BTN, INPUT_PULLUP);
  pinMode(AMBER_LED, OUTPUT);
  analogWrite(AMBER_LED, amberBrightness);

  pinMode(RED_BTN, INPUT_PULLUP);
  pinMode(RED_LED, OUTPUT);
  analogWrite(RED_LED, redBrightness);

  pinMode(BLUE_BTN, INPUT_PULLUP);
  pinMode(BLUE_LED, OUTPUT);
  analogWrite(BLUE_LED, blueBrightness);

  pinMode(WHITE_BTN, INPUT_PULLUP);
  pinMode(WHITE_LED, OUTPUT);
  analogWrite(WHITE_LED, whiteBrightness);
}

void loop() {
  greenBrightness = handleArcadeButton(GREEN_BTN, GREEN_LED, greenBrightness);
  amberBrightness = handleArcadeButton(AMBER_BTN, AMBER_LED, amberBrightness);
  redBrightness   = handleArcadeButton(RED_BTN,   RED_LED,   redBrightness);
  blueBrightness  = handleArcadeButton(BLUE_BTN,  BLUE_LED,  blueBrightness);
  whiteBrightness = handleArcadeButton(WHITE_BTN, WHITE_LED, whiteBrightness);
  delay(50);
}

bool btnIsPressed(int btn) {
  return HIGH != digitalRead(btn);
}

int handleArcadeButton(int btn, int led, int brightness) {
  if (btnIsPressed(btn)) {
    analogWrite(led, BRIGHTEST);

    return BRIGHTEST;
  }
  analogWrite(led, brightness);

  return fade(brightness);
}

int fade(int brightness) {
  int dimmed = brightness - fadeAmount;
  if (dimmed > DARKEST) {
    return dimmed;
  }

  return DARKEST;
}
