#include <iostream>
#include <vector>

enum Colour { White, Black };

class Piece {
    public:
        Colour colour = White;
        void flip() {};
};

class Board {
    public:
        std::vector<std::vector<Piece> > board;
        void initialise_board() {};
        Board() { 
        }
};

class Game {
    private:
        Board board;
        int time_elapsed;
        static Game *game_instance;
        Game(Board b = Board()) { board = b; };
    public:
        Colour turn() { return White; };
        void set_board(Board b) { board = b; };
        static Game *instance()
        {
            if(!game_instance) {
                game_instance = new Game;
            }
            return game_instance;
        }
};

Game *Game::game_instance = 0;

int main() {
    Board b;
    Game::instance()->set_board(b);
    return 0;
}
