# Autonomous Robot


- Created a autonomous robot that simulated lane detection by following a black line using IR sensors. 
- It was able to detect obstacles in its path and stop using ultrasonic distance sensor. 
- Using the feed from the webcam attached to it, it recognized stop signs, red and green traffic light signals. This was done by custom training a model using YOLOv8. Based on the features it recognizes,the python program sends a signal through Serial communication to the Arduino which then acts accordingly.
- Actions such as move forward,stop,turn left,turn right were displayed on an I2C OLED display.
- This project was inspired from the work of [Zheng Wang's Self Driving RC Car](https://zhengludwig.wordpress.com/projects/self-driving-rc-car/)
