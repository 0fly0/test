#pragma once
#include <stdio.h>
#include <windows.h>
int a[101];// = { 6,1,2,7,9,3,4,5, 10,8 };
int n = 10;//����ȫ�ֱ�����������������Ҫ���Ӻ�����ʹ��
void quicksort(int left, int right) {
	int i, j, t, temp;
	if (left > right)
		return;
	temp = a[left]; //temp�д�ľ��ǻ�׼��
	i = left;
	j = right;
	while (i != j) { //˳�����Ҫ��Ҫ�ȴ��ұ߿�ʼ��
		while (a[j] >= temp && i < j)
			j--;
		while (a[i] <= temp && i < j)//�����ұߵ�
			i++;
		if (i < j)//�����������������е�λ��
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	//���ս���׼����λ
	a[left] = a[i];
	a[i] = temp;
	quicksort(left, i - 1);//����������ߵģ�������һ���ݹ�Ĺ���
	quicksort(i + 1, right);//���������ұߵ� ��������һ���ݹ�Ĺ���
}

void quicksort_test() {
	int i;
	//��������
	//scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	quicksort(0, n); //�����������
					 //��������Ľ��
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);

	printf("%d\n", a[n]);
}
