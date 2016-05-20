#include "GameCore.hpp"

SudokuGame::SudokuGame()
{
    ifstream f("input.txt");
    f>>level_nr;
    int x;
    for(int i=0; i< level_nr*81; i++)
    {
        f>>x;
        table.push_back(x);
    }

    f.close();
    level=0;
}


void SudokuGame::debug()
{
    cout<<"level: "<<level<<endl;
    for(int k=0; k<level_nr; k++)
    {
        cout<<endl;
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                cout<<table[k*81 + i*9 + j]<<" ";
            }
            cout<<endl;
        }
    }
}

vector<int_bool> SudokuGame::SendCurrentState()
{
    if(level==level_nr)
    {
        level = 0;
    }
    vector<bool> tmp_validity(81,true);

    for(int i=0 ; i < 9; i++)
    {
        for(int j=0; j<8; j++)
        {
            for(int k=j+1; k<9;k++)
            {
                //column check
                if(table[level*81+i*9+j] == table[level*81+i*9+k] && table[level*81+i*9+j]!=0 && table[level*81+i*9+k]!=0)
                {
                    tmp_validity[i*9+j] = false;
                    tmp_validity[i*9+k] = false;
                }

                //row check
                if(table[level*81+j*9+i] == table[level*81+k*9+i] && table[level*81+j*9+i]!=0 && table[level*81+k*9+i]!=0)
                {
                    tmp_validity[j*9+i] = false;
                    tmp_validity[k*9+i] = false;
                }
            }
        }
    }

    //group check
    for(int l=0; l<81; l+=27)// sorban lepteti a harom csoportot
    {
        for(int k=0; k<9; k+=3)//oszlopban lepteti a harom csoportot
        {
            for(int i=0; i<27; i++)//egy csoporton beluli bejaras
            {
                for(int j=0; j<27; j++)
                {
                    if(table[level*81+l+k+i] == table[level*81+l+k+j] && table[level*81+l+k+j]!=0 && table[level*81+l+k+i]!=0 && l+k+i!=l+k+j)
                    {
                        tmp_validity[l+k+i] = false;
                        tmp_validity[l+k+j]=false;
                    }
                    if(j!=0 && (j+1)%3 == 0){j+=6;}
                }
                if(i!=0 && (i+1)%3 == 0){i+=6;}
            }
        }
    }

    vector<int_bool> tmp;
    for(int i=0;i<81;i++)
    {
        tmp.push_back(int_bool(table[level*81+i],!tmp_validity[i]));
    }
    return tmp;


}

void SudokuGame::getNewState(vector<int> tmp)
{
    for(size_t i=0; i< tmp.size(); i++)
    {
        if(tmp[i]>=0 && tmp[i]<=9)
        {
            table[level*81+i]=tmp[i];
        }
    }
}

bool SudokuGame::win()
{
    for(int i=0 ; i < 9; i++)
    {
        for(int j=0; j<8; j++)
        {
            for(int k=j+1; k<9;k++)
            {
                //column check
                if(table[level*81+i*9+j] == table[level*81+i*9+k] && table[level*81+i*9+j]!=0 && table[level*81+i*9+k]!=0)
                {
                    return false;
                }

                //row check
                if(table[level*81+j*9+i] == table[level*81+k*9+i] && table[level*81+j*9+i]!=0 && table[level*81+k*9+i]!=0)
                {
                    return false;
                }
            }
        }
    }

    //group check
    for(int l=0; l<81; l+=27)// sorban lepteti a harom csoportot
    {
        for(int k=0; k<9; k+=3)//oszlopban lepteti a harom csoportot
        {
            for(int i=0; i<27; i++)//egy csoporton beluli bejaras
            {
                for(int j=0; j<27; j++)
                {
                    if(table[level*81+l+k+i] == table[level*81+l+k+j] && table[level*81+l+k+j]!=0 && table[level*81+l+k+i]!=0 && l+k+i!=l+k+j)
                    {
                        return false;
                    }
                    if(j!=0 && (j+1)%3 == 0){j+=6;}
                }
                if(i!=0 && (i+1)%3 == 0){i+=6;}
            }
        }
    }

    for(int i=0; i<81; i++)
    {
        if(table[level*81 + i] == 0)
            return false;
    }

    return true;

}

void SudokuGame::ChooseLevel(int _level)
{
    if(_level>=0 && _level<=level_nr)
    {
        level = _level;
    }
    else
    {
        level = 0;
    }
}

int SudokuGame::getLevel()
{
    return level;
}

void SudokuGame::reset()
{
    ifstream f("input.txt");
    f>>level_nr;
    for(int i=0; i< level_nr*81; i++)
    {
        f>>table[i];

    }

    f.close();
}



