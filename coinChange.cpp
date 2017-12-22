#include <iostream>

using namespace std; 

int numberOfCoins = 3;

//this is bottom up approach
void coinChange(int change, int avilableCoins[]) {
	int **p = { 0 };
	for (int remaining = 0; remaining <= change; remaining++) {
		cout << "\n";
		for (int coins = 0; coins < numberOfCoins; coins++) {
			if (change == avilableCoins[coins]) {
				p[coins][remaining] = 1;
				cout << p[coins][remaining] << "\t";
			}
			else if (remaining == 0) {
				p[coins][remaining] = 0;
				cout << p[coins][remaining] << "\t";
			}
			else if (remaining > 0 && (change != avilableCoins[coins])) {
				p[coins][remaining] = 1 + p[coins - 1][remaining];
				cout << p[coins][remaining] << "\t";
			}
		}
	}
}

int main() {
	int coins[] = {1,5,10};
	coinChange(11, coins);
	system("pause");
}