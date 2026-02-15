#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

// ==================== Card Class ====================
class Card {
private:
    char symbol;
    bool faceUp;
    bool matched;

public:
    // Constructor
    Card(char sym = ' ') {
        symbol = sym;
        faceUp = false;
        matched = false;
    }

    // Getter methods
    char getSymbol() {
        return symbol;
    }

    bool isFaceUp() {
        return faceUp;
    }

    bool isMatched() {
        return matched;
    }

    // Setter methods
    void flip() {
        faceUp = !faceUp;
    }

    void setMatched() {
        matched = true;
        faceUp = true;
    }

    // Display method
    void display() {
        if (matched || faceUp) {
            cout << " " << symbol << " ";
        } else {
            cout << " * ";
        }
    }
};

// ==================== Player Class ====================
class Player {
private:
    string name;
    int score;

public:
    // Constructor
    Player(string n = "Player") {
        name = n;
        score = 0;
    }

    // Getter methods
    string getName() {
        return name;
    }

    int getScore() {
        return score;
    }

    // Increase score
    void addPoint() {
        score++;
    }

    // Display player info
    void displayInfo() {
        cout << name << ": " << score << " pairs" << endl;
    }
};

// ==================== Board Class ====================
class Board {
private:
    vector<vector<Card>> grid;
    int size;
    int totalPairs;
    int foundPairs;

public:
    // Constructor
    Board(int gridSize) {
        size = gridSize;
        totalPairs = (size * size) / 2;
        foundPairs = 0;
        initializeBoard();
    }

    // Initialize the board with cards
    void initializeBoard() {
        // Create symbols for pairs
        vector<char> symbols;
        char currentSymbol = 'A';
        
        for (int i = 0; i < totalPairs; i++) {
            symbols.push_back(currentSymbol);
            symbols.push_back(currentSymbol);
            currentSymbol++;
        }

        // Shuffle the symbols
        srand(time(0));
        random_shuffle(symbols.begin(), symbols.end());

        // Fill the grid
        int index = 0;
        grid.resize(size);
        for (int i = 0; i < size; i++) {
            grid[i].resize(size);
            for (int j = 0; j < size; j++) {
                grid[i][j] = Card(symbols[index]);
                index++;
            }
        }
    }

    // Display the board
    void display() {
        cout << "\n   ";
        for (int j = 0; j < size; j++) {
            cout << " " << j << "  ";
        }
        cout << endl;

        for (int i = 0; i < size; i++) {
            cout << " " << i << " ";
            for (int j = 0; j < size; j++) {
                cout << "[";
                grid[i][j].display();
                cout << "]";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Check if position is valid
    bool isValidPosition(int row, int col) {
        return (row >= 0 && row < size && col >= 0 && col < size);
    }

    // Check if card is already face up or matched
    bool isCardAvailable(int row, int col) {
        return !grid[row][col].isFaceUp() && !grid[row][col].isMatched();
    }

    // Flip a card
    void flipCard(int row, int col) {
        grid[row][col].flip();
    }

    // Check if two cards match
    bool checkMatch(int row1, int col1, int row2, int col2) {
        return grid[row1][col1].getSymbol() == grid[row2][col2].getSymbol();
    }

    // Set cards as matched
    void setCardsMatched(int row1, int col1, int row2, int col2) {
        grid[row1][col1].setMatched();
        grid[row2][col2].setMatched();
        foundPairs++;
    }

    // Check if game is complete
    bool isGameComplete() {
        return foundPairs == totalPairs;
    }

    // Get size
    int getSize() {
        return size;
    }
};

// ==================== Game Class ====================
class Game {
private:
    Board* board;
    vector<Player> players;
    int currentPlayerIndex;
    bool isSinglePlayer;
    int moveCount;

public:
    // Constructor
    Game() {
        board = nullptr;
        currentPlayerIndex = 0;
        moveCount = 0;
    }

    // Destructor
    ~Game() {
        if (board != nullptr) {
            delete board;
        }
    }

    // Start the game
    void start() {
        cout << "\n========================================" << endl;
        cout << "   WELCOME TO MEMORY MATCHING GAME!" << endl;
        cout << "========================================" << endl;

        setupGameMode();
        setupDifficulty();
        setupPlayers();
        playGame();
    }

    // Setup game mode
    void setupGameMode() {
        int choice;
        cout << "\nSelect Game Mode:" << endl;
        cout << "1. Single Player" << endl;
        cout << "2. Multiplayer (2 Players)" << endl;
        cout << "Enter your choice (1 or 2): ";
        cin >> choice;

        isSinglePlayer = (choice == 1);
    }

    // Setup difficulty
    void setupDifficulty() {
        int choice;
        cout << "\nSelect Difficulty:" << endl;
        cout << "1. Easy (4x4)" << endl;
        cout << "2. Medium (5x5 - Note: 1 card will be alone)" << endl;
        cout << "3. Hard (6x6)" << endl;
        cout << "Enter your choice (1, 2, or 3): ";
        cin >> choice;

        int size;
        switch (choice) {
            case 1:
                size = 4;
                break;
            case 2:
                size = 5;
                cout << "\nNote: 5x5 has 25 cards. One card won't have a pair!" << endl;
                break;
            case 3:
                size = 6;
                break;
            default:
                size = 4;
                cout << "Invalid choice. Setting to Easy (4x4)" << endl;
        }

        board = new Board(size);
    }

    // Setup players
    void setupPlayers() {
        if (isSinglePlayer) {
            string name;
            cout << "\nEnter your name: ";
            cin.ignore();
            getline(cin, name);
            players.push_back(Player(name));
        } else {
            string name1, name2;
            cout << "\nEnter Player 1 name: ";
            cin.ignore();
            getline(cin, name1);
            cout << "Enter Player 2 name: ";
            getline(cin, name2);
            players.push_back(Player(name1));
            players.push_back(Player(name2));
        }
    }

    // Play the game
    void playGame() {
        cout << "\n========================================" << endl;
        cout << "           GAME STARTING!" << endl;
        cout << "========================================" << endl;
        cout << "\nInstructions:" << endl;
        cout << "- Enter row and column numbers to flip cards" << endl;
        cout << "- Match all pairs to win!" << endl;
        cout << "- Grid positions start from 0" << endl;

        while (!board->isGameComplete()) {
            board->display();

            if (!isSinglePlayer) {
                cout << "\n" << players[currentPlayerIndex].getName() << "'s turn!" << endl;
            }

            // Display current scores
            cout << "\nCurrent Scores:" << endl;
            for (int i = 0; i < players.size(); i++) {
                players[i].displayInfo();
            }

            takeTurn();

            if (!isSinglePlayer) {
                // Switch player only if no match was found
            }
        }

        endGame();
    }

    // Take a turn
    void takeTurn() {
        int row1, col1, row2, col2;

        // Get first card
        do {
            cout << "\nEnter first card position (row col): ";
            cin >> row1 >> col1;

            if (!board->isValidPosition(row1, col1)) {
                cout << "Invalid position! Try again." << endl;
            } else if (!board->isCardAvailable(row1, col1)) {
                cout << "Card already flipped or matched! Choose another." << endl;
            }
        } while (!board->isValidPosition(row1, col1) || !board->isCardAvailable(row1, col1));

        board->flipCard(row1, col1);
        board->display();

        // Get second card
        do {
            cout << "\nEnter second card position (row col): ";
            cin >> row2 >> col2;

            if (!board->isValidPosition(row2, col2)) {
                cout << "Invalid position! Try again." << endl;
            } else if (!board->isCardAvailable(row2, col2)) {
                cout << "Card already flipped or matched! Choose another." << endl;
            } else if (row1 == row2 && col1 == col2) {
                cout << "Cannot select the same card! Choose another." << endl;
            }
        } while (!board->isValidPosition(row2, col2) || !board->isCardAvailable(row2, col2) || (row1 == row2 && col1 == col2));

        board->flipCard(row2, col2);
        board->display();

        moveCount++;

        // Check for match
        if (board->checkMatch(row1, col1, row2, col2)) {
            cout << "\n*** MATCH FOUND! ***" << endl;
            board->setCardsMatched(row1, col1, row2, col2);
            players[currentPlayerIndex].addPoint();
            
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
        } else {
            cout << "\n*** NO MATCH! ***" << endl;
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();

            // Flip cards back down
            board->flipCard(row1, col1);
            board->flipCard(row2, col2);

            // Switch player in multiplayer mode
            if (!isSinglePlayer) {
                currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
            }
        }
    }

    // End game
    void endGame() {
        board->display();
        cout << "\n========================================" << endl;
        cout << "           GAME OVER!" << endl;
        cout << "========================================" << endl;

        if (isSinglePlayer) {
            cout << "\nCongratulations " << players[0].getName() << "!" << endl;
            cout << "You completed the game in " << moveCount << " moves!" << endl;
        } else {
            cout << "\nFinal Scores:" << endl;
            for (int i = 0; i < players.size(); i++) {
                players[i].displayInfo();
            }

            // Determine winner
            if (players[0].getScore() > players[1].getScore()) {
                cout << "\n" << players[0].getName() << " WINS!" << endl;
            } else if (players[1].getScore() > players[0].getScore()) {
                cout << "\n" << players[1].getName() << " WINS!" << endl;
            } else {
                cout << "\nIt's a TIE!" << endl;
            }
        }

        cout << "\nThanks for playing!" << endl;
    }
};

// ==================== Main Function ====================
int main() {
    Game game;
    game.start();
    return 0;
}
