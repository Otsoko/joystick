# Joystick #

Arduino proyect using an analog joystick module and a MAX7219 led dot matrix module.

## Demo ##
![Demo](https://github.com/Otsoko/joystick/raw/master/joystick.gif)

## Schema ##
![Schema](https://github.com/Otsoko/joystick/raw/master/joystick_bb.png)

## Description ##
This program displays several arrow shapes corresponding to the directionthe joystick is momving to.

A circle is displayed when the joystick is in rest position.

A point is displayed if the joystick button is pressed.

The joystick `select` is connected to digital pin `8`. Horizontal output is connected to analog pin `A0`, vertical to analog pin `A1`.

Regarding the MAX7219 module, pin `5` is connected to the `DataIn`, pin `3` is connected to `LOAD(CS)`, and pin `4` is connected to the `CLK`.