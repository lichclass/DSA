#include <stdio.h>
#include <string.h>

#define MAX 50

typedef char String[100];

typedef struct {
    char LName[16];
    char FName[24];
    char Mi;
} Name;

typedef struct {
    Name name;
    unsigned int ID;
    char Course[8];
    int Year;
} Student;

typedef struct {
    Student students[MAX];
    int count;
} List;

void insert(Student x, int p, List *L){
    if(L->count<MAX && (p<=L->count && p>=0)){
        if(p!=L->count){
            int i;
            for(i=L->count; i>p; i--){
                L->students[i] = L->students[i-1];
            }
        }
        L->students[p] = x;
        L->count++;
    } else {
        printf("Insert position is out of bounds or list is full.\n");
    }
}

void delete(int p, List *L){
    if(p<L->count && p>=0){
        if(p!=L->count-1){
            int i;
            for(i=p; i<L->count-1; i++){
                L->students[i] = L->students[i+1];
            }
        }
        L->count--;
    }
}

int locate(char x[], List L){
    int i;
    for(i=0; i<L.count && strcmp(x, L.students[i].name.LName) != 0; i++){}
    return (i<L.count) ? i : -1; // -1 is a dummy value
}

Student retrieve (int p, List L){
    Student student = {{"XXXX", "XXXX", 'X'}, 0, "XXXX", 0}; // Dummy value
    if(p<L.count && p>=0){
        student = L.students[p];
    }
    return student;
}

void makenull(List *L){
    L->count = 0;
}

void printList(List L){
    int i;
    char nameFormat[48];
    for(i=0; i<L.count; i++){
        sprintf(nameFormat, "%s, %s %c.", L.students[i].name.LName, L.students[i].name.FName, L.students[i].name.Mi);
        printf("- %s - %u, %s, %d\n", nameFormat, L.students[i].ID, L.students[i].Course, L.students[i].Year);
    }
}

void printStud(Student stud){
    char nameFormat[48];
    sprintf(nameFormat, "%s, %s %c.", stud.name.LName, stud.name.FName, stud.name.Mi);
    printf("- %s - %u, %s, %d\n", nameFormat, stud.ID, stud.Course, stud.Year);
}

int main(){
    List myList = {
        {
            {{"Dela Cruz", "Juan", 'J'}, 21700005, "BSCS", 3},
            {{"Garcia", "Juanito", 'E'}, 21700006, "BSCS", 3}
        },
        2
    };

    Student insertThis = {{"Abrams", "John", 'M'}, 21700007, "BSIT", 2};
    
    printf("the value of pos %d is: ", 1);
    printStud(retrieve(1, myList));

    printList(myList);

    return 0;
}