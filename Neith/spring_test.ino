// Objective: To test whether or not the applied stepper motors can compress the current spring system.

/* 11/22/2019
 * Test 1: NOT SUCCESSFUL
 *  The compressive constant of the spring proved much to strong for the base torque of the 
 *  motors. The step types of SINGLE, DOUBLE and MICROSTEP were tested. The step type of 
 *  MICROSTEP proved to have the most success of the three, but could still only compress the
 *  spring a few millimeters.
 *  
 *  In order to increase torque, the radial distance between the tension in the string and the 
 *  motor arm must be minimized. This will include decreasing the diameter of the spool and/or 
 *  adding a gear mechanism to the system that would decrease total motor arm length.
*/

void spring_test(Adafruit_StepperMotor* motor_test)
{
  motor_test->setSpeed(3);
  motor_test->step(500, FORWARD, MICROSTEP);
  delay(1000);
  motor_test->release();
}
