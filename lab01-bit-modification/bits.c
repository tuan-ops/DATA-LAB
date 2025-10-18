/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2020 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
    int sign = x >> 31;
    return (x ^ sign) + ~sign + 1;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
    return ((x | (~x + 1)) >> 31) + 1;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
    int mask = 0x55;
    mask = mask | mask << 8;
    mask = mask | mask << 16;
    int mask2 = 0x33;
    mask2 = mask2 | mask2 << 8;
    mask2 = mask2 | mask2 << 16;
    int mask4 = 0x0F;
    mask4 = mask4 | mask4 << 8;
    mask4 = mask4 | mask4 << 16;
    int mask8 = 0xFF;
    mask8 = mask8 | mask8 << 16;
    int mask16 = 0xFF;
    mask16 = mask16 | mask16 << 8;
    x = (x & mask) + ((x>>1) & mask);
    x = (x & mask2) + ((x>>2) & mask2);
    x = (x & mask4) + ((x>>4) & mask4);
    x = (x & mask8) + ((x>>8) & mask8);
    x = (x & mask16) + ((x>>16) & mask16);
    return x;

}
/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {
    x = x ^ (x >> 16);
    x = x ^ (x >> 8);
    x = x ^ (x >> 4);
    x = x ^ (x >> 2);
    x = x ^ (x >> 1);
    return x & 1;
}
/*
 * bitReverse - Reverse bits in a 32-bit word
 *   Examples: bitReverse(0x80000002) = 0x40000001
 *             bitReverse(0x89ABCDEF) = 0xF7D3D591
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 45
 *   Rating: 4
 */
int bitReverse(int x) {
    x = ((x & 0x55555555) << 1) + ((x & 0xAAAAAAAA) >> 1);
    x = ((x & 0x33333333) << 2) + ((x & 0xCCCCCCCC) >> 2);
    x = ((x & 0x0F0F0F0F) << 4) + ((x & 0xF0F0F0F0) >> 4);
    x = ((x & 0x00FF00FF) << 8) + ((x & 0xFF00FF00) >> 8);
    x = ((x & 0x0000FFFF) << 16)+ ((x & 0xFFFF0000) >> 16);
    return x;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
    int mask = ((!!x) << 31) >> 31;
    return (y & mask) | (z & ~mask);
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
    int mask = 32 + ~n + 1;
    int res = (x << mask) >> mask;
    return !(x ^ res);
}
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  return ((x | (~x + 1)) >> 31) + 1;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1;
}
/* 
 * greatestBitPos - return a mask that marks the position of the
 *               most significant 1 bit. If x == 0, return 0
 *   Example: greatestBitPos(96) = 0x40
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Rating: 4 
 */
int greatestBitPos(int x) {
  int mask = x >> 31;
  x = (x | (x >> 1));
  x = (x | (x >> 2));
  x = (x | (x >> 4));
  x = (x | (x >> 8));
  x = (x | (x >> 16));
  x = (x >> 1) ^ x;
  int y =  1 << 31;
  int ma = (~(!mask) + 1);
  return (x  & ma) | (y & (~ma));

}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  int n = x ^ ( x >> 31);
  int pos = 0;
  int b1 = !!(n >> 16) << 4;
  n = n >> b1;
  int b2 = !!(n >> 8) << 3;
  n = n >> b2;
  int b3 = !!(n >> 4) << 2;
  n = n >> b3;
  int b4 = !!(n >> 2) << 1;
  n = n >> b4;
  int b5 = !!(n >> 1);
  n = n >> b5;
  pos = b1 + b2 + b3 + b4 + b5 + n;
  return pos + 1;
}
/*
 * intLog2 - return floor(log base 2 of x), where x > 0
 *   Example: intLog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int intLog2(int x) {
  int pos = 0;
  int b1 = !!(x >> 16) << 4;
  x = x >> b1;
  int b2 = !!(x >> 8) << 3;
  x = x >> b2;
  int b3 = !!(x >> 4) << 2;
  x = x >> b3;
  int b4 = !!(x >> 2) << 1;
  x = x >> b4;
  int b5 = !!(x >> 1);
  x = x >> b5;
  pos = b1 + b2 + b3 + b4 + b5 ;
  return pos;
}
/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value, and when negative overflow occurs,
 *          it returns minimum negative value.
 *   Examples: satAdd(0x40000000,0x40000000) = 0x7fffffff
 *             satAdd(0x80000000,0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int satAdd(int x, int y) {
  return x + y;
}
/* 
 * signMag2TwosComp - Convert from sign-magnitude to two's complement
 *   where the MSB is the sign bit
 *   Example: signMag2TwosComp(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int signMag2TwosComp(int x) {
  int mask = x >> 31;
  x = x & 0x7FFFFFFF;
  return (x ^ mask) + ~mask + 1;
}
/* 
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4 
 */
int isNonZero(int x) {
  return ~((x | (~x + 1)) >> 31) + 1;
}
/*
 * isPallindrome - Return 1 if bit pattern in x is equal to its mirror image
 *   Example: isPallindrome(0x01234567E6AC2480) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 45
 *   Rating: 4
 */
int isPallindrome(int x) {
    int n = x;
    n = ((n & 0x55555555) << 1) + ((n & 0xAAAAAAAA) >> 1);
    n = ((n & 0x33333333) << 2) + ((n & 0xCCCCCCCC) >> 2);
    n = ((n & 0x0F0F0F0F) << 4) + ((n & 0xF0F0F0F0) >> 4);
    n = ((n & 0x00FF00FF) << 8) + ((n & 0xFF00FF00) >> 8);
    n = ((n & 0x0000FFFF) << 16) + ((n & 0xFFFF0000) >> 16);
    return !(x ^ n);
}
/*
 * trueFiveEighths - multiplies by 5/8 rounding toward 0,
 *  avoiding errors due to overflow
 *  Examples: trueFiveEighths(11) = 6
 *            trueFiveEighths(-9) = -5
 *            trueFiveEighths(0x30000000) = 0x1E000000 (no overflow)
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 4
 */
int trueFiveEighths(int x) {
    int q = x >> 3;         
    int r = x & 7;          
    int result = (q << 2) + q; 
    int rem = (r << 2) + r;    
    int sign = x >> 31;        
    int bias = (sign & 7);
    rem = (rem + bias) >> 3;

    return result + rem;
}
/* 
 * twosComp2SignMag - Convert from two's complement to sign-magnitude 
 *   where the MSB is the sign bit
 *   You can assume that x > TMin
 *   Example: twosComp2SignMag(-5) = 0x80000005.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int twosComp2SignMag(int x) {
  int mask = x >> 31;
  int y = 0x80000000;
  return ((x & ~mask) | (((~x + 1) | y) & mask));
}
/* 
 * floatAbsVal - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatAbsVal(unsigned uf) {
  unsigned abs = uf & 0x7FFFFFFF;
  unsigned exp = uf & 0x7F800000;   
  unsigned frac = uf & 0x007FFFFF;
  if (exp == 0x7F800000 && frac != 0) return uf;
  return abs;
}
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  unsigned exp = uf & 0x7F800000;
  unsigned frac = uf & 0x007FFFFF;
  unsigned sign = uf & 0x80000000;
  if (exp == 0x7F800000) {
    return uf;
  }
  else if (exp  == 0) {
    frac <<= 1;
    if (frac & 0x00800000) {
      exp = 0x00800000;
      frac = frac & 0x007FFFFF;
    }
  }
  else {
    exp = exp + 0x00800000;
    if (exp == 0x7F800000) {
      frac = 0;
    }
  }
  return exp | frac | sign;
}
/* 
 * floatScale64 - Return bit-level equivalent of expression 64*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 35
 *   Rating: 4
 */
unsigned floatScale64(unsigned uf) {
  unsigned sign = uf & 0x80000000u;
  unsigned exp  = (uf >> 23) & 0xFFu;
  unsigned frac = uf & 0x7FFFFFu;

  if (exp == 0xFFu) return uf;

  if (exp != 0u) {
    unsigned newExp = exp + 6u;
    if (newExp >= 255u) return sign | 0x7F800000u;
    return sign | (newExp << 23) | frac;
  }

  {
    int k = 6;
    while (k > 0 && (frac << 1) < (1u << 23)) {
      frac <<= 1;
      k--;
    }
    if (k == 0) {
      return sign | frac;
    }
    frac <<= 1;
    k--;
    exp = 1u;
    frac &= 0x7FFFFFu;
    exp += (unsigned) k;
    if (exp >= 255u) return sign | 0x7F800000u;
    return sign | (exp << 23) | frac;
  }
}

/* 
 * floatInt2Float - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatInt2Float(int x) {
    int sign, exp, frac, bitc, tailb;
    
    if (x == 0) return 0;
    else if (x == 0x80000000) return 0xCF000000;
    
    sign = (x >> 31) & 1;
    if (sign) x = -x;
    bitc = 1;
    while ((x >> bitc) != 0)
        bitc++;
    bitc--;
    
    exp = bitc + 127;
    
    x = x << (31 - bitc); 
    frac = (x >> 8) & 0x7FFFFF;
    if (bitc > 23) {
        tailb = x & 0xFF; 
        
        if ((tailb > 128) || ((tailb == 128) && (frac & 1))) {
            frac += 1;
            if (frac >> 23) {
                exp += 1;
                frac = 0;
            } 
        }
    }
    
    return (sign << 31) | (exp << 23) | frac;
}
