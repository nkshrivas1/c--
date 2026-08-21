#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

// ENUMS
enum GameStatus{
    PLAYING,WON,LOSt
};
enum EnemyType{
    GOBLIN,ZOMBIE,WIZARD,DRAGON,BOSS
};

struct Position{
    int x;
    int y;
};
// forward declaration
class Enemy;
//player class
class Player{
    private:
        string name;
        int health;
        int score;
        int level;
        int coins;

        Position position;
        static int totalPlayers;
    public:
        Player(){
            name = "Unknown";
            health =100;
            score =0;
            level =1;
            coins =0;
            position.x=0;
            position.y = 0;
            totalPlayers++;
        }
        Player(string n,int h =100):name(n),health(h){
             score =0;
            level =1;
            coins =50;
            position.x=0;
            position.y = 0;
            totalPlayers++;
        } // copy cunstructor
        Player(const Player &other){
            this->name = other.name;
            this->health = other.health;
            this->score = other.score;
            this->level = other.level;
            this->coins = other.coins;
            this->position = other.position;
            totalPlayers++;
        }
        // empty destructor
        ~Player(){
            
        }
};

