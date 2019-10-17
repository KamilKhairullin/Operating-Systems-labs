#include <stdio.h>
#include <stdlib.h>

typedef struct frame{
  int value;
  int counter;
} page_frame;

void print_mem(page_frame frames[], int number_of_frames){
  for(int i = 0; i < number_of_frames; i++){
    printf("Frame number: %d has value '%d' and counter '%d'\n", i, frames[i].value, frames[i].counter);
  }
  printf("\n");
}

float aging_algorithm(FILE * input, int number_of_frames){
  page_frame frames[number_of_frames];
  for(int i = 0; i < number_of_frames; i++){
    frames[i].value = 0;
    frames[i].counter = 0;
  }
  int current_input = 0, hit = 0, miss = 0;
  while(fscanf(input, "%d", &current_input) != EOF){
    int min_counter = 256, min_id = 0;
    char is_written = 0;
    for(int i = 0; i < number_of_frames; i++){
      frames[i].counter = frames[i].counter >> 1;
      if(frames[i].value == current_input){
        frames[i].counter+=128;
        hit++;
        is_written = 1;
      }
      else if(frames[i].counter < min_counter || frames[i].value == 0){
        min_counter = frames[i].counter;
        min_id = i;
      }
    }
    if(is_written == 0){
      frames[min_id].value = current_input;
      miss++;
      frames[min_id].counter = 127;
    }
    //print_mem(frames, number_of_frames);
  }
  printf("For %d frames hit is %d miss is %d. Hit / Miss ratio is %f\n",number_of_frames, hit, miss, (float)hit/(float)miss);
  return (float)hit/(float)miss;
}

int main(){
  FILE * input = fopen("input.txt", "r");
  aging_algorithm(input, 10);
  fclose(input);
  input = fopen("input.txt", "r");
  aging_algorithm(input, 50);
  fclose(input);
  input = fopen("input.txt", "r");
  aging_algorithm(input, 100);
  fclose(input);
  return 0;
}
