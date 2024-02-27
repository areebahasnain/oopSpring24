/* K230059 - AREEBA HASNAIN SHAIKH */

#include <iostream>

using namespace std;

class ChessPiece {
public:
    string name, color;

    // Default constructor for white pawns 
    ChessPiece() : name("P"), color("white") {}

    // Parameterized Constructor for creating a ChessPiece of the type specified by the parameters.
    ChessPiece(string name, string color) : name(name), color(color) {}

    // Getters
    string getColor() { return color; }
    string getName() { return name; }
    
    // Setters
    void setColor(string color) { this->color = color; }
    void setName(string name) { this->name = name; }
};


class ChessBoard {
public:
    // 2D array to represent the 8x8 grid
    ChessPiece board[8][8]; 

    ChessBoard() {
        // initialization of white pieces
        board[0][0] = ChessPiece("R", "white");
        board[0][1] = ChessPiece("N", "white");
        board[0][2] = ChessPiece("B", "white");
        board[0][3] = ChessPiece("K", "white");
        board[0][4] = ChessPiece("Q", "white");
        board[0][5] = ChessPiece("B", "white");
        board[0][6] = ChessPiece("N", "white");
        board[0][7] = ChessPiece("R", "white");

        // initialization of white pawns
        for (int i = 0; i < 8; i++) 
            board[1][i] = ChessPiece();

        // initialization of black pieces
        board[7][0] = ChessPiece("r", "black");
        board[7][1] = ChessPiece("n", "black");
        board[7][2] = ChessPiece("b", "black");
        board[7][3] = ChessPiece("k", "black");
        board[7][4] = ChessPiece("q", "black");
        board[7][5] = ChessPiece("b", "black");
        board[7][6] = ChessPiece("n", "black");
        board[7][7] = ChessPiece("r", "black");

        // initialization of black pawns
        for (int i = 0; i < 8; i++) 
            board[6][i] = ChessPiece("p", "black");

        // empty slots
        for (int i = 2; i < 6; i++) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = ChessPiece(".", "none");
            }
        }
    }

    void display() {
        int c = 8;
        // printing the header
        cout << "  ";
        for (char h = 'a'; h < 'i'; h++) 
            cout << h << "  ";
        cout << endl;
        // printing the pieces
        for (int i = 0; i < 8; i++) {
            // row num - start
            cout << c << " ";
            for (int j = 0; j < 8; j++) 
                cout << board[i][j].name << "  ";
            // row num - end
            cout << c--;
            cout << endl;
        }
        // printing the footer
        cout << "  ";
        for (char h = 'a'; h < 'i'; h++) 
            cout << h << "  ";
    }

    bool movePiece(string source, string destination) {
    // Extracting row and column indices from the source and destination positions
    int dest_r = 7 - (destination[1] - '1'); // Destination row index
    int dest_c = destination[0] - 'a';       // Destination column index
    int src_r = 7 - (source[1] - '1');       // Source row index
    int src_c = source[0] - 'a';             // Source column index
    
    // Retrieving the names of the chess pieces at the source and destination positions
    string src_name = board[src_r][src_c].name;   // Chess piece name at source position
    string dest_name = board[dest_r][dest_c].name; // Chess piece name at destination position
    
    // Displaying the move being validated
    cout << "Validating move for '" << src_name << "' from " << source << " to " << destination << ":" << endl;

    // Validating the move based on the type of chess piece
    if (src_name == "n" || src_name == "N") { // Knight movement
        bool vertical = abs(dest_r - src_r) == 2 && abs(dest_c - src_c) == 1;
        bool horizontal = abs(dest_r - src_r) == 1 && abs(dest_c - src_c) == 2;

        // Validating knight move: either vertical or horizontal movement and destination is empty
        return (vertical || horizontal) && dest_name == ".";
    } else if (src_name == "p" || src_name == "P") { // Pawn movement
        // Validating pawn move: 
        // - Same column as source
        // - Upward movement and obstacle, or downward movement and obstacle
        return src_c == dest_c &&
               ((src_r - dest_r == 1 || src_r - dest_r == 2) && board[src_r - 1][src_c].name == ".") ||
               ((dest_r - src_r == 1 || dest_r - src_r == 2) && board[src_r + 1][src_c].name == ".");
    }

    // Default case: invalid move
    return false;
    }
};

int main()
{
    cout << "-------------------------------------------" << endl;
    cout << "\tNAME: AREEBA HASNAIN SHAIKH"<< endl << "\tSTUDENT ID: K23-0059" << endl;
    cout << "-------------------------------------------" << endl;

    ChessBoard board;
    board.display();
    cout << endl << endl;

    /* Testing knight movements */ 
    // Valid moves for knight
    cout << "\tValid knight movements:" << endl;
    cout << endl;
    cout << "(g8 to f6) " << (board.movePiece("g8", "f6") ? "valid" : "not valid") << endl << endl;
    cout << "(g8 to h6) " << (board.movePiece("g8", "h6") ? "valid" : "not valid") << endl << endl;

    // Invalid moves for knight
    cout << "\tInvalid knight movements:" << endl;
    cout << endl;
    cout << "(g8 to e7) " << (board.movePiece("g8", "e7") ? "valid" : "not valid") << endl << endl;
    cout << "(g8 to h7) " << (board.movePiece("g8", "h7") ? "valid" : "not valid") << endl << endl;

    cout << endl;

    return 0;
}
