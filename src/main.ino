#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP32Servo.h>

// Initialize I2C LCD (Address: 0x27 or 0x3F, 16x2 columns and rows)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Servo motor setup
Servo lockServo;
const int servoPin = 13; // Connect PWM pin of servo to GPIO 13 (change if needed)

// Define Keypad settings
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Connect to the row pinouts of the keypad
byte rowPins[ROWS] = {23, 22, 21, 19}; 
// Connect to the column pinouts of the keypad
byte colPins[COLS] = {18, 5, 17, 16}; 

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Password configuration
const String SECRET_PASSWORD = "1234"; // Set your password here
String enteredPassword = "";

void setup() {
  Serial.begin(115200);

  // Initialize LCD
  lcd.init();                      
  lcd.backlight();
  
  // Initialize Servo
  lockServo.attach(servoPin);
  lockServo.write(0); // Initial position: Locked (0 degrees)

  // Initial Display Message
  lcd.setCursor(0, 0);
  lcd.print("System Ready");
  delay(1500);
  showEnterPasswordPrompt();
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.print("Pressed: ");
    Serial.println(key);

    if (key == '#') {
      // '#' acts as the enter/submit key
      verifyPassword();
    } 
    else if (key == '*') {
      // '*' acts as a clear/reset key
      enteredPassword = "";
      showEnterPasswordPrompt();
    } 
    else {
      // Append characters up to the password length
      if (enteredPassword.length() < 16) {
        enteredPassword += key;
        lcd.setCursor(0, 1);
        // Print masking stars (*) instead of plain text for security
        String masked = "";
        for (int i = 0; i < enteredPassword.length(); i++) {
          masked += "*";
        }
        lcd.print(masked);
      }
    }
  }
}

void showEnterPasswordPrompt() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");
  lcd.setCursor(0, 1);
  enteredPassword = "";
}

void verifyPassword() {
  lcd.clear();
  lcd.setCursor(0, 0);
  
  if (enteredPassword == SECRET_PASSWORD) {
    lcd.print("Access Granted 🔓");
    Serial.println("Access Granted");
    
    // Rotate servo to unlock position (e.g., 90 or 180 degrees)
    lockServo.write(90); 
    
    // Keep unlocked for 3 seconds
    delay(3000); 
    
    // Relock
    lockServo.write(0);
  } else {
    lcd.print("Access Denied 🔒");
    Serial.println("Access Denied");
    
    // Error feedback blink/delay
    delay(2000);
  }
  
  showEnterPasswordPrompt();
}
