#include <iostream>
#include <math.h>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <time.h>
#include"Encryption.h"

using namespace std;

int determinant(int matrix[3][3], int n) 
{
  int det = 0;
  int submatrix[3][3];
  if (n == 2)
  {
    return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
  }
  else 
  {
    for (int x = 0; x < n; x++) 
    {
      int subi = 0;
      for (int i = 1; i < n; i++) 
      {
        int subj = 0;
        for (int j = 0; j < n; j++) 
        {
          if (j == x)
            continue;
          submatrix[subi][subj] = matrix[i][j];
          subj++;
        }
        subi++;
      }
      det = det + (pow(-1, x) * matrix[0][x] * determinant(submatrix, n - 1));
    }
  }
  return det;
}

void wordGen(int wordVec[26][1], char word[26], int l)
{
    for (int i = 0; i < l; i++) 
    {
      for (int j = 0; j < 1; j++) 
      {
        if (int(word[i]) >= 65 && int(word[i]) <= 91) 
        {
          wordVec[i][j] = int(word[i]) - 65;
        } 
        else if (int(word[i]) >= 97 && int(word[i]) <= 122) 
        {
          wordVec[i][j] = int(word[i]) - 97;
        }
      }
    }
}

void encryptArray(int encryptWordVec[3][1], int keyVec[3][3], int wordVec[26][1], int l)
{
    for (int i = 0; i < l; i++) 
    {
      for (int j = 0; j < 1; j++) 
      {
        encryptWordVec[i][j] = 0;
      }
    }

    for (int i = 0; i < l; i++) 
    {
      for (int j = 0; j < 1; j++) 
      {
        for (int k = 0; k < 3; k++) 
        {
          encryptWordVec[i][j] += keyVec[i][k] * wordVec[k][j];
        }
        encryptWordVec[i][j] %= 26;
      }
    }
}

void displayKey(int keyVec[3][3])
{
    for (int i = 0; i < 3; i++) 
    {
      for (int j = 0; j < 3; j++) 
      {
        cout << char(keyVec[i][j] + 65);
      }
    }
}

void displayWord(int encryptWordVec[3][1])
{
    for (int i = 0; i < 3; i++) 
    {
      for (int j = 0; j < 1; j++) 
      {
        cout << char(encryptWordVec[i][j] + 65);
      }
    }
    cout<<" ";
}
