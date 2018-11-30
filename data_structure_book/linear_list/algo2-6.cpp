#include "c1.h"
#define NAMELEN 20
#define CLASSLEN 10

struct stud {
    char name[NAMELEN + 1];
    long num;
    char sex;
    int age;
    char Class[CLASSLEN + 1];
    int health;
};

typedef stud ElemType;

#include "c2-2.h"
#include "bo2-8.cpp"
#include "func2-1.cpp"

char sta[3][9] = {"healthy ", "normal ", "feeble "};
FILE *fp;

void Print(stud e) {
    printf("%-8s %6ld", e.name, e.num);
    if (e.sex == 'm') {
        printf(" male");
    } else {
        printf(" female");
    }
    printf("%5d %-4s", e.age, e.Class);
    printf("%9s\n", sta[e.health]);
}

void ReadIn(stud &e) {
    printf("please input name (<= %d chars): ", NAMELEN);
    scanf("%s", e.name);
    printf("please input student num: ");
    scanf("%ld", &e.num);
    printf("please input sex: ");
    scanf("%*c%c", &e.sex);
    printf("please input age: ");
    scanf("%d", &e.age);
    printf("please input class (<= %d chars): ", CLASSLEN);
    scanf("%s", e.Class);
    printf("please input health condition (0: %s, 1: %s, 2: %s): ", sta[0], sta[1], sta[2]);
    scanf("%d", &e.health);
}

void WriteToFile(stud e) {
    fwrite(&e, sizeof(stud), 1, fp);
}

Status ReadFromFile(stud &e) {
    int i;
    i = fread(&e, sizeof(stud), 1, fp);
    if (i == 1) {
        return OK;
    } else {
        return ERROR;
    }
}

int cmp(ElemType c1, ElemType c2) {
    return (int) (c1.num - c2.num);
}

void Modify(LinkList &L, ElemType e) {
    char s[80];
    Print(e);
    printf("please input your new content, keep unchanged if you don't want to modify it: \n");
    printf("please input name (<= %d chars): ", NAMELEN);
    gets(s);
    if (strlen(s)) {
        strcpy(e.name, s);
    }
    printf("please input student number: ");
    gets(s);
    if (strlen(s)) {
        e.num = atol(s);
    }
    printf("please inpuot sex: ");
    gets(s);
    if (strlen(s)) {
        e.sex = s[0];
    }
    printf("please input age: ");
    gets(s);
    if (strlen(s)) {
        e.age = atoi(s);
    }
    printf("please input class (<= %d chars): ", CLASSLEN);
    gets(s);
    if (strlen(s)) {
        strcpy(e.Class, s);
    }
    printf("please input health condition (0: %s, 1: %s, 2: %s): ", sta[0], sta[1], sta[2]);
    gets(s);
    if (strlen(s)) {
        e.health = atoi(s);
    }
    InsertAscend(L, e, cmp);
}

#define N 4

Status EqualNum(ElemType c1, ElemType c2) {
    if (c1.num == c2.num) {
        return OK;
    } else {
        return ERROR;
    }
}

Status EqualName(ElemType c1, ElemType c2) {
    if (strcmp(c1.name, c2.name)) {
        return ERROR;
    } else {
        return OK;
    }
}

int main() {
    stud student[N] = {{"wangxiaolin", 790631, 'm', 18, "cs 91", 0}, 
                        {"chenhong", 790632, 'f', 20, "cs 91", 1}, 
                        {"liujianping", 790633, 'm', 21, "cs 91", 0},
                        {"zhanglili", 790634, 'm', 17, "cs 91", 2}};
    int i, j, flag = 1; 
    char filename[13];
    ElemType e;
    LinkList T, p, q;
    InitList(T);
    while (flag) {
        printf("1: take element from students' array to insert to linklist order by student num ascend\n");
        printf("2: take record from the file to insert to linklist order by student num ascend\n");
        printf("3: input record from keyboard to insert to linklist order by student num ascend\n");
        printf("4: delete record by given student num in the first place\n");
        printf("5: delete record by given student name in the first place\n");
        printf("6: modify record by given student num in the first place\n");
        printf("7: modify record by given student name in the first palce\n");
        printf("8: search record by given student num in the first place\n");
        printf("9: search record by given student name in the first place\n");
        printf("10: show all records 11: save all records to file 12: end\n");
        printf("input operation command: ");
        scanf("%d", &i);
        switch(i) {
            case 1:
                for (j = 0; j < N; j++) {
                    InsertAscend(T, student[j], cmp);
                }
                break;
            case 2:
                printf("please input filename: ");
                scanf("%s", filename);
                if ((fp = fopen(filename, "rb")) == nullptr) {
                    printf("open file failure!\n");
                } else {
                    while (ReadFromFile(e)) {
                        InsertAscend(T, e, cmp);
                    }
                    fclose(fp);
                }
                break;
            case 3:
                ReadIn(e);
                InsertAscend(T, e, cmp);
                break;
            case 4: 
                printf("please input student num: ");
                scanf("%ld", &e.num);
                if (!DeleteElem(T, e, EqualNum)) {
                    printf("no record found by student num = %ld\n", e.num);
                }
                break;
            case 5:
                printf("please input student name: ");
                scanf("%*c%s", e.name);
                if (!DeleteElem(T, e, EqualName)) {
                    printf("no record found by student name = %s\n", e.name);
                }
                break;
            case 6:
                printf("please input student num: ");
                scanf("%ld%*c", &e.num);
                if (!DeleteElem(T, e, EqualNum)) {
                    printf("no record found by student num = %ld\n", e.num);
                } else {
                    Modify(T, e);
                }
                break;
            case 7:
                printf("please input student name: ");
                scanf("%*c%s%*c", e.name);
                if (!DeleteElem(T, e, EqualName)) {
                    printf("no record found by student name = %s\n", e.name);
                } else {
                    Modify(T, e);
                }
                break;
            case 8:
                printf("please input student num: ");
                scanf("%ld", &e.num);
                if (!(q = Point(T, e, EqualNum, p))) {
                    printf("no record found by student num = %ld\n", e.num);
                } else {
                    Print(q->data);
                }
                break;
            case 9:
                printf("please input student name: ");
                scanf("%*c%s", e.name);
                if (!(q = Point(T, e, EqualName, p))) {
                    printf("no record found by name = %s\n", e.name);
                } else {
                    Print(q->data);
                }
                break;
            case 10:
                printf("name    num   sex   age   class   health condition\n");
                ListTraverse(T, Print);
                break;
            case 11:
                printf("please input filename: ");
                scanf("%s", filename);
                if ((fp = fopen(filename, "wb")) == nullptr) {
                    printf("open file failure!\n");
                } else {
                    ListTraverse(T, WriteToFile);
                }
                fclose(fp);
                break;
            case 12:
                flag = 0;
                break;
            default:
                break;
        }
    }
    return 0;
}
