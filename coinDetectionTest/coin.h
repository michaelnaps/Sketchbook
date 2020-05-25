// File: coin.h
// Created by: Michael Napoli
// Created on: 5/24/2020
// Last modified on:

/*
Purpose: Class for the declaration and organization of differing types of coins.
*/

#ifndef COIN_H
#define COIN_H

namespace mercury {
  class Coin
  {
  private:
    int count;
    String name;
    float ind_value;

  public:
    // CONSTRUCTORS:
    Coin::Coin() : name("INVALID NAME"), ind_value(-1), count(0) {}
    Coin::Coin(String given_name, float amount) : count(0) {
      name = given_name;
      ind_value = amount;
    }
    Coin::Coin(String given_name, float amount, int num) {
      name = given_name;
      ind_value = amount;
      count = num;
    }

    // GET MEMBER FUNCTIONS:
    // return the number of coins of the specified type
    int Coin::getCount() {
      return count;
    }

    // return the current coin's given title
    String Coin::getName() {
      return name;
    }

    // return the value of an individual coin of the specified type
    float Coin::getIndValue() {
      return ind_value;
    }

    // return the total (based on coin value and number of coins)
    float Coin::getTotal() {
      return (count * ind_value);
    }

    // OPERATOR FUNCTIONS (FRIEND):
    friend float operator+(const Coin& var1, const Coin& var2) {
      return ((var1.count * var1.ind_value) + (var2.count * var2.ind_value));
    }

    friend float operator-(const Coin& var1, const Coin& var2) {
      return ((var1.count * var1.ind_value) - (var2.count * var2.ind_value));
    }
    
    friend float operator++(Coin& var) {
      return ++var.count;
    }
    
    friend float operator--(Coin& var) {
      if (--var.count < 0) {
        // std::cout << "ERROR: No " << var.name << "(s) left to withdraw." << std::endl;
        return 0;
      }
      else {
        return --var.count;
      }
    }
  };
}

#endif
