#include <iostream>

using namespace std;

class Card {

    public:
        enum Suit { HEARTS, DIAMONDS, SPADES, CLUBS };
        Suit suit(void) {return su;};
        int value(void) {return val;};
        Card(int v, Suit s) {val = v; su = s; };
    private:
        Suit su;
        int val;
};

class BlackJack : Card {


    public:
        BlackJack(int v, Suit s)
        : Card(v, s)
        {
            sum += v;
        }
        int value(void) {
            int r = Card::value();
            if (r < 10) { return r;}
            return 10;
        };
        int sum;
        bool is_bust;

};
int main() {
    Card::Suit s = Card::HEARTS;
    Card c(1, s);
    cout << c.suit() << endl;
    cout << c.value() << endl;
    BlackJack bj(12, s);
    cout << bj.value() << endl;
    return 0;
}
