#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SIZE_X 130
#define SIZE_Y 130
#define GUARD '^'
#define OBJECT '#'
#define MAX_MOVES 60000

int main(void) {
    printf("Day Five\n");
    FILE* fptr;

    fptr = fopen("test.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    char map[SIZE_Y][SIZE_X+2];

    char line[500];
    char *pch;
    char *pchB;
    long i =0;
    int dir = 0; // 0 North 1 East 2 South 3 West
    int gaurdX;
    int gaurdY;
    int moves[SIZE_Y][SIZE_X];
    int hist[3][MAX_MOVES];
    for (int i =0;i<SIZE_Y;i++)
        for (int j=0;j<SIZE_X; j++)
            moves[i][j] =0;
    
    while (fgets(map[i], 500, fptr) != NULL) {
        
        //printf(map[i]);
        pch = strchr(map[i], GUARD);
        if(pch!=NULL){
            gaurdY = i;
            gaurdX = pch-map[i];
            printf("Guard found at %d, %d\n",gaurdX,gaurdY);
            
        }
        i++;
    }
    int guardStartX = gaurdX;
    int guardStartY = gaurdY;
    int count =0;
    i =0;
    int block =0;
    do{
        
        if(dir == 0){
            if(map[gaurdY -1][gaurdX]==OBJECT)
                dir = 1;
            else{
                gaurdY --;
                moves[gaurdY][gaurdX] = 1;
            }
        }
        else if(dir == 1){
            if(map[gaurdY][gaurdX+1]==OBJECT)
                dir = 2;
            else{
                gaurdX ++;
                moves[gaurdY][gaurdX] = 1;
            }
        }
        else if(dir == 2){
            if(map[gaurdY+1][gaurdX]==OBJECT)
                dir = 3;
            else{
                gaurdY ++;
                moves[gaurdY][gaurdX] = 1;
            }
        }
        else if(dir == 3){
            if(map[gaurdY][gaurdX-1]==OBJECT)
                dir = 0;
            else{
                gaurdX --;
                moves[gaurdY][gaurdX] = 1;
            }
        }
        
        
        
        i++;
        //printf("Move: DIR%d,X%d,Y%d\n",dir,gaurdX,gaurdY);

    }while(gaurdX>=0 & gaurdX<SIZE_X & gaurdY>=0 & gaurdY<SIZE_Y);

    for (int y =0; y<SIZE_Y; y++)
        for (int x =0; x<SIZE_X; x++){
            if(map[x][y]!=GUARD&map[x][y]!=OBJECT&moves[x][y]){
                map[x][y] = OBJECT;
                printf("Placing Object at %d,%d\n",x,y);
                dir = 0;
                gaurdX =guardStartX;
                gaurdY = guardStartY;
                i=0;
                int flag = 0;
                do{
        
                    hist[0][i]=dir;
                    hist[1][i]=gaurdY;
                    hist[2][i]=gaurdX;

                    if(dir == 0){
                        if(map[gaurdY -1][gaurdX]==OBJECT)
                            dir = 1;
                        else{
                            gaurdY --;
                        }
                    }
                    else if(dir == 1){
                        if(map[gaurdY][gaurdX+1]==OBJECT)
                            dir = 2;
                        else{
                            gaurdX ++;
                        }
                    }
                    else if(dir == 2){
                        if(map[gaurdY+1][gaurdX]==OBJECT)
                            dir = 3;
                        else{
                            gaurdY ++;
                        }
                    }
                    else if(dir == 3){
                        if(map[gaurdY][gaurdX-1]==OBJECT)
                            dir = 0;
                        else{
                            gaurdX --;
                        }
                    }
                    i++;
                    for(int j =0; j<i; j++)
                        if(dir == hist[0][j] && gaurdX == hist[2][j] && gaurdY == hist[1][j]){
                            block++;
                            flag = 1;
                            printf("Found Loop \n");
                            break;
                        }

                    
                    
                    
                    
                    //printf("Move: DIR%d,X%d,Y%d\n",dir,gaurdX,gaurdY);

                }while(gaurdX>=0 & gaurdX<SIZE_X & gaurdY>=0 & gaurdY<SIZE_Y & flag ==0);

            map[x][y] = '.';



            }
                

        }


    printf("\n");
    //printf("Length of Hist %d\n",i);
    // for (int j =0; j<i; j++){
    //     printf("HIST:%d,%d,%d\n",hist[0][j],hist[2][j],hist[1][j]);
    // }
    for (int i =0;i<SIZE_Y;i++)
        for (int j=0;j<SIZE_X; j++)
            count += moves[i][j];
    
    
    printf("Part A: %d\n", count);
    printf("Part B: %d\n",block);
    return 0;
}
