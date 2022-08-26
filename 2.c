#include "hw2.h"
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
*/
#define TRUE 1
#define FALSE 0
#define VISIT 'v'
#define SZ 7

/*
SAMPLE MAZE in maze.txt
x x x x x x x
x o o o o o x
x o x o x o x
x o o x o x x
x x o x o x x
x o o o o o x
x x x x x x x
*/ 

//char maze[SZ][SZ];

int si, sj, ei, ej;
int success;

// Write the following functions
int visit(int i, int j, char maze[SZ][SZ],int path[2*SZ-1][2]){
    //printf("%d %d\n",i,j);
    //printf("%c\n",maze[i][j]);
    if (i==ei && j==ej && maze[i][j]=='o'){
        path[i+j-2][0]=i;
        path[i+j-2][1]=j;
        return 1;
    }
    int flag=0;

    maze[i][j]='v';
    
    if (i<=SZ-2 && j<=SZ-1){
        if (maze[i+1][j]=='o'){
            //printf("아래로\n");
            int temp=(visit(i+1,j,maze,path));
            flag+=temp;
            if (temp==1){
                path[i+j-2][0]=i;
                path[i+j-2][1]=j;
            }
        }

    }
    if ((i<=SZ-1 && j<SZ-1) && flag!=1){
        if (maze[i][j+1]=='o'){
            //printf("옆으로\n");
            int temp=(visit(i,j+1,maze,path));
            flag+=temp;
            if (temp==1){
                path[i+j-2][0]=i;
                path[i+j-2][1]=j;
            }
        }
    }

    return flag;
}

void read_maze(char maze[SZ][SZ]){
    FILE* fp;
    fp=fopen("maze.txt","r");
    for(int i=0;i<SZ;i++){
        char ch;
        int count=0;
        while (count<SZ){
            ch=fgetc(fp);
            if(ch=='o'||ch=='x'){
                maze[i][count++]=ch;
                //printf("%c",ch);
            }
        }
       // puts("");
    }
            
    
    
    //printf("------\n");
    fclose(fp);
}
void q2 (void) 
//int main()
{
    
    si = 1; 
    sj = 1;
    ei = SZ-2; 
    ej = SZ-2;
    success = FALSE;
    char maze[SZ][SZ];
    int path[2*(SZ)-1][2];

    read_maze(maze);

    int a= visit(si,sj,maze,path);
    if (a<1){
        printf("No exit!\n");
    }
    else{
        for (int i=0; i<ei+ej-si-sj+1;i++){
            printf("(%d, %d) ",path[i][0],path[i][1]);
        }
        puts("");
    }
}