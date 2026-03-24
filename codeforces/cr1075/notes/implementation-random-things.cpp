// ceil
int ceil(int a, int b) {
	return (a+b-1)/b;
}
// to avoid overflow
int ceil2(int a, int b) {
	if (a==0) return 0;
	return (a-1)/b + 1;
}