#include<iostream>
 
using namespace std;
 
int main()
{
  int index, stopCod = 0, digit, localState, wordState, symbol;
  char ch, str[80] = "";
 
  int table[5][14] =
  {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0},//да
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1},//нет
    {3,3,3,3,3,3,3,3,3,3,3,3,1,1},//знак
    {3,3,3,3,3,3,3,3,3,3,1,1,2,0},//число
    {1,1,1,1,1,1,1,1,1,1,1,1,1,0}//конец
  };
   
  index = 0;
  cin >> ch;
  while ((stopCod != 35) && index < 80)
  {
    str[index++] = ch;
    cin >> ch;
    stopCod = ch;
  }
  str[index++] = ch;
  str[index] = '\0';
  digit = index - 1;
  localState = 2;
 
  for (int i = 0; i <= digit; ++i)
  {
    symbol = str[i];
    switch (symbol)
    {
    case '0':
      wordState = table[localState][0];
      break;
    case '1':
      wordState = table[localState][1];
      break;
    case '2':
      wordState = table[localState][2];
      break;
    case '3':
      wordState = table[localState][3];
      break;
    case '4':
      wordState = table[localState][4];
      break;
    case '5':
      wordState = table[localState][5];
      break;
    case '6':
      wordState = table[localState][6];
      break;
    case '7':
      wordState = table[localState][7];
      break;
    case '8':
      wordState = table[localState][8];
      break;
    case '9':
      wordState = table[localState][9];
      break;
    case '+':
      wordState = table[localState][10];
      break;
    case '-':
      wordState = table[localState][11];
      break;
    case '/':
      wordState = table[localState][12];
      break;
    case '#':
      wordState = table[localState][13];
      break;
    default:
      wordState = 1;
    }
    localState = wordState;
  }
  
  switch (wordState)
  {
  case 1:
    cout << endl << "STRING is WRONG" << endl;
    break;
  case 0:
    cout << endl << "STRING is RIGHT" << endl;
    break;
  }
  return 0;
};
