/*
����
N���� ���ڰ� ���� ���� �����ִ�. �� ���ڸ� ��� ���ؼ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ���� N (1 �� N �� 100)�� �־�����. ��° �ٿ� ���� N���� ������� �־�����.

���
�Է����� �־��� ���� N���� ���� ����Ѵ�.
*/
#include<stdio.h>
int main()
{
	int N; scanf("%d\n", &N);
	int sum = 0;
	char n;
	while (N--) {
		scanf("%c", &n);
		sum += n - '0';
	}
	printf("%d\n", sum);
	return 0;
}