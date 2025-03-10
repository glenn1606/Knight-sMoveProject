#include <iostream>
#include<bits/stdc++.h>

using namespace std;

//khoi tao o ban co, kich co max, nuoc di quan ma
const int max_n = 10;
int n;
int board[max_n][max_n];
int moves[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},{1, -2}, {1, 2}, {2, -1}, {2, 1}};

//sort list cac possible moves
void sortmoves(pair <int,int> nextmoves[], int count);

//kiem tra nuoc di nam trong pham vi ban co
bool validmoves(int x, int y);
//dem cac nuoc di co the
int countvalidmoves(int x, int y);
//in ra ban co
void chessboard();
//giai thuat tim duong di
bool knighttour(int x, int y, int step);

int main(){
    //kiem tra kich co ban co
    cin>> n;
    if (n<3 || n > max_n) {
        cout << "ban co khong hop le";
        return 0;
    }
    //khoi tao ban co chua di qua
    for(int i=0;i<n; i++)
        for(int j=0;j<n;j++)
            board[i][j] = -1;

    int startx, starty; // nhap o cua con ma ban dau
    cin >> startx >> starty;
     if (startx < 0 || startx >= n || starty < 0 || starty >= n) {
        cout << "vi tri ko hop le" << endl;
        return 0;
    }
    board[startx][starty] = 0; // danh dau vi tri ban dau cua con ma
    if(knighttour(startx,starty,1)) {
        chessboard();
    } else {
        cout<<"ko tim duoc duong di"<< endl;
    }

    return 0;
}
void sortmoves(pair <int,int> nextmoves[], int count){
    for(int i=0; i<count-1;i++){
        int minidx =i ;
        for(int j=i+1;j<count;j++){
            if(nextmoves[j].first < nextmoves[minidx].first) {
                minidx=j;
            }
        }
        swap(nextmoves[i],nextmoves[minidx]);
    }
}

//kiem tra nuoc di nam trong pham vi ban co
bool validmoves(int x, int y){
    if  (x >= 0 && x < n && y >= 0 && y < n && board[x][y] == -1)
        return true;
    else return false;
}

//dem cac nuoc di co the
int countvalidmoves(int x, int y){
    int count =0;
    for(int i=0;i<8;i++){
        int nextx= x+ moves[i][0];
        int nexty = y+ moves[i][1];
        if(validmoves(nextx,nexty)){
            count++;
        }
    }
    return count;
}
//in ra ban co
void chessboard(){
    for(int i=0;i<n;i++){
        for(int j=0; j<n;j++){
            cout << setw(2) << board[i][j] << " ";
        }
        cout << endl;
    }
}

//giai thuat tim duong di
bool knighttour(int x, int y, int step){
    // so buoc di qua = so o ban co thi endgame
    if (step == n*n) return true;
    // list cac nuoc di hop le
    pair <int,int> nextmoves[8];
    int count =0;
    //luu cac nuoc di hop le va cac possible moves
    for(int i=0; i<8;i++){
        int nextx= x+moves[i][0];
        int nexty= y+moves[i][1];
        if(validmoves(nextx,nexty)){
            nextmoves[count++] = {countvalidmoves(nextx,nexty),i};
        }
    }
    sortmoves(nextmoves, count); // sap xep de tim nuoc di it possible nhat

    for (int i = 0; i < count; i++) {
        int idx = nextmoves[i].second;
        int nextx = x + moves[idx][0];
        int nexty = y + moves[idx][1];

        board[nextx][nexty] = step;
        if (knighttour(nextx, nexty, step + 1)) {
            return true;
        }
        board[nextx][nexty] = -1; // Quay lui nếu không tìm được đường đi
    }
    return false;
}
