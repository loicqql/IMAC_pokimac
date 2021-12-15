#include <string>

using namespace std;

class Pokimac {

  public:
    Pokimac();
    Pokimac::Pokimac(int nbHealth);

    string getName();
    int getHealth();
    int getDamage();

    void setName(string username);
    void setHealth(int nbHealth);
    void setDamage(int nbDamage);
    

  private:
    string name;
    int health;
    int damage;
};