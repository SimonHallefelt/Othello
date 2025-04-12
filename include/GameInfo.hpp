#ifndef GameInfo_hpp
#define GameInfo_hpp

#include <Board.hpp>
#include <Player.hpp>

class GameInfo {
private:
    Board board;
    Player blackPlayer, whitePlayer;
    Int2D manualMove;
    bool hasManualMove, stopGame;
public:
    GameInfo();
    ~GameInfo();

    std::array<std::array<int, 8>, 8> getBoard() const;
    void newBoard();
    void printBoard() const;
    int getPlayersTurn() const;
    bool gameComplete();
    void makeMove(Int2D pos);
    void printWinner();

    const Player& getCurrentPlayer();
    void setPlayerType(int player, int playerType);

    void setManualMove(Int2D pos);
    void setHasManualMove(bool b);
    Int2D getManualMove() const;
    bool getHasManualMove() const;

    void setStopGame();
    bool getStopGame() const;
};

#endif