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

  //grand canyon
  reverse(4);
  motorSpeed(4,40);
  goToAbsolutePosition(-126);
  //airbrake
  reverse(4);
  motorSpeed(4,40);
  goFor(1.65);
  //pause
  brake(4);
  goFor(3);

  //maintenance station no stop
  motorSpeed(4,35);
  goToAbsolutePosition(0);
  brake(4);
  goFor(1);
  
  //waves
  motorSpeed(4,30);
  goToAbsolutePosition(330);
  brake(4);
  //airbrake
  reverse(4);
  motorSpeed(4,30);
  goFor(1.5);
  //pause
  brake(4);
  goFor(3);

  //stop on hill
  reverse(4);
  motorSpeed(4,60);
  goToAbsolutePosition(450);
  motorSpeed(4,50);
  goFor(5);

  //uphill to snow
  motorSpeed(4,70);
  goFor(.75);
  motorSpeed(4,50);
  goToAbsolutePosition(600);
  //airbrake
  reverse(4);
  motorSpeed(4,30);
  goFor(1.6);
  //pause 4 seconds
  brake(4);
  goFor(4);

  //downhill to the rockies
  motorSpeed(4,30);
  goToAbsolutePosition(500);
  brake(4);
  goFor(1);
  motorSpeed(4,30);
  goToAbsolutePosition(370);
  //airbrake
  reverse(4);
  motorSpeed(4,30);
  goFor(1.5);
  brake(4);
  goFor(3);

  //maintenance station's neighbor
  reverse(4);
  motorSpeed(4,30);
  goToAbsolutePosition(70);
  //airbrake
  reverse(4);
  motorSpeed(4,30);
  goFor(1.5);


  // And here--------------------------------------------------------------------------------

} // DO NOT REMOVE. end of void myCode()
