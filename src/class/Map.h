#include <string>

#define SIZE_MAP 20
#define VOID 0
#define PLAYER 1
#define POKIMAC 2

using namespace std;

class Map {
	public:
		Map();

	private:
		int width = SIZE_MAP;
		int height = SIZE_MAP;
		int tab[SIZE_MAP*SIZE_MAP];
		int const tab_size = SIZE_MAP*SIZE_MAP;
};