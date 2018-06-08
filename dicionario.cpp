#include "dicionario.h"

    dicionario::dicionario()
    {
        cont = 0; //Number of words

        //Create an object ifstream "file"
        ifstream file;

        //It is opened in the "in" way, so it only permits the reading of the file
        file.open("dict.txt", ios::in);

            //"is_open" returns TRUE if the "file" is opened
            //"good" returns TRUE if it doens't have any problem
            if(file.is_open() && file.good())
            {
                //"file" sends it's contents to "dict" 
                while(!file.fail()) //"fail" returns 1 when the file reaches it's end
                {
                    file >> dict[i].palavra;
                    cont++;
                }
            }
            else
            {
                std::cout << "ERROR" << std::endl;
            }

    }

    //Functions:

    void dicionario::consulta(arq dict, Palavra p) //Muito provavelmente haverá mudanças
    {
        for(int i = 0, i < cont; i++)
        {
            if(!strcmp(p, dict[i].palavra))
            {
                //Found it
                return 1; 
            }
        }

        //Nope
        return 0;
    }

    void dicionario::inclusao(arq dict, Palavra p)
    {
        for(int i = 0, i < cont; i++)
        {
            if(!strcmp(p, dict[i].palavra))
            {
                //Found it, so doesn't need to include
                return 0; 
            }
        }

        //Including it
        cont++;
        strcpy(dict[i + 1].palavra, p);
        return 1;
    }

    void dicionario::atualizarArquivo()
    {
        ofstream file;

        //Opens the file in an "out" way, to write there
        file.open("dict.txt", ios::out);
        for(int i = 0; i < cont; i++)
        {
            file << dict[i].palavra << std::endl;
        }
    }

    void dicionario::printar()
    {
        for(int i = 0; i < cont; i++)
        {
            
            std::cout << dict[i] << std::endl;

        }
    }
