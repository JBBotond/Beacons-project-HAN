*Components used*
    28byj-48 stepper motor with ULN2003 motor driver
    **replaced**

        - this motor was initially used for prototyping the locking mechanism, but was switched out for simple DC motors due to temperature problems, as stepper motors tend to get very hot (70 - 100 degrees celsius) during operation
        - DC motors don't require us to think about hot components

    DC motor with HW-095 H-bridge
        - the motor doesn't have heating issues, H-bridge has a lower operating temperature of around 25-75 degrees celsius
        - the group is familiar with the components already, so it is to our advantage choosing to use it for the locking mechanism
        - drivers converted from AVR-C to code for the NXP MCXA153

    hw-140 V3.2.0 buck boost converter

        - the step-down/step-up converter is used to safely supply power to motors from a battery pack