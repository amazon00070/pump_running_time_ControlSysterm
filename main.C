#include<stdio.h>
//泵参数结构体
struct pump_control
{
	int dangqian_bengshu;//当前运转的泵的数量
	int shijian_max_n;//在运转的泵中运转时间最长的泵号
	int shijian_min_n;//非运转的泵中运转时间最短的泵号
	int yunzhuan_zhuangtai[4];//每台泵的运转状态
	int yunzhuan_shijian[4];//每台泵的累积运转时间
};
struct pump_control pump;
void main(void)
{
	int n = 3;//计划运转的泵的数量
	//实验用的赋值参数
	pump.yunzhuan_zhuangtai[0] = 0;
	pump.yunzhuan_zhuangtai[1] = 0;
	pump.yunzhuan_zhuangtai[2] = 0;
	pump.yunzhuan_zhuangtai[3] = 0;
	pump.yunzhuan_shijian[0] = 50;
	pump.yunzhuan_shijian[1] = 150;
	pump.yunzhuan_shijian[2] = 100;
	pump.yunzhuan_shijian[3] = 200;

	for (int i = 0; i < 10; i++)//实则单片机中应当while(1)，此处为了便于VS环境下观察
	{
		int time_max = 0, time_min = 100000000;
		pump.dangqian_bengshu = 0;

		for (int i = 0; i < 4; i++)//屏幕显示泵的状态和泵的时间
		{
			printf("%d,%d\n", pump.yunzhuan_zhuangtai[i], pump.yunzhuan_shijian[i]);
		}
		printf("\n");

		for (int i = 0; i < sizeof(pump.yunzhuan_zhuangtai) / sizeof(pump.yunzhuan_zhuangtai[0]); i++)
		{
			if (pump.yunzhuan_zhuangtai[i])//数出当前泵数
			{
				pump.dangqian_bengshu++;
			}

			if ((pump.yunzhuan_zhuangtai[i]) && (time_max < pump.yunzhuan_shijian[i]))//找出最长时间的泵
			{
				time_max = pump.yunzhuan_shijian[i];
				pump.shijian_max_n = i;
			}

			if ((pump.yunzhuan_zhuangtai[i] == 0) && (time_min > pump.yunzhuan_shijian[i]))//找出最短时间的泵
			{
				time_min = pump.yunzhuan_shijian[i];
				pump.shijian_min_n = i;
			}
		}

		if (n > pump.dangqian_bengshu)//若缺泵，则启动
		{
			pump.yunzhuan_zhuangtai[pump.shijian_min_n] = 1;
		}
		if (n < pump.dangqian_bengshu)//若多泵，则停止
		{
			pump.yunzhuan_zhuangtai[pump.shijian_max_n] = 0;
		}
	}
}
