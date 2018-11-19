#include <iostream>
#include <string>
using namespace std;
int main() {
  string cardtype;
  long int cardn = 0;
  int card[16];
  cout << "請輸入卡號:";  
  cin >> cardn;
  for ( int i = 0; i < 16; i++ ){
    card[i] = cardn % 10;    //每個數除以10的餘數
    cardn /= 10;  //把卡號的最後一個數字去掉
  }
  //奇數的*2
  for ( int i = 1; i < 16; i += 2 ){
    card[i] *= 2;
  //如果乘積大於等於10要兩數相加
    if ( card[i] * 2 >= 10 ){
      int second = card[i] % 10;
      int first = card[i] / 10;
      card[i] = second + first;
    }
  }
  int totalc = card[1] + card[2] + card[3] + card[4] + card[5] + card[6] + card[7] + card[8] + card[9] + card[10] + card[11] + card[12] + card[13] + card[14] + card[15];
  int r = totalc % 10; //餘數
  int cnum = 10 - r; //驗證碼
  if( cnum == card[0] && card[15] / 2 == 4 ){
    cout << "Visa";
  } 
  else if( cnum == card[0] && card[15] / 2 == 5 && card[14] >= 1 || card[14] <= 5 ){
    cout << "Master card";
  }
  else{
    cout << "偽造卡";
  }
}