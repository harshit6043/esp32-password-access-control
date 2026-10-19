# 🔐 Password-Based Access Control System Using ESP32

An embedded electronic lock system built using an ESP32 microcontroller, a 4×4 matrix keypad, a 16×2 I2C LCD, and an SG90 micro servo motor. The system verifies a user-entered PIN and controls a servo-based locking mechanism to provide basic password-protected access control.

---

## 🚀 Features

* **PIN-Based Authentication:** Verify user access using a predefined password.
* **4×4 Matrix Keypad:** Enter and submit the password using the keypad.
* **LCD User Interface:** Display prompts and system status on a 16×2 I2C LCD.
* **Servo-Based Lock:** Control a physical latch using an SG90 servo motor.
* **Password Masking:** Display asterisks (`*`) instead of entered digits.
* **Input Controls:** Use `*` to clear the input and `#` to submit the password.
* **Access Feedback:** Display access-granted or access-denied messages.

---

## 🛠️ Hardware Requirements

| Component | Quantity | Purpose |
| :--- | :--- | :--- |
| **ESP32 development board** | 1 | Main controller |
| **4×4 matrix keypad** | 1 | PIN entry |
| **16×2 LCD with I2C backpack** | 1 | User interface |
| **SG90 micro servo motor** | 1 | Lock mechanism |
| **Regulated 5V power supply** | As required | Servo power |
| **Breadboard** | 1 | Prototyping |
| **Jumper wires** | As required | Connections |

---

## 🔌 Circuit Connections

The pin assignments below resolve previous conflicts by moving keypad rows away from the I2C lines (`GPIO 21` and `GPIO 22`).

### 1. I2C LCD to ESP32
| LCD Pin | ESP32 Pin |
| :--- | :--- |
| **SDA** | GPIO 21 |
| **SCL** | GPIO 22 |
| **VCC** | 5V / VIN (if supported by module) |
| **GND** | GND |

> *Important:* Verify that the LCD's I2C backpack is compatible with the ESP32's 3.3V logic.

### 2. SG90 Servo to ESP32
| Servo Wire | Connection |
| :--- | :--- |
| **Signal (orange/yellow)** | GPIO 13 |
| **VCC (red)** | Regulated 5V supply |
| **GND (brown/black)** | Power supply GND |

> Use an adequate regulated supply for the servo and connect its ground to ESP32 GND. Avoid powering a servo directly from an ESP32 GPIO pin.

### 3. 4×4 Keypad to ESP32 (Conflict-Free Mapping)
| Keypad Pin | ESP32 GPIO |
| :--- | :--- |
| **Row 1** | GPIO 23 |
| **Row 2** | GPIO 19 |
| **Row 3** | GPIO 18 |
| **Row 4** | GPIO 5 |
| **Column 1** | GPIO 17 |
| **Column 2** | GPIO 16 |
| **Column 3** | GPIO 4 |
| **Column 4** | GPIO 2 |

---

## 💻 Software and Dependencies

Make sure you have the following libraries installed in your **Arduino IDE** (via Library Manager):
* `LiquidCrystal_I2C` by Frank de Brabander
* `Keypad` by Mark Stanley, Alexander Brevig
* `ESP32Servo` (or standard `Servo` library configured for ESP32)

---

## ⚙️ Getting Started & Usage

1. Clone or download this repository into your local environment.
2. Open the project sketch inside the `src/` folder using the **Arduino IDE**.
3. Install the ESP32 board package and required libraries listed above.
4. Update the default PIN string in the source code if you wish to change the unlock combination.
5. Connect your ESP32 via USB, select your correct board/port, and flash the code.
6. **Operation:**
   * Type your PIN on the 4x4 keypad. View asterisks on the LCD.
   * Press **`#`** to submit. If correct, the servo will rotate to the "Unlocked" position.
   * Press **`*`** to clear your current input if you make a mistake.

---

## 📄 License
Distributed under the MIT License. See `LICENSE` for more information.
