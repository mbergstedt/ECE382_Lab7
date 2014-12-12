ECE382_Lab7
===========
##A/D Conversion - "Robot Sensing"
###Purpose
Learn the concepts of analog-to-digital conversion for the MSP430.
###Preliminary Design
My flowchart for the lab is:
![alt text](https://github.com/mbergstedt/ECE382_Lab7/blob/master/Flowchart.JPG?raw=true)

My pseudocode for the lab is:
![alt text](https://github.com/mbergstedt/ECE382_Lab7/blob/master/Pseudocode.JPG?raw=true)
###Hardware Design
My hardware schematic is:
![alt text](https://github.com/mbergstedt/ECE382_Lab7/blob/master/Hardware_Design.JPG?raw=true)
###Debugging
I used Dr. Coulston's code for input from one of the sensors and changed it to be able to receive from multiple sensors.  I would run the debugger and check how the LEDs would change based on the distance from the sensors.  For B functionality, I put the code I used for the sensor readings into its own header and source file and checked that it still worked.
###Testing Methodology/Results
For the required and b functionality, I used my hand or moved the robot near the wall to check that my lights worked.  For A functionality, I put a ruler on the floor and hooked the robot up to a DMM.  As I moved the robot closer to the wall, I would pick distances and measure the voltage from the sensor at that point.
###Documentation
I used Dr. Coulston's code from his site as a base for figuring out the sensor input.
