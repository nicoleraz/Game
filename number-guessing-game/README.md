# Number Guessing Game (C++)

A console game where the player guesses two numbers from 0 to 5 and bets coins on them.

## How to play
1. You start with 1000 coins.
2. Guess two numbers (0 to 5) and enter your bet.
3. The program draws two random numbers:
   - Both guesses correct: you win 2x your bet
   - One guess correct: you win 1x your bet
   - No guess correct: you lose your bet
4. Choose to play again, or stop. The game also ends when you run out of coins.

## Built with
- C++ (standard library only: iostream, cstdlib, ctime)

## What I practiced
- Functions with parameters and return values
- Passing a variable by reference (`int &coins`)
- Random numbers with `rand()` and `srand()`
- Input validation
- Loops for replaying rounds

## Run it in VS Code
1. Install a C++ compiler (see below) and the "C/C++" extension.
2. File > Open Folder > choose this folder.
3. Press Ctrl+Shift+B to build, then Terminal > Run Task > "Build and run game".
   Or in the terminal: `g++ main.cpp -o game` then `./game`

### Compiler
- Windows: install MSYS2 (msys2.org), then in its terminal run `pacman -S mingw-w64-ucrt-x86_64-gcc`, and add `C:\msys64\ucrt64\bin` to PATH.
- Mac: run `xcode-select --install`
- Linux: `sudo apt install g++`
Check it works with `g++ --version`.

## Author
Cyrille Nicole B. Raz, BS Information Technology, City College of Calamba
