8051 Microcontroller Based Password Door Lock System

This project implements a password-protected door lock system using the 8051 microcontroller (AT89C51/AT89S52).
A 4×4 matrix keypad is used to enter a PIN, an LCD displays system messages, and a motor and buzzer provide physical and audio feedback based on authentication results.

Features

4-digit PIN authentication using a keypad

 Secure PIN entry with masked display (*)

 16×2 LCD for user interaction

 Motor activation on correct PIN

Buzzer alert on incorrect PIN

 Continuous operation (retry after each attempt)

 Hardware Requirements
Component	Description
Microcontroller	8051 (AT89C51 / AT89S52)
LCD	16×2 Character LCD
Keypad	4×4 Matrix Keypad
Motor	DC Motor (via relay or driver)
Buzzer	Active/Passive Buzzer
Crystal Oscillator	11.0592 MHz
Power Supply	5V
Resistors, Capacitors	As required
 Pin Configuration
LCD Connections
LCD Pin	8051 Pin
RS	P3.5
RW	P3.6
EN	P3.7
Data (D0–D7)	P2
Keypad Connections
Keypad	8051 Pin
Rows (R1–R4)	P1.0 – P1.3
Columns (C1–C4)	P1.4 – P1.7
Output Devices
Device	8051 Pin
Motor	P3.0
Buzzer	P3.1
 Default PIN
1234


You can change the PIN by modifying the condition in the source code:

if(pass[0]=='1' && pass[1]=='2' && pass[2]=='3' && pass[3]=='4')

 Working Principle

System prompts “Enter PIN:” on LCD

User enters a 4-digit password via keypad

Each keypress is masked as * on LCD

Entered PIN is verified:

 Correct PIN → Motor ON (door unlock)

 Wrong PIN → Buzzer ON (alarm)

System resets and waits for next attempt

 Software Requirements

Keil µVision IDE

Proteus (for simulation – optional)

Embedded C Compiler (Keil C51)

 How to Run

Open the code in Keil µVision

Compile and generate HEX file

Load HEX into 8051 microcontroller

Connect hardware according to pin diagram

Power ON the circuit and test


 Applications

Door access control systems

Digital lockers

Security systems

Embedded systems learning projects

 Learning Outcomes

8051 GPIO interfacing

LCD programming

Matrix keypad scanning

Embedded security logic

Real-time hardware control
