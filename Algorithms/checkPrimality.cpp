bool isPrime(int ttttttt) {
    for (int d = 2; d * d <= ttttttt; d++) if (ttttttt % d == 0) return false;
    return true;
}
