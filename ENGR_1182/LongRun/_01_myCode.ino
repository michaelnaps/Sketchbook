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

  //grand canyon via 45% power for 120 marks
  motorSpeed(4,45);
  goToAbsolutePosition(120);
  //airbrake with 35% power for 1.7 seconds
  reverse(4);
  motorSpeed(4,35);
  goFor(1.1);
  //adjust to 177 marks at slow speed (10% power)
  reverse(4);
  motorSpeed(4,10);
  goToAbsolutePosition(177);
  //airbrake at 18% power for .8 seconds
  reverse(4);
  motorSpeed(4,18);
  goFor(.8);
  //wait .5 seconds, grab cart using hook displacement of 112 degrees
  brake(4);
  goFor(.5);
  rotateServo(112);
  //pause at stop for 3 seconds
  brake(4);
  goFor(3);

  //waves
  //start motors at 30% until 115 marks from origin
  motorSpeed(4,30);
  goToAbsolutePosition(115);
  //stop downhill
  brake(4);
  goToAbsolutePosition(0);
  //continue at 20% power till 330 marks past the origin
  motorSpeed(4,20);
  goToAbsolutePosition(-330);
  brake(4);
  //airbrake at 40% power for 1.7 seconds
  reverse(4);
  motorSpeed(4,40);
  goFor(1.7);
  //pause for 3 seconds
  brake(4);
  goFor(3);

  //denali
  //set motors to 42% power until 571 marks past the origin
  reverse(4);
  motorSpeed(4,42);
  goToAbsolutePosition(-571);
  //airbrake at 50% power for 1.25 seconds
  reverse(4);
  motorSpeed(4,50);
  goFor(1.25);
  //pause for 3 seconds
  brake(4);
  goFor(3);

  //The Hill
  //start motors at 35% power till 530 marks away from the origin
  motorSpeed(4,35);
  goToAbsolutePosition(-530);
  //reverse motors and give boost to stop cart via 75% power for .9 seconds
  reverse(4);
  motorSpeed(4,75);
  goFor(.9);
  //maintain stop with 45% power to motors for 5 seconds
  motorSpeed(4,45);
  goFor(5);
  brake(4);

  //rocky mountains
  //30% power till 345 marks past the origin
  reverse(4);
  motorSpeed(4,30);
  goToAbsolutePosition(-345);
  //airbrake 45% power for 1.4 seconds
  reverse(4);
  motorSpeed(4,45);
  goFor(1.4);
  //pause for 3 seconds
  brake(4);
  goFor(3);

  //Hocking Hills
  //maintenance pt.2 by 40% power till 80 marks past the origin
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
  //continue at 50% power till 160 marks past the origin
  reverse(4);
  motorSpeed(4,50);
  goToAbsolutePosition(160);
  //airbrake at 40% power for 1.2 seconds
  reverse(4);
  motorSpeed(4,40);
  goFor(1.2);
  //pause and let go
  //release cart via setting hook back to position 0
  brake(4);
  goFor(1);
  rotateServo(0);
  brake(4);
  goFor(3);

  //maintenance station pt.3
  //start motors at 30% power till 85 marks away from the origin
  motorSpeed(4,30);
  goToAbsolutePosition(85);
  //airbrake at 55% power for 1.5 seconds
  reverse(4);
  motorSpeed(4,55);
  goFor(1.5);
  //finished track
  
 

  // And here--------------------------------------------------------------------------------

} // DO NOT REMOVE. end of void myCode()
