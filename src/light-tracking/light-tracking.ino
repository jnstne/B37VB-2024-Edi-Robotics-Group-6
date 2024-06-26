#define FIRMWARE_VERSION "v1.0.0"

#define UART_BAUDRATE 9600

#define MOTOR_L1_PIN 5
#define MOTOR_L2_PIN 6
#define MOTOR_R1_PIN 9
#define MOTOR_R2_PIN 10

#define LDR_L_PIN A2 
#define LDR_R_PIN A1 

#define ADC_RESOLUTION         10                    
#define ADC_OUTPUT_RANGE       (1 << ADC_RESOLUTION)
#define ADC_FULL_SCALE_VOLTAGE 5.0                   

#define LDR_DIFF_THRESHOLD 100
#define LDR_LOCK_THRESHOLD 800

#define MOTOR_L_FORWARD_PWM 115
#define MOTOR_R_FORWARD_PWM 96

#define MOTOR_L_REVERSE_PWM -85
#define MOTOR_R_REVERSE_PWM -85

#define MOTOR_L_LEFT_TURN_PWM 50
#define MOTOR_R_LEFT_TURN_PWM 100

#define MOTOR_L_RIGHT_TURN_PWM 100
#define MOTOR_R_RIGHT_TURN_PWM 50

#define MOTOR_TURN_DURATION_MS 250

#define UPDATE_PERIOD_MS 500

#define PWM__MAX 120
#define PWM__MIN -120

// Function made to measure the LDR Circuit Voltage
int LDRVoltage(int PinNumber)
{
  int AnalogReadResult;
  
  // Measuring the voltage from the LDR circuit using ADC
  AnalogReadResult = analogRead(PinNumber);
  
  return AnalogReadResult;

}
// Function to Set Motor Control Parameters
void Parameters(int PWM,
                               unsigned int HBridgePin1,
                               unsigned int HBridgePin2)
{
  if (PWM >= 0)
  {
    analogWrite(HBridgePin2, PWM);
    digitalWrite(HBridgePin1, LOW);
  }
  else
  {
    analogWrite(HBridgePin1, -PWM);
    digitalWrite(HBridgePin2, LOW);
  }
}

// Function to Update Motor Speed
void UpdateMotorSpeed(int LeftMotorPWM,
                      int RightMotorPWM,
                      unsigned long DurationMS)
{
  // Set Left Motor Control Parameters
  Parameters(LeftMotorPWM,
                            MOTOR_L1_PIN,
                            MOTOR_L2_PIN);
  
  // Set Right Motor Control Parameters
  Parameters(RightMotorPWM,
                            MOTOR_R1_PIN,
                            MOTOR_R2_PIN);
  
  // Add blocking delay (in ms)
  delay(DurationMS);
}

// Setup function runs once when board is powered up or reset
void setup()
{
  // Initialise UART
  Serial.begin(UART_BAUDRATE);
  
  // Initialise GPIO
  pinMode(MOTOR_L1_PIN, OUTPUT);
  pinMode(MOTOR_L2_PIN, OUTPUT);
  pinMode(MOTOR_R1_PIN, OUTPUT);
  pinMode(MOTOR_R2_PIN, OUTPUT);
  
  // Initialise Motor Driver
  digitalWrite(MOTOR_L1_PIN, LOW);
  digitalWrite(MOTOR_L2_PIN, LOW);
  digitalWrite(MOTOR_R1_PIN, LOW);
  digitalWrite(MOTOR_R2_PIN, LOW);
  
  // Output message to console
  Serial.println("B37VB Motor Control and LDR tracking Basics Demonstration");
  Serial.print("Version: ");
  Serial.println(FIRMWARE_VERSION);

}
// Loop function runs over and over again forever
void loop()
{
  int LeftLDR;
  int RightLDR;
  
  unsigned int LDRDiffMagnitude;
  
  int LeftMotorPWM;
  int RightMotorPWM;
  
  unsigned long TurnDuration;
  
  LeftLDR  = LDRVoltage(LDR_L_PIN);
  RightLDR = LDRVoltage(LDR_R_PIN);
  
  LDRDiffMagnitude = abs(LeftLDR - RightLDR);
  
  if (LDRDiffMagnitude > LDR_DIFF_THRESHOLD)
  {
    if (LeftLDR > RightLDR)
    {
      LeftMotorPWM  = MOTOR_L_LEFT_TURN_PWM;
      RightMotorPWM = MOTOR_R_LEFT_TURN_PWM;
      TurnDuration  = MOTOR_TURN_DURATION_MS;
    }
    else
    {
      LeftMotorPWM  = MOTOR_L_RIGHT_TURN_PWM;
      RightMotorPWM = MOTOR_R_RIGHT_TURN_PWM;
      TurnDuration  = MOTOR_TURN_DURATION_MS;
    }
    
    UpdateMotorSpeed(LeftMotorPWM,
                     RightMotorPWM,
                     TurnDuration);
  }
  else
  {   
    if (min(LeftLDR, RightLDR) > LDR_LOCK_THRESHOLD)
    {
      LeftMotorPWM  = 0;
      RightMotorPWM = 0;
    }
    else
    {  
      LeftMotorPWM  = MOTOR_L_FORWARD_PWM;
      RightMotorPWM = MOTOR_R_FORWARD_PWM;
    }
    
    UpdateMotorSpeed(LeftMotorPWM,
                     RightMotorPWM,
                     0);
  }
}
