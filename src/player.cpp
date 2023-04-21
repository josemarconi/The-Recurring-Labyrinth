#include "player.hpp"

void Explore(int line, int columns, int numberDG, int lootAll)
{
    int contLoot = 0, life = 10, inventory = 0, n = 2, aux = 0, run = 0, mapAux, totalInventory = 0, visited = 0, totalTraps = 0,controlMapsNumber = 0;
    bool winControl = false;

    string mapName("dataset/input" + to_string(n) + ".data");
    
    vector<vector<string>> Matriz = GetMap(mapName);

    int Line_Position = 0 + rand() % line;
    int Column_Position = 0 + rand() % columns;   

    int Line_First_Position = Line_Position;
    int Column_First_Position = Column_Position;

    cout << "Line_First_Position: " << Line_First_Position << endl;
    cout << "Column_First_Position: " << Column_First_Position << endl;
    
    mapAux = n;

    while (Matriz[Line_Position][Column_Position] == "#")
    {
        Line_Position = 0 + rand() % line;
        Column_Position = 0 + rand() % columns;

        Line_First_Position = Line_Position;
        Column_First_Position = Column_Position;
    }  
    if (Matriz[Line_Position][Column_Position] != "#" && Matriz[Line_Position][Column_Position] != "*")
    {
        aux = stoi(Matriz[Line_Position][Column_Position]) - 1;
        Matriz[Line_Position][Column_Position] = to_string(aux);

        inventory = inventory + 1;
        contLoot = contLoot + 1;
        totalInventory = totalInventory + 1;

        cout << endl << "Loot Found!!!!";
        cout << endl << "Inventory: " << inventory;
        cout << endl << "Life Points: " << life << endl;

        winControl = false;

    }
    else if ((Matriz[Line_Position][Column_Position] == "*") || (Matriz[Line_Position][Column_Position] == "!"))
    {
        cout << endl << "You fell into a trap!!!!" << endl;

        life = life - 1;
        cout << endl << "Life Points: " << life << endl;

        totalTraps = totalTraps + 1;

        Matriz[Line_Position][Column_Position] = "!";

        winControl = true;
    }

    cout << endl << "---------------------------------------------------------------------------------------------------------------------------------" << endl << endl;

    do
    {
        if(mapAux != n)
        {
            Line_Position = 0 + rand() % line;
            Column_Position = 0 + rand() % columns;   

            while (Matriz[Line_Position][Column_Position] == "#")
            {
                Line_Position = 0 + rand() % line;
                Column_Position = 0 + rand() % columns;
            }

            if (Matriz[Line_Position][Column_Position] != "#" && Matriz[Line_Position][Column_Position] != "*" && Matriz[Line_Position][Column_Position] != "!")
            {
                if (Matriz[Line_Position][Column_Position] == "0")
                {
                    cout << endl << "Don't have more loot her!!!!";
                    cout << endl << "Inventory: " << inventory;
                    cout << endl << "Life Points: " << life << endl;

                    Line_Position = Line_Position;
                    Column_Position = Column_Position + 1;


                    winControl = true;
                }
                else
                {
                    aux = stoi(Matriz[Line_Position][Column_Position]) - 1;
                    Matriz[Line_Position][Column_Position] = to_string(aux);

                    inventory = inventory + 1;
                    contLoot = contLoot + 1;
                    totalInventory = totalInventory + 1;

                    if (inventory == 4)
                    {
                        life = life + 1;
                        inventory = 0;
                    }

                    cout << endl << "Loot Found!!!!";
                    cout << endl << "Inventory: " << inventory;
                    cout << endl << "Life Points: " << life << endl;

                    winControl = false;
                    controlMapsNumber = 0;
                }
            }
            else if ((Matriz[Line_Position][Column_Position] == "*") || (Matriz[Line_Position][Column_Position] == "!"))
            {
                cout << endl << "You fell into a trap!!!!" << endl;

                life = life - 1;
                cout << endl << "Life Points: " << life << endl;

                totalTraps = totalTraps + 1;

                Matriz[Line_Position][Column_Position] = "!";

                winControl = true;
            }
            
            mapAux = n;

            controlMapsNumber++;

            continue;
        }

        cout << endl << "-----------------------------------------------------------------------------------------------------------" << endl << endl;

        cout << endl << "Coordenadas: [" << Line_Position << ", " << Column_Position << "]" << endl;

        run = 0 + rand() % 8;

        cout << endl << "Run: " << run << endl;

        //------------------------------------------------------------  -------------------------------------------------------------------------------------------------------------------------------//
        //RIGHT//
        if (run == 0)
        {  
            visited = visited + 1;

            if (Column_Position == columns - 1)
            {
                if (n == (numberDG + 1))
                {
                    SaveMap(Matriz, mapName, line, columns);
                    n = 2;

                    Matriz.clear();

                    mapName = "dataset/input" + to_string(n) + ".data";
                    Matriz = GetMap(mapName);

                    cout << endl << endl << "Portão encontrado mudando de fase!!!!" << endl << endl;


                    mapAux++;
                }
                else
                {
                    SaveMap(Matriz, mapName, line, columns);
                    n++;

                    Matriz.clear();

                    mapName = "dataset/input" + to_string(n) + ".data";
                    Matriz = GetMap(mapName);

                    cout << endl << endl << "Portão encontrado mudando de fase!!!!" << endl << endl;


                    mapAux++;
                }
            }
            else if (Matriz[Line_Position][Column_Position + 1] == "#")
            {
                cout << endl << "Wall ahead, can't go on" << endl;
            }
            else if (Matriz[Line_Position][Column_Position + 1] != "#" && Matriz[Line_Position][Column_Position + 1] != "*" && Matriz[Line_Position][Column_Position + 1] != "!")
            {
                if (Matriz[Line_Position][Column_Position + 1] == "0")
                {
                    cout << endl << "Don't have more loot her!!!!";
                    cout << endl << "Inventory: " << inventory;
                    cout << endl << "Life Points: " << life << endl;

                    Line_Position = Line_Position;
                    Column_Position = Column_Position + 1;


                    winControl = true;
                }
                else
                {
                    aux = stoi(Matriz[Line_Position][Column_Position + 1]) - 1;
                    Matriz[Line_Position][Column_Position + 1] = to_string(aux);

                    inventory = inventory + 1;
                    contLoot = contLoot + 1;
                    totalInventory = totalInventory + 1;

                    if (inventory == 4)
                    {
                        life = life + 1;
                        inventory = 0;
                    }
                    
                    cout << endl << "Loot Found!!!!";
                    cout << endl << "Inventory: " << inventory;
                    cout << endl << "Life Points: " << life << endl;

                    Line_Position = Line_Position;
                    Column_Position = Column_Position + 1;


                    winControl = false;
                    controlMapsNumber = 0;
                }
            }
            else if ((Matriz[Line_Position][Column_Position + 1] == "*") || (Matriz[Line_Position][Column_Position + 1] == "!"))
            {
                cout << endl << "You fell into a trap!!!!";

                life = life - 1;
                cout << endl << "Life Points: " << life << endl;

                Line_Position = Line_Position;
                Column_Position = Column_Position + 1;

                totalTraps = totalTraps + 1;

                Matriz[Line_Position][Column_Position] = "!";

                winControl = true;
            }
        }
        //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
        //LEFT//
        else if (run == 1)
        {
            visited = visited + 1;

            if (Column_Position == 0)
            {
                if (n == 2)
                {
                    SaveMap(Matriz, mapName, line, columns);
                    n = (numberDG + 1);
                    
                    Matriz.clear();

                    mapName = "dataset/input" + to_string(n) + ".data";
                    Matriz = GetMap(mapName);

                    cout << endl << endl << "Portão encontrado mudando de fase!!!!" << endl << endl;


                    mapAux++;
                }
                else
                {
                    SaveMap(Matriz, mapName, line, columns);
                    n--;

                    Matriz.clear();

                    mapName = "dataset/input" + to_string(n) + ".data";
                    Matriz = GetMap(mapName);

                    cout << endl << endl << "Portão encontrado mudando de fase!!!!" << endl << endl;


                    mapAux++;
                }
            }
            else if (Matriz[Line_Position][Column_Position - 1] == "#")
            {
                cout << endl << "Wall ahead, can't go on" << endl;
            }
            else if (Matriz[Line_Position][Column_Position - 1] != "#" && Matriz[Line_Position][Column_Position - 1] != "*" && Matriz[Line_Position][Column_Position - 1] != "!")
            {
                if (Matriz[Line_Position][Column_Position - 1] == "0")
                {
                    cout << endl << "Don't have more loot her!!!!";
                    cout << endl << "Inventory: " << inventory;
                    cout << endl << "Life Points: " << life << endl;

                    Line_Position = Line_Position;
                    Column_Position = Column_Position - 1;


                    winControl = true;
                }
                else
                {
                    aux = (stoi(Matriz[Line_Position][Column_Position - 1])) - 1;
                    Matriz[Line_Position][Column_Position - 1] = to_string(aux);

                    inventory = inventory + 1;
                    contLoot = contLoot + 1;
                    totalInventory = totalInventory + 1;

                    if (inventory == 4)
                    {
                        life = life + 1;
                        inventory = 0;
                    }
                    
                    cout << endl << "Loot Found!!!!";
                    cout << endl << "Inventory: " << inventory;
                    cout << endl << "Life Points: " << life << endl;

                    Line_Position = Line_Position;
                    Column_Position = Column_Position - 1;


                    winControl = false;
                    controlMapsNumber = 0;
                }
            }
            else if ((Matriz[Line_Position][Column_Position - 1] == "*") || (Matriz[Line_Position][Column_Position - 1] == "!"))
            {
                cout << endl << "You fell into a trap!!!!";

                life = life - 1;
                cout << endl << "Life Points: " << life << endl;

                Line_Position = Line_Position;
                Column_Position = Column_Position - 1;

                totalTraps = totalTraps + 1;
        
                Matriz[Line_Position][Column_Position] = "!";

                winControl = true;
            }
        }
        //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
        //UP//
        else if (run == 2)
        {
            visited = visited + 1;

            if (Line_Position == 0)
            {
                if (n == (numberDG + 1))
                {
                    SaveMap(Matriz, mapName, line, columns);
                    n = 2;

                    Matriz.clear();

                    mapName = "dataset/input" + to_string(n) + ".data";
                    Matriz = GetMap(mapName);

                    cout << endl << endl << "Portão encontrado mudando de fase!!!!" << endl << endl;


                    mapAux++;
                }
                else
                {
                    SaveMap(Matriz, mapName, line, columns);
                    n++;

                    Matriz.clear();

                    mapName = "dataset/input" + to_string(n) + ".data";
                    Matriz = GetMap(mapName);

                    cout << endl << endl << "Portão encontrado mudando de fase!!!!" << endl << endl;


                    mapAux++;
                }
            }
            else if (Matriz[Line_Position - 1][Column_Position] == "#")
            {
                cout << endl << "Wall ahead, can't go on" << endl;
            }
            else if (Matriz[Line_Position - 1][Column_Position] != "#" && Matriz[Line_Position - 1][Column_Position] != "*" && Matriz[Line_Position - 1][Column_Position] != "!")
            {
                if (Matriz[Line_Position - 1][Column_Position] == "0")
                {
                    cout << endl << "Don't have more loot her!!!!";
                    cout << endl << "Inventory: " << inventory;
                    cout << endl << "Life Points: " << life << endl;

                    Line_Position = Line_Position - 1;
                    Column_Position = Column_Position;


                    winControl = true;
                }
                else
                {
                    aux = (stoi(Matriz[Line_Position - 1][Column_Position])) - 1;
                    Matriz[Line_Position - 1][Column_Position] = to_string(aux);

                    inventory = inventory + 1;
                    contLoot = contLoot + 1;
                    totalInventory = totalInventory + 1;

                    if (inventory == 4)
                    {
                        life = life + 1;
                        inventory = 0;
                    }
                    
                    cout << endl << "Loot Found!!!!";
                    cout << endl << "Inventory: " << inventory;
                    cout << endl << "Life Points: " << life << endl;

                    Line_Position = Line_Position - 1;
                    Column_Position = Column_Position;


                    winControl = false;
                    controlMapsNumber = 0;
                }
            }
            else if ((Matriz[Line_Position - 1][Column_Position] == "*") || (Matriz[Line_Position - 1][Column_Position] == "!"))
            {
                cout << endl << "You fell into a trap!!!!";

                life = life - 1;
                cout << endl << "Life Points: " << life << endl;

                Line_Position = Line_Position - 1;
                Column_Position = Column_Position;

                totalTraps = totalTraps + 1;

                Matriz[Line_Position][Column_Position] = "!";

                winControl = true;
            }
        }
        //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
        //DOWN//
        else if (run == 3)
        {
            visited = visited + 1;

            if (Line_Position == line - 1)
            {
                if (n == 2)
                {
                    SaveMap(Matriz, mapName, line, columns);
                    n = (numberDG + 1);

                    Matriz.clear();

                    mapName = "dataset/input" + to_string(n) + ".data";
                    Matriz = GetMap(mapName);

                    cout << endl << endl << "Portão encontrado mudando de fase!!!!" << endl << endl;


                    mapAux++;
                }
                else
                {
                    SaveMap(Matriz, mapName, line, columns);
                    n--;

                    Matriz.clear();

                    mapName = "dataset/input" + to_string(n) + ".data";
                    Matriz = GetMap(mapName);

                    cout << endl << endl << "Portão encontrado mudando de fase!!!!" << endl << endl;


                    mapAux++;
                }
            }
            else if (Matriz[Line_Position + 1][Column_Position] == "#")
            {
                cout << endl << "Wall ahead, can't go on" << endl;
            }
            else if (Matriz[Line_Position + 1][Column_Position] != "#" && Matriz[Line_Position + 1][Column_Position] != "*" && Matriz[Line_Position + 1][Column_Position] != "!")
            {
                if (Matriz[Line_Position + 1][Column_Position] == "0")
                {
                    cout << endl << "Don't have more loot her!!!!";
                    cout << endl << "Inventory: " << inventory;
                    cout << endl << "Life Points: " << life << endl;

                    Line_Position = Line_Position + 1;
                    Column_Position = Column_Position;



                    winControl = true;
                }
                else
                {
                    aux = stoi(Matriz[Line_Position + 1][Column_Position]) - 1;
                    Matriz[Line_Position + 1][Column_Position] = to_string(aux);

                    inventory = inventory + 1;
                    contLoot = contLoot + 1;
                    totalInventory = totalInventory + 1;

                    if (inventory == 4)
                    {
                        life = life + 1;
                        inventory = 0;
                    }
                    
                    cout << endl << "Loot Found!!!!";
                    cout << endl << "Inventory: " << inventory;
                    cout << endl << "Life Points: " << life << endl;

                    Line_Position = Line_Position + 1;
                    Column_Position = Column_Position;


                    winControl = false;
                    controlMapsNumber = 0;
                }
            }
            else if ((Matriz[Line_Position + 1][Column_Position] == "*") || (Matriz[Line_Position + 1][Column_Position] == "!"))
            {
                cout << endl << "You fell into a trap!!!!";

                life = life - 1;
                cout << endl << "Life Points: " << life << endl;

                Line_Position = Line_Position + 1;
                Column_Position = Column_Position;

                totalTraps = totalTraps + 1;

                Matriz[Line_Position][Column_Position] = "!";

                winControl = true;
            }
        }
        //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
        //D.UP.RIGHT//
        else if (run == 4)
        {
            visited = visited + 1;

            if (Line_Position == 0 || Column_Position == columns - 1)
            {
                if (n == (numberDG + 1))
                {
                    SaveMap(Matriz, mapName, line, columns);
                    n = 2;

                    Matriz.clear();

                    mapName = "dataset/input" + to_string(n) + ".data";
                    Matriz = GetMap(mapName);

                    cout << endl << endl << "Portão encontrado mudando de fase!!!!" << endl << endl;


                    mapAux++;
                }
                else
                {
                    SaveMap(Matriz, mapName, line, columns);
                    n++;

                    Matriz.clear();

                    mapName = "dataset/input" + to_string(n) + ".data";
                    Matriz = GetMap(mapName);

                    cout << endl << endl << "Portão encontrado mudando de fase!!!!" << endl << endl;


                    mapAux++;
                }
            }
            else if (Matriz[Line_Position - 1][Column_Position + 1] == "#")
            {
                cout << endl << "Wall ahead, can't go on" << endl;
            }
            else if (Matriz[Line_Position - 1][Column_Position + 1] != "#" && Matriz[Line_Position - 1][Column_Position + 1] != "*" && Matriz[Line_Position - 1][Column_Position + 1] != "!")
            {
                if (Matriz[Line_Position - 1][Column_Position + 1] == "0")
                {
                    cout << endl << "Don't have more loot her!!!!";
                    cout << endl << "Inventory: " << inventory;
                    cout << endl << "Life Points: " << life << endl;

                    Line_Position = Line_Position - 1;
                    Column_Position = Column_Position + 1;


                    winControl = true;
                }
                else
                {
                    aux = stoi(Matriz[Line_Position - 1][Column_Position + 1]) - 1;
                    Matriz[Line_Position - 1][Column_Position + 1] = to_string(aux);

                    inventory = inventory + 1;
                    contLoot = contLoot + 1;
                    totalInventory = totalInventory + 1;

                    if (inventory == 4)
                    {
                        life = life + 1;
                        inventory = 0;
                    }
                    
                    cout << endl << "Loot Found!!!!";
                    cout << endl << "Inventory: " << inventory;
                    cout << endl << "Life Points: " << life << endl;

                    Line_Position = Line_Position - 1;
                    Column_Position = Column_Position + 1;


                    winControl = false;
                    controlMapsNumber = 0;
                }
            }
            else if ((Matriz[Line_Position - 1][Column_Position + 1] == "*") || (Matriz[Line_Position - 1][Column_Position + 1] == "!"))
            {
                cout << endl << "You fell into a trap!!!!";

                life = life - 1;
                cout << endl << "Life Points: " << life << endl;

                Line_Position = Line_Position - 1;
                Column_Position = Column_Position + 1;

                totalTraps = totalTraps + 1;

                Matriz[Line_Position][Column_Position] = "!";

                winControl = true;
            }
        }
        //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
        //D.UP.LEFT//
        else if (run == 5)
        {
            visited = visited + 1;

            if (Line_Position == 0 && Column_Position == 0)
            {
                if (n == 2)
                {
                    SaveMap(Matriz, mapName, line, columns);
                    n = (numberDG + 1);

                    Matriz.clear();

                    mapName = "dataset/input" + to_string(n) + ".data";
                    Matriz = GetMap(mapName);

                    cout << endl << endl << "Portão encontrado mudando de fase!!!!" << endl << endl;


                    mapAux++;
                }
                else
                {
                    SaveMap(Matriz, mapName, line, columns);
                    n--;

                    Matriz.clear();

                    mapName = "dataset/input" + to_string(n) + ".data";
                    Matriz = GetMap(mapName);

                    cout << endl << endl << "Portão encontrado mudando de fase!!!!" << endl << endl;


                    mapAux++;
                }
            }
            else if (Line_Position >= 0 && Column_Position == 0)
            {
                if (n == 2)
                {
                    SaveMap(Matriz, mapName, line, columns);
                    n = (numberDG + 1);

                    Matriz.clear();

                    mapName = "dataset/input" + to_string(n) + ".data";
                    Matriz = GetMap(mapName);

                    cout << endl << endl << "Portão encontrado mudando de fase!!!!" << endl << endl;


                    mapAux++;
                }
                else
                {
                    SaveMap(Matriz, mapName, line, columns);
                    n--;

                    Matriz.clear();

                    mapName = "dataset/input" + to_string(n) + ".data";
                    Matriz = GetMap(mapName);

                    cout << endl << endl << "Portão encontrado mudando de fase!!!!" << endl << endl;


                    mapAux++;
                }
            }
            else if (Line_Position == 0 && Column_Position >= 0)
            {
                if (n == (numberDG + 1))
                {
                    SaveMap(Matriz, mapName, line, columns);
                    n = 2;
                    
                    Matriz.clear();

                    mapName = "dataset/input" + to_string(n) + ".data";
                    Matriz = GetMap(mapName);

                    cout << endl << endl << "Portão encontrado mudando de fase!!!!" << endl << endl;


                    mapAux++;
                }
                else
                {
                    SaveMap(Matriz, mapName, line, columns);
                    n++;

                    Matriz.clear();

                    mapName = "dataset/input" + to_string(n) + ".data";
                    Matriz = GetMap(mapName);

                    cout << endl << endl << "Portão encontrado mudando de fase!!!!" << endl << endl;


                    mapAux++;
                }
            }
            else if (Matriz[Line_Position - 1][Column_Position - 1] == "#")
            {
                cout << endl << "Wall ahead, can't go on" << endl;
            }
            else if (Matriz[Line_Position - 1][Column_Position - 1] != "#" && Matriz[Line_Position - 1][Column_Position - 1] != "*" && Matriz[Line_Position - 1][Column_Position - 1] != "!")
            {
                if (Matriz[Line_Position - 1][Column_Position - 1] == "0")
                {
                    cout << endl << "Don't have more loot her!!!!";
                    cout << endl << "Inventory: " << inventory;
                    cout << endl << "Life Points: " << life << endl;

                    Line_Position = Line_Position - 1;
                    Column_Position = Column_Position - 1;


                    winControl = true;
                }
                else
                {
                    aux = stoi(Matriz[Line_Position - 1][Column_Position - 1]) - 1;
                    Matriz[Line_Position - 1][Column_Position - 1] = to_string(aux);

                    inventory = inventory + 1;
                    contLoot = contLoot + 1;
                    totalInventory = totalInventory + 1;

                    if (inventory == 4)
                    {
                        life = life + 1;
                        inventory = 0;
                    }
                    
                    cout << endl << "Loot Found!!!!";
                    cout << endl << "Inventory: " << inventory;
                    cout << endl << "Life Points: " << life << endl;

                    Line_Position = Line_Position - 1;
                    Column_Position = Column_Position - 1;


                    winControl = false;
                    controlMapsNumber = 0;
                }
            }
            else if ((Matriz[Line_Position - 1][Column_Position - 1] == "*") || (Matriz[Line_Position - 1][Column_Position - 1] == "!"))
            {
                cout << endl << "You fell into a trap!!!!";

                life = life - 1;
                cout << endl << "Life Points: " << life << endl;

                Line_Position = Line_Position - 1;
                Column_Position = Column_Position - 1;

                totalTraps = totalTraps + 1;

                Matriz[Line_Position][Column_Position] = "!";

                winControl = true;
            }
        }
        //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
        //D.DOWN.RIGHT//
        else if (run == 6)
        {
            visited = visited + 1;

            if (Line_Position == line - 1 && Column_Position == columns - 1)
            {
                if (n == (numberDG + 1))
                {
                    SaveMap(Matriz, mapName, line, columns);
                    n = 2;

                    Matriz.clear();

                    mapName = "dataset/input" + to_string(n) + ".data";
                    Matriz = GetMap(mapName);

                    cout << endl << endl << "Portão encontrado mudando de fase!!!!" << endl << endl;


                    mapAux++;
                }
                else
                {
                    SaveMap(Matriz, mapName, line, columns);
                    n++;

                    Matriz.clear();

                    mapName = "dataset/input" + to_string(n) + ".data";
                    Matriz = GetMap(mapName);

                    cout << endl << endl << "Portão encontrado mudando de fase!!!!" << endl << endl;


                    mapAux++;
                }
            }
            else if (Line_Position >= 0 && Column_Position == columns - 1)
            {
                if (n == (numberDG + 1))
                {
                    SaveMap(Matriz, mapName, line, columns);
                    n = 2;

                    Matriz.clear();

                    mapName = "dataset/input" + to_string(n) + ".data";
                    Matriz = GetMap(mapName);

                    cout << endl << endl << "Portão encontrado mudando de fase!!!!" << endl << endl;


                    mapAux++;
                }
                else
                {
                    SaveMap(Matriz, mapName, line, columns);

                    n++;
                    
                    Matriz.clear();

                    mapName = "dataset/input" + to_string(n) + ".data";
                    Matriz = GetMap(mapName);

                    cout << endl << endl << "Portão encontrado mudando de fase!!!!" << endl << endl;


                    mapAux++;
                }
            }
            else if (Line_Position == line - 1 && Column_Position <= columns - 1)
            {
                if (n == 2)
                {
                    SaveMap(Matriz, mapName, line, columns);
                    n = (numberDG + 1);
                    
                    Matriz.clear();

                    mapName = "dataset/input" + to_string(n) + ".data";
                    Matriz = GetMap(mapName);

                    cout << endl << endl << "Portão encontrado mudando de fase!!!!" << endl << endl;


                    mapAux++;
                }
                else
                {
                    SaveMap(Matriz, mapName, line, columns);
                    n--;

                    Matriz.clear();

                    mapName = "dataset/input" + to_string(n) + ".data";
                    Matriz = GetMap(mapName);

                    cout << endl << endl << "Portão encontrado mudando de fase 1 !!!!" << endl << endl;


                    mapAux++;
                }
            }
            else if (Matriz[Line_Position + 1][Column_Position + 1] == "#")
            {
                cout << endl << "Wall ahead, can't go on" << endl;
            }
            else if (Matriz[Line_Position + 1][Column_Position + 1] != "#" && Matriz[Line_Position + 1][Column_Position + 1] != "*" && Matriz[Line_Position + 1][Column_Position + 1] != "!")
            {
                if (Matriz[Line_Position + 1][Column_Position + 1] == "0")
                {
                    cout << endl << "Don't have more loot her!!!!";
                    cout << endl << "Inventory: " << inventory;
                    cout << endl << "Life Points: " << life << endl;

                    Line_Position = Line_Position + 1;
                    Column_Position = Column_Position + 1;


                    winControl = true;
                }
                else
                {
                    aux = stoi(Matriz[Line_Position + 1][Column_Position + 1]) - 1;
                    Matriz[Line_Position + 1][Column_Position + 1] = to_string(aux);

                    inventory = inventory + 1;
                    contLoot = contLoot + 1;
                    totalInventory = totalInventory + 1;

                    if (inventory == 4)
                    {
                        life = life + 1;
                        inventory = 0;
                    }
                    
                    cout << endl << "Loot Found!!!!";
                    cout << endl << "Inventory: " << inventory;
                    cout << endl << "Life Points: " << life << endl;

                    Line_Position = Line_Position + 1;
                    Column_Position = Column_Position + 1;


                    winControl = false;
                    controlMapsNumber = 0;
                }
            }
            else if ((Matriz[Line_Position + 1][Column_Position + 1] == "*") || (Matriz[Line_Position + 1][Column_Position + 1] == "!"))
            {
                cout << endl << "You fell into a trap!!!!";

                life = life - 1;
                cout << endl << "Life Points: " << life << endl;

                Line_Position = Line_Position + 1;
                Column_Position = Column_Position + 1;

                totalTraps = totalTraps + 1;

                Matriz[Line_Position][Column_Position] = "!";

                winControl = true;
            }
        }
        //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
        //D.DOWN.LEFT//
        else if (run == 7)
        {
            visited = visited + 1;

            if (Line_Position == line - 1 || Column_Position == 0)
            {
                if (n == 2)
                {
                    SaveMap(Matriz, mapName, line, columns);
                    n = (numberDG + 1);

                    Matriz.clear();

                    mapName = "dataset/input" + to_string(n) + ".data";
                    Matriz = GetMap(mapName);

                    cout << endl << endl << "Portão encontrado mudando de fase!!!!" << endl << endl;


                    mapAux++;
                }
                else
                {
                    SaveMap(Matriz, mapName, line, columns);
                    n--;

                    Matriz.clear();

                    mapName = "dataset/input" + to_string(n) + ".data";
                    Matriz = GetMap(mapName);

                    cout << endl << endl << "Portão encontrado mudando de fase!!!!" << endl << endl;


                    mapAux++;
                }
            }
            else if (Matriz[Line_Position + 1][Column_Position - 1] == "#")
            {
                cout << endl << "Wall ahead, can't go on" << endl;
            }
            else if (Matriz[Line_Position + 1][Column_Position - 1] != "#" && Matriz[Line_Position + 1][Column_Position - 1] != "*" && Matriz[Line_Position + 1][Column_Position - 1] != "!")
            {
                if (Matriz[Line_Position + 1][Column_Position - 1] == "0")
                {
                    cout << endl << "Don't have more loot her!!!!";
                    cout << endl << "Inventory: " << inventory;
                    cout << endl << "Life Points: " << life << endl;

                    Line_Position = Line_Position + 1;
                    Column_Position = Column_Position - 1;


                    winControl = true;
                }
                else
                {
                    aux = stoi(Matriz[Line_Position + 1][Column_Position - 1]) - 1;
                    Matriz[Line_Position + 1][Column_Position - 1] = to_string(aux);

                    inventory = inventory + 1;
                    contLoot = contLoot + 1;
                    totalInventory = totalInventory + 1;

                    if (inventory == 4)
                    {
                        life = life + 1;
                        inventory = 0;
                    }
                    
                    cout << endl << "Loot Found!!!!";
                    cout << endl << "Inventory: " << inventory;
                    cout << endl << "Life Points: " << life << endl;

                    Line_Position = Line_Position + 1;
                    Column_Position = Column_Position - 1;


                    winControl = false;
                    controlMapsNumber = 0;
                }
            }
            else if ((Matriz[Line_Position + 1][Column_Position - 1] == "*") || (Matriz[Line_Position + 1][Column_Position - 1] == "!"))
            {
                cout << endl << "You fell into a trap!!!!";

                life = life - 1;
                cout << endl << "Life Points: " << life << endl;

                Line_Position = Line_Position + 1;
                Column_Position = Column_Position - 1;

                totalTraps = totalTraps + 1;

                Matriz[Line_Position][Column_Position] = "!";

                winControl = true;
            }
        }
        //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
        else
        {
            cout << endl << endl << "Este passo não é possível!!!" << endl << endl;
        }

        if ((winControl == true) && (n == 2) && (controlMapsNumber > (n + numberDG)) && (Column_Position == Column_First_Position) && (Line_Position == Line_First_Position))
        {
            life = 0;
        }
        
        Show(Matriz, line);

    } while (life != 0);

    if ((winControl == true) && (n == 2) && (controlMapsNumber > (n + numberDG)) && (Column_Position == Column_First_Position) && (Line_Position == Line_First_Position))
    {
        cout << endl << endl << "Congratulation. You win!!!!" << endl << endl;
        cout << "All loot in every dungeons: " << lootAll << endl;
        cout << "All collected loot: " << totalInventory << endl;
        cout << "Number of houses visited: " << visited - 7 << endl;
        cout << "Dangerous encontered: " << totalTraps << endl;
    }
    else if (life == 0)
    {
        cout << endl << endl << "YOU DIED" << endl << endl;
        cout << "All loot in every dungeons: " << lootAll << endl;
        cout << "All collected loot: " << totalInventory << endl;
        cout << "Number of houses visited: " << visited << endl;
        cout << "Dangerous encontered: " << totalTraps << endl;
    }
}