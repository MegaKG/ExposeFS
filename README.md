# ExposeFS
Exposes LittleFS as a virtual FAT16 disk.


This library allows the internal LittleFS of a microcontroller to be exposed for read only access via USB mass storage.

Assuming the LittleFS filesystem is Constructed as Follows:
Root (/):
  - Test.txt
  - Test2.txt

The program will create a new FAT16 table in memory based on this structure and redirect calls to the assigned logical blocks to the relevant LittleFS file.
Visible to the computer will be a read-only drive containing:
Root (/):
  - Test.txt
  - Test2.txt

This currently only works with Linux implementations of the FAT16 filesystem driver.
I suspect this is due to the lack of VFAT support.

ToDo: Windows / MacOS debugging.

Tested on a Raspberry Pi Pico using the Arduino Core:
https://github.com/earlephilhower/arduino-pico
