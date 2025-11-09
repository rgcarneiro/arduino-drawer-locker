# Smart Drawer Locker (Arduino)

An intelligent drawer locking system controlled by a sound sensor (KY-037) and a motion sensor (HC-SR501).  
The mechanism uses a servo motor to open and close the drawer based on detected claps and presence.

## Description

This project combines sound and motion detection to control a drawer’s locking mechanism.  
It is ideal for home security prototypes, automatic storage systems, or IoT demonstrations using Arduino.

- The system recognizes two consecutive claps while motion is detected to open the drawer.  
- After five claps, the drawer automatically closes.  
- If no motion or sound is detected, the servo remains locked.

## Components Used

| Component | Function |
|------------|-----------|
| Arduino UNO/Nano | Main microcontroller |
| KY-037 | Sound sensor for clap detection |
| HC-SR501 | PIR motion sensor |
| Servo motor (SG90 or similar) | Opening/closing mechanism |
| Jumpers + Breadboard | Wiring and assembly |

## Operation Logic

1. The PIR sensor detects nearby presence.  
2. The KY-037 sensor measures sound peaks above the defined threshold (`threshold = 389`).  
3. The system:
   - Rotates the servo to 45° after two claps with motion detected.  
   - Returns the servo to 0° after five claps.  
4. The serial monitor displays real-time sound and motion readings.

## Pinout

| Component | Arduino Pin |
|------------|-------------|
| KY-037 (digital) | D7 |
| KY-037 (analog) | A0 |
| HC-SR501 (PIR) | D2 |
| Servo motor | D9 |

## Usage Example

1. Power on the system and open the serial monitor (9600 baud).  
2. Clap twice near the sensor — the servo rotates and the drawer opens.  
3. Clap five times — the servo returns to the initial position, closing the drawer.
