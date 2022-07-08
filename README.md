# Depraz Mice on USB via Arduino

This code lets you connect a [Depraz mouse](https://www.oldmouse.com/mouse/logitech/digimouse.shtml) to a modern computer via USB. The Depraz mouse has a male DE-9 connector but does *not* use RS-232. Instead, it directly exposes the internal quadrature encoders (two pins for X axis, two pins for Y axis) and each of the three buttons gets its own pin. Add in +5V and GND pins and you've got 9 wires.

You'll need a board with an ATmega32U4 in order to emulate a USB HID device. I used an Arduino Pro Micro with 1M pullup resistors connected to pins 7, 8, and 9. To break out the DB9 port, I used [https://www.amazon.com/gp/product/B07PNWF3DW/](https://www.amazon.com/gp/product/B07PNWF3DW/).

For the Depraz, I connected it as follows:

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

It also works with an original Macintosh mouse if wired as follows:

 Mouse port pin   | Arduino pin
------------------|------------
1 (GND)           | GND
2 (+5V)           | Vcc
3 (GND)           | GND
4 (X2)            | 3
5 (X1)            | 2
6 (NC)            | (not connected)
7 (button)        | 9
8 (Y2)            | 1
9 (Y1)            | 0

# Notes/Tweaks

If you find the pointer moves way too fast/slow for you, tweak the SPEED_CONSTANT define at the top of the file.

If your vertical movement is inverted, swap Arduino pins 0 and 1. If horizontal is inverted, swap 2 and 3.

# Caveats

When I plugged it into an old Powerbook running Mac OS 9, the OS didn't recognize it as a mouse.

This has only been tested with a red "Type D 83/P" mouse. Apparently the grey ones have a different pinout on the connector:

* 1 - GND
* 2 - MB
* 3 - Y
* 4 - LB
* 5 - RB
* 6 - Vcc
* 7 - Y
* 8 - X
* 9 - X

(Source: https://www.vcfed.org/forum/forum/technical-support/vintage-computer-hardware/74403-whitechapel-mg-1-depraz-mouse-grey-pinout#post904391)
