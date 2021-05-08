// Test circuit to test current-limiting resistors for a 7 segment
// display at 1/4 duty

#define SEG_A ((uint8_t)(1<<0))
#define SEG_B ((uint8_t)(1<<1))
#define SEG_C ((uint8_t)(1<<2))
#define SEG_D ((uint8_t)(1<<3))
#define SEG_E ((uint8_t)(1<<4))
#define SEG_F ((uint8_t)(1<<5))
#define SEG_G ((uint8_t)(1<<6))

const uint8_t g_hexfont[16] = {
  (uint8_t) ~(SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_F),
  (uint8_t) ~(SEG_B|SEG_C),
  (uint8_t) ~(SEG_A|SEG_B|SEG_D|SEG_E|SEG_G),
  (uint8_t) ~(SEG_A|SEG_B|SEG_C|SEG_D|SEG_G),
  (uint8_t) ~(SEG_B|SEG_C|SEG_F|SEG_G),
  (uint8_t) ~(SEG_A|SEG_C|SEG_D|SEG_F|SEG_G),
  (uint8_t) ~(SEG_A|SEG_C|SEG_D|SEG_E|SEG_F|SEG_G),
  (uint8_t) ~(SEG_A|SEG_B|SEG_C),
  (uint8_t) ~(SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_F|SEG_G),
  (uint8_t) ~(SEG_A|SEG_B|SEG_C|SEG_F|SEG_G),
  (uint8_t) ~(SEG_A|SEG_B|SEG_C|SEG_E|SEG_F|SEG_G),
  (uint8_t) ~(SEG_C|SEG_D|SEG_E|SEG_F|SEG_G),
  (uint8_t) ~(SEG_D|SEG_E|SEG_G),
  (uint8_t) ~(SEG_B|SEG_C|SEG_D|SEG_E|SEG_G),
  (uint8_t) ~(SEG_A|SEG_D|SEG_E|SEG_F|SEG_G),
  (uint8_t) ~(SEG_A|SEG_E|SEG_F|SEG_G),
};

// Connections:
// - port D pins 0 through 7 are connected to the LED segment
//   cathodes via current-limiting resistors (these are digital
//   pins 0 through 7, although note that Arduino digital pins 0 and 1
//   are actually bits 1 and 0, respectively, in port D)
// - Arduino digital pin 7 is connected to the base of a PNP
//   (2N3906) transistor via a 4.7k resistor
// - the transistor's emitter is connected to VCC (the Arduino's +5V)
// - the transistor's collector is connected to the LED display's
//   common anode pins

void setup() {
  DDRD = 0x7F;
  pinMode(8, OUTPUT);

}

uint8_t muxCount = 0;
uint8_t data = 0;

void loop() {
  if ((muxCount & 0x3) == 0) {
    PORTD = g_hexfont[data & 0xF];
    digitalWrite(8, LOW);
  } else {
    digitalWrite(8, HIGH);
  }

  delayMicroseconds(500); // This will give us approximately a 500 Hz refresh rate
  muxCount++;
  if (muxCount == 255) {
    data++;
    if (data > 15) { data = 0; }
  }
}
