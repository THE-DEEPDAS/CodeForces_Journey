#include <bits/stdc++.h>

using namespace std;

int main(){
    int x1 = 0 , x2 = 0 , x3 = 0;
    cin >> x1 >> x2 >> x3;
      //they should meet at median to cover least distance
      int median = 0;
      if((x1 > x2 && x1 < x3) || (x1 < x2 && x1 > x3)) median = x1;
      else if((x2 > x1 && x2 < x3) || (x2 < x1 && x2 > x3)) median = x2;
      else median = x3;
      //distance by the person standing on x1 
      int distance1 = abs(x1 - median);
      //distance by the person standing on x2
      int distance2 = abs(x2 - median);
      //distance by the person standing on x3
      int distance3 = abs(x3 - median);
      //minimum distance
      int totalDistance = distance1 + distance2 + distance3;
      cout << totalDistance << endl;
}

