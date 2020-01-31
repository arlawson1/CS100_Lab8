#include <stdio.h>
#include <stdlib.h>

int **allocateMatrix(int row, int col);
void initMatrix(int **, int, int);
int findRange(int **, int, int);
double findAverage(int **, int, int);
void printCorners(int **, int, int);

int main(int argc, char *argv[]){
  int **data;
  int row = atoi(argv[1]);
  int col = atoi(argv[2]);

  data = allocateMatrix(row, col);
  initMatrix(data, row, col);
  printf("The range of values in the array is %d\n", findRange(data, row, col));
  printf("The average of all array values is %lf\n", findAverage(data, row, col));
  printCorners(data, row, col);

  return 0;
}

int **allocateMatrix(int row, int col){
  int **data = malloc(sizeof(int *) *row);
  for(int a = 0; a <row; a++){
    data[a] = malloc(sizeof(int) * col);
  }
  return data;
}

void initMatrix(int **data, int row, int col){
  srand(0);
  for(int a = 0; a < row; a++){
    for(int b = 0; b < col; b++){
      data[a][b] = rand() % 1000;
    }
  }
  return;
}

int findRange(int **data, int row, int col){
  int min, max;
  max = data[0][0];
  min = data[0][0];
  for(int a = 0; a < row; a++){
      for(int b = 0; b < col; b++){
        if(data[a][b] > max){
          max = data[a][b];
        }
        if(data[a][b] < min){
          min = data[a][b];
        }
      }
  }
  int range = (max - min);
  return range;
}

double findAverage(int **data, int row, int col){
  int tempSum = 0;
  for(int a = 0; a < row; a++){
    for(int b = 0; b < col; b++){
      tempSum = tempSum + data[a][b];
    }
  }
  int numItems = (row * col);
  double average = ((double)tempSum / numItems);
  return average;
}

void printCorners(int **data, int row, int col){
  printf("%d %d", data[0][0], data[0][col - 1]);
  printf("\n");
  printf("%d %d", data[row -1][0], data[row - 1][col - 1]);
  printf("\n");
  return;
}
