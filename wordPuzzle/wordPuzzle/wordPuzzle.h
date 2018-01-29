
#include <iostream>
#include<stdlib.h>
#include<time.h>
//#include<windows.h>
using namespace std;
#define UNASSIGNED 0
#define N 4

//the following are UBUNTU/LINUX ONLY terminal color codes.
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */


class puzzle{
    
private:
    int content[N+1];
    int map[N][N];
    int gamePlay[N][N];
    int hints[N];
    //function to print NxN grid
    void printSudoku(int sudoku[N][N])
    {
        cout<<endl;
        cout<<"x 1 2 3 4\ny ";
        for(int i=0; i<N+1; i++)
        {
            cout<<"--";
        }
        cout<<endl;
        for(int i=0; i<N; i++)
        {
            cout<<i+1<<" |";
            for(int j=0; j<N; j++)
            {
                cout<<sudoku[i][j]<<" ";
            }
            cout<<"|";
            cout<<endl;
        }
        cout<<"  ";
        for(int i=0; i<N+1; i++)
        {
            cout<<"--";
        }
    }
    
    //checks if it's safe to put the number in specific row and col or not
    bool isSafe(int sudoku[N][N],int i,int j,int value)
    {
        //cout<<"isSafe ("<<i<<j<<") val:"<<value<<" col:"<<!isCol(sudoku,j,value)<<" row: "<<!isRow(sudoku,i,value)<<endl;
        if(!isCol(sudoku,j,value) && !isRow(sudoku, i, value) && !isDiag(sudoku, i, j, value))
        {
            return true;
        }
        return false;
    }
    
    //checks if it is safe to put the number in specific column or not
    bool isCol(int sudoku[N][N], int i, int value)
    {
        for (int j = 0; j < N; j++)
        {
            if (sudoku[j][i] == value)
                return true;
        }
        
        return false;
    }
    
    //checks if it is safe to put the number in specific row or not
    bool isRow(int sudoku[N][N], int j, int value)
    {
        for (int i = 0; i < N; i++)
            if (sudoku[j][i] == value)
                return true;
        return false;
    }
    
    /*
     checks if it is safe to keep a number in diagonal,
     however, the problem is it doesn't check for i+j==N-1
     which would give if it is safe to keep in second diagonal
     as well for higher Ns than 4
     */
    bool isDiag(int sudoku[N][N], int i, int j, int value)
    {
        if(i==j)
        {
            int k;
            for(k=0; k<j; k++)
            {
                for(int i=0; i<N; i++)
                {
                    if(k==i)
                    {
                        if(sudoku[k][i]==value) return true;
                    }
                }
            }
        }
        return false;
    }
    
    void printHints(int gamePlay[N][N], int map[N][N])
    {
        srand(time(NULL));
        for(int i=0; i<N; i++)
        {
            int x = rand()%N;
            //cout<<x<<endl;
            gamePlay[i][x]=map[i][x];
            hints[i]=x;
            //cout<<hints[i]<<endl;
        }
    }
    
public:
    puzzle(int contents[N+1])
    {
        generateMap(contents, map, gamePlay);
        printHints(gamePlay, map);
        cout<<"----Int/Word Puzzle----"<<endl;
        cout<<"Your characters to be \nused are: ";
        for(int i=1; i<=N; i++)
        {
            cout<<contents[i]<<" ";
        }
        printSudoku(gamePlay);
        //printSudoku(map);
        //ClearScreen();
        //system("clear");
        //system("Color F3");
        //cout<<RED<<"This is color"<<RESET;
        //menu();
        //clear();
        //printSudoku(gamePlay);
        //printSudoku(map);
    }
    void menu()
    {
        cout<<"\n----MENU----"<<endl;
        cout<<"1. Play"<<endl;
        cout<<"2. Reset hints"<<endl;
        cout<<"3. Reset string/numbers"<<endl;
        cout<<"4. Exit"<<endl;
    }
    
    
    void generateMap(int content[N+1], int map[N][N], int gamePlay[N][N])
    {
        int sudoku[N][N];
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                sudoku[i][j]=UNASSIGNED;
                gamePlay[i][j]=UNASSIGNED;
                if(i==0)
                {
                    sudoku[i][j]=j+1;
                }
            }
        }
        int value=1;
        int counter=1;
        int tries=0;
        int backX=1;
        int backY=0;
        int backValueCounter=0;
        int backTrack[]={backX,backY,backValueCounter};
        for(int i=1; i<N; i++)
        {
            counter=1;
            for(int j=0; j<N; j++)
            {
                tries++;
                //cout<<endl;
                //printSudoku(sudoku);
                //printSudoku(sudoku);
                if(counter>N)
                {
                    counter=1;
                    
                    //backY++;
                    //backValueCounter++;
                    //backTrack[0]=backX;
                    // backTrack[1]=backY;
                    //backTrack[2]=backValueCounter;
                    //cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
                    tries=0;
                    break;
                }
                if(value>N)
                {
                    value=1;
                }
                else
                {
                    /*
                     cout<<"Value: "<<value<<" "<<"("<<i<<j<<") "<<"Safe: "<<(isSafe(sudoku, i, j, value) && sudoku[i][j]==UNASSIGNED)<<endl;
                     cout<<"Counter: "<<counter<<endl;
                     cout<<"Tries: "<<tries<<endl;
                     cout<<"BackX: "<<backTrack[0]<<endl;
                     cout<<"BackY: "<<backTrack[1]<<endl;
                     cout<<"BackCount: "<<backTrack[2]<<endl;
                     printSudoku(sudoku);
                     cout<<endl;
                     */
                    if(isSafe(sudoku, i, j, value) && sudoku[i][j]==UNASSIGNED)
                    {
                        
                        sudoku[i][j]=value;
                        j=-1;
                        //cout<<"value j: "<<j;
                        value++;
                        counter++;
                        tries=0;
                    }
                    
                    
                    /*
                     if(sudoku[i][j]==UNASSIGNED)
                     {
                     while(isSafe(sudoku, i, j, value))
                     {
                     value++;
                     if(value>N)
                     {
                     value=1;
                     }
                     
                     }
                     sudoku[i][j]=value;
                     j=-1;
                     value=1;
                     tries=0;
                     }*/
                    
                    
                    //backtracking starts
                    if(tries>=N)
                    {
                        /*
                         cout<<"---------------Backtracking Deletion---------------------";
                         cout<<endl;
                         */
                        value=sudoku[backTrack[i]] [backTrack[j]];
                        for(int x=backTrack[0]; x<i+1; x++ )
                        {
                            for (int y=0; y<N; y++)
                            {
                                if(x==backTrack[0]&&y==0)
                                {
                                    y=backTrack[1];
                                }
                                sudoku[x][y]=UNASSIGNED;
                                /*
                                 cout<<"X: "<<x<<" Y: "<<y<<endl;
                                 printSudoku(sudoku);
                                 */
                            }
                        }
                        i=backTrack[0];
                        j=backTrack[1];
                        value=1;
                        
                        tries=0;
                        counter=j+1;
                        //sudoku[i][j]++;
                        //cout<<"Sudoku Value: "<<sudoku[i][j];
                        //printSudoku(sudoku);
                        
                        for(int x=1; x<=N; x++)
                        {
                            if(isSafe(sudoku, i, j, x) &&  x>backTrack[2])
                            {
                                backTrack[2]=x;
                                sudoku[i][j]=x;
                                //cout<<"fhdsajfhajsdfhajksdfhajkdfhlasdfhjajsdfl x"<<backTrack[0]<<endl;
                                //cout<<"fhdsajfhajsdfhajksdfhajkdfhlasdfhjajsdfl x"<<backTrack[1]<<endl;
                                //cout<<"fhdsajfhajsdfhajksdfhajkdfhlasdfhjajsdfl magic "<<backTrack[2]<<endl;
                                counter=backTrack[1]+1;
                                break;
                            }
                        }
                        
                        //using sum of elements of index 2 and 1 is the ket to backtrack
                        if(backTrack[2]+backTrack[1]>=N)
                        {
                            backTrack[1]=backTrack[1]+1;
                            backTrack[2]=0;
                            //cout<<"jsjjsjsjhhjshjshjsjhhjshin";
                        }
                        
                        if(backTrack[1]>=N)
                        {
                            backTrack[0]=backTrack[0]+1;
                            backTrack[1]=0;
                        }
                        //cout<<"Sudoku"<<endl;
                        //printSudoku(sudoku);
                        //backTrack[2]=sudoku[i][j];
                        
                        //backtrack ends
                    }
                }
            }
        }
        //printSudoku(sudoku);
        for (int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                map[i][j]=content[sudoku[i][j]];
            }
        }
    }
    
    void clear()
    {
        //printSudoku(map);
        for(int i=0; i<N; i++)
        {
            content[i+1]=UNASSIGNED;
            hints[i]=UNASSIGNED;
            for(int j=0; j<N; j++)
            {
                map[i][j]=UNASSIGNED;
                gamePlay[i][j]=UNASSIGNED;
            }
        }
    }
    
    void setContent(int contents[N+1])
    {
        for(int i=1; i<N+1; i++)
        {
            content[i]=contents[i];
        }
        generateMap(contents, map, gamePlay);
        printHints(gamePlay, map);
        cout<<"----Int/Word Puzzle----"<<endl;
        cout<<"Your characters to be \nused are: ";
        for(int i=1; i<=N; i++)
        {
            cout<<contents[i]<<" ";
        }
       // printSudoku(gamePlay);
       // printSudoku(map);
    }
    
    bool getContent(int x, int y, int val)
    {
        x--;
        y--;
        /*
        bool hintLocationUsed=false;
        for(int i=0; i<N; i++)
        {
            cout<<"MAP: "<<map[i][y]<<" HINTS: "<<hints[i]<<endl;
            if(map[i][y]==map[i][hints[i])
            {
                hintLocationUsed=true;
                //cout<<"TRUE "<<endl;
                break;
            }
        }
        */
        if(x<N && y<N && hints[x]!=y)
        {
            cout<<"x: "<<x<<" y: "<<y<<endl;
            gamePlay[x][y]=val;
            printSudoku(gamePlay);
            cout<<"Game Play: "<<gamePlay[x][y]<<endl;
            return true;
        }
        
        return false;
        //printSudoku(gamePlay);
    }
    
};
