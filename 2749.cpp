/*
2749. 피보나치 수 3

[문제]
피보나치 수는 0과 1로 시작한다. 0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다. 그 다음 2번째 부터는 바로 앞 두 피보나치 수의 합이 된다.

이를 식으로 써보면 Fn = Fn-1 + Fn-2 (n>=2)가 된다.

n=17일때 까지 피보나치 수를 써보면 다음과 같다.

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597

n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램을 작성하시오.

[입력]
첫째 줄에 n이 주어진다. n은 1,000,000,000,000,000,000보다 작거나 같은 자연수이다.

[출력]
첫째 줄에 n번째 피보나치 수를 1,000,000으로 나눈 나머지를 출력한다.


1. 일단 이걸 O(N)으로 구할 수 없다는건 너무 잘 알겠다. 
2. 그렇지만 출력해야 할 것이 fibo(N) 이 아니라 fibo(N) % 1,000,000 이다.
3-1. 피보나치 수열을 K로 나눈 나머지는 주기를 15*10^(k-1) 이하로 갖는다.

3-2. 피보나치 수열을 행렬 연산을 통해 구현할 수 있다.
3-2-1. 
[F2, F1]	[1, 1]
[F1, F0]  = [1, 0] = A 라 하자.
그렇다면
[Fn,  	 F(n-1)]	
[F(n-1), F(n-2)] = A^(n-1)이다.

그렇다면 Fibo[N] 은 A^N의 1행 2열 (또는 2행 1열)의 숫자가 된다.
A의 N거듭제곱은 재귀로 계산해도 좋을 듯하다. (몇 개 안되니까)


[문제점] 이걸 많이 틀렸는데 다음과 같은 실수를 했다.
1. DIV로 나눈 나머지를 입력하는 부분을 rt= rt*rt 바로 뒤에 넣었었다.
이 경우, rt = rt * fibomat(N % 2) 를 수행한 후 나머지가 제대로 계산되지 않는 문제점이 있었다.

오류를 바로 잡아내지 못한 이유는 
1. input이 N=45까지 입력되는 이전 문제(2747)에서는 정확하게 동작했으며 (답이 1,000,000을 넘지 않음)
2. N = 90까지 입력되는 이전 문제 (2748)에서도 정확하게 동작 (답에 나머지 연산을 하지 않음) 했기 때문에 오류를 재현하지 못했기 때문이다.

[해결]
rt = rt * fibomat(N % 2) 수행 후 나머지 연산을 수행하도록 했다.
이전의 알고리즘에서는 N=51일때 잘못된 결과를 출력했다.
*/
#include<stdio.h>
#include<iostream>
#define __int64 long long
__int64 N;
const __int64 DIV = 1000000LL;
typedef struct Mat
{
	__int64 val[2][2];
	const Mat operator* (const Mat& rhs);
}Mat;

Mat fibomat(__int64 N) {
	Mat rt;
	if (N == 1)
	{
		rt.val[0][0] = 1; rt.val[0][1] = 1;
		rt.val[1][0] = 1; rt.val[1][1] = 0;
		return rt;
	}
	else if (N == 0)
	{
		rt.val[0][0] = 1; rt.val[0][1] = 0;
		rt.val[1][0] = 0; rt.val[1][1] = 1;
		return rt;
	}
	else
	{
		auto n2 = N / 2;
		rt = fibomat(n2);
		rt = rt * rt ;
		rt = rt * fibomat(N % 2);
		rt.val[0][0] %= DIV;
		rt.val[0][1] %= DIV;
		rt.val[1][0] %= DIV;
		rt.val[1][1] %= DIV;
		return rt;
	}
}
int main()
{
	std::cin >> N;
	Mat fibo = fibomat(N);
	std::cout << fibo.val[1][0] << std::endl;
}

const Mat Mat::operator*(const Mat & rhs)
{
	Mat rt;
	rt.val[0][0] = this->val[0][0] * rhs.val[0][0] + this->val[0][1] * rhs.val[1][0];
	rt.val[0][1] = this->val[0][0] * rhs.val[0][1] + this->val[0][1] * rhs.val[1][1];
	rt.val[1][0] = this->val[1][0] * rhs.val[0][0] + this->val[1][1] * rhs.val[1][0];
	rt.val[1][1] = this->val[1][0] * rhs.val[0][1] + this->val[1][1] * rhs.val[1][1];

	return rt;
}