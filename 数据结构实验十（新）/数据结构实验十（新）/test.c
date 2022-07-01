#include"HuffCode.h"

int main()
{
	int n = 8, i;
	char str[] = { 'A','B','C', 'D', 'E', 'F' ,'G' , 'H' };
	int fnum[] = { 9,5,3,7,6,2,1,1 };
	HuffNode ht[MAXNUM];
	HuffCode hcd[MAXNUM];
	for (i = 0; i < n; i++)
	{
		ht[i].data = str[i];
		ht[i].weight = fnum[i];
	}

	HuffmanCreate(ht, n);
	PrintHaffman(ht, n);
	EnCoding(ht, hcd, n);
	PrintHuffCode(ht, hcd, n);
	return 0;
}