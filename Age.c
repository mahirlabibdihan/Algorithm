#include <stdio.h>
#include <time.h>
int Birth_Date,Birth_Month,Birth_Year;
int Current_Date,Current_Month,Current_Year;
int Day,Month,Year;
void Welcome()
{
	puts("Welcome.");
}

int Calculate()
{

	time_t Current;
	time(&Current);
	struct tm *Time = localtime(&Current);

	Current_Date = Time->tm_mday;
	Current_Month = Time->tm_mon+1;
	Current_Year = Time->tm_year+1900;

	int month[] = { 31, 28, 31, 30, 31, 30, 31,31, 30, 31, 30, 31 };

	if(Birth_Date>Current_Date)
	{
		Current_Date+=month[Birth_Month-1];
		Current_Month--;
	}

	if(Birth_Month>Current_Month)
	{
		Current_Year--;
		Current_Month+=12;
	}

	Day=Current_Date-Birth_Date;
	Month=Current_Month-Birth_Month;
	Year=Current_Year-Birth_Year;
}	


int main()
{

	Welcome();
	scanf("%d-%d-%d",&Birth_Date,&Birth_Month,&Birth_Year);
	Calculate();
	printf("Years:%d  Months:%d  Days:%d\n",Year,Month,Day);
}