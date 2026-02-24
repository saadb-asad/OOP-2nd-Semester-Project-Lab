#include <iostream>
using namespace std;

class Board {
public:
    int  values[6] = {1, 2, 3, 1, 2, 3};
    bool matched[6] = {false, false, false, false, false, false};
    int  size = 6;

    void display() {
        cout << "\nPositions: ";
        for (int i = 0; i < size; i++)
            cout << "[" << i + 1 << "] ";
        cout << "\nCards:     ";
        for (int i = 0; i < size; i++) {
            if (matched[i]) cout << " *  ";
            else            cout << " ?  ";
        }
        cout << "\n\n";
    }

    void display(string message) {
        cout << message << "\n";
        display();
    }

    bool allMatched() {
        for (int i = 0; i < size; i++)
            if (!matched[i]) return false;
        return true;
    }
};


class Player {
public:
    string name;
    int score;

    Player(string n) {
        name  = n;
        score = 0;
    }

    virtual int pickCard(Board& board, int alreadyPicked) = 0;

    virtual void showResult() {
        cout << name << ": " << score << " pairs\n";
    }
};


class HumanPlayer : public Player {
public:
    HumanPlayer(string n) : Player(n) {
        Player::name = n;
    }

    int pickCard(Board& board, int alreadyPicked) {
        int choice;
        cout << name << ", pick one card (1-6): ";
        cin >> choice;
        return choice - 1;
    }
};


void playGame(Player* p1, Player* p2, bool twoPlayers) {
    Board board;
    board.display("Ready!");

    int current = 1;

    while (!board.allMatched()) {
        Player* p;
        if (current == 1)
            p = p1;
        else
            p = p2;

        cout << p->name << "'s Turn\n";
        board.display();

        int first = p->pickCard(board, -1);
        cout << "Value: " << board.values[first] << "\n";

        int second = p->pickCard(board, first);
        cout << "Value: " << board.values[second] << "\n";

        if (board.values[first] == board.values[second]) {
            cout << "MATCH!\n\n";
            board.matched[first] = board.matched[second] = true;
            p->score++;
        } else {
            cout << "No match!\n\n";
            if (twoPlayers) {
                if (current == 1) current = 2;
                else              current = 1;
            }
        }
    }

    p1->showResult();
    if (twoPlayers) {
        p2->showResult();
        cout << "\n";
        if (p1->score > p2->score)
            cout << "Winner: " << p1->name << "\n";
        else if (p2->score > p1->score)
            cout << "Winner: " << p2->name << "\n";
        else
            cout << "Tie!";
    }
}


int main() {
    cout << "Select Mode:\n1.Single Player\n2.Multiplayer\n";
    cout << "Choice: " << endl;

    int mode;
    cin >> mode;

    switch (mode) {
        case 1: {
            Player* p1 = new HumanPlayer("Player 1");
            playGame(p1, p1, false);
            delete p1;
            break;
        }
        case 2: {
            Player* p1 = new HumanPlayer("Player 1");
            Player* p2 = new HumanPlayer("Player 2");
            playGame(p1, p2, true);
            delete p1;
            delete p2;
            break;
        }
    }

    return 0;
}
