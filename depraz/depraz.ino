#include <Mouse.h>

#define SPEED_CONSTANT 5

// Quadrature Encoder Pins
int y1Pin = 0;
int y2Pin = 1;
int x1Pin = 2;
int x2Pin = 3;

// Button Pins
int midPin = 7;
int rightPin = 8;
int leftPin = 9;

// Button state
int mid;
int left;
int right;

// Variables the interrupts use to hold pin stats
int y1;
int y2;
int x1;
int x2;

// If the mouse has moved in either the X or Y axis,
// the corresponding ISR will set this integer to 1 or -1.
volatile int xmoved;
volatile int ymoved;

void setup()
{
  Mouse.begin();
  // Set all pins as inputs
  pinMode(y1Pin, INPUT);
  pinMode(y2Pin, INPUT);
  pinMode(x1Pin, INPUT);
  pinMode(x2Pin, INPUT);
  pinMode(midPin, INPUT);
  pinMode(rightPin, INPUT);
  pinMode(leftPin, INPUT);
  // Attach interrupts on the falling edges of 1 encoder per pair. This has proven sufficient.
  attachInterrupt(digitalPinToInterrupt(y1Pin), yint, FALLING);
  attachInterrupt(digitalPinToInterrupt(x1Pin), xint, FALLING);
  delay(1000);
}

// The y-axis ISR
void yint() {
  y1 = digitalRead(y1Pin);
  y2 = digitalRead(y2Pin);

  if (y1 == y2) {
    ymoved = -1;
  } else {
    ymoved = 1;
  }
}

// The x-axis ISR
void xint() {
  x1 = digitalRead(x1Pin);
  x2 = digitalRead(x2Pin);

  if (x1 == x2) {
    xmoved = -1;
  } else {
    xmoved = 1;
  }
}


void loop()
{
  // If the ISRs have fired, ymoved and/or xmoved will be set.
  if (ymoved != 0) {
      Mouse.move(0, SPEED_CONSTANT*ymoved, 0);
      ymoved = 0;
  }

  if (xmoved != 0) {
      Mouse.move(-SPEED_CONSTANT*xmoved, 0, 0);
      xmoved = 0;
  }

  // Read the buttons. Doing it like this is more than fast enough.
  left = digitalRead(leftPin);
  if (!left) {
    Mouse.press(MOUSE_LEFT);
  } else {
    Mouse.release(MOUSE_LEFT);
  }
  right = digitalRead(rightPin);
  if (!right) {
    Mouse.press(MOUSE_RIGHT);
  } else {
    Mouse.release(MOUSE_RIGHT);
  }
  mid = digitalRead(midPin);
  if (!mid) {
    Mouse.press(MOUSE_MIDDLE);
  } else {
    Mouse.release(MOUSE_MIDDLE);
  }
}
