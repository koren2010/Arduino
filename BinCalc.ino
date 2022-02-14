// 4-digit binary addition calculator

// numbers represnt by boolean arrays, true means 1, false mean 0


// global variables

bool num1[4]; // input num #1, array of 4 booleans
bool num2[4]; // input num #2, array of 4 booleans
bool result[5]; // sum of num1 and num2, array of 5 booleans
bool carry; // represents if carry exists or not in a calculation


// calculates addition of the two binary numbers and set the result variable to the sum

void calculate(bool num1[], bool num2[], bool result[]) {
  carry = false; // initializes the carry to false before starting calculation
  byte i = 0; // the variable to use in the for loop, declared out of the loop for use outside afterwards
  for (; i < 4; i++) { // iterating over the bits in the numbers and calculating
    result[i] = addBit(num1[i], num2[i]); // adds two bits and assigns to the corresponding place in result, if there is carry it is handled within addBit()
  }
  result[i] = carry; // if we're left with a carry after all bit adds has been done, assigns it to the last place in the result
}


// adding two bits and return the result. if there is carry, moved to the global variable.

bool addBit(bool bit1, bool bit2) {
  if (bit1 && bit2) { // if both numbers are 1
    if (carry) // if there is carry from previous calculation, we're doing 1 + 1 + 1
      return true; // return 1 and keep carry set to true because there is a carry after the calculation
  }
  //    if there is not a carry, calculation is 1 + 1
  carry = true; // we have a carry in case of 1 + 1
  return false; // the value for the digit to be returned is 0
}
if (bit1 || bit2) { // if numbers are 1 and 0, or 0 and 1 (we already took care of case 1 and 1)
  if (carry) { // if there is a carry, we're doing 1 + 1
    return false; // return 0 and keep carry set to true
  }
  //    in case there is not a carry, we're doing 1 + 0
  return true; // return 1 and leave carry false
}
// if both numbers are 0
if (carry) { // if there is a carry, calculate 1 + 0
  carry = false; // there is no carry for next calculation
  return true; // resukt is 1
}
//  if there is not a carry
return false; // 0 + 0 = 0
}
