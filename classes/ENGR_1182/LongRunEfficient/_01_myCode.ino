void myCode()
{
  //----------------------------------------------------------------------------------------
  // myCode();
  //
  // This is the tab where the programming of your vehicle operation is done.
  // Tab _00_AEV_key_words contains a compiled list of functions/subroutines used for vehicle
  // operation. 
  //
  // Note:
  // (1) After running your AEV do not turn the AEV off, connect the AEV to a computer, or 
  //     push the reset button on the Arduino. There is a 13 second processing period. In 
  //     post processing, data is stored and battery recuperation takes place. 
  // (2) Time, current, voltage, total marks, position traveled are recorded approximately 
  //     every 60 milliseconds. This may vary depending on the vehicles operational tasks. 
  //     It takes approximately 35-40 milliseconds for each recording. Thus when programming,
  //     code complexity may not be beneficial. 
  // (3) Always comment your code. Debugging will be quicker and easier to do and will 
  //     especially aid the instructional team in helping you. 
  //---------------------------------------------------------------------------------------- 

  // Program between here-------------------------------------------------------------------

  //grand canyon via 45% power to motors till 133 marks past the origin
  motorSpeed(4,45);
  goToAbsolutePosition(133);
  //airbrake at 30% power for 1.7 seconds
  reverse(4);
  motorSpeed(4,30);
  goFor(1.7);
  //grab cart by rotate servo 105 degrees
  brake(4);
  goFor(.5);
  rotateServo(105);
  //pause at stop for 3 seconds
  brake(4);
  goFor(3);

  //waves
  //satrt at 30% power till 120 marks away from the origin
  motorSpeed(4,30);
  goToAbsolutePosition(120);
  //brake down the hill until cart reaches the origin point
  brake(4);
  goToAbsolutePosition(0);
  //continue by maintaining motors at 25% power until 270 marks past the origin
  motorSpeed(4,25);
  goToAbsolutePosition(-270);
  brake(4);
  //airbrake at 30% power for 2 seconds
  reverse(4);
  motorSpeed(4,30);
  goFor(2);
  //pause for 3 seconds
  brake(4);
  goFor(3);

  //denali
  //42% power uphill till 545 marks past the origin
  reverse(4);
  motorSpeed(4,42);
  goToAbsolutePosition(-545);
  //airbrake at 35% power for 1.8 seconds
  reverse(4);
  motorSpeed(4,35);
  goFor(1.8);
  //pause for 3 seconds
  brake(4);
  goFor(3);

  //The Hill
  //set motors to 30% power until 530 marks past the origin
  motorSpeed(4,30);
  goToAbsolutePosition(-530);
  //reverse motors and give boost of 65% power for .8 seconds to stop cart
  reverse(4);
  motorSpeed(4,65);
  goFor(.8);
  //maintain stop on hill by setting motors to 45% for 5 seconds
  motorSpeed(4,45);
  goFor(5);
  brake(4);

  //rocky mountains
  //start motors ar 30% power until 380 marks away from the maintenance station
  reverse(4);
  motorSpeed(4,30);
  goToAbsolutePosition(-380);
  //airbrake at 30% power for 2 seconds
  reverse(4);
  motorSpeed(4,30);
  goFor(2); 
  //pause for 3 seconds
  brake(4);
  goFor(3);
  
  //maintenance pt.2 via 40% power until 80 marks from the origin
  reverse(4);
  motorSpeed(4,40);
  goToAbsolutePosition(-80);
  //airbrake at 40% power for 1.3 seconds
  reverse(4);
  motorSpeed(4,40);
  goFor(1.3);
  //pause for 3 seconds
  brake(4);
  goFor(3);

  //Grand Canyon pt.2
  //set motors to 45% power till 150 marks from the origin
  reverse(4);
  motorSpeed(4,45);
  goToAbsolutePosition(150);
  //airbrake at 35% power for 1.7 seconds
  reverse(4);
  motorSpeed(4,35);
  goFor(1.7);
  //pause and let go
  //set hook back to original position
  brake(4);
  goFor(1);
  rotateServo(0);
  brake(4);
  goFor(3);

  //maintenance station pt.3
  //set motors to 30% power till 90 marks from the origin
  motorSpeed(4,30);
  goToAbsolutePosition(90);
  //airbrake at 55% power for 1.6 seconds
  reverse(4);
  motorSpeed(4,55);
  goFor(1.6);
  //stop
  
 

  // And here--------------------------------------------------------------------------------

} // DO NOT REMOVE. end of void myCode()
