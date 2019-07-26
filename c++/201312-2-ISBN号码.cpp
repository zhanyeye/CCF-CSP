#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    int a, b, c; //前３个数
    char d, s1[4], s2[6];
    int sum = 0, cnt = 1; //sum表示９个数与权重相乘的和，cnt权重
    scanf("%d-%d-%d-%c", &a, &b, &c, &d); 
    sum += a * cnt++; //进行权重乘法加和 
    //将读取的整型转换成字符串
    sprintf(s1, "%d", b);
    sprintf(s2, "%d", c);
    for (int i = 0; i < 3; i++) {
        sum += cnt * (s1[i] - '0');
        cnt++;
    }
    for (int i = 0; i < 5; i++) {
        sum += cnt * (s2[i] - '0');
        cnt++;
    }
    int tmp = sum % 11;
    if ((tmp < 10 && tmp == d - '0') || (tmp == 10 && d == 'X'))
        printf("Right\n");
    else 
        printf("%d-%d-%d-%c\n", a, b, c, (tmp == 10 ? 'X' : tmp + '0'));
    return 0;
}
