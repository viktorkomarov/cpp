int Factorial(int a){
    return (a <= 0) ? 1 : a * Factorial(a-1);
}