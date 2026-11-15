# GMRT MAGANG DAY 3
## Following-Axis Servo Motor and Motion Detection

### 1. Profile
- **Nama:** Khoirul Ramadhan
- **NIM:** 26/587906/SV/29319
- **NIU:** 587906
- **Program Studi:** D4 Teknologi Rekayasa Mesin
- **Kelas:** JRM 2
- **Angkatan:** 2026

### 2. Description
Proyek ini merupakan simulasi sistem Following-Axis Servo Motor and Motion Detection menggunakan ESP32, lima buah servo motor, sensor BNO055 berbasis Custom Chip, dan sensor PIR.

Sistem menggunakan komunikasi I2C untuk membaca orientasi dan PWM untuk mengendalikan servo motor.

### 3. Feature Table

| Fitur | Input Sensor | Output Aktuator | Perilaku |
|---|---|---|---|
| Roll | BNO055 | Servo 1 dan 2 | Bergerak berlawanan arah |
| Pitch | BNO055 | Servo 3 dan 4 | Bergerak mengikuti arah rotasi |
| Yaw | BNO055 | Servo 5 | Kembali ke posisi awal setelah 1 detik |
| Gerakan Eksternal | PIR | Semua servo | Bergerak serentak lalu kembali ke posisi awal |

### 4. Hardware and Software
- ESP32
- 5 Servo Motor
- BNO055 Custom Chip
- PIR Sensor
- Arduino Framework (C++)
- Wokwi Simulator
- Komunikasi I2C
- Kontrol PWM

### 5. How to Run
1. Buka proyek simulasi melalui link Wokwi.
2. Jalankan simulasi.
3. Buka Serial Monitor.
4. Amati pembacaan orientasi dan nilai PWM servo.
5. Uji respons sensor PIR.

### 6. Project Link
- **Wokwi:** [Masukkan link Wokwi]
- **Video Simulation:** [Masukkan link Google Drive]

### 7. Project Structure
- Code: Program utama dan Custom Chip.
- Schematic: Dokumentasi rangkaian.
- Screenshot: Bukti hasil pengujian.

### 8. Notes
BNO055 pada simulasi menggunakan Custom Chip yang dibuat untuk merepresentasikan pembacaan orientasi melalui komunikasi I2C. Implementasi ini merupakan emulator, bukan perangkat BNO055 fisik.
