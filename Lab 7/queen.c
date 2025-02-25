#include<stdio.h>
#define N 8

int main(){
    int placed[N],row=0,col=0,solCount=0;
    while(row>=0){
        if(col==N){
            row--;
            if(row>=0){
                col=placed[row]+1;
            }
            continue;
        }

        int safe = 1;
        for(int prev=0;prev<row;prev++){
            if(placed[prev]==col || placed[prev]-prev == col - row || placed[prev]+prev == col + row){
                safe=0;break;
            }
        }

        if(safe){
            placed[row++] = col;
            col=0;
            if(row==N){
                printf("\nSolution %d found:\n",++solCount);
                for(int i=0;i<N;i++,printf("\n")){
                    for(int j=0;j<N;j++){
                        printf("%c",(placed[i]==j) ? 'Q' : '.');
                    }
                }
                printf("\nQueens position (row,col):");
                for(int i=0;i<N;i++){
                    printf("(%d,%d)",i,placed[i]);
                } printf("\n");
                row--;
                col = placed[row]+1;
            }
        } else {
            col++;
        }
    }
    printf("\nTotal Solution Found: %d\n",solCount);
    return 0;
}
