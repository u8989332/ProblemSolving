#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> blocks[25];
int curBlockPosition[25];

bool is_same_block(int a, int b)
{
    return curBlockPosition[a] == curBlockPosition[b];
}

void recover_block(int index)
{
    int curPosition = curBlockPosition[index];
    bool finds = false;
    int findIndex = -1;
    int curPositionSize = blocks[curPosition].size();
    for(int i = 0 ; i < curPositionSize; ++i)
    {
        int curNo = blocks[curPosition][i];
        if(finds)
        {
            blocks[curNo].push_back(curNo);
            curBlockPosition[curNo] = curNo;
        }
        else if(curNo == index)
        {
            finds = true;
            findIndex = i;
        }
    }


    blocks[curPosition].erase(blocks[curPosition].begin() + findIndex + 1, blocks[curPosition].end());
}


void move_full_blocks(int from, int to)
{
    int curPosition = curBlockPosition[from];
    int curToPosition = curBlockPosition[to];
    bool finds = false;
    int findIndex = -1;
    int curPositionSize = blocks[curPosition].size();
    for(int i = 0 ; i < curPositionSize; ++i)
    {
        int curNo = blocks[curPosition][i];
        if(finds)
        {
            blocks[curToPosition].push_back(curNo);
            curBlockPosition[curNo] = curToPosition;
        }
        else if(curNo == from)
        {
            finds = true;
            findIndex = i;
            blocks[curToPosition].push_back(curNo);
            curBlockPosition[curNo] = curToPosition;
        }
    }

    blocks[curPosition].erase(blocks[curPosition].begin() + findIndex, blocks[curPosition].end());
}

// debug
void printf_blocks(int n)
{
    for(int i = 0 ; i < n; ++i)
    {
        cout << i << ":";
        for(int j = 0 ; j < blocks[i].size(); ++j)
        {
            cout << " " << blocks[i][j];
        }
        cout << endl;
        cout << "cur position = " << curBlockPosition[i] << endl;
    }

    cout << endl;
}

int main()
{

    int n;
    string v1, v2;
    int a,b;
    while(cin >> n)
    {
        for(int i = 0 ; i < n; ++i)
        {
            blocks[i].push_back(i);
            curBlockPosition[i] = i;
        }
        while(cin >> v1)
        {
            if(v1 == "quit")
            {
                for(int i = 0 ; i < n; ++i)
                {
                    cout << i << ":";
                    for(int j = 0 ; j < blocks[i].size(); ++j)
                    {
                        cout << " " << blocks[i][j];
                    }
                    cout << endl;
                }

                for(int i = 0 ; i < n ; ++i)
                {
                    blocks[i].clear();
                }

                break;
            }
            cin >> a >> v2 >> b;
            if(is_same_block(a,b))
            {
                continue;
            }
            if(v1 == "move")
            {
                recover_block(a);
                if(v2 == "onto")
                {
                    recover_block(b);
                    move_full_blocks(a, b);
                }
                else if(v2 == "over")
                {
                    move_full_blocks(a, b);
                }
            }
            else if(v1 == "pile" && v2 == "onto")
            {
                recover_block(b);
                move_full_blocks(a, b);
            }
            else if(v1 == "pile" && v2 == "over")
            {
                move_full_blocks(a, b);
            }
            // debug
            //printf_blocks(n);
        }
    }

    return 0;
}
