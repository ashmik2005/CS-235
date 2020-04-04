#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int result;
int MiniMaxAlphaBeta(int n,int max){
   printf("N: %d  Max: %d",n,max);
   int state,i=0;
   if(max == 1){
      state=0;
      if(n == 1){
         return 0;
      }
      if(n == 2){
         return 1;
      }
      for(i=n-1;i>=n-3 && i>=1;i--){
         state = MiniMaxAlphaBeta(i,0);
         if(state == 1){
            result = n - i;
            break;

         }

      }
      return state;
   }
      else {
         state = 1;
         if(n == 1){
            return 1;
         }

         if(n == 2){
            return 0;
         }
         for(i=n-1;i>=n-3&&i>=1;i--){
            state = MiniMaxAlphaBeta(i,1);
            if(state == 0){
               break;
            }
         }
         return state;

      }

   }



int main(void) {
	// your code goes here
	srand(time(0));
	int exitStatus=0,choice=0,numberOfSticks,toss,turn,value;
	do{
	   printf("Welcome to the Game of sticks\n");
	   printf("Here are the rules\nIt is a 2-player game.\nThere is a heap of sticks on a board\n Each player picks up sticks alternatively.\nOn their turn, each player has to pick at least 1 stick and he can pick at most 3 sticks.\n The one who has to pick the final stick will be the loser.\n First turn will be randomly decided with toss.\n");
	   printf("Please select a choice\n");
	   printf("1. Human v/s Human\n");
	   printf("2. Human v/s AI\n");
	   printf("3. AI v/s AI\n");
	   scanf("%d",&choice);
	   numberOfSticks=toss=turn=value=0;
	   printf("Enter the number of sticks\n");
	   scanf("%d",&numberOfSticks);
	   if(choice == 1){
	      /* Randomly determining whose turn it will be first */
	      toss=(rand() % 2);
	      turn=toss;
	      while(1){
	         printf("Number of sticks left: %d\n",numberOfSticks);
	         printf("According to random number generator it is player %d's turn\n",turn+1);
	         printf("Player %d please enter the number of sticks you want to remove from the heap\n",turn+1);
	         while(1){
	            scanf("%d",&value);
	            if(value >= 1&&value <= 3){
	               numberOfSticks -= value;
	               printf("\nNumber of sticks left on the heap is %d\n",numberOfSticks);
	               break;

	            }
	            printf("Please comply with the rules and enter a value between 1 and 3");

	         }
	         if(numberOfSticks==1){
	            if(turn == 1){
	               printf("\nCongratulations Player 2 you win!!\n");
	            }
	            else{
	               printf("\nCongratulations Player 1 you win!!\n");

	            }
	            printf("\nEnter 0 to exit or any other key to continue\n");
	            scanf("%d",&choice);
	            break;

	         }

	         if(turn==1){
	            turn=0;
	         }
	         else{
	            turn=1;
	         }

	      }

	   }

	   if(choice == 2){
	      toss=(rand() % 2);
	      if(toss==1){
	         printf("\nYou won the toss\n");
	      }
	      else{
	         printf("\nAI won the toss\n");
	      }
	      turn=toss;
	      while(1){
	         printf("\nNumber of sticks left: %d\n",numberOfSticks);
	         value=0;
	         if(turn==1){
	            printf("\nPlease Enter the number of sticks\n");
	            while(1){
	               scanf("%d",&value);
	               if(value >= 1 && value <= 3){
	                  numberOfSticks -= value;
	                  break;
	               }
	               printf("\nPlease comply with the rules any Enter a value between 1 and 3\n");
	            }
	            turn=0;
	         }
	         else{
	            result = 0;
	            MiniMaxAlphaBeta(numberOfSticks,1);
	            if(result!=0){
	               numberOfSticks -= result;
	               printf("\nAI has chosen %d sticks\n",result);
	            }
	            else{
	               printf("\nAI picked one stick\n");
	               numberOfSticks --;

	            }
	            turn = 1;
	         }
	            if(numberOfSticks==1){
	               if(turn == 1){
	                  printf("\nAI won the game\n");
	               }
	               else{
	                  printf("\nCongratulations you won the game\n");
	               }
	               printf("\nEnter any key to continue or 0 to exit the game\n");
	               scanf("%d",&choice);
	               break;

	            }

	      }
	   }

	   if(choice == 3){
	      printf("\n AI v/s AI\n");
	      toss = (rand()%2);
	      turn = toss;
	      while(1){
	         printf("\nNumber of sticks left:\n");
	         if(turn == 0){
	            MiniMaxAlphaBeta(numberOfSticks,1);
	            numberOfSticks -= result;
	            printf("\nAI picks %d sticks. %d sticks remain\n",result,numberOfSticks);
	            turn=1;

	         }

	         else{
	            MiniMaxAlphaBeta(numberOfSticks,1);
	            numberOfSticks -= result;
	            printf("\nAI picks %d sticks. %d sticks remain\n",result,numberOfSticks);
	            turn=0;

	         }

	         if(numberOfSticks == 1){
	            if(turn == 1){
	               printf("\nAI 1 is victorious\n");

	            }

	            else{
	               printf("\nAI 2 is victorious\n");

	            }

	            printf("\nPress any key to continue playing or zero to exit\n");
	            scanf("%d",&choice);
	            break;
	         }

	      }

	   }

	 }while(exitStatus!=0);
	return 0;
}



