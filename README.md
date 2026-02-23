# Memory Matching Game
A console-based Memory Matching Game written in C++ as a semester project to demonstrate core Object-Oriented Programming concepts.

---

## How to Compile & Run

```bash
g++ memory_matching_game.cpp -o game
./game
```

---

## How to Play

1. Run the program and select a game mode.
2. The board shows 6 face-down cards marked as `?`.
3. On your turn, pick two card positions by entering their numbers.
4. If both cards have the same value — it's a **MATCH** and they are marked as `*`.
5. If they don't match, the turn passes to the other player.
6. The game ends when all 3 pairs are found.

---

## Game Modes

| Mode | Description |
|---|---|
| 1. Single Player | One player finds all pairs alone |
| 2. Multiplayer | Two players take turns, most pairs wins |
| 3. Play Against Computer | You vs the Computer |

---

## Board Layout

```
Positions: [1] [2] [3] [4] [5] [6]
Cards:      ?    ?    ?    ?    ?    ?
```

- `?` — card is hidden
- `*` — card has been matched

There are **3 pairs** hidden on the board: values 1, 2, and 3 each appear twice.

---

## OOP Concepts Used

| Concept | Where |
|---|---|
| Classes & Objects | `Board`, `Player`, `HumanPlayer`, `ComputerPlayer` |
| Constructors | Every class has a constructor |
| Inheritance | `HumanPlayer` and `ComputerPlayer` extend `Player` |
| Pointers | `Player* p1`, `Player* p2`, `Player* p` |
| Arrays | `values[6]` and `matched[6]` in `Board` |
| Dynamic Memory | `new` to create players, `delete` to free them |
| Function Overloading | `display()` and `display(string message)` |
| Polymorphism | `pickCard()` and `showResult()` resolved at runtime |
| Abstract Class | `Player` has pure virtual `pickCard() = 0` |

---

## Project Structure

```
memory_matching_game.cpp
│
├── class Board          — manages the card grid
├── class Player         — abstract base class
├── class HumanPlayer    — human input handling
├── class ComputerPlayer — computer AI logic
├── playGame()           — main game loop
└── main()               — mode selection & startup
```

---

## Example Output

```
Select Mode:
1.Single Player
2.Multiplayer
3.Play Against Computer
Choice: 3

Ready!
Positions: [1] [2] [3] [4] [5] [6]
Cards:      ?    ?    ?    ?    ?    ?

Player 1's Turn
Player 1, pick one card (1-6): 1
Value: 1
Player 1, pick one card (1-6): 4
Value: 1
MATCH!

Computer's Turn
Computer picks card 2
Value: 2
Computer again pick card 5
Value: 2
MATCH!
```
