﻿#include <iostream>
#include <cmath>
using namespace std;
double S0(const int K, const int N)
{
	double s = 0;
	for (int i = K; i <= N; i++)
		s += (cos(i) * 1.0) / (1 + sin(i) * sin(i));
	return s;
}
double S1(const int K, const int N, const int i)
{
	if (i > N)
		return 0;
	else
		return cos(i) * 1.0 / (1 + sin(i) * sin(i)) + S1(K, N, i + 1);
}
double S2(const int K, const int N, const int i)
{
	if (i < K)
		return 0;
	else
		return cos(i) * 1.0 / (1 + sin(i) * sin(i)) + S2(K, N, i - 1);
}
double S3(const int K, const int N, const int i, double t)
{
	t = t + cos(i) / (1 + sin(i) * sin(i));
	if (i >= N)
		return t;
	else
		return S3(K, N, i + 1, t);
}
double S4(const int K, const int N, const int i, double t)
{
	t = t + cos(i) * 1.0 / (1 + sin(i) * sin(i));
	if (i <= K)
		return t;
	else
		return S4(K, N, i - 1, t);
}
int main()
{
	int K, N = 15;
	cout << "K = "; cin >> K;
	cout << "(iter) S0 = " << S0(K, N) << endl;
	cout << "(rec up ++) S1 = " << S1(K, N, K) << endl;
	cout << "(rec up --) S2 = " << S2(K, N, N) << endl;
	cout << "(rec down ++) S3 = " << S3(K, N, K, 0) << endl;
	cout << "(rec down --) S4 = " << S4(K, N, N, 0) << endl;
	return 0;
}