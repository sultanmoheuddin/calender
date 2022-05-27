#include<stdio.h>

int firstDay(int year){
        int day = (year*365 + ((year-1)/4) - ((year-1)/100) + ((year-1)/400)) & 7;
        return day;
}

int main(){
    int dayCount=0, weekBreak=0 ,year;
    printf("Which year : ");
    scanf("%d", &year);
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November","December"};
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for(int i=0; i<12; i++){
        printf("\n  ---------------------  %s  ----------------------\n", months[i]);
        printf("\n\n    sun     mon     tue     wed     thr     fri     sat     \n");

        weekBreak = firstDay(year);
        for(int k = 1; k <= weekBreak; k++){
            printf("        ");
        }
        dayCount = days[i];
        if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            days[1] = 29;
        for(int j = 1; j < dayCount; j++){
            printf("%7d ", j);

            weekBreak++;
            if(weekBreak > 6){
                printf("\n");
                weekBreak=0;
            }
        }

    }
    return 0;
}
