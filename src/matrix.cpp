#include "matrix.hpp"

void Show(vector<vector<string>> Matriz, int line)
{
    cout << endl << "line: " << line << endl;

    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < line; j++)
        {
            cout << Matriz[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl << endl;
}

void Read(int *lootAll, int *line, int *columns, int *numberDG)
{                               
    string arqName("dataset/input.data");
    string sizeMatrix, aux;
    int cont = 0, i = 0, n = 2;
    ifstream arq(arqName);
    vector <string> matrixLine;
    vector<vector<string>> Matriz;

    if(!arq)                                            
    {
        cout << endl << "Não foi possível abrir o arquivo de entrada: " << endl << endl << "Saindo do programa!!!" << endl;
        exit(-1);
    }
    while (!arq.eof())                                  
    {
        while (getline(arq, sizeMatrix, '\n'))        
        {
            stringstream token(sizeMatrix);             
            if(cont == 0)                               
            {
                while (token >> aux)
                {
                    if (i == 0)
                    {
                        *line = atoi(aux.c_str());
                    }
                    else if (i == 1)
                    {
                        *columns = atoi(aux.c_str());
                    }
                    else if (i == 2)
                    {
                        *numberDG = atoi(aux.c_str());
                    }
                
                    i++;  
                }

                cont++;

                aux.clear();

                continue; 
            }
            else if(sizeMatrix.size() > 1)                                     
            {
                while(token >> aux)                     
                {
                    matrixLine.push_back((aux.c_str()));
                }

                Matriz.push_back(matrixLine);           

                matrixLine.clear();                     
                aux.clear();
            }
            else
            {
                Maps(Matriz, *line, *columns, n);
                n++;

                AllLoot(Matriz, *line, *columns, lootAll);

                Matriz.clear();                       
            }
        }
    }
}

void Maps(vector<vector<string>> Matriz, int line, int columns, int n)
{
    string NewArqName("dataset/input" + to_string(n) + ".data");

    ofstream arqAux(NewArqName); 

    if(!arqAux)
    {
        cout << endl << "Não foi possível abrir o arquivo!!" << endl;
        exit(-1);
    }
    else
    {
        for (int i = 0; i < line; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                arqAux << Matriz[i][j];
                arqAux << " ";
            }

            arqAux << "\n";
        }

        arqAux << "\n";
    }    
}

void AllLoot(vector<vector<string>> Matriz, int line, int columns, int *lootAll)
{
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < columns; j++)
        {   
            if (Matriz[i][j] != "#" && Matriz[i][j] != "*")
            {
                *lootAll = *lootAll + stoi(Matriz[i][j]);
            }
        }
    }
}

vector< vector <string>> GetMap(string mapName)
{   
    ifstream map(mapName);

    string sizeMatriz, aux;

    vector <string> MatrizLine;
    vector<vector<string>> Matriz;

    int i = 0;
    
    if (!map)
    {
        cout << endl << "Impossível carregar o mapa!!" << endl;
        exit(-1);
    }
    while (!map.eof())
    {
        while (getline(map, sizeMatriz, '\n'))        
        {
            stringstream token(sizeMatriz);      

            while(token >> aux)                     
            {
                MatrizLine.push_back((aux.c_str()));
            }

            Matriz.push_back(MatrizLine);           
            i++;

            MatrizLine.clear();                     
            aux.clear();
        }           
    }

    return Matriz;
}

void SaveMap(vector<vector<string>> Matriz, string mapName, int line, int columns)
{
    ofstream newMap(mapName);

    if(!newMap)
    {
        cout << endl << "Não foi possível abrir o arquivo!!" << endl;
        exit(-1);
    }
    else
    {
        for (int i = 0; i < line; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                newMap << Matriz[i][j];
                newMap << " ";
            }

            newMap << "\n";
        }

        newMap << "\n";
    } 

    newMap.close();
}

void Remove(int numberDG)
{
    int n = 2;

    while (numberDG != 0)
    {
        string NewArqName("dataset/input" + to_string(n) + ".data");
        
        if(remove(NewArqName.c_str()) != 0 )
        {
            perror("Erro ao remover o arquivo!");
        }

        numberDG--;
        n++;
    }
}

void ReadCompareMatrix(int line, int columns)
{
    string arqName("dataset/input.data");
    string sizeMatrix, aux;
    int cont = 0, i = 0, n = 2, contNotPosition = 0;
    ifstream arq(arqName);
    vector <string> matrixLine;
    vector<vector<string>> Matriz;

    if(!arq)                                            
    {
        cout << endl << "Não foi possível abrir o arquivo de entrada: " << endl << endl << "Saindo do programa!!!" << endl;
        exit(-1);
    }
    while (!arq.eof())                                  
    {
        while (getline(arq, sizeMatrix, '\n'))        
        {
            stringstream token(sizeMatrix);             
            if(cont == 0)                               
            {
                while (token >> aux)
                {
                    if (i == 0)
                    {
                        line = atoi(aux.c_str());
                    }
                    else if (i == 1)
                    {
                        columns = atoi(aux.c_str());
                    }
                
                    i++;  
                }

                cont++;

                aux.clear();

                continue; 
            }
            else if(sizeMatrix.size() > 1)                                     
            {
                while(token >> aux)                     
                {
                    matrixLine.push_back((aux.c_str()));
                }

                Matriz.push_back(matrixLine);           

                matrixLine.clear();                     
                aux.clear();
            }
            else
            {
                string NewArqName("dataset/input" + to_string(n) + ".data");

                CompareMatrix(Matriz, line, columns, NewArqName, &contNotPosition);

                Matriz.clear();            

                n++; 
            }
        }
    }

    cout << "Number of positions that were not visited: " << contNotPosition << endl << endl;
}

void CompareMatrix(vector<vector<string>> Matriz, int line, int columns, string NewArqName, int *contNotPosition)
{
    vector<vector<string>> MatrizAux = GetMap(NewArqName);

    for (int i = 0; i < line ;i++)
    {
        for (int j = 0; j < columns ;j++)
        {
            if (Matriz[i][j] != "#")
            {
                if (Matriz[i][j] == MatrizAux[i][j])
                {
                    *contNotPosition = *contNotPosition + 1;
                }   
            }
        }
    }

    MatrizAux.clear();
}

void SaveOutput(int line, int columns, int numberDG)
{
    string arqName("dataset/output.data");
    ofstream newMap(arqName);

    int n = 2;

    while (numberDG != 0)
    {
        string NewArqName("dataset/input" + to_string(n) + ".data");
        n++;
        vector<vector<string>> MatrizAux = GetMap(NewArqName);

        if(!newMap)
        {
            cout << endl << "Não foi possível abrir o arquivo!!" << endl;
            exit(-1);
        }
        else
        {
            for (int i = 0; i < line; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    newMap << MatrizAux[i][j];
                    newMap << " ";
                }

                newMap << "\n";
            }

            newMap << "\n";
        }

        numberDG--;
    }
}