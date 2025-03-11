#include <vector>
#include <algorithm>
#include <cmath>


float vec_average(std::vector<float> M) {
    float sm = 0;

    for (int i = 0; i < M.size(); i++) {
        sm += M[i];
    }

    float avg = sm / M.size();
    return avg;
}

float vec_mediana(std::vector<float> M) {
    float mediana = 0;
    sort(M.begin(), M.end());

    if (M.size() % 2 == 0) {
        mediana = (M[M.size() / 2] + M[M.size() / 2 - 1]) / 2;
    }
    else mediana = M[M.size() / 2];

    return mediana;
}

float vec_asd(std::vector<float> M) {
    float sm = 0;

    for (int i = 0; i < M.size(); i++)
        sm += M[i] * M[i];

    float sd = sqrt(sm / M.size());
    return sd;
}

float vec_dispersia(std::vector<float> M) {
    float avg = vec_average(M);
    float sm = 0;

    for (int i = 0; i < M.size(); i++)
        sm += (avg - M[i]) * (avg - M[i]);

    float d = sqrt(sm / M.size());
    return d;
}