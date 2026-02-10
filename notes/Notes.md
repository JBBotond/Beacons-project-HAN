NXP MCXA153 supports:
- supply voltage: 1,71 - 3,6 V
- Output high current total: 100 mA
- Power consumption max: 8,14 mA

Adding iBeacon support to your app involves detecting beacons in two different stages:

    -Use region monitoring to detect the presence of an iBeacon.

    -Use beacon ranging to determine the proximity to a detected iBeacon.

When deploying your iBeacon hardware, you must program each iBeacon with an appropriate proximity UUID, major value, and minor value. These values identify each of your beacons uniquely.

    The uuid (universally unique identifier) is a 128-bit value that uniquely identifies your app’s beacons.

    The major value is a 16-bit unsigned integer that you use to differentiate groups of beacons with the same UUID.

    The minor value is a 16-bit unsigned integer that you use to differentiate groups of beacons with the same UUID and major value.

Only the UUID is required, but it is recommended that you program all three values into your iBeacon hardware. In your app, you can look for related groups of beacons by specifying only a subset of values.