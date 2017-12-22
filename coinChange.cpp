#include <iostream>

using namespace std; 

int numberOfCoins = 4;

void minChange(int R[], int avilableCoins[], int length) {
	if (R[length] == -1)
		cout << "Cannot obtain this change\n"; 

	while (length!= 0) {
		int j = R[length];
			}
	cout<<endl;
}
//this is bottom up approach
int coinChange(int change, int avilableCoins[]) {
	int *T = new int[change + 1]; //beacuse we need to have value stroed for 0
	int *R = new int[change + 1];
	T[0] = 0;
	for (int i = 1; i < change; i++) { //initializing all the arrays to -1
		T[i] = -1;
		R[i] = -1;
	}
	//calculate how many coins I need and which one
	for (int j = 0; j < numberOfCoins; j++) {
		for (int i = 1; i <= change; i++) {
			if (i >= avilableCoins[j]) {
				if (T[i - avilableCoins[j]] + 1 < T[i]) {
					T[i] = T[i - avilableCoins[j]] + 1;
					R[i] = j;
				}
			}
		}
	}
	minChange(R, avilableCoins, change);
	return T[change];
}

int main() {
	int coins[] = {1,5,10,25};
	coinChange(13, coins);
	system("pause");
}