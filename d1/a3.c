#include <stdio.h>

struct E
{
    int id;
    char name[100];
    char des[100];
    float sal;
    float h;
    float d;
    float g;
};

void calcG(struct E *e)
{
    e->g = e->sal + (e->sal * e->h / 100) + (e->sal * e->d / 100);
}

int main()
{
    int n;
    scanf("%d", &n);
    struct E emps[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &emps[i].id);
        scanf("%s", emps[i].name);
        scanf("%s", emps[i].des);
        scanf("%f", &emps[i].sal);
        scanf("%f", &emps[i].h);
        scanf("%f", &emps[i].d);
        calcG(&emps[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", emps[i].id);
        printf("%s\n", emps[i].name);
        printf("%s\n", emps[i].des);
        printf("%.2f\n", emps[i].sal);
        printf("%.2f\n", emps[i].h);
        printf("%.2f\n", emps[i].d);
        printf("%.2f\n\n", emps[i].g);
    }
    return 0;
}
