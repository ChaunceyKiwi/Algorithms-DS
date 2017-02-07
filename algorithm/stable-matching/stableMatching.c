#include <stdio.h>
#define Num 4  //NumOfPeople + 1
void GetPrefList(int ManPref[Num][Num],int WomanPref[Num][Num]);
void RenewNext(int Next[Num],int GuyNeedRenew);
void init(int CurrentMan[Num],int CurrentWoman[Num]);
int FreeMen(int CurrentMan[Num]);
void GetRankFromPrefList(int Ranking[Num][Num],int WomanPref[Num][Num]);  //Ranking[w, m]
void printResult(int CurrentMan[Num]);
int ManPref[Num][Num];
int WomanPref[Num][Num];
//index [m, i] holds the "name" of woman in preference position i
int Next[Num]; // next women to propose
int CurrentMan[Num];
int CurrentWoman[Num];
// index w holds the "name" of the man with whom w is currently engaged
int Rangking[Num][Num];
// index [w, m] holds the position that m holds in w's preference list


int main(void){
    int women,men,men2;
    init(CurrentMan,CurrentWoman);
    //get the Preference List
    GetPrefList(ManPref, WomanPref);
    GetRankFromPrefList(Rangking, WomanPref);
    RenewNext(Next, 1);
    RenewNext(Next, 2);
    RenewNext(Next, 3);

    while(FreeMen(CurrentMan) != -1){
        men = FreeMen(CurrentMan);
        women = Next[men];
        RenewNext(Next, men);

        if(CurrentWoman[women] == -1){
            CurrentWoman[women] = men;
            CurrentMan[men] = women;
        }
        else{
            men2 = CurrentWoman[women];
            if(Rangking[women][men2] > Rangking[women][men]){
                CurrentWoman[women] = men;
                CurrentMan[men] = women;
                CurrentMan[men2] = -1;
            }
        }
    }
    printResult(CurrentMan);
    return 0;
}

void init(int CurrentMan[Num],int CurrentWoman[Num]){
    int i;
    for (i = 1;i < Num;i++){
        CurrentMan[i]   = -1;
        CurrentWoman[i] = -1;
    }
}

//Ranking[w, m]
void GetRankFromPrefList(int Ranking[Num][Num],int WomanPref[Num][Num]){
    int i,j,temp;
    for(i = 1;i < Num;i++){
        for(j = 1;j < Num;j++){
            temp = WomanPref[i][j];
            Ranking[i][temp] = j;
        }
    }
}

void GetPrefList(int ManPref[Num][Num],int WomanPref[Num][Num]){
    ManPref[1][1] = 1;  //man1's first  love women is 2
    ManPref[1][2] = 2;  //man1's second love women is 1
    ManPref[1][3] = 3;  //man1's third  love women is 3

    ManPref[2][1] = 2;
    ManPref[2][2] = 1;
    ManPref[2][3] = 3;

    ManPref[3][1] = 1;
    ManPref[3][2] = 2;
    ManPref[3][3] = 3;

    WomanPref[1][1] = 2;
    WomanPref[1][2] = 3;
    WomanPref[1][3] = 1;

    WomanPref[2][1] = 1;
    WomanPref[2][2] = 2;
    WomanPref[2][3] = 3;

    WomanPref[3][1] = 1;
    WomanPref[3][2] = 2;
    WomanPref[3][3] = 3;
}

void RenewNext(int Next[Num],int GuyNeedRenew){
    static int CurrentCount[Num] = {0,1,1,1};

    if(GuyNeedRenew == 1){
        Next[1] = ManPref[1][CurrentCount[1]];
        CurrentCount[1]++;
    }
    if(GuyNeedRenew == 2){
        Next[2] = ManPref[2][CurrentCount[2]];
        CurrentCount[2]++;
    }
    if(GuyNeedRenew == 3){
        Next[3] = ManPref[3][CurrentCount[3]];
        CurrentCount[3]++;
    }
}

int FreeMen(int CurrentMan[Num]){
    int i = 1;
    for(i = 1;i < Num;i++){
        if(CurrentMan[i] == -1)
            return i;
    }
    return -1;
}

void printResult(int CurrentMan[Num]){
    int i;

    for (i = 1;i < Num;i++){
        printf("Men%d and Women%d are couple\n",i,CurrentMan[i]);
    }
}
