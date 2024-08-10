#include <iostream>
#include <cstdlib> // For system("clear") or system("cls")
using namespace std;

const int BOARD_SIZE = 3;
char board[BOARD_SIZE][BOARD_SIZE];

class Board
{
public:
    Board()
    {
        for (int i = 0; i < BOARD_SIZE; ++i)
        {
            for (int j = 0; j < BOARD_SIZE; ++j)
            {
                board[i][j] = ' '; // Empty Board
            }
        }
    }

    void print() const
    {
        cout << "   0   1   2" << endl;
        for (int i = 0; i < BOARD_SIZE; ++i)
        {
            cout << "  ";
            for (int j = 0; j < BOARD_SIZE; ++j)
            {
                cout << " " << board[i][j] << " ";
                if (j < BOARD_SIZE - 1)
                {
                    cout << "|";
                }
            }
            cout << endl;
            if (i < BOARD_SIZE - 1)
            {
                cout << "  ---|---|---" << endl;
            }
        }
    }

    bool make_move(int row, int col, char cp)
    {
        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != ' ')
        {
            return false;
        }
        board[row][col] = cp;
        return true;
    }

    bool is_won(char cp) const
    {
        for (int i = 0; i < BOARD_SIZE; ++i)
        {
            if ((board[i][0] == cp && board[i][1] == cp && board[i][2] == cp) ||
                (board[0][i] == cp && board[1][i] == cp && board[2][i] == cp))
            {
                return true;
            }
        }
        // check diagonals
        return (board[0][0] == cp && board[1][1] == cp && board[2][2] == cp) ||
               (board[0][2] == cp && board[1][1] == cp && board[2][0] == cp);
    }

    bool checkDraw() const
    {
        for (int i = 0; i < BOARD_SIZE; ++i)
        {
            for (int j = 0; j < BOARD_SIZE; ++j)
            {
                if (board[i][j] == ' ')
                    return false; // There is an empty cell
            }
        }
        return true; // No empty cells
    }
};

void clearConsole()
{
    #ifdef _WIN32
        system("cls"); // Windows
    #else
        system("clear"); // Unix-based (Linux, macOS)
    #endif
}

int main()
{
    Board gameBoard;
    char currentPlayer = 'X';

    while (true)
    {
    	cout << "Welcome to Tic Tac Toe Game" << endl;
    	cout << "Made by Ali Raza" << endl;
        gameBoard.print();
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        int row, col;
        cin >> row >> col;

        if (!gameBoard.make_move(row, col, currentPlayer))
        {
            cout << "Invalid move. Try again!" << endl;
            
            system("pause");
            clearConsole();
            continue;
        }

        if (gameBoard.is_won(currentPlayer))
        {
            clearConsole();
            gameBoard.print();
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        if (gameBoard.checkDraw())
        {
            clearConsole();
            gameBoard.print();
            cout << "It's a draw!" << endl;
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        clearConsole();
    }

    return 0;
}

