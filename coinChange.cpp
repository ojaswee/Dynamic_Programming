#include <iostream>
#include <algorithm> // for minuimum function

using namespace std; 

const int numberOfCoins = 3;
const int target = 11; 
int p[numberOfCoins][target];

//this is bottom up approach
void coinChange( int avilableCoins[]) {
	//int **p = { 0 };
	//int **p = new int[numberOfCoins*change];
	for (int remaining = 1; remaining <= numberOfCoins; remaining++) {
		for (int coins = 1; coins <= target; coins++) {
			if (target == avilableCoins[coins-1]) {
				p[remaining][coins] = 1;
				//cout << p[remaining][coins] << "\t";
			}
			else if (coins > avilableCoins[remaining-1] && avilableCoins[remaining-1] == 1) {
				p[remaining][coins] = 1+ p[remaining][coins-avilableCoins[remaining-1]];
				//cout << p[remaining][coins] << "\t";
			}
			else if (coins > avilableCoins[remaining-1] && avilableCoins[remaining-1] != 1) {
				p[remaining][coins] =min(p[remaining-1][coins],1+p[remaining][coins-1]); //error here 
				//cout << p[remaining][coins] << "\t";
			}
			else if (coins<avilableCoins[remaining-1]) {
				p[remaining][coins] = p[remaining - 1][coins];
				//cout << p[remaining][coins] << "\t";
			}
			cout << p[remaining][coins] << "\t";
		}
		cout << "\n";
	}
}

int main() {
	int coins[] = { 1,5,10 };
	coinChange(coins);
	system("pause");
}