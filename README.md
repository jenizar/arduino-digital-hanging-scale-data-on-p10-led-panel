# arduino-digital-hanging-scale-data-on-p10-led-panel
Displaying modified digital hanging scale data on p10 led panel using arduino

materials: 

digital hanging scale custom, load cell amplifier high quality HX711, 2x1 led panel p10 (2 pcs), arduino uno/duemilanov, power supply 5v/10A for led panel p10, adaptor 5v/3A, data cable hub 16 pin, power cable, jumper cable.

![alt text](https://github.com/jenizar/arduino-digital-hanging-scale-data-on-p10-led-panel/blob/main/digital_hanging_scale_w_parts.jpg)
![alt text](https://github.com/jenizar/arduino-digital-hanging-scale-data-on-p10-led-panel/blob/main/portable_digital_hanging_scale.jpg)
![alt text](https://github.com/jenizar/arduino-digital-hanging-scale-data-on-p10-led-panel/blob/main/p10_led_panel_to_arduino.jpg)
![alt text](https://github.com/jenizar/arduino-digital-hanging-scale-data-on-p10-led-panel/blob/main/p10_led_panel_2_unit_front.jpg)
![alt text](https://github.com/jenizar/arduino-digital-hanging-scale-data-on-p10-led-panel/blob/main/p10_led_panel_2_unit_back.jpg)
![alt text](https://github.com/jenizar/arduino-digital-hanging-scale-data-on-p10-led-panel/blob/main/p10_led_panel_show.jpg)

instructions: 

A. digital hanging scale to HX711 load cell amplifier
1. disconnect the cables connecting the scale sensor (green-white-red-black) to the modified scale display board. Then solder the cables to the PCB
2. use a mouse cable or a former speaker cable with a length of 1 - 1.2 meter to and connect the 4 cables to the PCB that has been soldered at number 1.
3. the weighing case is punched at the top so that the 1 meter long cable can come out
4. disconnect the cable connected to the battery on the modified scale display panel board.
5. lastly, close the case gently tighten the bolt nut; make sure the position of the component parts remains the same when first opened.
6. match the 4 wires coming from the weighing sensor to the load cell amplifier HX711 red - red, black - black, white - white, green - green
7. Adjust the 4 pins on the HX711 load cell amplifier with the pins on the Arduino board. VCC - 5v, DAT - A1, CLK - A0, GND - GND

B. Arduino to p10 led panel pin connection (see http://indomaker.com/index.php/2019/01/05/memulai-p10-led-matrix-menggunakan-arduino/)

If you use HX711 green board:

Pin HX711 Loadcell

E+ -- Green

E- -- White

A- -- Black

A+ -- Red

[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/jFOSPNXvPRU/0.jpg)](http://www.youtube.com/watch?v=jFOSPNXvPRU)

references:

https://youtu.be/tmNJagY0NEg
