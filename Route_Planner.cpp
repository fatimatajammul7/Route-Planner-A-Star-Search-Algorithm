#include <iostream>
#include<queue>
#include <utility>
#include<stack>
#include<iostream>
#include <cstdlib>
#include <ctime>
#include<cmath>

using namespace std;

void initializeGrid(int grid[40][40])
{
	for(int i = 0; i<40; i++)
    {
    	for(int j = 0; j<40; j++)
    	{
    		grid[i][j]=1;
		}
	}
	
	srand(std::time(0));

    for (int i = 0; i < 500; i++) {
        int x = rand() % 40;
        int y = rand() % 40;
        grid[x][y] = 0;
    }
}

void displayGrid(int grid[40][40], int x1, int y1, int x2, int y2)
{
    for(int i = 0; i<40; i++)
    {
    	for(int j = 0; j<40; j++)
    	{
    		cout<<grid[i][j]<<"  ";
		}
		cout<<endl;
	}
}

class element
{
public:
    int X, Y, f, g, h;
    element()
    {
        f = g = h = X = Y = -1;
    }
    void defineSource(int x, int y)
    {
        X = x, Y = y, f = 0, g = 0, h = 0;
    }
};

bool check(int x, int y, int G[40][40])
{
    if ((x >= 0 && x <= 40 && y >= 0 && y <= 40 && G[y][x] == 1)==true)
    {
    	return true;
	}
	else
		return false;
}

int calculateHeuristic(int x, int y, int x2, int y2)
{
	int value1 =pow((x - x2),2);
	int value2 = pow((y - y2),2);
	int value3 =  value1 + value2;
	int value4 = sqrt (value3);
    return value3;
}

void loopNeighbours(int& xNeighbour, int& yNeighbour, int x, int y, int i){
	if (i == 0)
	{
	    xNeighbour = x - 1;
	    yNeighbour = y;
	}
	else if (i == 1)
	{
	    xNeighbour = x + 1;
	    yNeighbour = y;
	}
	else if (i == 2)
	{
	    xNeighbour = x;
	    yNeighbour = y - 1;
	}
	else if (i == 3)
	{
	    xNeighbour = x;
	    yNeighbour = y + 1;
	}
	else if (i == 4)
	{
	    xNeighbour = x - 1;
	    yNeighbour = y + 1;
	}
	else if (i == 5)
	{
	    xNeighbour = x - 1;
	    yNeighbour = y - 1;
	}
	else if (i == 6)
	{
	    xNeighbour = x + 1;
	    yNeighbour = y + 1;
	}
	else if (i == 7)
	{
	    xNeighbour = x + 1;
	    yNeighbour = y - 1;
	}
}

void findpath(element grid2[40][40], int grid[40][40], int x1, int y1, int x2, int y2)
{
    int x = x2, y = y2;
    stack<pair<int, int>> path;
    while ((x == x1 && y == y1)==false)
    {
        path.push(make_pair(x, y));
        int tempX = grid2[y][x].X, tempY = grid2[y][x].Y;
        x = tempX, y = tempY;
    }
    path.push(make_pair(x, y));
    while (path.empty()==false)
    {
        pair<int, int> p = path.top();
        path.pop();
        grid[p.second][p.first] = 4;
    }
}

void applyAStar(int grid[40][40], int x1, int y1, int x2, int y2)
{
    typedef pair<int, pair<int, int>> currelement;
    priority_queue<currelement, vector<currelement>, greater<currelement> > currentElements;

    element grid2[40][40];
    
    int visited[40][40] = { '0' }; 

    currentElements.push(make_pair(grid2[y1][x1].f, make_pair(x1, y1)));
    grid2[y1][x1].defineSource(x1, y1);

    int destinationCheck = 0;

    int x, y, xNeighbour, yNeighbour;

    while (currentElements.empty()==false && destinationCheck == 0)
    {
        currelement topValue = currentElements.top();
        currentElements.pop();
        x = topValue.second.first;
        y = topValue.second.second;
        visited[y][x] = 1;

        int cG, cH, cF;

        for (int i = 0; i < 8; i++)
        {
        	loopNeighbours(xNeighbour,yNeighbour, x, y, i);
     
            if ((visited[yNeighbour][xNeighbour] == false) && (check(xNeighbour, yNeighbour, grid) == true))
            {
                if (xNeighbour == x2 && yNeighbour == y2)
                {
                    cout << "A destinaition solution is acheived" << endl;
                    grid2[yNeighbour][xNeighbour].X = x;
                    grid2[yNeighbour][xNeighbour].Y = y;
                    destinationCheck = 1;
                    break;
                }
                cG = grid2[y][x].g + 1;
                cH = calculateHeuristic(xNeighbour, yNeighbour, x2, y2);
                cF = cG + cH;

                if (grid2[yNeighbour][xNeighbour].f == -1 || grid2[yNeighbour][xNeighbour].f > cF)
                {
                    currentElements.push(make_pair(cF, (make_pair(xNeighbour, yNeighbour))));
               
                    grid2[yNeighbour][xNeighbour].f = cF;
                    grid2[yNeighbour][xNeighbour].g = cF;
                    grid2[yNeighbour][xNeighbour].h = cH;
                    grid2[yNeighbour][xNeighbour].X = x;
                    grid2[yNeighbour][xNeighbour].Y = y;
                }                                                                                                                
            }
        }
    }
    if (destinationCheck == 0)
        cout << "Destination can not be reached" << endl;
    else
        findpath(grid2, grid, x1, y1, x2, y2);
    return;
}

int main(){

    int x1 = 1;
	int y1 = 7;
	int x2 = 35;
	int y2 = 8;           
	int grid[40][40];
	initializeGrid(grid);
	if (check(x1, y1, grid)!=true)
    {
        cout << "Source is not valid" << endl;
    }
    else if (check(x2, y2, grid)!=true)
    {
        cout << "Destination is not valid" << endl;
    }
    else
    {
    	 cout<<"BEFORE:"<<endl<<endl<<endl<<endl;
	    displayGrid(grid, x1, y1, x2, y2);
	    cout<<endl<<endl<<endl<<endl;
	    applyAStar(grid, x1, y1, x2, y2);
	    cout<<"AFTER:"<<endl<<endl<<endl<<endl;
	    displayGrid(grid, x1, y1, x2, y2);
	    cout<<endl<<endl<<endl<<endl;
	}
   
	return 0;
	
}