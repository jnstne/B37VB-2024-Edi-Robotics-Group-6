# Motor charactarisation Report - B37VB - Aidan Johnstone & Seán Kelly

## Introduction
WE set out tocharacterise our motors and find the differences in power that are necessary to make said motors function as is required. 

## Method
### Direction Testing

### Speed Testing


When both motors pwm were set to identical parameters of 100 each, the robot turned left. To fix this we brought the right motor down to 85 while leaving the left at 100, this resulted in the robot driving straight. We then decided to up the speed putting the left motor at 120 and the right at 100 the robot once again drove straight. We then decided to try another higher speed and set the left to 150 and right to 130, this time the robot started turning slightly right after a few seconds of moving straight so we lowered the left to 145 and the robot started moving straight ahead again. We thenm decided top try another higher speed and so we set the left pwn to 170 and the right pwm to 150 which caused the robot to move mostly straight but drifting to the left, so we upped the left pwm to 172 and the robot moved straight again. From this we were able to determine that the left motor requires a higher pwm setting than the right.

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

