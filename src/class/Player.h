#include <string>

using namespace std;

class Player {

  public:
    Player();
    Player::Player(int nbHealth);

    string getName();
    int getHealth();

    void setName(string username);
    void setHealth(int nbHealth);
    void setDamage(int nbDamage);
    
  private:
    string name;
    int health;
};