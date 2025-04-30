# 🔋 Simple Digital Voltmeter using ADC and LCD

This project demonstrates a basic **digital voltmeter** built using a microcontroller, **ADC (Analog to Digital Converter)**, and a **16x2 LCD display**. It reads an analog input voltage (0–5V) and displays the corresponding digital voltage on the screen in real time.

## 📌 Features

- Measures voltage in the range of **0V to 5V**
- Displays the voltage with **2 decimal points** on a 16x2 LCD
- Uses **ADC module** of the microcontroller
- Written in **Embedded C**
- Compatible with most 8-bit and 32-bit MCUs like **ATmega32, LPC2129, STM32**, etc.

## 🛠️ Hardware Requirements

- Microcontroller (e.g., **LPC2129**, **ATmega32**, etc.)
- 16x2 Alphanumeric LCD
- Potentiometer or adjustable voltage source (for input voltage)
- Breadboard and jumper wires
- Power supply (e.g., 5V DC)

## ⚙️ Software Requirements

- Keil µVision 
- Proteus (for simulation, optional)
- Flashing tool (e.g., Flash Magic for LPC series)

## 📈 Working Principle

- The analog voltage is applied to an ADC input pin of the MCU.
- The internal **ADC converts** the analog voltage into a digital value based on reference voltage (Vref).
- The digital value is then **converted to actual voltage** using the ADC formula:
  
  ```
  Voltage = (ADC_Value / 1023.0) * Vref  // For 10-bit ADC and Vref = 5V
  ```

- The final voltage is displayed on the LCD in the format:
  
  ```
  Voltage: 2.36 V
  

## 🧠 Learning Outcomes

- How ADC works in embedded systems
- Interfacing 16x2 LCD using 4-bit or 8-bit mode
- Voltage scaling and floating-point calculation
- Real-time display of measured 

## 📚 Future Improvements

- Auto calibration feature
- Display max/min voltage values
- Save readings using EEPROM
