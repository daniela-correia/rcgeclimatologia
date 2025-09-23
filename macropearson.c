void pearson() {
    // Abrir arquivo
    FILE *fpi = fopen("Pearson_data.csv", "r");
    if (!fpi) {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    const Int_t nlines = 667;  // número de linhas máximo
    char line[256];
    double x[nlines], y[nlines];
    Int_t n = 0;

    // Leitura dos dados
    while (fgets(line, sizeof(line), fpi)) {
        double xi, yi;
        if (sscanf(line, "%lf,%lf", &xi, &yi) == 2) {  
            x[n] = xi;
            y[n] = yi;
            n++;
        }
    }
    fclose(fpi);

    // 1. Calcular médias
    double med_x = 0, med_y = 0;
    for (int i = 0; i < n; i++) {
        med_x += x[i];
        med_y += y[i];
    }
    med_x /= n;
    med_y /= n;

    // 2. Calcular numerador e denominadores
    double num = 0, den_x = 0, den_y = 0;
    for (int i = 0; i < n; i++) {
        double dx = x[i] - med_x;
        double dy = y[i] - med_y;
        num += dx * dy;
        den_x += dx * dx;
        den_y += dy * dy;
    }

    // 3. Calcular coeficiente de Pearson
    double r = num / sqrt(den_x * den_y);

    // 4. Classificação da correlação
    TString classificacao;
    double abs_r = fabs(r);
    if (abs_r >= 0.9) classificacao = (r > 0 ? "Correlacao muito forte" : "Anticorrelacao muito forte");
    else if (abs_r >= 0.7) classificacao = (r > 0 ? "Correlacao forte" : "Anticorrelacao forte");
    else if (abs_r >= 0.5) classificacao = (r > 0 ? "Correlacao moderada" : "Anticorrelacao moderada");
    else if (abs_r >= 0.3) classificacao = (r > 0 ? "Correlacao fraca" : "Anticorrelacao fraca");
    else classificacao = (r > 0 ? "Correlacao desprezivel" : "Anticorrelacao desprezivel");

    // 5. Mostrar resultados
    cout << "Media RCG = " << med_x << ", Media manchas solares = " << med_y << endl;
    cout << "Coeficiente de Pearson r = " << r << endl;
    cout << "Classificacao: " << classificacao << endl;
}
