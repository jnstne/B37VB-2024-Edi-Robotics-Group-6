# Motor charactarisation Report - B37VB - Aidan Johnstone & Seán Kelly

## Introduction
We set out to characterise our motors and find the PWM values each motor must be set to to make this robot drive straight at several different speeds. During our project we were successfully able to characterise our motors for a range of speeds. At each speed a different difference in PWM is required to make the motors drive straight

## Method
### Direction Testing
- First we set both motors PWMs to the same value
- Turn the robot on and record the direction in which it moves (left/right/straight)
- If robot turns left increase PWM of Left Motor or decrease PWM of right motor
- If robot turns right increase PWM of Right motor or decrease PWM of left motor 
- Repeat until robot moves straight

### Speed Testing
- Place a line of insulation tape on the ground (this is our start line)
- Using a tape measure mesuyre 1m away from the start line and place another line of insulation tape on the ground (this is our finish line)
- Set the motor PWMs to their lowest straight driving values and record these PWM values
- Place the robot on the start line and turn it on
- Using a stopwatch record the time taken for the robot to cross the finish line and record
- Repeat 2 more times and calculate the average time and record
- Using   Speed = Distance/time   calculate the speed of the robot and record
- Repeat for several higher PWM values and record the results

## Results

### A Table Showing the PWM Values of Each Motor and the Direction the Robot Turns
| Motor Left (PWM) | Motor Right        | Direction     |
| :---:            |       :---:        |      :---:    | 
| 100              | 100                | left          |
| 100              | 85                 | straight      |
| 120              | 100                | straight      |
| 150              | 130                | right         |
| 145              | 130                | straight      |
| 170              | 150                | drifts to left|
| 172              | 150                | straight      |

### A Table Showing the PWM Values for the Left and Right Motors and the Resultant Speed
| Motor Left (PWM) | Motor Right (PWM)  | Distance (m)  | Time 1 (s)   | Time 2 (s)     | Time 3 (s)    |  Average Time (s)    |  Speed (m/s) |            
| :---:            |       :---:        |      :---:    |     :---:    |      :---:     |    :---:      |        :---:         |         :---:|  
| 100              | 85                 | 1             | 3.96         | 3.62           | 3.72          |  3.76                | 0.266        |  
| 120              | 100                | 1             | 2.8          | 2.7            | 3.0           |  2.83                | 0.353        |  
| 145              | 130                | 1             | 2.37         | 2.47           | 2.33          |  2.37                | 0.422        |  


## Conclusion

We found this experiment interesting as we found out relatively quickly that the robot's right motor works faster than its left one. when the PWM values of both motors were at 100 our robot went significantly left, using our intuition we figured out what would be a better PWM value for the right motor to start with being 85. for us, the anomoly was when the robot drifted right slightly when we upped both PWM values by 20 (Left 150, Right 130). of course not every increase of PWM values would be by the same increments, increasing by 20 worked before but it just wasnt as accurate the second time around. we found that when the robot's PWM values are lower it struggles to stay straight and then beyond this expereiment we realised when it gets to greater PWM values than 200 it struggles again. it seems that the robot is at its most consistent when its speed is at a rather mid level. 
