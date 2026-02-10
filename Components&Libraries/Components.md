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