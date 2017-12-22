#include <iostream>
#include <algorithm> // for minuimum function

using namespace std; 

int avilableCoins[] = {1,5,10};
const int numberOfCoins = 3;
const int target = 11; 
int p[numberOfCoins][target+1];

//this is bottom up approach
void coinChange() {
	cout << "Coins\t";
	for (int i = 0; i <= target; i++) {
		cout << i << "\t";
	}
	cout << endl;
	for (int change = 0; change < numberOfCoins; change++) {
		cout << avilableCoins[change] << "\t";
		for (int remaining = 0; remaining <= target; remaining++) {
			if (remaining == avilableCoins[change])
				p[change][remaining] = 1;
			else if (remaining > avilableCoins[change] && avilableCoins[change] ==1)
				p[change][remaining] = 1+ p[change][remaining -avilableCoins[change]];
			else if (remaining > avilableCoins[change] && avilableCoins[change] != 1)
				p[change][remaining] =min(p[change-1][remaining],1+p[change][remaining - avilableCoins[change]]);
			else if (remaining<avilableCoins[change]) 
				p[change][remaining] = p[change-1][remaining];
			cout << p[change][remaining] << "\t";
		}
		cout << "\n";
	}
}

int main() {
	coinChange();
	system("pause");
}