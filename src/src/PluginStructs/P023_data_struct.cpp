#include "../PluginStructs/P023_data_struct.h"
#ifdef USES_P023

#include "../Helpers/Misc.h"
#include "../Helpers/StringParser.h"


const char Plugin_023_myFont_Size[] PROGMEM = {
  0x05, // SPACE
  0x05, // !
  0x07, // "
  0x08, // #
  0x08, // $
  0x08, // %
  0x08, // &
  0x06, // '
  0x06, // (
  0x06, // )
  0x08, // *
  0x08, // +
  0x05, // ,
  0x08, // -
  0x05, // .
  0x08, // /
  0x08, // 0
  0x07, // 1
  0x08, // 2
  0x08, // 3
  0x08, // 4
  0x08, // 5
  0x08, // 6
  0x08, // 7
  0x08, // 8
  0x08, // 9
  0x06, // :
  0x06, // ;
  0x07, // <
  0x08, // =
  0x07, // >
  0x08, // ?
  0x08, // @
  0x08, // A
  0x08, // B
  0x08, // C
  0x08, // D
  0x08, // E
  0x08, // F
  0x08, // G
  0x08, // H
  0x06, // I
  0x08, // J
  0x08, // K
  0x08, // L
  0x08, // M
  0x08, // N
  0x08, // O
  0x08, // P
  0x08, // Q
  0x08, // R
  0x08, // S
  0x08, // T
  0x08, // U
  0x08, // V
  0x08, // W
  0x08, // X
  0x08, // Y
  0x08, // Z
  0x06, // [
  0x08, // BACKSLASH
  0x06, // ]
  0x08, // ^
  0x08, // _
  0x06, // `
  0x08, // a
  0x08, // b
  0x07, // c
  0x08, // d
  0x08, // e
  0x07, // f
  0x08, // g
  0x08, // h
  0x05, // i
  0x06, // j
  0x07, // k
  0x06, // l
  0x08, // m
  0x07, // n
  0x07, // o
  0x07, // p
  0x07, // q
  0x07, // r
  0x07, // s
  0x06, // t
  0x07, // u
  0x08, // v
  0x08, // w
  0x08, // x
  0x07, // y
  0x08, // z
  0x06, // {
  0x05, // |
  0x06, // }
  0x08, // ~
  0x08  // DEL
};


const char Plugin_023_myFont[][8] PROGMEM = {
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, // SPACE
  { 0x00, 0x00, 0x5F, 0x00, 0x00, 0x00, 0x00, 0x00 }, // !
  { 0x00, 0x00, 0x07, 0x00, 0x07, 0x00, 0x00, 0x00 }, // "
  { 0x00, 0x14, 0x7F, 0x14, 0x7F, 0x14, 0x00, 0x00 }, // #
  { 0x00, 0x24, 0x2A, 0x7F, 0x2A, 0x12, 0x00, 0x00 }, // $
  { 0x00, 0x23, 0x13, 0x08, 0x64, 0x62, 0x00, 0x00 }, // %
  { 0x00, 0x36, 0x49, 0x55, 0x22, 0x50, 0x00, 0x00 }, // &
  { 0x00, 0x00, 0x05, 0x03, 0x00, 0x00, 0x00, 0x00 }, // '
  { 0x00, 0x1C, 0x22, 0x41, 0x00, 0x00, 0x00, 0x00 }, // (
  { 0x00, 0x41, 0x22, 0x1C, 0x00, 0x00, 0x00, 0x00 }, // )
  { 0x00, 0x08, 0x2A, 0x1C, 0x2A, 0x08, 0x00, 0x00 }, // *
  { 0x00, 0x08, 0x08, 0x3E, 0x08, 0x08, 0x00, 0x00 }, // +
  { 0x00, 0xA0, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00 }, // ,
  { 0x00, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00 }, // -
  { 0x00, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00 }, // .
  { 0x00, 0x20, 0x10, 0x08, 0x04, 0x02, 0x00, 0x00 }, // /
  { 0x00, 0x3E, 0x51, 0x49, 0x45, 0x3E, 0x00, 0x00 }, // 0
  { 0x00, 0x00, 0x42, 0x7F, 0x40, 0x00, 0x00, 0x00 }, // 1
  { 0x00, 0x62, 0x51, 0x49, 0x49, 0x46, 0x00, 0x00 }, // 2
  { 0x00, 0x22, 0x41, 0x49, 0x49, 0x36, 0x00, 0x00 }, // 3
  { 0x00, 0x18, 0x14, 0x12, 0x7F, 0x10, 0x00, 0x00 }, // 4
  { 0x00, 0x27, 0x45, 0x45, 0x45, 0x39, 0x00, 0x00 }, // 5
  { 0x00, 0x3C, 0x4A, 0x49, 0x49, 0x30, 0x00, 0x00 }, // 6
  { 0x00, 0x01, 0x71, 0x09, 0x05, 0x03, 0x00, 0x00 }, // 7
  { 0x00, 0x36, 0x49, 0x49, 0x49, 0x36, 0x00, 0x00 }, // 8
  { 0x00, 0x06, 0x49, 0x49, 0x29, 0x1E, 0x00, 0x00 }, // 9
  { 0x00, 0x00, 0x36, 0x36, 0x00, 0x00, 0x00, 0x00 }, // :
  { 0x00, 0x00, 0xAC, 0x6C, 0x00, 0x00, 0x00, 0x00 }, // ;
  { 0x00, 0x08, 0x14, 0x22, 0x41, 0x00, 0x00, 0x00 }, // <
  { 0x00, 0x14, 0x14, 0x14, 0x14, 0x14, 0x00, 0x00 }, // =
  { 0x00, 0x41, 0x22, 0x14, 0x08, 0x00, 0x00, 0x00 }, // >
  { 0x00, 0x02, 0x01, 0x51, 0x09, 0x06, 0x00, 0x00 }, // ?
  { 0x00, 0x32, 0x49, 0x79, 0x41, 0x3E, 0x00, 0x00 }, // @
  { 0x00, 0x7E, 0x09, 0x09, 0x09, 0x7E, 0x00, 0x00 }, // A
  { 0x00, 0x7F, 0x49, 0x49, 0x49, 0x36, 0x00, 0x00 }, // B
  { 0x00, 0x3E, 0x41, 0x41, 0x41, 0x22, 0x00, 0x00 }, // C
  { 0x00, 0x7F, 0x41, 0x41, 0x22, 0x1C, 0x00, 0x00 }, // D
  { 0x00, 0x7F, 0x49, 0x49, 0x49, 0x41, 0x00, 0x00 }, // E
  { 0x00, 0x7F, 0x09, 0x09, 0x09, 0x01, 0x00, 0x00 }, // F
  { 0x00, 0x3E, 0x41, 0x41, 0x51, 0x72, 0x00, 0x00 }, // G
  { 0x00, 0x7F, 0x08, 0x08, 0x08, 0x7F, 0x00, 0x00 }, // H
  { 0x00, 0x41, 0x7F, 0x41, 0x00, 0x00, 0x00, 0x00 }, // I
  { 0x00, 0x20, 0x40, 0x41, 0x3F, 0x01, 0x00, 0x00 }, // J
  { 0x00, 0x7F, 0x08, 0x14, 0x22, 0x41, 0x00, 0x00 }, // K
  { 0x00, 0x7F, 0x40, 0x40, 0x40, 0x40, 0x00, 0x00 }, // L
  { 0x00, 0x7F, 0x02, 0x0C, 0x02, 0x7F, 0x00, 0x00 }, // M
  { 0x00, 0x7F, 0x04, 0x08, 0x10, 0x7F, 0x00, 0x00 }, // N
  { 0x00, 0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00, 0x00 }, // O
  { 0x00, 0x7F, 0x09, 0x09, 0x09, 0x06, 0x00, 0x00 }, // P
  { 0x00, 0x3E, 0x41, 0x51, 0x21, 0x5E, 0x00, 0x00 }, // Q
  { 0x00, 0x7F, 0x09, 0x19, 0x29, 0x46, 0x00, 0x00 }, // R
  { 0x00, 0x26, 0x49, 0x49, 0x49, 0x32, 0x00, 0x00 }, // S
  { 0x00, 0x01, 0x01, 0x7F, 0x01, 0x01, 0x00, 0x00 }, // T
  { 0x00, 0x3F, 0x40, 0x40, 0x40, 0x3F, 0x00, 0x00 }, // U
  { 0x00, 0x1F, 0x20, 0x40, 0x20, 0x1F, 0x00, 0x00 }, // V
  { 0x00, 0x3F, 0x40, 0x38, 0x40, 0x3F, 0x00, 0x00 }, // W
  { 0x00, 0x63, 0x14, 0x08, 0x14, 0x63, 0x00, 0x00 }, // X
  { 0x00, 0x03, 0x04, 0x78, 0x04, 0x03, 0x00, 0x00 }, // Y
  { 0x00, 0x61, 0x51, 0x49, 0x45, 0x43, 0x00, 0x00 }, // Z
  { 0x00, 0x7F, 0x41, 0x41, 0x00, 0x00, 0x00, 0x00 }, // [
  { 0x00, 0x02, 0x04, 0x08, 0x10, 0x20, 0x00, 0x00 }, // BACKSLASH
  { 0x00, 0x41, 0x41, 0x7F, 0x00, 0x00, 0x00, 0x00 }, // ]
  { 0x00, 0x04, 0x02, 0x01, 0x02, 0x04, 0x00, 0x00 }, // ^
  { 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00 }, // _
  { 0x00, 0x01, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00 }, // `
  { 0x00, 0x20, 0x54, 0x54, 0x54, 0x78, 0x00, 0x00 }, // a
  { 0x00, 0x7F, 0x48, 0x44, 0x44, 0x38, 0x00, 0x00 }, // b
  { 0x00, 0x38, 0x44, 0x44, 0x28, 0x00, 0x00, 0x00 }, // c
  { 0x00, 0x38, 0x44, 0x44, 0x48, 0x7F, 0x00, 0x00 }, // d
  { 0x00, 0x38, 0x54, 0x54, 0x54, 0x18, 0x00, 0x00 }, // e
  { 0x00, 0x08, 0x7E, 0x09, 0x02, 0x00, 0x00, 0x00 }, // f
  { 0x00, 0x18, 0xA4, 0xA4, 0xA4, 0x7C, 0x00, 0x00 }, // g
  { 0x00, 0x7F, 0x08, 0x04, 0x04, 0x78, 0x00, 0x00 }, // h
  { 0x00, 0x00, 0x7D, 0x00, 0x00, 0x00, 0x00, 0x00 }, // i
  { 0x00, 0x80, 0x84, 0x7D, 0x00, 0x00, 0x00, 0x00 }, // j
  { 0x00, 0x7F, 0x10, 0x28, 0x44, 0x00, 0x00, 0x00 }, // k
  { 0x00, 0x41, 0x7F, 0x40, 0x00, 0x00, 0x00, 0x00 }, // l
  { 0x00, 0x7C, 0x04, 0x18, 0x04, 0x78, 0x00, 0x00 }, // m
  { 0x00, 0x7C, 0x08, 0x04, 0x7C, 0x00, 0x00, 0x00 }, // n
  { 0x00, 0x38, 0x44, 0x44, 0x38, 0x00, 0x00, 0x00 }, // o
  { 0x00, 0xFC, 0x24, 0x24, 0x18, 0x00, 0x00, 0x00 }, // p
  { 0x00, 0x18, 0x24, 0x24, 0xFC, 0x00, 0x00, 0x00 }, // q
  { 0x00, 0x00, 0x7C, 0x08, 0x04, 0x00, 0x00, 0x00 }, // r
  { 0x00, 0x48, 0x54, 0x54, 0x24, 0x00, 0x00, 0x00 }, // s
  { 0x00, 0x04, 0x7F, 0x44, 0x00, 0x00, 0x00, 0x00 }, // t
  { 0x00, 0x3C, 0x40, 0x40, 0x7C, 0x00, 0x00, 0x00 }, // u
  { 0x00, 0x1C, 0x20, 0x40, 0x20, 0x1C, 0x00, 0x00 }, // v
  { 0x00, 0x3C, 0x40, 0x30, 0x40, 0x3C, 0x00, 0x00 }, // w
  { 0x00, 0x44, 0x28, 0x10, 0x28, 0x44, 0x00, 0x00 }, // x
  { 0x00, 0x1C, 0xA0, 0xA0, 0x7C, 0x00, 0x00, 0x00 }, // y
  { 0x00, 0x44, 0x64, 0x54, 0x4C, 0x44, 0x00, 0x00 }, // z
  { 0x00, 0x08, 0x36, 0x41, 0x00, 0x00, 0x00, 0x00 }, // {
  { 0x00, 0x00, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00 }, // |
  { 0x00, 0x41, 0x36, 0x08, 0x00, 0x00, 0x00, 0x00 }, // }
  { 0x00, 0x02, 0x01, 0x01, 0x02, 0x01, 0x00, 0x00 }, // ~
  { 0x00, 0x02, 0x05, 0x05, 0x02, 0x00, 0x00, 0x00 }  // DEL
};


P023_data_struct::P023_data_struct(uint8_t _address,   uint8_t _type, P023_data_struct::Spacing _font_spacing, uint8_t _displayTimer,uint8_t _use_sh1106)
  :  address(_address), type(_type),  font_spacing(_font_spacing),  displayTimer(_displayTimer), use_sh1106(_use_sh1106)
{}

void P023_data_struct::setDisplayTimer(uint8_t _displayTimer) {
  displayOn();
  displayTimer = _displayTimer;
}

void P023_data_struct::checkDisplayTimer() {
  if (displayTimer > 0)
  {
    displayTimer--;

    if (displayTimer == 0) {
      displayOff();
    }
  }
}

// Perform some specific changes for OLED display
String P023_data_struct::parseTemplate(String& tmpString, uint8_t lineSize) {
  String result             = parseTemplate_padded(tmpString, lineSize);
  const char degree[3]      = { 0xc2, 0xb0, 0 }; // Unicode degree symbol
  const char degree_oled[2] = { 0x7F, 0 };       // P023_OLED degree symbol

  result.replace(degree, degree_oled);
  return result;
}

void P023_data_struct::resetDisplay()
{
  displayOff();
  clearDisplay();
  displayOn();
}

void P023_data_struct::StartUp_OLED()
{
  init_OLED();
  resetDisplay();
  displayOff();
  setXY(0, 0);
  clearDisplay();
  displayOn();
}

void P023_data_struct::displayOn()
{
  sendCommand(0xaf); // display on
}

void P023_data_struct::displayOff()
{
  sendCommand(0xae); // display off
}

void P023_data_struct::clearDisplay()
{
  unsigned char i, k;

  for (k = 0; k < 8; k++)
  {
    setXY(k, 0);
    {
      for (i = 0; i < 128; i++) // clear all COL
      {
        sendChar(0);            // clear all COL
      }
    }
  }
}

// Actually this sends a byte, not a char to draw in the display.
void P023_data_struct::sendChar(unsigned char data)
{
  Wire.beginTransmission(address); // begin transmitting
  Wire.write(0x40);                // data mode
  Wire.write(data);
  Wire.endTransmission();          // stop transmitting
}

// Prints a display char (not just a byte) in coordinates X Y,
// currently unused:
// void P023_data_struct::Plugin_023_sendCharXY(unsigned char data, int X, int Y)
// {
//   //if (interrupt && !doing_menu) return; // Stop printing only if interrupt is call but not in button functions
//   setXY(X, Y);
//   Wire.beginTransmission(Plugin_023_OLED_address); // begin transmitting
//   Wire.write(0x40);//data mode
//
//   for (int i = 0; i < 8; i++)
//     Wire.write(pgm_read_byte(Plugin_023_myFont[data - 0x20] + i));
//
//   Wire.endTransmission();    // stop transmitting
// }


void P023_data_struct::sendCommand(unsigned char com)
{
  Wire.beginTransmission(address); // begin transmitting
  Wire.write(0x80);                // command mode
  Wire.write(com);
  Wire.endTransmission();          // stop transmitting
}

// Set the cursor position in a 16 COL * 8 ROW map (128x64 pixels)
// or 8 COL * 5 ROW map (64x48 pixels)
void P023_data_struct::setXY(unsigned char row, unsigned char col)
{
  unsigned char col_offset = 0;

  if (use_sh1106) {
      col_offset = 0x02;    // offset of 2 when using SSH1106 controller
  }

  switch (type)
  {
    case OLED_64x48:
      col += 4;
      break;
    case OLED_64x48 | OLED_rotated:
      col += 4;
      row += 2;
  }

  sendCommand(0xb0 + row);                              // set page address
  sendCommand(0x00 + ((8 * col + col_offset) & 0x0f));  // set low col address
  sendCommand(0x10 + ((8 * col >> 4) & 0x0f));          // set high col address
}

// Prints a string regardless the cursor position.
// unused:
// void P023_data_struct::Plugin_023_sendStr(unsigned char *string)
// {
//   unsigned char i = 0;
//   while (*string)
//   {
//     for (i = 0; i < 8; i++)
//     {
//       sendChar(pgm_read_byte(Plugin_023_myFont[*string - 0x20] + i));
//     }
//     string++;
//   }
// }


// Prints a string in coordinates X Y, being multiples of 8.
// This means we have 16 COLS (0-15) and 8 ROWS (0-7).
void P023_data_struct::sendStrXY(const char *string, int X, int Y)
{
  setXY(X, Y);
  unsigned char i             = 0;
  unsigned char char_width    = 0;
  unsigned char currentPixels = Y * 8; // setXY always uses char_width = 8, Y = 0-based
  unsigned char maxPixels     = 128;   // Assumed default display width

  switch (type) {                      // Cater for that 1 smaller size display
    case OLED_64x48:
    case OLED_64x48 | OLED_rotated:
      maxPixels = 64;
      break;
  }

  while (*string && currentPixels < maxPixels) // Prevent display overflow on the character level
  {
    switch (font_spacing)
    {
      case Spacing::optimized:
        char_width = pgm_read_byte(&(Plugin_023_myFont_Size[*string - 0x20]));
        break;
      default:
        char_width = 8;
    }

    for (i = 0; i < char_width && currentPixels + i < maxPixels; i++) // Prevent display overflow on the pixel-level
    {
      sendChar(pgm_read_byte(Plugin_023_myFont[*string - 0x20] + i));
    }
    currentPixels += char_width;
    string++;
  }
}

void P023_data_struct::init_OLED()
{
  unsigned char multiplex;
  unsigned char compins;

  switch (type)
  {
    case OLED_128x32:
      multiplex = 0x1F;
      compins   = 0x02;
      break;
    default:
      multiplex = 0x3F;
      compins   = 0x12;
  }

  sendCommand(0xAE);       // display off
  sendCommand(0xD5);       // SETDISPLAYCLOCKDIV
  sendCommand(0x80);       // the suggested ratio 0x80
  sendCommand(0xA8);       // SSD1306_SETMULTIPLEX
  sendCommand(multiplex);  // 0x1F if 128x32, 0x3F if others (e.g. 128x64)
  sendCommand(0xD3);       // SETDISPLAYOFFSET
  sendCommand(0x00);       // no offset
  sendCommand(0x40 | 0x0); // SETSTARTLINE
  if (use_sh1106) {
    sendCommand(0xAD);       // CHARGEPUMP mode SH1106
    sendCommand(0x8B);       // CHARGEPUMP On SH1106
    sendCommand(0x32);       // CHARGEPUMP voltage 8V SH1106
    sendCommand(0x81);       // SETCONTRAS
    sendCommand(0x80);       // SH1106
  } else {
    sendCommand(0x8D);       // CHARGEPUMP
    sendCommand(0x14);
    sendCommand(0x81);       // SETCONTRAS
    sendCommand(0xCF);
  }
  sendCommand(0x20);       // MEMORYMODE
  sendCommand(0x00);       // 0x0 act like ks0108
  sendCommand(0xA0);       // 128x32 ???
  sendCommand(0xC0);       // 128x32 ???
  sendCommand(0xDA);       // COMPINS
  sendCommand(compins);    // 0x02 if 128x32, 0x12 if others (e.g. 128x64)
  sendCommand(0xD9);       // SETPRECHARGE
  sendCommand(0xF1);
  sendCommand(0xDB);       // SETVCOMDETECT
  sendCommand(0x40);
  sendCommand(0xA4);       // DISPLAYALLON_RESUME
  sendCommand(0xA6);       // NORMALDISPLAY

  clearDisplay();
  sendCommand(0x2E);       // stop scroll
  sendCommand(0x20);       // Set Memory Addressing Mode
  sendCommand(0x00);       // Set Memory Addressing Mode ab Horizontal addressing mode
}

#endif // ifdef USES_P023
