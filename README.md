# Offline Emergency Communication System

## Project Overview

The Offline Emergency Communication System is a simulation-based emergency communication project designed to enable short-range emergency messaging without depending on the Internet or cellular mobile networks.

The system is based on ESP32 wireless communication technology and is intended for situations such as natural disasters, network failures, accidents, and other emergency conditions where conventional communication infrastructure may be unavailable.

## Problem Statement

During emergencies, Internet and cellular communication networks may become unavailable or unreliable. This can make it difficult for people in the affected area to communicate urgent information.

This project explores an offline communication approach in which an emergency message can be transmitted directly between nearby ESP32-based communication nodes.

## Objective

The main objectives of the project are:

- To develop an offline emergency communication concept.
- To transmit an emergency alert without Internet connectivity.
- To use ESP32 wireless communication capabilities.
- To provide a simple emergency alert mechanism using an SOS button.
- To activate visual and audio indicators when an emergency alert is generated or received.
- To validate the transmitter and receiver concepts through simulation.

## System Architecture

The system consists of two main nodes:

### 1. Transmitter Node

The transmitter node consists of:

- ESP32
- SOS push button
- LED indicator
- Buzzer
- ESP-NOW wireless communication

When the SOS button is pressed, the ESP32 generates an emergency alert and transmits the message wirelessly.

### 2. Receiver Node

The receiver node consists of:

- ESP32
- LED indicator
- Buzzer
- ESP-NOW wireless communication

When an emergency message is received, the receiver activates the LED and buzzer to indicate the emergency condition.

## Communication Technology

The project uses **ESP-NOW**, a low-power wireless communication protocol supported by ESP32 devices.

ESP-NOW allows ESP32 devices to exchange data directly without requiring:

- Internet
- Wi-Fi router
- Cellular network

This makes it suitable for exploring offline, short-range emergency communication.

## Simulation

The project is implemented as a **simulation-only prototype using Wokwi**.

The transmitter and receiver are maintained as separate Wokwi simulations because the current Wokwi environment does not provide a single simulation containing multiple independent microcontrollers communicating with each other.

The simulations are used to verify the individual transmitter and receiver behavior.

### Transmitter Simulation

The transmitter simulation contains:

- ESP32
- SOS push button
- LED
- 220 Ω resistor
- Buzzer

### Receiver Simulation

The receiver simulation contains:

- ESP32
- LED
- 220 Ω resistor
- Buzzer

## Project Structure

```text
offline-emergency-communication-system/
│
├── firmware/
│   └── README.md
│
├── simulation/
│   ├── transmitter/
│   │   ├── sketch.ino
│   │   └── diagram.json
│   │
│   └── receiver/
│       ├── sketch.ino
│       └── diagram.json
│
└── README.md

## Wokwi Simulation

### Transmitter Simulation
https://wokwi.com/projects/476937528729322497

### Receiver Simulation
https://wokwi.com/projects/476938522958842881
