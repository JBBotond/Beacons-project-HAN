Main unit: NXP microcontroller

Locking system: DC motors with 3d printed rails

**Operating modes**

| Normal/Game mode                                                        | Admin mode                                                                    | Testing mode                       |
| ----------------------------------------------------------------------- | ----------------------------------------------------------------------------- | ---------------------------------- |
| Default mode, let's the game play with a set of rules set in admin mode | Accessible wirelessly, can change game settings (such as reordering ibeacons) | Optional - implemented if required |

A hm-10 module will be used alongside the NXP microcontroller for wireless communication. The hm-10 module will scan for ibeacons, providing information to the MCXA153.

**Locking**

| Normal/Game mode                                       | Admin mode                       |
| ------------------------------------------------------ | -------------------------------- |
| System is locked until game ends, password is revealed | System opens, access to anything |
