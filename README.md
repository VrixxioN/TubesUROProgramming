# Tubes Programming URO
## Program robot pembasmi kecoak mutan
_Link_ GitHub: [TubesUROProgramming](https://github.com/VrixxioN/TubesUROProgramming.git)

Robot memiliki _health_ 200 dan _damage_ 5. Kecoak memiliki _health_ 20 dan _damage_ 5.
Robot dan kecoak memiliki jangkauan tembakan sejauh 3 satuan.
Cara menjalankan program:
1. Koordinat _battlefield_ dibatasi sejauh m x n. Program akan meminta masukan m dan n, dengan m dan n bilangan bulat.
2. Tampilan peta awal akan terlihat. Robot ditandai dengan angka 7, berada pada koordinat (0,0). Kecoak ditandai dengan angka 8, muncul pada koordinat secara _random_.
3. Status robot dan kecoak akan muncul. Status ini terdiri atas posisi robot dan kecoak, jarak robot dengan kecoak, serta _health_ robot dan kecoak.
4. Selama _health_ robot masih tersisa, program akan meminta komando dari _user_ apakah robot akan bergerak, menembak, atau permainan akan dihentikan.
5. Jika _user_ memilih bergerak, robot dapat bergerak maju, mundur, ke kanan, atau ke kiri. Robot tidak dapat bergerak menabrak kecoak atau keluar dari peta. Program akan memberi peringatan jika robot akan menabrak kecoak atau keluar dari peta. Jika robot berhasil bergerak, _health_ robot akan berkurang 5.
6. Jika _user_ memilih menembak, tembakan akan berhasil selama jarak antara robot dan kecoak tidak lebih dari 3 satuan. Program akan memberi peringatan jika kecoak berada di luar jangkauan. Jika robot berhasil menembak kecoak, _health_ kecoak akan berkurang sebesar _damage_ robot, sedangkan _health_ robot akan berkurang 5.
7. Selama robot bergerak atau menembak, kecoak akan bergerak atau menembak juga secara _random_. Syarat gerakan dan tembakan kecoak sama dengan robot. Jika kecoak berhasil bergerak atau menembak, _health_ kecoak akan berkurang 5. Jika kecoak berhasil menembak robot, _health_ robot akan berkurang sebanyak _damage_ kecoak.
8. Setelah itu, peta koordinat dan status akan ter-_update_ sesuai dengan pergerakan dan serangan robot dan kecoak.
9. Pergerakan serta serangan robot dan kecoak terjadi berulang-ulang selama _health_ robot masih ada. Jika _health_ kecoak telah habis, akan muncul kecoak baru secara _random_. Program juga akan menghitung jumlah kecoak yang berhasil dibunuh.
10. Jika permainan dihentikan, program akan menampilkan status akhir yang berisi _health_ robot dan kecoak serta jumlah kecoak yang berhasil dibunuh.
11. Jika _health_ robot sudah habis, program akan memberitahu bahwa permainan telah selesai dan menampilkan jumlah kecoak yang berhasil dibunuh.
