#include <stdio.h>
#include <stdlib.h>
//--------------------------------------------------------------------------------------------------------
int y,m,d,Week;                                     // 年,月,日,星期
int Start_tag = 0,                                  // 起始標籤 初始為0 正確為1 錯誤為2
    Month_value[13] = {0,0,3,3,6,1,4,6,2,5,0,3,5},  // 月值
    Month_array[13] = {1,4,2,4,3,4,3,4,4,3,4,3,4}   // 月份偵錯陣列
    ;
//--------------------------------------------------------------------------------------------------------
void Debug()                                        //偵測是否輸入正常的日期
{
    if(Month_array[m]%4==0 & d<32) Start_tag = 1;
    else if(Month_array[m]%4==3  & d<31) Start_tag = 1;
    else if(Month_array[m]%4==2)
    {
        if(y%4==0 & d<30) Start_tag = 1;
        else if(y%4>0 & d<29) Start_tag = 1;
        else Start_tag = 2;
    }
    else Start_tag = 2;
}
void Weekly_algorithm_function()                    //算法函式
{
    if(y >= 1753) Week = ( (2*(3-((y/100)%4))) + (y%100) + ((y%100)/4) + Month_value[m] + d)%7;
    else Start_tag = 2;
}
void Divider()                                      //分隔函式
{
    printf("\n------------------------\n");
}
//--------------------------------------------------------------------------------------------------------
int main(void)
{

    while(1)
    {
                        printf("請輸入年:"); scanf("%d",&y);
                        printf("請輸入月:"); scanf("%d",&m);
        if(m>0 & m<13) {printf("請輸入日:"); scanf("%d",&d);} else Start_tag = 2;
        if(d>0) Debug();
        else Start_tag = 2;

        Weekly_algorithm_function();

        if(Start_tag == 1)
        {
            printf("\n%d年%d月%d日為 星期",y,m,d);
            switch(Week)
            {
                case 0: printf("日"); break;
                case 1: printf("一"); break;
                case 2: printf("二"); break;
                case 3: printf("三"); break;
                case 4: printf("四"); break;
                case 5: printf("五"); break;
                case 6: printf("六"); break;
            }
            Divider();
        }
        else {printf("\n輸入錯誤請重新輸入"); Divider();}

    }

    system("pause");

    return 0;

}
