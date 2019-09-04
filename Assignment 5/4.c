#include<stdio.h>
int check(int arr[],int num){
    int i;
    int counter = 0;
    for (i = 0; i < num; ++i) {
        if(arr[i] != -1){
            counter++;
        }
    }

    if (counter == 1){
        return 0;
    }
    else{
        return 1;
    }

}

int answer(int arr[], int num){
    int i;
    for (int i = 0; i < num; ++i) {
        if (arr[i] != -1){
            printf("Final answer is\t%c\n\n", 65+i);
        }
    }
}

int jump(int arr[], loc, num){
    if(loc != num-1){
        loc++;
    }
    else{
        loc = 0;
    }
    while(arr[loc] == -1){
        if(loc != num-1){
            loc++;
        }
        else{
            loc = 0;
        }
    }
    return loc;
}
int main(){

    int num, i, loc, temp;
    printf("Enter the number of people\t");
    scanf("%d", &num);
    int array[num];

    printf("Enter the choices of people\n\n");
    for (i = 0; i < num; ++i) {
        scanf("%d", &array[i]);
    }

    printf("Enter the initial choice\n\n");
    scanf("%d", &loc);
    temp = array[loc];
    array[loc] = -1;

    while(check(array, num)){

        for (i = 0; i < temp; ++i) {
            loc = jump(array, loc, num);
        }

        temp = array[loc];
        array[loc] = -1;
    }
    answer(array, num);
}