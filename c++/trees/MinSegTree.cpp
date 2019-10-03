long long min_seg[4 * N];
long long min_combine(long long &a, long long &b) {
	return min(a , b);
}
void min_build(long long t, long long i, long long j) {
	if (i == j) {
		min_seg[t] = a[i];
		return ;
	}
	long long mid = (i + j) / 2;
	min_build(t * 2, i, mid);
	min_build(t * 2 + 1, mid + 1, j);
	min_seg[t] = min_combine(min_seg[2*t], min_seg[2*t+1]);
}
void min_update(long long t, long long i, long long j, long long x, long long y) {	
	if (i == j) {
		min_seg[t] = y;
		return ;
	}
	long long mid = (i + j) / 2;
	if(x <= mid)
		min_update(t * 2, i, mid, x, y);
	else 
		min_update(t * 2 + 1, mid + 1, j, x, y);
	min_seg[t] = min_combine(min_seg[2*t], min_seg[2*t+1]);
}
long long min_query(long long t, long long i, long long j, long long l, long long r) {
	if (l <=i && j <= r) {
		return min_seg[t];
	}
	long long mid = (i + j) / 2;
	if (l <= mid) {
		if (r <= mid) {
			return min_query(t * 2, i, mid, l, r);
		}
		else {
			long long a = min_query(t * 2, i, mid, l, r);
			long long b = min_query(t * 2 + 1,  mid + 1, j, l, r);
			return min_combine(a, b);
		}
	}
	else {
		return min_query(t * 2 + 1,  mid + 1, j, l, r);
	}
}