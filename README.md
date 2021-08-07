# Depraz Mice on USB via Arduino

This code lets you connect a [Depraz mouse](https://www.oldmouse.com/mouse/logitech/digimouse.shtml) to a modern computer via USB. The Depraz mouse has a male DE-9 connector but does *not* use RS-232. Instead, it directly exposes the internal quadrature encoders (two pins for X axis, two pins for Y axis) and each of the three buttons gets its own pin. Add in +5V and GND pins and you've got 9 wires.

You'll need a board with an ATmega32U4 in order to emulate a USB HID device. I used an Arduino Pro Micro and connected it as follows:

 Mouse port pin   | Arduino pin
------------------|------------
1 (+5V)           | Vcc
2 (Y1)            | 0
3 (Y2)            | 1
4 (X1)            | 2
5 (X2)            | 3
6 (GND)           | GND
7 (mid button)    | 7
8 (right button)  | 8
9 (left button)   | 9

# Notes/Tweaks

If you find the pointer moves way too fast/slow for you, tweak the SPEED_CONSTANT define at the top of the file.

# Caveats

This has only been tested with a red "Type D 83/P" mouse.

When I plugged it into an old Powerbook running Mac OS 9, the OS didn't recognize it as a mouse.
