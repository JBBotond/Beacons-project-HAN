Main unit: NXP microcontroller
The microcontroller must have the order of ibeacons and their respective UUID's programmed into it before the "game" begins via the admin panel. The system automatically indicates distance from the next ibeacon in the given order. The display will indicate whether the user is getting closer or further from the ibeacon (hotter or colder game). Once the user has reached the ibeacons, an event is triggered to reward the user, or offer clues to a bigger prize in the end.

The box remains locked by a stepper motor and 3d printed parts until all ibeacons have been discovered

**Operating modes**

| Normal/Game mode                                                        | Admin mode                                                                    | Testing mode                       |
| ----------------------------------------------------------------------- | ----------------------------------------------------------------------------- | ---------------------------------- |
| Default mode, let's the game play with a set of rules set in admin mode | Accessible wirelessly, can change game settings (such as reordering ibeacons) | Optional - implemented if required |
