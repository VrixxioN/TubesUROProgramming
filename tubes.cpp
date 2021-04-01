#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <math.h>
using namespace std;

float jarak(int p, int q, int r, int s){
// Fungsi untuk menghitung jarak antara 2 titik (p,q) dan (r,s)
    int x=(p-r)*(p-r);
    int y=(q-s)*(q-s);
    float hasil=sqrt(x+y);
    return hasil;
}

int main(){
    srand(time(0));
    int health_robot=200, health_kecoak=20;     // Health awal robot dan kecoak
    int damage_robot=5, damage_kecoa=5;         // Damage awal tembakan robot dan kecoak (random)
    int kecoak=1, kecoak_killed=0;              // Jumlah kecoak dan yang terbunuh
    int a, b;

    //Batas koordinat
    int m, n;
    printf("Koordinat battlefield: m x n\nm: ");
    scanf("%d", &m);
    printf("n: ");
    scanf("%d", &n);
    int koor[m][n];
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            koor[i][j]=0;
        }
    }

    // Koordinat awal robot
    int Xr=0, Yr=0;
    koor[m-1-Yr][Xr]=7; // Robot di peta adalah angka 7

    // Spawn kecoak random
    int Xk, Yk;
    while (kecoak>0){
        Xk = rand() % n;
        Yk = rand() % m;
        if (Xk!=0 && Yk!=m-1){
            if (koor[m-1-Yk][Xk]==0){
                koor[m-1-Yk][Xk]=8; // Kecoak di peta adalah angka 8
                kecoak-=1;
            }
        }
    }

    // Peta awal
    printf("\n===PETA AWAL ROBOT DAN KECOAK===\n");
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            printf("%d ", koor[i][j]);
        }
        printf("\n");
    }

    // Status robot dan kecoak
    printf("\n===STATUS ROBOT DAN KECOAK===\n");
    printf("Posisi robot: (%d,%d)\n", Xr, Yr);
    printf("Posisi kecoak: (%d,%d)\n", Xk, Yk);
    printf("Jarak robot dan kecoak: %f\n", jarak(Xr, Yr, Xk, Yk));
    printf("Health robot: %d\n", health_robot);
    printf("Health kecoak: %d\n", health_kecoak);

    while (health_robot>0){
        // Komando robot bergerak, menembak, atau permainan dihentikan
        printf("\n===COMMAND===\n");
        printf("1. Bergerak\n2. Menembak\n3. Hentikan permainan\nApakah yang akan dilakukan robot (masukkan angka)? ");
        scanf("%d", &a);
        koor[m-1-Yr][Xr]=0;
        if (a==1){        // Robot bergerak
            printf("\n===PERGERAKAN===\n");
            printf("1. Maju\n2. Mundur\n3. Kanan\n4. Kiri\nKe arah mana robot akan bergerak (masukkan angka)? ");
            scanf("%d", &b);
            if (b==1){      // Robot maju
                if ((m-1-Yr) == 0){           // Robot di ujung atas battlefield
                    printf("\n[Tidak bisa maju, robot berada di ujung battefield]\n");
                }
                else {
                    if (Yr+1==Yk && Xr==Xk){  // Robot akan menabrak kecoak
                        printf("\n[Tidak bisa maju, robot akan bertabrakan dengan kecoak]\n");
                    }
                    else{
                        Yr+=1;
                        health_robot-=5;
                    }
                }
            }
            else if (b==2){ // Robot mundur
                if (Yr == 0) {                // Robot di ujung bawah battlefield
                    printf("\n[Tidak bisa mundur, robot berada di ujung battefield]\n");
                }
                else {
                    if (Yr-1==Yk && Xr==Xk){  // Robot akan menabrak kecoak
                        printf("\n[Tidak bisa mundur, robot akan bertabrakan dengan kecoak]\n");
                    }
                    else{
                        Yr-=1;
                        health_robot-=5;
                    }
                }
            }
            else if (b==3){ // Robot ke kanan
                if (Xr == (n-1)){             // Robot di ujung kanan battlefield
                    printf("\n[Tidak bisa ke kanan, robot berada di ujung battefield]\n");
                }
                else {
                    if (Xr+1==Xk && Yr==Yk){  // Robot akan menabrak kecoak
                        printf("\n[Tidak bisa ke kanan, robot akan bertabrakan dengan kecoak]\n");
                    }
                    else{
                        Xr+=1;
                        health_robot-=5;
                    }
                }
            }
            else if (b==4){ // Robot ke kiri
                if (Xr == 0){                 // Robot di ujung kiri battlefield
                    printf("\n[Tidak bisa ke kiri, robot berada di ujung battefield]\n");
                }
                else {
                    if (Xr-1==Xk && Yr==Yk){  // Robot akan menabrak kecoak
                        printf("\n[Tidak bisa ke kiri, robot akan bertabrakan dengan kecoak]\n");
                    }
                    else{
                        Xr-=1;
                        health_robot-=5;
                    }
                }
            }
        }
        else if (a==2){   // Robot menembak
            if (jarak(Xr, Yr, Xk, Yk)<=3){  // Kecoak dalam jangkauan tembakan robot
                health_kecoak -= damage_robot;
                health_robot-=5;
            }
            else{                           // Kecoak di luar jangkaaun tembakan robot
                printf("Kecoak di luar jangkauan.\n");
            }
        }
        else if (a==3){   // Permainan dihentikan
            break;
        }

        // Pergerakan dan tembakan kecoak
        int c=rand()%2;
        if (c==0){      // Kecoak bergerak
            koor[m-1-Yk][Xk]=0;
            int d=rand()%4;
            if (d==0){      // Kecoak maju
                if ((m-1-Yk) == 0){             // Kecoak di ujung atas battlefield
                }
                else {
                    if (Yk+1==Yr && Xr==Xk){    // Kecoak akan menabrak robot
                    }
                    else{
                        Yk+=1;
                    }
                }
            }
            else if (d==1){ // Kecoak mundur
                if (Yk == 0){                   // Kecoak di ujung bawah battlefield
                }
                else {
                    if (Yk-1==Yr && Xr==Xk){    // Kecoak akan menabrak robot
                    }
                    else{
                        Yk-=1;
                    }
                }
            }
            else if (d==2){ // Kecoak ke kanan
                if (Xk == (n-1)){               // Kecoak di ujung kanan battlefield
                }
                else {
                    if (Xk+1==Xr && Yr==Yk){    // Kecoak akan menabrak robot
                    }
                    else{
                        Xk+=1;
                    }
                }
            }
            else if (d==3){ // Kecoak ke kiri
                if (Xk == 0){                   // Kecoak di ujung kiri battlefield
                }
                else {
                    if (Xk-1==Xr && Yr==Yk){    // Kecoak akan menabrak robot
                    }
                    else{
                        Xk-=1;
                    }
                }
            }
        }
        else if (c==1){ // Kecoak menembak
            if (jarak(Xk, Yk, Xr, Yr)<=3){  // Robot dalam jangkauan tembakan kecoak
                health_robot -= damage_kecoa;
                health_kecoak-=5;
            }
        }

        // Spawn kecoak baru
        if (health_kecoak <= 0){
            kecoak_killed += 1;
            health_kecoak = 20;
            koor[m-1-Yk][Xk] = 0;
            Xk = rand() % n;
            Yk = rand() % m;
            if (Xk!=Xr && Yk!=Yr){
                if (koor[m-1-Yk][Xk]==0){
                    koor[m-1-Yk][Xk]=8;
                }
            }
            printf("\n===KECOAK BERHASIL DIBUNUH, KECOAK BARU TELAH MUNCUL===\n");
        }

        // Update peta
        printf("\n===PETA ROBOT DAN KECOAK===\n");
        koor[m-1-Yr][Xr]=7;
        koor[m-1-Yk][Xk]=8;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                printf("%d ", koor[i][j]);
            }
            printf("\n");
        }

        // Mencetak status health dari robot dan kecoak setelah command
        printf("\n===STATUS ROBOT DAN KECOAK===\n");
        printf("Posisi robot: (%d,%d)\n", Xr, Yr);
        printf("Posisi kecoak: (%d,%d)\n", Xk, Yk);
        printf("Jarak robot dan kecoak: %f\n", jarak(Xr, Yr, Xk, Yk));
        printf("Health robot: %d\n", health_robot);
        printf("Health kecoak: %d\n", health_kecoak);
    }
    // health_robot<=0
    if (a==3){
        printf("\nPermainan dihentikan.\n");
        printf("\n===STATUS ROBOT DAN KECOAK===\n");
        printf("Health robot: %d\n", health_robot);
        printf("Health kecoak: %d\n", health_kecoak);
        printf("Jumlah kecoak yang berhasil dibunuh: %d", kecoak_killed);
    }
    else{
        printf("Health robot telah habis. Permainan selesai!!!\n");
        printf("Jumlah kecoak yang berhasil dibunuh: %d", kecoak_killed);
    }
}
