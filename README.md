# Leap Motion Controlled Bot

- Firstly using leap motion camera, we can detect hand gestures and other stuff

- Sadly this is how I look through the camera

## NOTE: This project had multiple iterations:
### First Iteration
- We initially thought we’ll use it with some game probably like fruit ninja or something but again we always have the fact that it will end up looking like some ad we are giving for leap motion. So we though we’ll control the drone using the leap motion Camera
- Challenges involved in the same are:
    - The drone’s stability
    - The signal traveling immediately from the laptop to the pixhawk that is in air
- Okay so the next thing we did was try to find research on what other things that can be done using the same API
- We did find a webAPI which can be integrated with any web app and the signal can be sent to the pixhawk using telemetry
- We tried flying the drones under many modes, but we couldn't promise stability so we gave up 

### Second Iteration
- We went to using a bluetooth module based bot which would send signal from one bluetooth module to another
- This Was done without unity, basically we have a web app running and a touchfree service instance running. 
- Both of them interact with each other and send signals to the arduino. 
- For this use the React Project and the server files
- But we had a lot of latency issues with bluetooth module and the motors moving due to these

### Third Iteration
- Here we use an ESP and use it as a webserver and send get requests to the esp bot directly. For this use the ino file for esp and the unity file for interaction with the leap motion sensor

### References
- [TouchFree-Tooling-Examples/Examples-Web/AnimatedProgressButtons at develop · ultraleap/TouchFree-Tooling-Examples (github.com)](https://github.com/ultraleap/TouchFree-Tooling-Examples/tree/develop/Examples-Web/AnimatedProgressButtons)
- [Drone example 1: Acquiring Telemetry Data from Pixhawk Cube to Raspberry Pi with Dronekit in Python - YouTube](https://www.youtube.com/watch?v=vCpxpqxA1Uo)
- [https://www.youtube.com/watch?v=lgqBFj1rkbw](https://www.youtube.com/watch?v=lgqBFj1rkbw)
- [Unity API](https://developer.leapmotion.com/unity)

### Members:
1. Divyateja Pasupuleti
2. Kumarasamy Chelliah
3. Gaurav Somai
 
