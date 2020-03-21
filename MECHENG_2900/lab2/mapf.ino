// Function: mapf()
// Created by: Michael Napoli
// Created on: 3/12/2020

/*
 *  Purpose: To convert a given value from its initial range
 *  to another range given.
 *  
 *  intput: initial value, initial range, final range
 *  output: desired value in floating point form
*/

float mapf(int val, int init1, int fin1, int init2, int fin2)
{
  float desired(0);

  // '(float)' operator forces following value to be floating type
  
  // scale original value to percent representation of its boundaries
  desired = (float)val / (float)(fin1 - init1);
  
  // multiply by the span of the new boundaries given
  desired *= (float)(fin2 - init2);
  
  // add the bottom boundary back to desired value
  desired += (float)init2;

  return desired;
}
