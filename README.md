# Analisis Perbandingan Return Trading dan Investing Saham BBCA 2014-2023

Repositori ini berisi implementasi program C++ untuk analisis perbandingan return strategi trading dan investing pada saham Bank Central Asia (BBCA) periode 2014-2023 dengan koreksi inflasi menggunakan metode Newton-Raphson.

## 📊 Overview

Program ini menganalisis dua strategi investasi utama:
- **Trading Strategy**: Transaksi aktif jangka pendek dengan volatilitas tinggi
- **Investing Strategy**: Buy-and-hold jangka panjang dengan fokus pertumbuhan konsisten

Analisis dilakukan dengan mempertimbangkan:
- ✅ Koreksi inflasi untuk mendapatkan return riil
- ✅ Perhitungan Internal Rate of Return (IRR) menggunakan metode Newton-Raphson
- ✅ Data historis 10 tahun (2014-2023)
- ✅ Perbandingan risk-return profile kedua strategi

## 🔧 Requirements

- Compiler C++ (g++, clang++, atau MSVC)
- Standard library C++ (iostream, iomanip, cmath)

## 🚀 Cara Menjalankan

### Kompilasi
```bash
g++ -o analysis main.cpp
```

### Eksekusi
```bash
./analysis
```

### Atau dalam satu perintah
```bash
g++ -o analysis main.cpp && ./analysis
```

## 📈 Hasil Utama

Berdasarkan analisis data historis 2014-2023:

| Metrik | Trading | Investing | Selisih |
|--------|---------|-----------|---------|
| **IRR Kumulatif Real** | 3.19% | 5.74% | +2.55% |
| **Return Tertinggi** | 28.26% | 25.02% | -3.24% |
| **Return Terendah** | -9.83% | -0.78% | +9.05% |
| **Volatilitas (Range)** | 38.09% | 25.80% | -12.29% |
| **Tahun Return Negatif** | 2 tahun | 1 tahun | -1 tahun |

### 💡 Key Insights

1. **Strategi Investing Unggul**: IRR riil 5.74% vs 3.19% trading (selisih 2.55% per tahun)
2. **Volatilitas Trading Tinggi**: Range return 38.09% vs 25.80% investing
3. **Resiliensi Krisis**: Investing lebih tahan terhadap shock (COVID-2020, krisis 2018)
4. **Potensi Return Maksimal**: Trading dapat menghasilkan return tertinggi di bull market

## 🧮 Metodologi

### Koreksi Inflasi
```cpp
Real Return = ((1 + Nominal Return) / (1 + Inflation Rate)) - 1
```

### Metode Newton-Raphson untuk IRR
Program menggunakan iterasi Newton-Raphson untuk mencari IRR yang membuat NPV = 0:

```
r(k+1) = r(k) - f(r(k)) / f'(r(k))
```

dengan toleransi error 1e-8 dan maksimal 1000 iterasi.

## 📊 Data Sources

- **Data Harga Saham**: Yahoo Finance (BBCA.JK)
- **Data Inflasi**: Badan Pusat Statistik Indonesia (BPS)
- **Periode**: Januari 2014 - Desember 2023

### Fungsi Utama

1. **`realReturn()`**: Menghitung return riil dengan koreksi inflasi
2. **`newtonRaphson()`**: Implementasi metode Newton-Raphson untuk IRR
3. **`main()`**: Orkestrasi analisis dan output hasil

## 💻 Output Program

Program akan menampilkan:
1. Tabel perbandingan return nominal vs riil per tahun
2. IRR kumulatif untuk kedua strategi
3. Reminder tentang karakteristik risiko

output:
```
Tahun | Trading Nominal(%) | Investing Nominal(%) | Inflasi(%) | Real Trading(%) | Real Investing(%)
---------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------
2014  |             15.20 |               12.50 |       8.40 |            6.27 |             3.78
2015  |             10.10 |                9.00 |       3.40 |            6.48 |             5.42
2016  |             18.30 |               15.60 |       3.00 |           14.85 |            12.23
2017  |             12.50 |               13.80 |       3.60 |            8.59 |             9.85
2018  |             -5.20 |                2.30 |       3.10 |           -8.05 |            -0.78
2019  |             25.40 |               20.70 |       2.70 |           22.10 |            17.53
2020  |             -8.30 |                5.00 |       1.70 |           -9.83 |             3.24
2021  |             30.70 |               27.40 |       1.90 |           28.26 |            25.02
2022  |             18.00 |               15.80 |       4.20 |           13.24 |            11.13
2023  |             10.50 |               12.00 |       3.00 |            7.28 |             8.74
---------------------------------------------------------------------------------------------
2015  |             10.10 |                9.00 |       3.40 |            6.48 |             5.42
2016  |             18.30 |               15.60 |       3.00 |           14.85 |            12.23
2017  |             12.50 |               13.80 |       3.60 |            8.59 |             9.85
2018  |             -5.20 |                2.30 |       3.10 |           -8.05 |            -0.78
2019  |             25.40 |               20.70 |       2.70 |           22.10 |            17.53
2020  |             -8.30 |                5.00 |       1.70 |           -9.83 |             3.24
2021  |             30.70 |               27.40 |       1.90 |           28.26 |            25.02
2022  |             18.00 |               15.80 |       4.20 |           13.24 |            11.13
2023  |             10.50 |               12.00 |       3.00 |            7.28 |             8.74
---------------------------------------------------------------------------------------------
IRR kumulatif Real Trading: 3.19 % per tahun
IRR kumulatif Real Investing: 5.74 % per tahun
```

## 📚 Referensi

1. Paper: "Analisis Perbandingan Return Trading dan Investing Saham BBCA 2014-2023"
2. Badan Pusat Statistik Indonesia - Data Inflasi
3. Yahoo Finance - Historical Stock Data
4. Numerical Methods in Finance Literature

## 👨‍💻 Author

**Muhammad Rifat Faqih**
- Email: mrifat08.mr@gmail.com
- Program: Teknik Komputer, Universitas Indonesia
