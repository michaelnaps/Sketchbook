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

  //start all motors at 40% power and continue for 125 marks
  reverse(4);
  motorSpeed(4,40);
  goToAbsolutePosition(-125);
  
  //airbrake at 40% for 1.7 seconds
  reverse(4);
  motorSpeed(4,40);
  goFor(1.7);

  //pause at stop for 3 seconds
  brake(4);
  goFor(3);

  //set motorSpeed to 35% until AEV reached the origin and then pause for 1 second
  motorSpeed(4,35);
  goToAbsolutePosition(0);
  brake(4);
  goFor(1);
  
  //set motorSpeed to 30% till the AEV reached 330 marks and then brake
  motorSpeed(4,30);
  goToAbsolutePosition(330);
  brake(4);
  //airbrake at 30% for 1.5 seconds
  reverse(4);
  motorSpeed(4,30);
  goFor(1.5);
  //brake for 3 seconds
  brake(4);
  goFor(3);

  //start all motors at 45% power and continue for 565 marks past the initial start position
  reverse(4);
  motorSpeed(4,45);
  goToAbsolutePosition(565);

  //airbrake AEV at 40% power for 1.35 seconds
  reverse(4);
  motorSpeed(4,40);
  goFor(1.35);


  // And here--------------------------------------------------------------------------------

} // DO NOT REMOVE. end of void myCode()
