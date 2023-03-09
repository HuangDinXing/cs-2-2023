#include <stdio.h>
#include <string.h>
typedef struct employee{
    int em_id;
    char em_name[10] ;
    int em_age;
    char em_phone[12] ;
    float em_salary;
}employee_t;

void employee_info(employee_t my_emp){
    printf("em_id=%d\n",my_emp.em_id);
    printf("em_name=");
    for(int i=0;i<10;i++){
        printf("%c",my_emp.em_name[i]);
    }
    printf("\nem_age=%d\n",my_emp.em_age);
    printf("em_phone=");
    for(int j=0;j<12;j++){
        printf("%c",my_emp.em_phone[j]);
    }
    printf("\nem_salary=%f\n",my_emp.em_salary);
}

int main()
{
    struct employee a;
   
    a.em_id=23;
    strcpy(a.em_name, "IU Lee");
    a.em_age=18;
    strcpy(a.em_phone, "0937123456");
    a.em_salary=1000.30;
    employee_info(a);
    return 0;
}
