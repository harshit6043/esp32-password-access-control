# 🔐 Password-Based Access Control System Using ESP32

An embedded electronic lock system built using an ESP32 microcontroller, a 4×4 matrix keypad, a 16×2 I2C LCD, and an SG90 micro servo motor. The system verifies a user-entered PIN and controls a servo-based locking mechanism to provide basic password-protected access control.

## 🚀 Features

- **PIN-Based Authentication:** Verify user access using a predefined password.
- **4×4 Matrix Keypad:** Enter and submit the password using the keypad.
- **LCD User Interface:** Display prompts and system status on a 16×2 I2C LCD.
- **Servo-Based Lock:** Control a physical latch using an SG90 servo motor.
- **Password Masking:** Display asterisks (`*`) instead of entered digits.
- **Input Controls:** Use `*` to clear the input and `#` to submit the password.
- **Access Feedback:** Display access-granted or access-denied messages.

## 🛠️ Hardware Requirements

| Component | Quantity | Purpose |
|---|---:|---|
| ESP32 development board | 1 | Main controller |
| 4×4 matrix keypad | 1 | PIN entry |
| 16×2 LCD with I2C backpack | 1 | User interface |
| SG90 micro servo motor | 1 | Lock mechanism |
| Regulated 5V power supply | 1 as required | Servo power |
| Breadboard | 1 | Prototyping |
| Jumper wires | As required | Connections |

## 🔌 Circuit Connections

The following pin assignments are proposed for a typical ESP32 DevKit V1 and must match the firmware.

### I2C LCD to ESP32

| LCD Pin | ESP32 Pin |
|---|---|
| SDA | GPIO 21 |
| SCL | GPIO 22 |
| VCC | 5V/VIN, if supported by the module |
| GND | GND |

**Important:** Verify that the LCD's I2C backpack is compatible with the ESP32's 3.3V logic. Some backpacks pull SDA and SCL up to their supply voltage, which can expose the ESP32 to unsafe 5V signals. Use a suitable I2C level shifter or compatible pull-ups if needed.

### SG90 Servo to ESP32

| Servo Wire | Connection |
|---|---|
| Signal (orange/yellow) | GPIO 13 |
| VCC (red) | Regulated 5V supply |
| GND (brown/black) | Power supply GND |

Use an adequate regulated supply for the servo and connect its ground to ESP32 GND. Avoid powering a servo directly from a GPIO pin.

### 4×4 Keypad to ESP32

| Keypad Pin | ESP32 GPIO |
|---|---|
| Row 1 | GPIO 23 |
| Row 2 | GPIO 22 |
| Row 3 | GPIO 21 |
| Row 4 | GPIO 19 |
| Column 1 | GPIO 18 |
| Column 2 | GPIO 5 |
| Column 3 | GPIO 17 |
| Column 4 | GPIO 16 |

**Wiring conflict to resolve:** GPIO 21 and GPIO 22 are assigned to both the I2C LCD and the keypad in the proposed mapping above. These connections cannot be shared this way. Choose
