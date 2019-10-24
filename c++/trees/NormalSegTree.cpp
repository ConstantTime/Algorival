long long seg[4 * N];
long long combine(long long &a, long long &b) {
	return a + b;
}
void update(long long t, long long i, long long j) {
	if (i == j) {
		seg[t] = a[i];
		return ;
	}
	long long mid = (i + j) / 2;
	update(t * 2, i, mid);
	update(t * 2 + 1, mid + 1, j);
	seg[t] = combine(seg[2*t], seg[2*t+1]);
}
void update(long long t, long long i, long long j, long long x, long long y) {
	if (i > y || j < x) {
		return ;
	}
	if (i == j) {
		seg[t] = y;
		return ;
	}
	long long mid = (i + j) / 2;
	update(t * 2, i, mid, x, y);
	update(t * 2 + 1, mid + 1, j, x, y);
	seg[t] = combine(seg[2*t], seg[2*t+1]);
}
long long query(long long t, long long i, long long j, long long l, long long r) {
	if (l <=i && j <= r) {
		return seg[t];
	}
	long long mid = (i + j) / 2;
	if (l <= mid) {
		if (r <= mid) {
			return query(t * 2, i, mid, l, r);
		}
		else {
			long long a = query(t * 2, i, mid, l, r);
			long long b = query(t * 2 + 1,  mid + 1, j, l, r);
			return combine(a, b);
		}
	}
	else {
		return query(t * 2 + 1,  mid + 1, j, l, r);
	}
}