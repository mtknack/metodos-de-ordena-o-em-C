void radix(int *v, int n, int base, int num_digitos) {
    int i, j, w, count[base+1], d, posicao;
    int *aux = (int *) malloc(n * sizeof(int));
    for(w = 0; w < num_digitos; w++) {
        for(j = 0; j < base; j++) count[j] = 0; 
        for(i = 1; i <= n; i++) { 
            d = digito(v[i], w, base);
            count[d+1]++; 
        }
        for(j = 1; j < base; j++) count[j] += count[j-1];
        for(i = 0; i < n; i++) {
            d = digito(v[i], w, base);
            posicao = count[d];
            count[d] += 1;
            aux[posicao] = v[i]; 
        }
        for(i = 0; i < n; i++) v[i] = aux[i];
    }
}