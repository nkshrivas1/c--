#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<ctime>

using namespace std;

// PART 12: ENUMS
enum GameStatus {
    PLAYING, WON, LOST
};
enum EnemyType {
    GOBLIN, ZOMBIE, WIZARD, DRAGON, BOSS
};

// PART 13: Struct for position/coordinates
struct Position {
    int x;
    int y;
};

// Forward declaration of classes
class Enemy;
class Player;

// PART 1 & 2: Treasure Class and Constructors
class Treasure {
private:
    string name;
    int value;
    string type;
    bool isCollected;

public:
    // Default constructor
    Treasure() {
        name = "Rusty Key";
        value = 50;
        type = "Key";
        isCollected = false;
    }

    // Parameterized constructor
    Treasure(string n, int v, string t) {
        name = n;
        value = v;
        type = t;
        isCollected = false;
    }

    // Getters and Setters
    string getName() const { return name; }
    int getValue() const { return value; }
    string getType() const { return type; }
    bool getIsCollected() const { return isCollected; }
    void collect() { isCollected = true; }

    // PART 17: Manipulators for formatted printing
    void display() const {
        cout << left << setw(20) << name 
             << right << setw(10) << fixed << setprecision(2) << (double)value << endl;
    }
};

// PART 1 & 2: Player Class and Constructors
class Player {
private:
    string name;
    int health;
    int score;
    int level;
    int coins;
    Position position;

    // PART 4: Static data member
    static int totalPlayers;

public:
    // DSA connection: inventory and treasure arrays (Part 5)
    string inventory[10];
    int inventoryCount;
    
    Treasure collectedTreasures[10];
    int collectedCount;

    // Default constructor
    Player() {
        name = "Unknown";
        health = 100;
        score = 0;
        level = 1;
        coins = 0;
        position.x = 0;
        position.y = 0;
        inventoryCount = 0;
        collectedCount = 0;
        totalPlayers++;
    }

    // Parameterized constructor with default argument for health (Part 2 & Part 15)
    Player(string n, int h = 100) : name(n), health(h) {
        score = 0;
        level = 1;
        coins = 50;
        position.x = 0;
        position.y = 0;
        inventoryCount = 0;
        collectedCount = 0;
        totalPlayers++;
    }

    // Copy constructor (Part 2)
    Player(const Player &other) {
        // PART 3: 'this' pointer usage
        this->name = other.name;
        this->health = other.health;
        this->score = other.score;
        this->level = other.level;
        this->coins = other.coins;
        this->position = other.position;
        this->inventoryCount = other.inventoryCount;
        for (int i = 0; i < other.inventoryCount; i++) {
            this->inventory[i] = other.inventory[i];
        }
        this->collectedCount = other.collectedCount;
        for (int i = 0; i < other.collectedCount; i++) {
            this->collectedTreasures[i] = other.collectedTreasures[i];
        }
        totalPlayers++;
    }

    // Destructor
    ~Player() {
        // Empty destructor
    }

    // PART 3: 'this' pointer in setter
    void setName(string name) {
        this->name = name;
    }

    // PART 16: Inline functions
    inline string getName() const { return name; }
    inline int getHealth() const { return health; }
    inline int getScore() const { return score; }
    inline int getLevel() const { return level; }
    inline int getCoins() const { return coins; }
    inline bool isAlive() const { return health > 0; }

    // PART 4: Static member function
    static int getTotalPlayers() {
        return totalPlayers;
    }

    void displayStatus() const {
        cout << "\n========================================" << endl;
        cout << "              PLAYER STATUS             " << endl;
        cout << "========================================" << endl;
        cout << "Name      : " << name << endl;
        cout << "Health    : " << health << "/100" << endl;
        cout << "Level     : " << level << endl;
        cout << "Score     : " << score << endl;
        cout << "Coins     : " << coins << endl;
        cout << "Position  : (" << position.x << ", " << position.y << ")" << endl;
        cout << "========================================" << endl;
    }

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
        cout << name << " takes " << damage << " damage! Current Health: " << health << endl;
    }

    void increaseScore(int amount) {
        score += amount;
        cout << "Score increased by " << amount << "! Current Score: " << score << endl;
    }

    // PART 15: Default Argument in heal method
    void heal(int amount = 20) {
        health += amount;
        if (health > 100) health = 100;
        cout << name << " heals by " << amount << " health! Current Health: " << health << endl;
    }

    void earnCoins(int amount) {
        coins += amount;
        cout << name << " earned " << amount << " coins! Current Coins: " << coins << endl;
    }

    void levelUp() {
        level++;
        health = 100; // Restore health on level up
        cout << "\n🌟 CONGRATULATIONS! " << name << " leveled up to Level " << level << "! Health restored. 🌟\n" << endl;
    }

    void move(int dx, int dy) {
        position.x += dx;
        position.y += dy;
        cout << name << " moved to position (" << position.x << ", " << position.y << ")." << endl;
    }

    void addItem(string item) {
        if (inventoryCount < 10) {
            inventory[inventoryCount] = item;
            inventoryCount++;
            cout << item << " added to inventory!" << endl;
        } else {
            cout << "Inventory is full!" << endl;
        }
    }

    void addTreasure(Treasure t) {
        if (collectedCount < 10) {
            collectedTreasures[collectedCount] = t;
            collectedCount++;
            increaseScore(t.getValue());
            addItem(t.getName());
        } else {
            cout << "Treasure bag is full!" << endl;
        }
    }

    // PART 11: Friend function declaration
    friend void comparePlayers(Player p1, Player p2);
};

// PART 1 & 2: Enemy Class
class Enemy {
private:
    string name;
    int health;
    int attackPower;
    int reward;
    EnemyType type;

public:
    // Default constructor
    Enemy() {
        name = "Goblin";
        health = 50;
        attackPower = 10;
        reward = 30;
        type = GOBLIN;
    }

    // Parameterized constructor
    Enemy(string n, int h, int ap, int r, EnemyType t) {
        name = n;
        health = h;
        attackPower = ap;
        reward = r;
        type = t;
    }

    // Member functions
    void display() const {
        cout << name << " | HP: " << health << " | ATK: " << attackPower << " | Reward: " << reward << " coins" << endl;
    }

    int attack() const {
        return attackPower;
    }

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
        cout << name << " takes " << damage << " damage! Enemy Health: " << health << endl;
    }

    // PART 16: Inline function
    inline bool isAlive() const {
        return health > 0;
    }

    inline int getHealth() const { return health; }
    string getName() const { return name; }
    int getReward() const { return reward; }
};

// ========================================================
//                     DSA ALGORITHMS
// ========================================================

// PART 10: Battle System utilizing Reference Variables
void battle(Player &player, Enemy &enemy) {
    cout << "\n========================================" << endl;
    cout << "             ⚔️ BATTLE START ⚔️            " << endl;
    cout << "========================================" << endl;
    cout << player.getName() << " vs " << enemy.getName() << endl;

    while (player.isAlive() && enemy.isAlive()) {
        cout << "\n" << player.getName() << " Health: " << player.getHealth() 
             << " | " << enemy.getName() << " Health: " << enemy.getHealth() << endl;
        cout << "1. Attack" << endl;
        cout << "2. Heal" << endl;
        cout << "3. Run" << endl;
        cout << "Enter choice: ";
        
        int choice;
        cin >> choice;

        if (choice == 1) {
            // Player attacks enemy
            cout << "\nYou attack the " << enemy.getName() << "!" << endl;
            enemy.takeDamage(15 + player.getLevel() * 5); // Attack damage scales with player level
            
            if (enemy.isAlive()) {
                // Enemy counter-attacks
                cout << "The " << enemy.getName() << " counter-attacks!" << endl;
                player.takeDamage(enemy.attack());
            }
        }
        else if (choice == 2) {
            // Player heals (Part 15: default argument)
            player.heal(); 
            
            // Enemy attacks while player heals
            cout << "The " << enemy.getName() << " attacks while you heal!" << endl;
            player.takeDamage(enemy.attack());
        }
        else if (choice == 3) {
            cout << "\nYou successfully fled from the battle!" << endl;
            return;
        }
        else {
            cout << "Invalid choice! You lost your turn." << endl;
            player.takeDamage(enemy.attack());
        }
    }

    if (!player.isAlive()) {
        cout << "\n💀 You were defeated by the " << enemy.getName() << "! Game Over. 💀" << endl;
    } else if (!enemy.isAlive()) {
        cout << "\n🎉 You defeated the " << enemy.getName() << "! 🎉" << endl;
        player.earnCoins(enemy.getReward());
        player.increaseScore(enemy.getReward() * 5);
        player.addItem(enemy.getName() + "'s Trophy");
        
        // Level up if player score crosses threshold
        if (player.getScore() >= player.getLevel() * 200) {
            player.levelUp();
        }
    }
}

// PART 11: Friend Function implementation
void comparePlayers(Player p1, Player p2) {
    cout << "\n========================================" << endl;
    cout << "           PLAYER COMPARISON            " << endl;
    cout << "========================================" << endl;
    // Accessing private member variables directly
    cout << left << setw(15) << p1.name << " Score: " << p1.score << endl;
    cout << left << setw(15) << p2.name << " Score: " << p2.score << endl;
    cout << "----------------------------------------" << endl;
    if (p1.score > p2.score) {
        cout << "Winner: " << p1.name << endl;
    } else if (p2.score > p1.score) {
        cout << "Winner: " << p2.name << endl;
    } else {
        cout << "It's a tie!" << endl;
    }
    cout << "========================================" << endl;
}

// PART 6: Searching using Linear Search
int searchItem(const string inventory[], int count, const string &target) {
    for (int i = 0; i < count; i++) {
        if (inventory[i] == target) {
            return i; // Target found at index i
        }
    }
    return -1; // Target not found
}

// PART 7: Sorting using Bubble Sort on objects
void sortTreasures(Treasure arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].getValue() < arr[j+1].getValue()) { // Descending order
                // Swap treasures
                Treasure temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// PART 14: Recursion
int calculateTreasureValue(const Treasure arr[], int n) {
    // Base Case
    if (n == 0) {
        return 0;
    }
    // Recursive Case: sum current + recursion of remainder
    return arr[n - 1].getValue() + calculateTreasureValue(arr, n - 1);
}

// ========================================================
//                     GAME COORDINATOR
// ========================================================

// PART 9: Object Interaction / Game Coordinator Class
class Game {
private:
    Player player;
    GameStatus status;
    
    // Arrays for storing game data (Part 5)
    Enemy enemies[5];
    int enemyCount;
    
    Treasure treasures[5];
    int treasureCount;

public:
    Game() {
        status = PLAYING;
        
        string playerName;
        cout << "Enter Your Character's Name: ";
        getline(cin, playerName);
        if (playerName.empty()) playerName = "Hero";
        player.setName(playerName);
        
        // Initialize enemies list
        enemies[0] = Enemy("Goblin Scout", 40, 8, 20, GOBLIN);
        enemies[1] = Enemy("Zombie Wanderer", 60, 12, 30, ZOMBIE);
        enemies[2] = Enemy("Dark Wizard", 50, 15, 40, WIZARD);
        enemies[3] = Enemy("Fire Dragon", 90, 20, 60, DRAGON);
        enemies[4] = Enemy("Dungeon Lord (BOSS)", 120, 25, 100, BOSS);
        enemyCount = 5;
        
        // Initialize treasures list
        treasures[0] = Treasure("Bronze Chalice", 150, "Valuable");
        treasures[1] = Treasure("Silver Ring", 300, "Valuable");
        treasures[2] = Treasure("Golden Crown", 600, "Valuable");
        treasures[3] = Treasure("Ruby Scepter", 800, "Valuable");
        treasures[4] = Treasure("Ancient Diamond", 1200, "Valuable");
        treasureCount = 5;
    }

    void explore() {
        cout << "\n🗺️ Exploring the dungeon..." << endl;
        // Simulating player coordinates changes
        int dx = (rand() % 3) - 1; // -1, 0, or 1
        int dy = (rand() % 3) - 1; // -1, 0, or 1
        player.move(dx, dy);

        int event = rand() % 3; // Random room event
        if (event == 0) {
            // Random Enemy encounter
            int enemyIndex = rand() % enemyCount;
            if (enemies[enemyIndex].isAlive()) {
                cout << "\n⚠️ Watch out! A wild " << enemies[enemyIndex].getName() << " appeared!" << endl;
                battle(player, enemies[enemyIndex]);
            } else {
                cout << "\nYou find the ashes of a defeated " << enemies[enemyIndex].getName() << ". The room is quiet." << endl;
            }
        } 
        else if (event == 1) {
            // Random Treasure chest encounter
            int treasureIndex = rand() % treasureCount;
            if (!treasures[treasureIndex].getIsCollected()) {
                cout << "\n✨ Jackpot! You found a treasure chest containing: " << treasures[treasureIndex].getName() << "! ✨" << endl;
                treasures[treasureIndex].collect();
                player.addTreasure(treasures[treasureIndex]);
            } else {
                cout << "\nYou find an opened, empty treasure chest." << endl;
            }
        } 
        else {
            cout << "\nYou enter a peaceful sanctuary. No monsters here." << endl;
            player.heal(10); // Restore a little health for resting
        }
    }

    void fightEnemyMenu() {
        cout << "\n========================================" << endl;
        cout << "            CHOOSE ENEMY TO FIGHT       " << endl;
        cout << "========================================" << endl;
        for (int i = 0; i < enemyCount; i++) {
            cout << (i + 1) << ". ";
            enemies[i].display();
        }
        cout << "Enter choice: ";
        int choice;
        cin >> choice;

        if (choice >= 1 && choice <= enemyCount) {
            // Prevention of re-fighting defeated enemies (User feedback integration)
            if (!enemies[choice - 1].isAlive()) {
                cout << "\n❌ The " << enemies[choice - 1].getName() << " is already defeated!" << endl;
            } else {
                battle(player, enemies[choice - 1]);
            }
        } else {
            cout << "Invalid choice!" << endl;
        }
    }

    void collectTreasureMenu() {
        cout << "\n========================================" << endl;
        cout << "            AVAILABLE TREASURES         " << endl;
        cout << "========================================" << endl;
        for (int i = 0; i < treasureCount; i++) {
            if (!treasures[i].getIsCollected()) {
                cout << (i + 1) << ". " << treasures[i].getName() << " (Value: " << treasures[i].getValue() << ")" << endl;
            } else {
                cout << (i + 1) << ". [COLLECTED] " << treasures[i].getName() << endl;
            }
        }
        cout << "Enter choice: ";
        int choice;
        cin >> choice;

        if (choice >= 1 && choice <= treasureCount) {
            // Prevent double collection (User feedback integration)
            if (treasures[choice - 1].getIsCollected()) {
                cout << "\n❌ You have already collected this treasure!" << endl;
            } else {
                treasures[choice - 1].collect();
                player.addTreasure(treasures[choice - 1]);
                cout << "\nCollected " << treasures[choice - 1].getName() << "!" << endl;
            }
        } else {
            cout << "Invalid choice!" << endl;
        }
    }

    void viewInventory() const {
        cout << "\n========== INVENTORY ==========" << endl;
        if (player.inventoryCount == 0) {
            cout << "No items in inventory." << endl;
        } else {
            for (int i = 0; i < player.inventoryCount; i++) {
                cout << (i + 1) << ". " << player.inventory[i] << endl;
            }
        }
        cout << "===============================" << endl;
    }

    void searchInventoryMenu() const {
        viewInventory();
        if (player.inventoryCount == 0) return;

        cout << "\nSearch item name: ";
        string target;
        cin.ignore();
        getline(cin, target);

        // Linear Search implementation check (Part 6)
        int pos = searchItem(player.inventory, player.inventoryCount, target);
        if (pos != -1) {
            cout << "\n\"" << target << "\" found at position " << (pos + 1) << " in inventory." << endl;
        } else {
            cout << "\n\"" << target << "\" not found in inventory." << endl;
        }
    }

    void viewTreasureRanking() {
        cout << "\n================================================" << endl;
        cout << "              TREASURE RANKING                  " << endl;
        cout << "================================================" << endl;
        cout << left << setw(20) << "Name" << right << setw(10) << "Value" << endl;
        cout << "------------------------------------------------" << endl;

        if (player.collectedCount == 0) {
            cout << "No treasures collected yet." << endl;
        } else {
            // Create a temporary array to sort the collected treasures
            Treasure sortedList[10];
            for (int i = 0; i < player.collectedCount; i++) {
                sortedList[i] = player.collectedTreasures[i];
            }
            
            // Hand-written bubble sort (Part 7)
            sortTreasures(sortedList, player.collectedCount);

            for (int i = 0; i < player.collectedCount; i++) {
                sortedList[i].display();
            }
            
            // Recursive calculation of sum (Part 14)
            int totalValue = calculateTreasureValue(player.collectedTreasures, player.collectedCount);
            cout << "------------------------------------------------" << endl;
            cout << left << setw(20) << "Total Value (Recursive):" 
                 << right << setw(10) << fixed << setprecision(2) << (double)totalValue << endl;
        }
        cout << "================================================" << endl;
    }

    void viewStatus() const {
        player.displayStatus();
    }

    void run() {
        // PART 18: Game Menu Loop
        while (status == PLAYING && player.isAlive()) {
            // Win condition (Part 19): Level 5 reached OR Boss defeated
            if (player.getLevel() >= 5 || !enemies[4].isAlive()) {
                status = WON;
                break;
            }

            cout << "\n========================================" << endl;
            cout << "             DUNGEON QUEST              " << endl;
            cout << "========================================" << endl;
            cout << "1. Explore Dungeon" << endl;
            cout << "2. Fight Enemy" << endl;
            cout << "3. Collect Treasure" << endl;
            cout << "4. View Inventory" << endl;
            cout << "5. Search Inventory" << endl;
            cout << "6. View Treasure Ranking" << endl;
            cout << "7. View Player Status" << endl;
            cout << "8. Exit Game" << endl;
            cout << "\nEnter choice: ";
            
            int choice;
            cin >> choice;

            switch (choice) {
                case 1: explore(); break;
                case 2: fightEnemyMenu(); break;
                case 3: collectTreasureMenu(); break;
                case 4: viewInventory(); break;
                case 5: searchInventoryMenu(); break;
                case 6: viewTreasureRanking(); break;
                case 7: viewStatus(); break;
                case 8: 
                    status = LOST; 
                    cout << "Cowardly retreating from the dungeon..." << endl;
                    break;
                default: 
                    cout << "Invalid choice! Please enter a number between 1 and 8." << endl;
            }
        }

        // PART 19: Game Completion Output
        if (status == WON) {
            cout << "\n╔══════════════════════════════════════╗" << endl;
            cout << "║          🏆 DUNGEON CLEARED!         ║" << endl;
            cout << "╚══════════════════════════════════════╝" << endl;
            cout << "Player       : " << player.getName() << endl;
            cout << "Level        : " << player.getLevel() << endl;
            cout << "Health       : " << player.getHealth() << endl;
            cout << "Score        : " << player.getScore() << endl;
            cout << "Coins        : " << player.getCoins() << endl;
            cout << "Treasures    : " << player.collectedCount << endl;
            cout << "\nCongratulations!" << endl;
            cout << "You escaped the dungeon." << endl;
        } else if (!player.isAlive()) {
            cout << "\n╔══════════════════════════════════════╗" << endl;
            cout << "║             💀 YOU DIED!             ║" << endl;
            cout << "╚══════════════════════════════════════╝" << endl;
            cout << "Your journey ends here. The dungeon remains unconquered." << endl;
        }
    }
};

// Initialize static member variable
int Player::totalPlayers = 0;

int main() {
    // Seed random generator
    srand(time(0));

    cout << "========================================" << endl;
    cout << "       DEMO: OOP Static & Friend        " << endl;
    cout << "========================================" << endl;
    // Demonstrate creation of two players to showcase constructor count
    Player p1("Aman");
    Player p2("Rahul");
    
    // Give them some dummy scores
    p1.increaseScore(150);
    p2.increaseScore(250);
    
    // Display total players created (Part 4)
    cout << "Total Players Created: " << Player::getTotalPlayers() << endl;
    
    // Call friend function (Part 11)
    comparePlayers(p1, p2);

    cout << "\nStarting the real game now..." << endl;
    
    // Create Game instance (Part 9)
    Game game;
    game.run();

    // PART 20: Complexity Analysis Table
    cout << "\n========================================================" << endl;
    cout << "                COMPLEXITY ANALYSIS                     " << endl;
    cout << "========================================================" << endl;
    cout << left << setw(28) << "Operation" << setw(20) << "Algorithm" << setw(12) << "Complexity" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << left << setw(28) << "Display enemies" << setw(20) << "Traversal" << setw(12) << "O(n)" << endl;
    cout << left << setw(28) << "Search inventory" << setw(20) << "Linear Search" << setw(12) << "O(n)" << endl;
    cout << left << setw(28) << "Sort treasures" << setw(20) << "Bubble Sort" << setw(12) << "O(n^2)" << endl;
    cout << left << setw(28) << "Calculate treasure value" << setw(20) << "Recursion" << setw(12) << "O(n)" << endl;
    cout << "========================================================" << endl;

    return 0;
}
