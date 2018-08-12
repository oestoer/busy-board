/*
Busy Board
 */

#define GREEN_BTN 2
#define GREEN_LED 3
#define AMBER_BTN 4
#define AMBER_LED 5
#define RED_BTN   6
#define RED_LED   7
#define BLUE_BTN  8
#define BLUE_LED  9
#define WHITE_BTN 10
#define WHITE_LED 11

void setup() {
  pinMode(GREEN_BTN, INPUT_PULLUP);
  pinMode(GREEN_LED, OUTPUT);
  digitalWrite(GREEN_LED, LOW);

  pinMode(AMBER_BTN, INPUT_PULLUP);
  pinMode(AMBER_LED, OUTPUT);
  digitalWrite(AMBER_LED, LOW);

  pinMode(RED_BTN, INPUT_PULLUP);
  pinMode(RED_LED, OUTPUT);
  digitalWrite(RED_LED, LOW);

  pinMode(BLUE_BTN, INPUT_PULLUP);
  pinMode(BLUE_LED, OUTPUT);
  digitalWrite(BLUE_LED, LOW);

  pinMode(WHITE_BTN, INPUT_PULLUP);
  pinMode(WHITE_LED, OUTPUT);
  digitalWrite(WHITE_LED, LOW);
}

void loop() {
  handleArcadeButton(GREEN_BTN, GREEN_LED);
  handleArcadeButton(AMBER_BTN, AMBER_LED);
  handleArcadeButton(RED_BTN,   RED_LED);
  handleArcadeButton(BLUE_BTN,  BLUE_LED);
  handleArcadeButton(WHITE_BTN, WHITE_LED);
}

bool btnIsPressed(int btn) {
  return HIGH != digitalRead(btn);
}

void handleArcadeButton(int btn, int led) {
  if (btnIsPressed(btn)) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}

