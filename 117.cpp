#include <iostream>

struct boardGame{
    char board[3][3];
    bool gameOver;
    int currentPlayer;
};

void playerTurn(char board[][3], int player, int &r, int &c){
    if(player == 1){
        std::cout << "Enter the row: ";
        std::cin >> r;
        std::cout << "Enter the column: ";
        std::cin >> c;
        board[r][c] = 'x';
    } else {
        std::cout << "Enter the row: ";
        std::cin >> r;
        std::cout << "Enter the column: ";
        std::cin >> c;
        board[r][c] = 'o';
    }
}

void switchTurn(int &player){
    if(player == 1){
        player = 2;
        std::cout << "Player 2's turn!" << std::endl;
    } else {
        player = 1;
        std::cout << "Player 1's turn!" << std::endl;
    }
}

void checkMate(char board[][3], bool &checkmateO, bool &checkmateX, bool &gameOver){
    for(int i = 0; i <= 2; i++){
        if (board[i][0] == 'x' && board[i][1] == 'x' && board[i][2] == 'x'){
            checkmateX = true;
            gameOver = true;
        } else if (board[i][0] == 'o' && board[i][1] == 'o' && board[i][2] == 'o'){
            checkmateO = true;
            gameOver = true;
        } else if (board[0][i] == 'x' && board[1][i] == 'x' && board[2][i] == 'x'){
            checkmateX = true;
            gameOver = true;
        } else if (board[0][i] == 'o' && board[1][i] == 'o' && board[2][i] == 'o'){
            checkmateO = true;
            gameOver = true;
        }
    }

    if (board[0][0] == 'x' && board[1][1] == 'x' && board[2][2] == 'x'){
        checkmateX = true;
        gameOver = true;
    } else if (board[0][0] == 'o' && board[1][1] == 'o' && board[2][2] == 'o'){
        checkmateO = true;
        gameOver = true;
    } else if (board[0][2] == 'x' && board[1][1] == 'x' && board[2][0] == 'x'){
        checkmateX = true;
        gameOver = true;
    } else if (board[0][2] == 'o' && board[1][1] == 'o' && board[2][0] == 'o'){
        checkmateO = true;
        gameOver = true;
    }    
}

void printBoard(char board[][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(){

    int r,c;
    bool checkmateX = false;
    bool checkmateO = false;

    boardGame xo;

    xo.gameOver = false;
    xo.currentPlayer = 1;

    std::cout << "Starting with player 1!" << std::endl;

    for(int i = 0; i < 10; i++){
        playerTurn(xo.board, xo.currentPlayer, r, c);
        printBoard(xo.board);
        std::cout << std::endl;
        checkMate(xo.board, checkmateO, checkmateX, xo.gameOver);
        if (xo.gameOver == true){
            break;
        }
        switchTurn(xo.currentPlayer);
    }

    if(checkmateX == true){
        std::cout << "Player 1 wins!";
    } else if (checkmateO == true){
        std::cout << "Player 2 wins!";
    }


    return 0;
}