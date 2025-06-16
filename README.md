# <h1>🤖PID controller based Robot</h1>

# <h2>📌Aim</h2>
This project aims to Robot movement control to reach the target point using PID controller with the help of US-Senor distance measurement.

# <h2>⚙️List of Kit & tools Requirement</h2>
1. Arduino and IDE
2. Robotics platform
3. Motor driver module
4. US-Sensor
5. Battery

# <h2>📒Theory</h2>
A simple motor operated Robot is a robot whose movement can be controlled to reach a predetermined set-point (or target distance) using PID-controller. The actual distance from the robot to target point is measured by using US-Sensor. The co-ordination between the sensor and robot movement is controlled by coding with ARDUINO-UNO board. The robot can move forward and backward depends on the error between the target point and the measured distance. Finally it settles down around the target point. Based on the calculated error the speed and direction of the robot will be decide. Oscillations and steady state error around the target point of the robot movement can be controlled by varying the gains of the PID-controller.

Error (in “cm”) = Measured Distance (in “cm”) – set point (in “cm”)  .........(1)

Output (or desired speed) = K p *Error + K i * integral + K d *Derivative  .......(2)

Integral= Previous Error + Current Error  .......(3)

Derivative= Previous Error - Current Error  ........(4)


Note:
1. Configure the US-Sensor to measure the actual distance of the robot to obstacle which is placed at greater distance compared to target or set-point distance.

2. If the calculated error from (1) is positive (+ve) robot has to move in the forward direction and if the error is negative (-ve) robot has to move in the backward direction. If the error becomes zero then robot will stop to move.
   
3. Based on the output value derived from the eq. (2) the speed of the motor will decide.

4. By using the above information the students has to write the code by self and observe the robot movement for Proportional controller (P), Proportional plus integral controller (P+I) and Proportional + Integral + Derivative controller (PID) separately with different controller gains combinations.

# <h2>🛠️Hardware setup</h2>

Steps for adding motor zip file to the Arduino UNO IDE:
1. Download the motor zip file.
2. Open Arduino UNO IDE in computer then go to Sketch->Include library->add zip libraryadd motor zip.
3. Connect the robot with Arduino UNO Board to the Computer by using USB based Communication probe.
4. Connect the US-sensor to the Arduino UNO Board and configure the trigger and echo pins to Digital pins 9 and 10.

# <h2>💻Experimental Procedure</h2>

I. Open the Arduino UNO IDE in the Computer then select the Arduino UNO Board type and select the communication PORT from tools.

II. Click on File and take New Sketch

III. Write, Load and Compile the program.

IV. Remove the Communication probe from the computer and connect it to the battery provided on the robot.

V. Keep the robot on the plain surface and observe the movement of the robot

VI. Observe the robot movement for Proportional controller (P), Proportional plus integral controller (P+I) and Proportional + Integral + Derivative controller (PID) separately with different Kp, Ki and Kd values.





<h6>⁕In this video, we can see that the robot moves forward if the distance is  >20 cm it moves forward, and moves backward if distance is <20cm and stops at an exact distance of 20cm from the target.</h6>

https://github.com/user-attachments/assets/91b9b656-552a-40f1-b0bd-52ab7220648a

<h6>⁕In this video, my hand is the target obstacle, where the robot tries to maintain a constant distanc of 20cm.</h6>

https://github.com/user-attachments/assets/d6207a20-850c-469f-8b24-83649e18b751


