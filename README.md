# Rock Paper Scissors Game in C++

## Description
This is a simple **Rock, Paper, Scissors** console game implemented in C++.  
The user plays against the computer for a number of rounds, and the final winner is determined based on the most round wins.

## Features
- Play up to **10 rounds** per game.
- **Random computer choices** using `rand()`.
- **Color-coded results** for each round:
  - 🟥 Red: Computer wins
  - 🟩 Green: Player wins
  - 🟨 Yellow: Draw
- Display of:
  - Player and computer choices per round.
  - Round winner.
  - Game summary at the end.

## File
- `RockPaperScissor.cpp` - Main game source file.

## Gameplay Flow

1. User chooses how many rounds to play (1–10).
2. For each round:
   - User picks Rock (1), Paper (2), or Scissors (3).
   - Computer randomly selects its choice.
   - Winner is determined and result shown.
3. After all rounds:
   - Final scores are shown.
   - Final winner is declared.
4. User is prompted to play again or exit.

## Notes
- Random seed is initialized using `srand(time(NULL))` to ensure randomness.
- ANSI `system("color")` commands are used to change console text background for visual feedback (may not work properly on all platforms).

## Author
Developed as a console-based C++ practice project by [Ahmad Atiyeh].
