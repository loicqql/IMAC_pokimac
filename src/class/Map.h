#include <string>
#define SIZE 4
using namespace std;

class Map {
    private :
        int map[SIZE];
        int poki[SIZE];
        int player[SIZE];

    public :
        Map(){
            map[SIZE]=(1,0,0,2);
            poki[SIZE]=(NULL,NULL,NULL, NULL);
            player[SIZE]=(NULL,NULL,NULL, NULL);
        }
    };