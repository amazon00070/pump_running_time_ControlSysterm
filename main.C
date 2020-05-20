#include<stdio.h>
struct pump_control
{
	int dangqian_bengshu;
	int shijian_max_n;
	int shijian_min_n;
	int yunzhuan_zhuangtai[4];
	int yunzhuan_shijian[4];
};
struct pump_control pump;
void main(void)
{
	int n = 4;
	pump.yunzhuan_zhuangtai[0] = 0;
	pump.yunzhuan_zhuangtai[1] = 0;
	pump.yunzhuan_zhuangtai[2] = 0;
	pump.yunzhuan_zhuangtai[3] = 0;
	pump.yunzhuan_shijian[0] = 50;
	pump.yunzhuan_shijian[1] = 150;
	pump.yunzhuan_shijian[2] = 100;
	pump.yunzhuan_shijian[3] = 200;
	for (int i = 0; i < 10; i++)
	{
		int time_max = 0, time_min = 100000000;
		pump.dangqian_bengshu = 0;
		for (int i = 0; i < 4; i++)
		{
			printf("%d,%d\n", pump.yunzhuan_zhuangtai[i], pump.yunzhuan_shijian[i]);
		}
		printf("\n");
		for (int i = 0; i < sizeof(pump.yunzhuan_zhuangtai) / sizeof(pump.yunzhuan_zhuangtai[0]); i++)
		{
			if (pump.yunzhuan_zhuangtai[i])
			{
				pump.dangqian_bengshu++;
			}
			if ((pump.yunzhuan_zhuangtai[i]) && (time_max < pump.yunzhuan_shijian[i]))
			{
				time_max = pump.yunzhuan_shijian[i];
				pump.shijian_max_n = i;
			}
			if ((pump.yunzhuan_zhuangtai[i] == 0) && (time_min > pump.yunzhuan_shijian[i]))
			{
				time_min = pump.yunzhuan_shijian[i];
				pump.shijian_min_n = i;
			}
		}
		if (n > pump.dangqian_bengshu)
		{
			pump.yunzhuan_zhuangtai[pump.shijian_min_n] = 1;
		}
		if (n < pump.dangqian_bengshu)
		{
			pump.yunzhuan_zhuangtai[pump.shijian_max_n] = 0;
		}
	}
}
