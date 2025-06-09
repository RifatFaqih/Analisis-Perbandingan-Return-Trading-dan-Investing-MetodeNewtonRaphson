#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Fungsi koreksi inflasi untuk return tahunan (%)
double realReturn(double nominalReturn, double inflation) {
    return ((1 + nominalReturn/100) / (1 + inflation/100) - 1) * 100;
}

// Fungsi Newton-Raphson untuk mencari IRR dari cashflow array
double newtonRaphson(double cashFlows[], int n, double guess = 0.1) {
    const double EPSILON = 1e-8;
    const int MAX_ITER = 1000;
    double irr = guess;

    for (int iter = 0; iter < MAX_ITER; ++iter) {
        double f = 0.0, df = 0.0;
        for (int t = 0; t < n; ++t) {
            f += cashFlows[t] / pow(1 + irr, t);
            if (t > 0) df -= t * cashFlows[t] / pow(1 + irr, t+1);
        }
        double newIrr = irr - f / df;
        if (fabs(newIrr - irr) < EPSILON) return newIrr;
        irr = newIrr;
    }
    return irr;
}

int main() {
    const int years = 10;
    int startYear = 2014;

    // Data nominal return trading, investing (%) per tahun
    double tradingReturns[years] = {15.2,10.1,18.3,12.5,-5.2,25.4,-8.3,30.7,18.0,10.5};
    double investingReturns[years] = {12.5,9.0,15.6,13.8,2.3,20.7,5.0,27.4,15.8,12.0};
    double inflation[years] = {8.4,3.4,3.0,3.6,3.1,2.7,1.7,1.9,4.2,3.0};

    double realTrading[years];
    double realInvesting[years];

    // Hitung return real per tahun
    for (int i = 0; i < years; ++i) {
        realTrading[i] = realReturn(tradingReturns[i], inflation[i]);
        realInvesting[i] = realReturn(investingReturns[i], inflation[i]);
    }

    // Buat cashflow cumulative untuk IRR:
    // Asumsi invest 1 unit awal (tahun 0 = -1)
    // Return sebagai pertumbuhan nilai investasi tiap tahun
    // Jadi cashflow = nilai akhir tiap tahun - nilai akhir tahun sebelumnya
    double tradingCashFlows[years+1];
    double investingCashFlows[years+1];
    tradingCashFlows[0] = -1.0;
    investingCashFlows[0] = -1.0;

    double tradingValue = 1.0;
    double investingValue = 1.0;

    for (int i = 0; i < years; ++i) {
        tradingValue *= (1 + realTrading[i]/100);
        investingValue *= (1 + realInvesting[i]/100);
        if (i == 0) {
            tradingCashFlows[1] = tradingValue - 1.0;
            investingCashFlows[1] = investingValue - 1.0;
        } else {
            tradingCashFlows[i+1] = tradingValue - (tradingValue/(1 + realTrading[i]/100));
            investingCashFlows[i+1] = investingValue - (investingValue/(1 + realInvesting[i]/100));
        }
    }

    // Hitung IRR kumulatif (per tahun)
    double irrTrading = newtonRaphson(tradingCashFlows, years+1) * 100;
    double irrInvesting = newtonRaphson(investingCashFlows, years+1) * 100;

    cout << fixed << setprecision(2);
    cout << "Tahun | Trading Nominal(%) | Investing Nominal(%) | Inflasi(%) | Real Trading(%) | Real Investing(%)\n";
    cout << "---------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < years; ++i) {
        cout << startYear + i << "  | "
             << setw(17) << tradingReturns[i] << " | "
             << setw(19) << investingReturns[i] << " | "
             << setw(10) << inflation[i] << " | "
             << setw(15) << realTrading[i] << " | "
             << setw(16) << realInvesting[i] << "\n";
    }
    cout << "---------------------------------------------------------------------------------------------\n";
    cout << "IRR kumulatif Real Trading: " << irrTrading << " % per tahun\n";
    cout << "IRR kumulatif Real Investing: " << irrInvesting << " % per tahun\n\n";

    cout << "Reminder: Return trading lebih volatile dan berisiko dibanding investing.\n";

    return 0;
}
