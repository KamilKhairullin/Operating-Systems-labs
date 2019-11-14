#include <stdio.h>
#include <stdlib.h>

int main(){
    int number_of_processes = 5;
    int number_of_resourses = 3;

    int all_resourses[number_of_resourses];
    int avalible_now[number_of_resourses];
    int have_resourses_now[number_of_processes][number_of_resourses];
    int need_resourses[number_of_processes][number_of_resourses];
    int isChanged = 1;
    int ended[number_of_processes];
    FILE *file_in;
    FILE *file_out;
    file_in = fopen("c:\\Users\\Kamil\\Desktop\\input.txt", "r+");
    file_out = fopen("c:\\Users\\Kamil\\Desktop\\output.txt", "w+");
    for (int i = 0; i < number_of_resourses; i++){
        fscanf(file_in, "%d", &all_resourses[i]);
    }
    for (int i = 0; i < number_of_resourses; i++){
        fscanf(file_in, "%d", &avalible_now[i]);
    }
    for (int i = 0; i < number_of_processes; i++){
      ended[i] = 0;
      for(int j = 0; j < number_of_resourses; j++){
        fscanf(file_in, "%d", &have_resourses_now[i][j]);
      }
    }
    for (int i = 0; i < number_of_processes; i++){
      for(int j = 0; j < number_of_resourses; j++){
        fscanf(file_in, "%d", &need_resourses[i][j]);
      }
    }



    for (int i = 0; i < number_of_resourses; i++){
        printf("%d ", all_resourses[i]);
    }
    printf("\n");
    for (int i = 0; i < number_of_resourses; i++){
        printf("%d ", avalible_now[i]);
    }
    printf("\n");
    for (int i = 0; i < number_of_processes; i++){
      ended[i] = 0;
      for(int j = 0; j < number_of_resourses; j++){
        printf("%d ", have_resourses_now[i][j]);
      }
      printf("\n");
    }
    for (int i = 0; i < number_of_processes; i++){
      for(int j = 0; j < number_of_resourses; j++){
        printf("%d ", need_resourses[i][j]);
      }
      printf("\n");
    }





    int haveDeadlock = 0;
    for(int i = 0; i < number_of_processes; i++){
      for(int j = 0; j < number_of_processes; j++){
        if(ended[j] == 0){
        int isOk = 1;
        for(int k = 0; k < number_of_resourses; k++){
          if((need_resourses[j][k] > avalible_now[k])){
            isOk = 0;
          }
        }
        if(isOk == 1){
          ended[j] = 1;
          for(int k = 0; k < number_of_resourses; k++){
            avalible_now[k] += have_resourses_now[j][k];
            have_resourses_now[j][k] = 0;
          }
          j = number_of_processes;
        }
      }
    }
  }

for(int i = 0; i < number_of_processes; i++){
      if(ended[i] == 0){
        haveDeadlock = 1;
        fprintf(file_out, "Process is deadlocked %d\n", i + 1);
      }
    }
    if (!haveDeadlock){
      fprintf(file_out, "No deadlock\n");
    }
    fclose(file_in);
    fclose(file_out);
    return 0;
}
