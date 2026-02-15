# Memory Matching Game - C++ Project

## Project Overview
This is a console-based Memory Matching Game developed in C++ using Object-Oriented Programming (OOP) principles for a semester project.

## Features
- **Single Player Mode**: Play alone and try to complete the game in minimum moves
- **Multiplayer Mode**: Play with a friend and compete for the highest score
- **Three Difficulty Levels**:
  - Easy (4x4 grid - 8 pairs)
  - Medium (5x5 grid - 12 pairs, 1 unpaired card)
  - Hard (6x6 grid - 18 pairs)

## How to Compile and Run

### On Windows (using g++)
```bash
g++ MemoryMatchingGame.cpp -o MemoryGame.exe
MemoryGame.exe
```

### On Linux/Mac
```bash
g++ MemoryMatchingGame.cpp -o MemoryGame
./MemoryGame
```

### Using an IDE (Code::Blocks, Dev-C++, Visual Studio)
1. Create a new C++ project
2. Add the MemoryMatchingGame.cpp file
3. Build and run the project

## Game Rules
1. All cards are placed face-down on a grid
2. On each turn, flip two cards
3. If they match, they stay face-up and you score a point
4. If they don't match, they flip back face-down
5. Remember the positions of cards to find matching pairs
6. The game ends when all pairs are found

### Single Player
- Complete the game in as few moves as possible
- Track your move count

### Multiplayer
- Players take turns flipping cards
- If you find a match, you get a point and take another turn
- If no match, the turn passes to the other player
- Player with the most pairs wins!

## Object-Oriented Design

### Classes Used

#### 1. Card Class
- **Attributes**: symbol, faceUp, matched
- **Methods**: getSymbol(), isFaceUp(), isMatched(), flip(), setMatched(), display()
- **Purpose**: Represents a single card in the game

#### 2. Player Class
- **Attributes**: name, score
- **Methods**: getName(), getScore(), addPoint(), displayInfo()
- **Purpose**: Stores player information and tracks score

#### 3. Board Class
- **Attributes**: grid (2D vector of Cards), size, totalPairs, foundPairs
- **Methods**: initializeBoard(), display(), isValidPosition(), isCardAvailable(), flipCard(), checkMatch(), setCardsMatched(), isGameComplete()
- **Purpose**: Manages the game board and card grid

#### 4. Game Class
- **Attributes**: board, players, currentPlayerIndex, isSinglePlayer, moveCount
- **Methods**: start(), setupGameMode(), setupDifficulty(), setupPlayers(), playGame(), takeTurn(), endGame()
- **Purpose**: Controls the game flow and logic

## Code Structure
```
MemoryMatchingGame.cpp
├── Card Class (represents individual cards)
├── Player Class (tracks player data)
├── Board Class (manages the game grid)
├── Game Class (controls game logic)
└── main() function (entry point)
```

## Key OOP Concepts Used
- **Encapsulation**: Private data members with public methods
- **Abstraction**: Hiding complex implementation details
- **Classes and Objects**: Card, Player, Board, Game
- **Dynamic Memory**: Using pointers for Board object
- **Standard Template Library (STL)**: Vectors for dynamic arrays

## Sample Gameplay

```
========================================
   WELCOME TO MEMORY MATCHING GAME!
========================================

Select Game Mode:
1. Single Player
2. Multiplayer (2 Players)
Enter your choice (1 or 2): 1

Select Difficulty:
1. Easy (4x4)
2. Medium (5x5)
3. Hard (6x6)
Enter your choice (1, 2, or 3): 1

Enter your name: Ali

========================================
           GAME STARTING!
========================================

     0   1   2   3
 0  [ * ][ * ][ * ][ * ]
 1  [ * ][ * ][ * ][ * ]
 2  [ * ][ * ][ * ][ * ]
 3  [ * ][ * ][ * ][ * ]

Current Scores:
Ali: 0 pairs

Enter first card position (row col): 0 0
```

## Future Enhancements (Optional)
- Add a timer to track completion time
- Implement difficulty levels with different symbols
- Add a hint system
- Create a leaderboard
- Add sound effects (if using graphics library)
- Implement a GUI version using SFML or SDL

## Notes
- The code uses `<algorithm>` for `random_shuffle()` which is deprecated in C++14. For newer compilers, you may need to replace it with `shuffle()` from `<random>`.
- Grid positions start from 0 (e.g., top-left is 0,0)
- The 5x5 grid has 25 cards (odd number), so one card won't have a matching pair

## Author
Created for Object-Oriented Programming Course
Semester Project

## License
Free to use for educational purposes
