#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
	int N;
	scanf("%d", &N);
	for (int tc = 1; tc <= N; tc++)
	{
		int N;
		scanf("%d", &N);
		vector<int> score;
		int t, sum = 0;
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &t);
			score.push_back(t);
			sum += t;
		}
		double average = (double)sum / N;
		int numOver = 0;
		for (int i = 0; i < N; i++) 
		{
			if (score[i] > average)
			{
				numOver++;
			}
		}
		printf("%.3f%%\n", ((double)numOver / N * 100));
	}
}