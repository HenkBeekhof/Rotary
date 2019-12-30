# Library for a rotary (non interrupt version)

Functions
* Define the two rotary pins by calling the constructor
* Swap functionality if left turn and right turn should create incrementing or decrementing values
* Counts all pulses from A input as well as from B input
* Read the current value of the rotary
* Reset the current value of the rotary
* Check if the rotary value is changed

The aim is to stow away the rotary read details in this class
It was developed for the rotary on the RAMPS board, on this board the rotary is connected to the MEGA2560 pins D31 and D33. These pins are not connected to the interrupt module, therefor no interrupts are used in this library. 
