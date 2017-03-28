#include<stdio.h>
#include<vector>

#include<algorithm>
using namespace std;
vector<int> score;
int main()
{
	int N, t;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &t);
		score.push_back(t);
	}
	auto best = max_element(score.begin(), score.end());
	double sum = 0;
	for (auto &e : score) {
		sum += (double)e / (double)(*best) * 100;
	}
	printf("%.2f\n", sum / N);
	return 0;
} 