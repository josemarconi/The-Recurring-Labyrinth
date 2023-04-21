#include "player.hpp"

int main()
{
    cout << endl << '\t' << "----- Starting Dungeon -----" << endl << endl;

    int lootAll = 0, line, columns, numberDG;

    Read(&lootAll, &line, &columns, &numberDG);

    Explore(line, columns, numberDG, lootAll);

    ReadCompareMatrix(line, columns);

    SaveOutput(line, columns, numberDG);

    Remove(numberDG);

    return 0;
}

