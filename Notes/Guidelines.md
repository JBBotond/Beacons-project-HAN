# Beacon Locator Puzzle Box - Project Documentation

## Project Overview

The Beacon Locator Puzzle Box is an indoor navigation device that uses iBeacon technology to guide users through multiple target locations within a building. The locked box automatically opens when users reach their destination, creating a puzzle-like experience where each solved location reveals the next target​

---

## Hardware Requirements

### Core Components

- **Microcontroller**: FRDM-MCXA153 board as the processing unit​
- **Beacon Receiver**: HM-10 CC2541 Bluetooth 4.0 module for iBeacon signal reception​
- **Housing**: Electronically lockable enclosure​
- **Lock Mechanism**: Electronic lock operated by an actuator​
- **Display**: Visualization system for current location within the building
- **Power Supply**: Power bank in a separate, accessible compartment

### Additional Requirements

- Unknown sensors and actuators to be determined during design​
    
- Budget constraint: Additional parts and materials must not exceed €50 (excluding FRDM-MCXA153)​
    

---

## Functional Requirements

### Core Functionality

- Beacon-based indoor location tracking using Bluetooth Low Energy (BLE) technology[​
- Multi-location puzzle system requiring users to visit several target locations sequentially
- Automatic lock release upon reaching target destinations​
- Progressive puzzle revelation - next target only visible after solving current location

### User Interface Requirements

- Clear visualization of current location within the building
- Continuous display of received beacon signal status​
- User manual with step-by-step instructions for operation and settings

### Administrator Features

Administrator must be able to update target locations through:

- Direct input via the beacon locator box itself (e.g., keyboard entry or route walking)​
- Access protected by a menu system hidden from normal users
- PC application with graphical interface​
    

### Data Logging & Communication

- Continuous storage of log information with persistence when power is removed​
- Communication capability with PC/laptop​
- Automatic log transfer to PC application when connected​
- Clear display of logged information through PC interface

---

## PC Application Requirements

### Interface Requirements

- Clear graphical user interface (GUI)​
- Two-way communication with the microcontroller​
- Display of beacon locator puzzle box status​
- Real-time monitoring of sensor and actuator values

### Administrative Functions

- Target location configuration and updates​
- Log data retrieval and visualization​
    

---

## Technical Specifications

### iBeacon Protocol Standards

The iBeacon messages contain two key identification fields:​

**Major Field (16-bit)** - Building identifier:

- 0x0AEA: HAN Academy Engineering and Automotive, Ruitenberglaan 26, Arnhem​
- 0x0B01: Bronkhorst Hightech, Nijverheidsstraat 1A, Ruurlo
- 0x0B02: Bronkhorst Hightech, Lunet 10c, Veenendaal​
    

**Minor Field (16-bit)** - Room/location identifier within building:

- 0x0001: Room 1 (Bronkhorst Hightech building)​
- 0x0002: Room 2 (Bronkhorst Hightech building)​
- 0x0037: Room H0.37 (HAN AEA building) or Room 37 (Bronkhorst Hightech building)

### Power Management

- Power bank-based operation​
- Separate power bank compartment accessible without unlocking main housing​
- Non-volatile data storage maintaining logs during power loss​
    

---

## Design Process Guidelines

### Phase I: Orientation

- Create collaborative Plan of Action based on project manual​
- Document contact details and establish task division​
- Define responsibilities for professional products

### Phase II: Analysis

- Analyze problem requirements[
- Develop functional and technical requirement packages​
- Research applicable theoretical backgrounds
- Conduct experiments and measurements to validate theory against practical implementation​
- Document research findings in product report appendices​
    
### Phase III: Functional Design

- Transform concept into feasible design meeting all functional requirements​
- Define **what** will be created​
- Ensure concept viability​

### Phase IV: Technical Design

- Develop detailed technical implementation of functional design
- Define **how** the product will be created​
- Complete calculations (energy, power, construction)​
- Create technical documentation: drawings, diagrams, schematics, PCB designs
- Finalize parts list, materials, production methods, and assembly procedures
- Develop pseudo code and unit test plans

### Phase V: Realization

- Build the physical product​
- Execute mechanical assembly (components and units)
- Perform electrical-electronic assembly (PCBs and units)​
- Implement software (unit coding)
- Apply knowledge from previous studies (e.g., ARLE equipment usage)

### Phase VI: Verification/Testing

- Test and verify all realized components against functional and technical requirements​
    
- Execute test plans at multiple levels:
    - Unit/Device tests​
    - Sub-system integration tests​
    - System-level tests​
    - Factory Acceptance Test​
    - Site Acceptance Test​
- Follow V-model methodology for interim testing

---

## Documentation Requirements

### Technical Documentation

- Product report with research findings in appendices
- Functional and technical requirements documentation​
- Test plans and verification results​

### User Documentation

- Step-by-step user manual​
- Available options and settings with adjustment instructions

### Project Management

- Plan of Action​
- Task division and responsibility assignments​