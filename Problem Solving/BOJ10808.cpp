//¾ËÆÄºª °³¼ö

#include<stdio.h>
using namespace std;

int alphabet[26];
int main() {
	char str[101];
	scanf("%s", str);
	for (int i = 0; str[i] != '\0'; i++) 
		alphabet[str[i] - 'a']++;

		for (int i = 0; i < 26; i++) {
			printf("%d ", alphabet[i]);
		}
	
}