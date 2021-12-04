# ChocAn

## Introductions
Chocoholics Anonymous(ChocAn) is a software geared towards recovering chocolate addicts. It gives members unlimited consultations and treatments once they subscribe to ChocAn.

## Setup Instructions
1. Once you have downloaded the program run ``make`` in order to generate an executable
2. Ensure that you have the directories **cache** and **data**, where the data directory consists of **member** and **provider** sub-directories.
3. You can now run the executable by typing in ``./executable``
4. If you wish to clean up the report and the executable, type in ``make clean``

## The ChocAn team
- Cristina Stone Pedraza
- Tanner Mestas
- David Motorca
- Melissa Nguyen
- Nicole Chen
- Nahom Ketema

## Known Errors
> Unfortunately, the team was not able to properly use a Unit Testing frame work, instead, the team decided to use a brute force method
of entering in values for functions that we deemed neccessary to test. Below is some of the test cases that the team used to test the system. 

### Test Case - Proivder Number
Sample Input  | Result
--------------|-------------
91762077      |  Validated
12345678910   |  Invalid Number
123           |  Invalid Number
512488612     |  Invalid Number
-1-245-7-129  |  Invalid Number

### Test Case - Member Report
Sample Input  | Result
--------------|-------------
Tanner Mestas |  Valid Member Name
"Name that exceeds 25 characters" | Invalid Member Name
Portland  |  Valid City Name
97236  |  Valid Zip Code
Oregon  |  Invalid State Name
OR  |  Valid State Name


### Test Case - Provider Report
Sample Input          | Result
--------------|-------------
475.00  |  Valid Service Cost
2760.00  | Invalid Service Cost
HELLO WORLD  |  Invalid Service Cost
123,279.00  |  Invalid Weekly Service Cost
42,269.00  |  Valid Weekly Service Cost
HELLO WORLD  |  Invalid Weekly Service Cost


# License
[MIT License](LICENSE)
