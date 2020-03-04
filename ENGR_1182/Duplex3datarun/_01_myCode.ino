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

  //start all motors at 65% power and continue for 125 marks
  motorSpeed(4,65);
  goToAbsolutePosition(130);
  
  //airbrake at 40% for 1.7 seconds
  reverse(4);
  motorSpeed(4,35);
  goFor(1.7);

  //pause at stop for 3 seconds
  brake(4);
  goFor(3);

  //set motor speed to 25% power until the AEV reaches the origin point, then stop motors for 1.2 second
  motorSpeed(4,25);
  goToAbsolutePosition(0);
  brake(4);
  goFor(1.2);
  
  //set motor speed to 25% power until the AEV reaches 300 marks past the origin and then brake
  motorSpeed(4,25);
  goToAbsolutePosition(-300);
  brake(4);
  //airbrake at 45% power for 1.6 seconds
  reverse(4);
  motorSpeed(4,50);
  goFor(1.6);
  //stop for 3 seconds
  brake(4);
  goFor(3);

  //start all motors at 40% power and continue for 565 marks past the initial start position
  reverse(4);
  motorSpeed(4,40);
  goToAbsolutePosition(-565);

  //airbrake AEV at 50% power for 1.35 seconds
  reverse(4);
  motorSpeed(4,50);
  goFor(1.35);


  // And here--------------------------------------------------------------------------------

} // DO NOT REMOVE. end of void myCode()
