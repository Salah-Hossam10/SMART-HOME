Project Title: Home Automation and Security System using AVR Microcontroller
This project implements a home automation and security system using an AVR microcontroller. It provides multiple functionalities, including password-based authentication, door control, light and fan control, temperature and light level monitoring, and a security alert in case of unauthorized access.

Table of Contents
Project Description
Hardware Requirements
Software Requirements
System Overview
Functionality
Installation
Usage
Contributing
License
Project Description
The home automation and security system project integrates various functionalities to enhance home safety and convenience. This system allows users to:

Control access through password authentication.
Operate appliances like AC, fan, and lights.
Monitor temperature and light levels.
Change the access password and receive a warning in case of unauthorized attempts.
Hardware Requirements
ATmega Microcontroller (e.g., ATmega32)
LCD Display - 16x2
4x4 Keypad - for user input and authentication
Servo Motor - for door lock mechanism
Temperature Sensor (LM35)
LDR (Light Dependent Resistor) - for light level monitoring
Power Supply - 5V DC
LEDs and Resistors - for indicating security status
Push Buttons
Software Requirements
AVR GCC - for compiling C code
AVRDUDE - for programming the microcontroller
Proteus (Optional) - for simulation
Microcontroller Libraries - for interfacing with LCD, keypad, ADC, etc.
System Overview
This project uses the AVR microcontroller to interact with various hardware components:

LCD Display: Provides a user interface to show messages and status.
Keypad: Accepts user input for password authentication.
Servo Motor: Controls the door mechanism to open/close based on successful password entry.
Sensors: Monitors environmental parameters like temperature (using LM35) and light intensity (using LDR).
Relays/LEDs: Toggles lights, fan, and AC based on user commands or environmental conditions.
The system has two main modes:

Authentication Mode: Users enter a password to gain access and unlock the door.
Monitoring Mode: Displays real-time temperature and light levels.
Functionality
1. Password Authentication
Users are prompted to enter a password.
The door opens if the entered password matches the saved password.
After three incorrect attempts, an alarm is triggered.
2. Mode Selection
Upon successful authentication, users can select various modes for controlling home appliances.
3. Appliance Control
Users can turn the AC, fan, and lights on/off.
An automated LDR-based system controls the lights based on ambient light levels.
4. Temperature and Light Monitoring
The system displays the current temperature and light levels on the LCD.
5. Password Change
Users can change the password after successful authentication.
Installation
Clone the Repository


git clone https://github.com/yourusername/home-automation-security-system
cd home-automation-security-system
Compile the Code

Use AVR GCC to compile the code for your microcontroller:

avr-gcc -mmcu=atmega32 -DF_CPU=8000000UL -Wall -Os -o main.elf main.c
avr-objcopy -O ihex main.elf main.hex
Upload to Microcontroller

Use avrdude to upload the compiled code:

avrdude -c your_programmer -p m32 -U flash:w:main.hex
Usage
System Power-On: Upon powering on, the LCD will display a welcome message and prompt for a mode selection.
Enter Passcode: Use the keypad to enter the passcode.
Successful entry grants access.
After three incorrect attempts, an alarm is triggered.
Select Mode: Users can select various modes:
1 - Enter Password
2 - Change Password
3-5 - Appliance Control and Monitoring
Contributing
Contributions are welcome! Please fork the repository and submit a pull request for any improvements.
