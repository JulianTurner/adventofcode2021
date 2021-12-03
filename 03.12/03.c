/*
The submarine has been making some odd creaking noises, so you ask it to produce
a diagnostic report just in case.

The diagnostic report (your puzzle input) consists of a list of binary numbers
which, when decoded properly, can tell you many useful things about the
conditions of the submarine. The first parameter to check is the power
consumption.

You need to use the binary numbers in the diagnostic report to generate two new
binary numbers (called the gamma rate and the epsilon rate). The power
consumption can then be found by multiplying the gamma rate by the epsilon rate.

Each bit in the gamma rate can be determined by finding the most common bit in
the corresponding position of all numbers in the diagnostic report. For example,
given the following diagnostic report:

00100
11110
10110
10111
10101
01111
00111
11100
10000
11001
00010
01010

Considering only the first bit of each number, there are five 0 bits and seven 1
bits. Since the most common bit is 1, the first bit of the gamma rate is 1.

The most common second bit of the numbers in the diagnostic report is 0, so the
second bit of the gamma rate is 0.

The most common value of the third, fourth, and fifth bits are 1, 1, and 0,
respectively, and so the final three bits of the gamma rate are 110.

So, the gamma rate is the binary number 10110, or 22 in decimal.

The epsilon rate is calculated in a similar way; rather than use the most common
bit, the least common bit from each position is used. So, the epsilon rate is
01001, or 9 in decimal. Multiplying the gamma rate (22) by the epsilon rate (9)
produces the power consumption, 198.

Use the binary numbers in your diagnostic report to calculate the gamma rate and
epsilon rate, then multiply them together. What is the power consumption of the
submarine? (Be sure to represent your answer in decimal, not binary.)
*/

#include <math.h>
#include <stdio.h>

#define REPORTS 1
#define REPORTLENGTH 12

int binToDec(int arr[]) {
  int result = 0;

  for (int i = 0; i < REPORTLENGTH; i++) {
    int multiplier = 2;
    for (int j = REPORTLENGTH - 4; j - i >= 0; j--) {
      multiplier *= 2;
    }

    if (i == 10) {
      continue;
    }

    if (i == 11) {
      if (arr[i] == 1) {
        result += 1;
      };
      continue;
    }

    result += arr[i] * multiplier;
  }

  return result;
}

int main() {

  long report[REPORTS][12];

  // read the reports from the input file
  FILE *file = fopen("03.12/report.txt", "r");
  for (int i = 0; i < REPORTS; i++) {
    // read the long numbers from the file
    for (int j = 0; j < REPORTLENGTH; j++) {
      long temp = 0;
      fscanf(file, "%ld", &temp);
      printf("%ld\n", temp);
    }
  }
  fclose(file);

  //   // ! MCB = most common bit
  //   int MCB[REPORTLENGTH] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  //   // ! LCB = least common bit
  //   int LCB[REPORTLENGTH] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  //   for (int i = 0; i < REPORTS; i++) {
  //     for (int j = 0; j < REPORTLENGTH; j++) {
  //       if (report[i][j] == 1) {
  //         MCB[j]++;
  //       }
  //     }
  //   }

  //   for (int j = 0; j < REPORTLENGTH; j++) {
  //     if (MCB[j] > 500) {
  //       MCB[j] = 1;
  //       LCB[j] = 0;
  //     } else {
  //       MCB[j] = 0;
  //       LCB[j] = 1;
  //     }
  //   }

  //   // gamma rate
  //   int gamma = binToDec(MCB);
  //   int epsilon = binToDec(LCB);

  //   long result = gamma * epsilon;

  //   printf("%ld\n", result);

  return 0;
}