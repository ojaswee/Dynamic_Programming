#include <iostream>
#include <algorithm> // for minuimum function

using namespace std; 

int avilableCoins[] = {1,5,10};
const int numberOfCoins = 3;
const int target = 11; 
int p[numberOfCoins][target+1];

/*
mat = [[0 for x in range(n+1)] for x in range(len(change)+1)]

for c in range(1,(len(change)+1)):
for m in range(1, n + 1):
if change[c-1] ==m :
mat[c][m] = 1
elif m>change[c-1] and change[c-1]==1:
mat[c][m] = 1 + mat[c][m - change[c - 1]]

elif m>change[c-1] and change[c-1]!=1:
mat[c][m] = min(mat[c-1][m],1+ mat[c][m-change[c-1]])

elif m<change[c-1]:
mat[c][m] = mat[c-1][m]

return mat
*/

//this is bottom up approach
void coinChange() {
	cout << "Coins\t";
	for (int i = 0; i <= target; i++) {
		cout << i << "\t";
	}
	cout << endl;
	for (int change = 0; change < numberOfCoins; change++) {
		cout <<change <<" "<< avilableCoins[change] << "\t";
		for (int remaining = 0; remaining <= target; remaining++) {
			if (remaining == avilableCoins[change]) {// all correct
				p[change][remaining] = 1;
			}
			else if (remaining > avilableCoins[change] && avilableCoins[change] == 1) {
				p[change][remaining] = 1+ p[change][remaining -avilableCoins[change]];// all correct
			}
			else if (remaining > avilableCoins[change] && avilableCoins[change] != 1) {
				p[change][remaining] =min(p[change-1][remaining],1+p[change][remaining]); 
			}
			else if (remaining<avilableCoins[change]) {
				p[change][remaining] = p[change][remaining];
			}
			cout << p[change][remaining] << "\t";
		}
		cout << "\n";
	}
}

int main() {
	coinChange();
	system("pause");
}