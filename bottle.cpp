#include <stdio.h>
#include <iostream>

using namespace std;

struct iNode{
    int drink;
    int cup;
    int bottle;
    iNode* left;
    iNode* right;
};

void Tree(iNode* x){
    if(x ->cup < 4 && x ->bottle < 2)
        return;
    if(x->cup > 3){
        iNode* l;
        int c = x->cup / 4;
        l->cup = x->cup - c * 4;
        l->drink = x->drink + c;
        l->cup = x->cup + c;
        l->bottle = x->bottle + c;
        x->left = l;
        Tree(l);
    }
    if(x->bottle > 1){
        iNode* r;
        int b = x->cup / 2;
        r->cup = x->cup - b * 2;
        r->drink = x->drink + b;
        r->cup = x->cup + b;
        r->bottle = x->bottle + b;
        x->right = r;
    }
    return;
}

void GetMax(iNode* x,int* max){
    if(x->left)
        GetMax(x->left,max);
    if(x->right)
        GetMax(x->right,max);
    if(x->drink > *max){
        *max = x->drink;
        return;
    }
}

int main(){
    int m = 0;
    printf("Enter money:");
    scanf("%d",&m);

    iNode* boot;
    boot->drink = m / 2;
    boot->cup = 0;
    boot->drink = 0;

    Tree(boot);
    int max = 0;
    GetMax(boot,&max);

    printf("Max = %d",max);
    getchar();
    return 0;
}
