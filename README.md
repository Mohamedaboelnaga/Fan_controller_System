# Fan_controller_System
A system consists of a temperature sensor that measures the temperature,an Lcd that displays the current temp, and a motor that rotates with a certain speed according
to the current temp.If the temp<30 ,the  fan is off. If  temp >30 ,  fan is 25% max speed, if temp > 60 fan is 50%max  speed,if temp > 90 fan is  75% maxspeed.
Maxspeed if  temp>120

The sytem uses pwm to generate 25%,50%,75% or 100% of the motor max speed
Ths sytem uses adc module to convert the temperature into a digital signal
Layered Model is used between files
