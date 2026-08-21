```markdown
# Dungeon Quest — Build Your Own Adventure Game
**Duration:** 2–3 Hours  
**Language:** C++

## Objective
Build a console-based adventure game where the player explores a dungeon, collects items, fights enemies and tries to achieve the highest score.

Your program must demonstrate both:

**OOP**
* Class & objects
* Encapsulation
* Constructors
* Destructor
* `this` pointer
* Static data members/functions
* Member functions
* Friend function
* Reference variables / passing objects by reference

**DSA**
* Arrays
* Traversal
* Searching
* Sorting (optional)
* Functions
* Loops
* Structures/enums where appropriate
* Recursion (basic)
* Time-complexity analysis

---

## 🎮 GAME STORY
The player enters a dungeon containing:
* 🗺️ Locations
* 👾 Enemies
* 💎 Treasures
* ⚔️ Weapons
* 🧪 Potions
* 🔑 Keys

**The objective is to:**
Explore → Collect → Fight → Level Up → Find the Exit

The player with the highest score wins.

---

## PART 1 — Design the Game Using Classes
You must create at least 3 classes. A recommended design is:

```text
             Game
               |
      -------------------
      |        |        |
    Player   Enemy   Treasure

```

You may create additional classes such as: `Weapon`, `Inventory`, `Dungeon`, `Boss`

### 1️⃣ Player Class

Create: `class Player`

**Private data (At minimum):**

* `name`
* `health`
* `score`
* `level`
* `coins`

**Example:**

```cpp
class Player {
private:
    string name;
    int health;
    int score;
    int level;
    int coins;

public:
    // constructors
    // member functions
};

```

**Required member functions (At least):**

* `displayStatus()`
* `takeDamage()`
* `increaseScore()`
* `heal()` // max health 10
* `levelUp()`

### 2️⃣ Enemy Class

Create: `class Enemy`

**Private data:**

* `name`
* `health`
* `attackPower`
* `reward`

**Functions:**

* `display()`
* `attack()`
* `takeDamage()`
* `isAlive()`

You must create an array of `Enemy` objects.

**Example:** `Enemy enemies[5];`

*This is where OOP + array come together.*

### 3️⃣ Treasure Class

Create: `class Treasure`

**Possible data:**

* `name`
* `value`
* `type`

**For example:**

* Gold: 100
* Ruby: 500
* Diamond: 1000
* Potion: 50

Create an array: `Treasure treasures[10];`

---

## PART 2 — Constructors

Each major class should have:

* **Default constructor:** `Player();`
* **Parameterized constructor:** `Player(string name, int health);`

**For example:**

```cpp
Player p1("Rahul", 100);

```

---

## PART 3 — `this` Pointer

Use `this` somewhere meaningfully.

**For example:**

```cpp
void setName(string name) {
    this->name = name;
}

```

*You must be able to explain: What does `this` point to when `p1.setName()` is executed?*

---

## PART 4 — Static Members

The game should maintain the total number of players created. Inside `Player`:

```cpp
static int totalPlayers;

```

Increment it whenever a player is created. Create:

```cpp
static int getTotalPlayers();

```

Then display: `Total Players Created: 5`

> **Important:** The static member should actually have a purpose. Don't add a meaningless `static int x`.

---

## PART 5 — Game Array / DSA

The game must use arrays for storing game data.
**For example:**

```cpp
Enemy enemies[5];
Treasure treasures[10];

```

You must demonstrate array traversal.
**Example:**

```cpp
for(int i = 0; i < enemyCount; i++) {
    enemies[i].display();
}

```

---

## PART 6 — Searching 🔎

The player should be able to search the inventory.

**Example Output:**

```text
========== INVENTORY ==========

1. Sword
2. Potion
3. Diamond
4. Shield

Search item: Sword

Sword found at position 1.

```

Implement `int searchItem(...);` using Linear Search.

> **Requirement:** Do not use `find()` or another library search function. Implement the algorithm yourself.

---

## PART 7 — Sorting 🏆

At the end of the game, show the treasure ranking.

**Example Output:**

```text
========== TREASURE RANKING ==========

Diamond       1000
Ruby           700
Gold           500
Silver         250
Potion         100

```

Implement one of: Bubble Sort, Selection Sort, or Insertion Sort.

> **Important OOP connection:** You are not sorting simple integers only. You are sorting `Treasure treasures[10];` based on `treasures[i].getValue()`. So the sorting algorithm operates on objects. This is an important part of the assignment.

---

## PART 8 — Battle System ⚔️

When the player encounters an enemy:

**Example Output:**

```text
================================
             BATTLE
================================

Player
Health: 100

Enemy: Goblin
Health: 50

1. Attack
2. Heal
3. Run

Choice: Attack

```

Player attacks enemy: `enemy.takeDamage(player.getAttackPower());`

Enemy attacks player: `player.takeDamage(enemy.getAttackPower());`

Continue until `Enemy defeated!` or `You died!`

---

## PART 9 — Object Interaction

This is where students should actually use OOP. The objects should interact.

**For example:**

```cpp
player.attack(enemy);
// or
enemy.attack(player);

```

The game should not have all logic inside `main()`.

**Bad:**

```cpp
main() {
    // 500 lines of game logic
}

```

**Instead:**

```text
main()
   |
   └── Game object
          |
          ├── Player
          ├── Enemies
          ├── Treasures
          └── Game functions

```

---

## PART 10 — Reference Variables

At least one function must accept an object using a reference.

**For example:**

```cpp
void battle(Player &player, Enemy &enemy);

```

The function should modify the actual objects.

```cpp
player.takeDamage(20);
enemy.takeDamage(30);

```

*Students must explain why `Player &player` is being used instead of `Player player`.*

---

## PART 11 — Friend Function

Create one meaningful friend function.

**For example:**

```cpp
friend void comparePlayers(Player p1, Player p2);

```

The function could compare score, level, or health.

**Example Output:**

```text
================================
       PLAYER COMPARISON
================================

Rahul Score : 2500
Aman Score  : 1800

Winner: Rahul

```

The function should access at least one private member.

*Students must explain: Is `comparePlayers()` a member function? No.*

---

## PART 12 — Enum

Use an enum for game state or types.

**For example:**

```cpp
enum GameStatus {
    PLAYING,
    WON,
    LOST
};
// or
enum EnemyType {
    GOBLIN,
    ZOMBIE,
    DRAGON,
    BOSS
};

```

Use the enum in your program rather than merely declaring it.

---

## PART 13 — Struct

Use a struct for some supporting information.

**For example:**

```cpp
struct Position {
    int x;
    int y;
};

```

The player can have `Position playerPosition;` or create:

```cpp
struct Weapon {
    string name;
    int damage;
};

```

Then the player can own a weapon.

---

## PART 14 — Recursion

The game must contain one meaningful recursive operation. Don't simply add `factorial(5);` just to satisfy the syllabus.

**Example: Dungeon Treasure**
Suppose the player has collected treasures: `100, 200, 500, 300`

Create: `int calculateTreasureValue(Treasure arr[], int n);` to recursively calculate the total value.

**Conceptually:**
`total(n) = value[n-1] + total(n-1)`

**Base case:** `n == 0`

**Output:** `Total Treasure Value: 1100`

This makes recursion part of the actual game.

---

## PART 15 — Default Arguments

Use a default argument in a meaningful game function.

**For example:**

```cpp
void attack(Enemy &enemy, int damage = 10);

```

Then `player.attack(enemy);` uses default damage.

Or: `void heal(int amount = 20);`

---

## PART 16 — Inline Function

Use an appropriate small inline function.

**For example:**

```cpp
inline bool isAlive() {
    return health > 0;
}
// or
inline int getScore() {
    return score;
}

```

---

## PART 17 — Manipulators

Your game output should be properly formatted using `setw()`, `fixed`, and `setprecision()`.

**Example Output:**

```text
================================================
                  TREASURE
================================================

Name                 Value
------------------------------------------------
Diamond             1000.00
Ruby                 500.00
Gold                 250.00
------------------------------------------------

```

---

## PART 18 — Game Menu

Your game must have a menu.

**Example Output:**

```text
========================================
             DUNGEON QUEST
========================================

1. Explore Dungeon
2. Fight Enemy
3. Collect Treasure
4. View Inventory
5. Search Inventory
6. View Treasure Ranking
7. View Player Status
8. Exit Game

Enter choice:

```

Use a loop so the menu continues until the player exits or wins/loses.

---

## PART 19 — Game Completion

The game should have a proper ending.

**Winning condition:**
Player reaches Level 5

**OR** Defeats the Final Boss

**OR** Finds the Exit Key

**Then:**

```text
╔══════════════════════════════════════╗
║          🏆 DUNGEON CLEARED!         ║
╚══════════════════════════════════════╝

Player       : Rahul
Level        : 5
Health       : 75
Enemies      : 8
Treasures    : 6
Score        : 4250

Congratulations!
You escaped the dungeon.

```

---

## Part 20 — Complexity Analysis

At the end of the program, students must submit a small table. They must explain why they obtained each complexity.

| Operation | Algorithm | Complexity |
| --- | --- | --- |
| Display enemies | Traversal | O(n) |
| Search inventory | Linear Search | O(n) |
| Sort treasures | Selection/Bubble/Insertion | O(n²) |
| Calculate treasure value | Recursion | O(n) |

---

## The Important Part

**Concept map of the assignment:**

```text
                DUNGEON QUEST
                       │
              ┌────────┴────────┐
              │                 │
             OOP               DSA
              │                 │
        ┌─────┼─────┐      ┌────┼─────┐
        ↓     ↓     ↓      ↓    ↓     ↓
      Class  Object Static Array Search Sort
        │      │      │      │     │     │
        ↓      ↓      ↓      ↓     ↓     ↓
     Player  Enemy  Players Inventory  Treasure
        │                              Ranking
        │
   ┌────┼──────────┐
   ↓    ↓          ↓
 this Constructor Friend
        │
        ↓
    Reference
        │
        ↓
    Battle
        │
        ↓
    Recursion

```

```

```