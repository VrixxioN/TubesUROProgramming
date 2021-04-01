#include <stdio.h>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main(){
    srand(time(0));

    int health_robot=50, health_kecoak=20;      // Health awal robot dan kecoak
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
            if (koor[Yk][Xk]==0){
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
    printf("\n===STATUS ROBOT DAN KECOAK===\n");
    printf("Health robot: %d\n", health_robot);
    printf("Health kecoak: %d\n", health_kecoak);

    while (health_robot>0){
        // Komando robot bergerak atau menembak
        printf("\n===COMMAND===\n");
        printf("1. Bergerak\n2. Menembak\n3. Hentikan permainan\nApakah yang akan dilakukan robot (masukkan angka)? ");
        scanf("%d", &a);
        koor[m-1-Yr][Xr]=0;
        if (a==1){        // Robot bergerak
            printf("\n===PERGERAKAN===\n");
            printf("1. Maju\n2. Mundur\n3. Kanan\n4. Kiri\nKe arah mana robot akan bergerak (masukkan angka)? ");
            scanf("%d", &b);
            if (b==1){      // Robot maju
                if ((m-1-Yr) == 0){ //Pengecekan apakah robot ada di ujung battlefield
                    printf("\n[Tidak bisa maju, robot berada di ujung battefield]\n");
                }
                else {
                    Yr+=1;
                } 
            }
            else if (b==2){ // Robot mundur
                if (Yr == 0) {
                    printf("\n[Tidak bisa mundur, robot berada di ujung battefield]\n");
                }
                else {
                    Yr-=1;
                }
            }
            else if (b==3){ // Robot ke kanan
                if (Xr == (n-1)) {
                    printf("\n[Tidak bisa ke kanan, robot berada di ujung battefield]\n");
                }
                else {
                    Xr+=1;
                }
            }
            else if (b==4){ // Robot ke kiri
                if (Xr == 0) {
                    printf("\n[Tidak bisa ke kiri, robot berada di ujung battefield]\n");
                }
                else {
                    Xr-=1;
                }
            }
            health_robot-=5;
        }
        else if (a==2){   // Robot menembak
            if ((m-1-Yr) == (m-1-Yk)) {   // Robot berada pada 1 garis vertikal dengan kecoak
                if (abs(Xr-Xk) <= 3) {
                    health_kecoak -= damage_robot;
                }
                else {
                    printf("Kecoak diluar jangkauan\n");
                }
            }
            else if (Xk == Xr) {    // Robot berada pada 1 garis horizontal dengan kecoak
                if (abs(m-1-Yr-Yk) <= 3) {
                    health_kecoak -= damage_robot;
                }
                else {
                    printf("Kecoak diluar jangkauan\n");
                }
            }
            else {
                printf("Kecoak diluar jangkauan\n");
            }
            health_robot-=5;
        }
        else if (a==3) {
            health_robot = 0;
            /*printf("Permainan dihentikan.\n");
            printf("\n===STATUS ROBOT DAN KECOAK===\n");
            printf("Health robot: %d\n", health_robot);
            printf("Health kecoak: %d\n", health_kecoak);
            printf("Jumlah kecoak yang berhasil dibunuh: %d", kecoak_killed);
            break;*/
        }

        // Pergerakan dan tembakan kecoak
        int c=0;
        printf("%d", c);
        if (c==0){      // Kecoak bergerak
            koor[m-1-Yk][Xk]=0;
            int d=rand()%4;
            if (d==0){      // Kecoak maju
                Yk+=1;
            }
            else if (d==1){ // Kecoak mundur
                Yk-=1;
            }
            else if (d==2){ // Kecoak ke kanan
                Xk+=1;
            }
            else if (d==3){ // Kecoak ke kiri
                Xk-=1;
            }
        }
        else if (c==1){ // Kecoak menembak
            //belum
        }

        // Update peta
        printf("\n===PETA ROBOT DAN KECOAK===");
        koor[m-1-Yr][Xr]=7;
        koor[m-1-Yk][Xk]=8;
        printf("\n");
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                printf("%d ", koor[i][j]);
            }
            printf("\n");
        }

        if (health_kecoak <= 0) {
            kecoak_killed += 1;
            health_kecoak = 0;
        }        

        // Mencetak status health dari robot dan kecoak setelah command
        printf("\n===STATUS ROBOT DAN KECOAK===\n");
        printf("Health robot: %d\n", health_robot);
        printf("Health kecoak: %d\n", health_kecoak);
    }

    // health_robot <= 0
    printf("Health robot telah habis. Permainan selesai!!!\n");
    printf("Jumlah kecoak yang berhasil dibunuh: %d", kecoak_killed);
}
