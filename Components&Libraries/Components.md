## iBeacons

#### How does iBeacon work?
* They send out signals that contain a unique identifier
* The beacons send these signals to a server, which processes the information to determine the beacon's exact location
* The final data is then sent to your smartphone, where the mobile app processes the information and displays it to you

#### Bluetooth® Direction Finding

* ***AOA (Angle of Arrival):** This architecture is used for real-time location tracking and is based on the angle at which the radio signal arrives at the anchor point. The Bluetooth® technology calculates angular directions (elevation and azimuth) from the receiving device, enabling indoor positioning with Bluetooth® to achieve an accuracy of up to 1 meter. The transmitting device has one antenna, while the receiving device has at least two. By analyzing the phase difference between radio signals, the angle of arrival is determined, and the direction from which the signals arrive is calculated [[rssi.gif]]
* **AoD (Angle of Departure):** This architecture is used for object navigation scenarios. It is based on determining the location considering the angle of departure of the radio signals. In this architecture, the transmitter has several antennas, while the receiver has only one. The transmitting device sends out pulses from each antenna, after which the phase differences between these radio signals are analyzed to estimate the angle of deviation and determine the direction from which the pulses were sent [[bleaoa.gif]]

When implementing a BLE solution, consider the following:

- **System Accuracy:** While RSSI (Received Signal Strength Indicator) is a simple method, newer Bluetooth® direction-finding technologies like **Angle of Arrival (AoA)** and **Angle of Departure (AoD)** can provide sub-meter accuracy by analyzing the direction of radio signals.
- **Scalability:** Choose a solution that can easily expand with your business. Our [Open Source solution](https://navigine.com/open-source/ "Open Source") offers powerful, customizable algorithms for developers to integrate into their projects, ensuring a flexible and scalable system.

Repo: https://github.com/Navigine

#### In iBeacon, **major** and **minor** are just numbers you choose to identify groups of beacons and individual beacons inside those groups.

##### Short meaning
- Major: A group ID (for example: all beacons in one store, floor, or museum).
- Minor: A device ID inside that group (for example: a specific room, exhibit, or beacon in that store)
    

Both are unsigned integers (usually 0–65535) that sit under a shared UUID, which is the top‑level ID for your whole beacon “project” or organization.

#### Questions to investigate
* The range the current ibeacons
* What is time between sending signals

#### References
* https://www.instructables.com/make-iBeacon/
* https://www.hackerstore.nl/PDFs/iBeacon.pdf
* https://kontakt.io/blog/beacon-id-strategy-guide-quick-deployment/

## LCD Display

* https://www.nxp.com/design/design-center/development-boards-and-designs/LCD-PAR-S035

## FRDM-MCXA153
### CMSIS naming convention
* CMSIS defines strict naming conventions for Cortex-M peripherals, registers, interrupts, and access types to ensure portability across vendors like NXP
###### Core Naming Rules
- **Registers**: UPPERCASE (e.g., `SysTick->CTRL`, `SCB->SHPR3`).
- **Functions**: CamelCase (e.g., `NVIC_SetPriority`, `CLOCK_GetFreq`).​
- **Structs**: `<Device>_TypeDef` (e.g., `SysTick_Type`, `UART_TypeDef`).​
- **Pointers**: `<Device> + postfix` (e.g., `LPUART0`, `LPUART1`).
###### Peripheral Access Qualifiers

CMSIS uses type qualifiers for register permissions in structs:

| Qualifier | Meaning          | Example Use Case                                                                                               |
| --------- | ---------------- | -------------------------------------------------------------------------------------------------------------- |
| `__IM`    | Read-only        | Status/flag registers                                                                                          |
| `__OM`    | Write-only       | Command/control registers                                                                                      |
| `__IOM`   | Read/Write       | Config/data registers                                                                                          |
| `__I`     | Read-only scalar | Constants[arm-software.github](https://arm-software.github.io/CMSIS_6/latest/Core/group__peripheral__gr.html)​ |
###### Memory Map Overview
| Region           | Address Range           | Purpose                                                                                         |
| ---------------- | ----------------------- | ----------------------------------------------------------------------------------------------- |
| Code Flash       | 0x0000_0000–0x0001_FFFF | Up to 128 KB program storage (ECC-protected)                                                    |
| SRAM X0          | 0x2000_0000–0x2000_7FFF | 32 KB data RAM (8 KB ECC)                                                                       |
| Core Peripherals | 0xE000_E000–0xE000_EFFF | SysTick, NVIC, SCB (CMSIS-Core) [arm-software.github](https://arm-software.github.io/CMSIS_5/)​ |
| AHB Peripherals  | 0x4000_0000–0x5FFF_FFFF | Clocks, GPIO, DMA, timers                                                                       |
| APB Peripherals  | 0x4000_0000+            | UARTs, SPIs, etc. (specific bases below)                                                        |
###### Key Peripheral Base Addresses (MCXA153)

| Peripheral  | Base Address | Example Access                                                        |
| ----------- | ------------ | --------------------------------------------------------------------- |
| SysTick     | 0xE000_0E10  | `SysTick->LOAD = 0xBB80;`                                             |
| GPIO0       | 0x400A_0000  | `GPIO0->PCR[0] = 0x100;`                                              |
| LPUART0     | 0x4003_4000  | `LPUART0->CTRL                                                        |
| FlexPWM0    | 0x4041_8000  | PWM for motor control                                                 |
| ADC0        | 0x4008_0000  | `ADC0->CMD[0] = 0x80;`                                                |
| CLOCK (SCG) | 0x400B_0000  | Clock config https://www.nxp.com/docs/en/data-sheet/MCXAP64M96FS3.pdf |