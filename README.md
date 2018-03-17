# PWC
Powerful Watts' Controller - A module used to control power source drivers.

# WARNING
It is important to say that this driver was made with one single microcontroller. Due to this, it has to be used carefully, any deadlock on your code can put your MCU on fire. It is important to state that the **main interrupt, responsible for controlling the CC converter has to be always free to run.** Don't put any other interrupt with more priority to run before the Timer 2.

## About
This module was created to be used as a controller for small power sources, the first microcontroller used on this project was the ATmega8.

Datasheets and MCU Information:
  * [ATmega8] - https://www.microchip.com/wwwproducts/en/ATmega8
