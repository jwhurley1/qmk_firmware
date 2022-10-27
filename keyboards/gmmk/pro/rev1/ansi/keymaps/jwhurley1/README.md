# GMMK Pro: Enable Encoder wheel to change the RGB of the side LEDs by holding modifier keys

## ​DEMO
https://imgur.com/a/J3MLHbr

## How to use Encoder

| Modifier           | Action                                |
|--------------------|---------------------------------------|
| Ctrl               | Hue increase/decrease                 |
| Shift              | Saturation increase/decrease          |
| Alt                | Brightness increase/decrease          |
| Ctrl+Encoder Press | Toggle Side LED on/off (default: off) |

## Other features

- The keyboard lights will turn white when CAPS LOCK is enabled.
- When modifying RGB_MATRIX colors while holding the FN key, the spacebar LED will show what the color will look like.

| Holding FN + ...   | Action                                |
|--------------------|---------------------------------------|
| 1    | Windows arrangement (CTRL, Win, ALT)  |
| 2    | Mac  arrangement (CTRL, Option, CMD)  |
| Q/A  | Hue increase/decrease of RGB_Matrix, respectively   |
| W/S  | Saturation increase/decrease of RGB_Matrix, respectively   |
| E/D  | Brightness increase/decrease of RGB_Matrix, respectively   |
| F9/F10  | Previous/Next Media   |
| F11  | Play/Pause Media |
| F12  | Stop Media |
| F12  | Stop Media |
| Del  | Enable Debugging in QMK_SYS |
| \  | Enable RESET for flashing firmware |
| up/down arrow keys  | RGB Matrix mode change|
| left/right arrow keys  | RGB Matrix Speed decrease/increase, respectively |
| ESC |Toggle RGB on/off for whole keyboard |


## How to Install

You will need to be able to flash QMK firmware to your GMMK Pro. It's much easier than it sounds.

Follow the steps on the "newbs" tutorial here: https://docs.qmk.fm/#/newbs.

 Get all the way through the tutorial. You will need to get to the point where you have your own custom keymap folder and have flashed QMK to the keyboard, even if its just a clone of the default keymap. This is just so you are familiar with the process.

Go to the Github linked above and replace the keymap.c in your folder that you created in the tutorial.The rules.mk and config.h are not necessary. They just allow you to use the Via app, unlock more RGB modes (woohoo lights!), and force N-key rollover. The keymap.c is the most important.(You may wish to edit the key layout that I configured for my keyboard. You can easily do this later with apps like Via, Vial, or just editing the keymap.c manually.)

Run qmk compile again with the new keymap.c to create a new .bin file and flash that to the board.

That's it! Check out the README on the Github to see how to control the side LEDs.

